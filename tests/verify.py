"""Build individual C11 programs and verify stdout and file effects in fresh directories."""
import argparse
import concurrent.futures
import hashlib
import json
import os
from pathlib import Path
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
TESTS = ROOT / "tests"
FLAGS = ["-std=c11", "-Wall", "-Wextra", "-pedantic", "-Werror"]


def read_json(path):
    return json.loads(path.read_text(encoding="utf-8"))


def write_json(path, data):
    path.write_text(json.dumps(data, indent=2, ensure_ascii=False) + "\n",
                    encoding="utf-8", newline="\n")


def text_output(data):
    return data.decode("utf-8").replace("\r\n", "\n")


def sample_case(q, index, sample, adapters):
    case = {"input": sample["input"], "output": sample["output"]}
    if case["input"] == "No input":
        case["input"] = ""
    case.update(adapters.get(f"{q['id']}.{index}", {}))
    return case


def run_case(exe, case, sandbox):
    for name, contents in case.get("before", {}).items():
        (sandbox / name).write_bytes(contents.encode("utf-8"))
    for name, hex_bytes in case.get("before_hex", {}).items():
        (sandbox / name).write_bytes(bytes.fromhex(hex_bytes))
    try:
        process = subprocess.run([exe, *case.get("args", [])], cwd=sandbox,
                                 input=case["input"].encode("utf-8"),
                                 capture_output=True, timeout=5)
        observed = text_output(process.stdout)
        errors = []
        expected = case["output"]
        # Compare every space and line. A program may terminate its last line with a newline.
        if observed != expected and observed != expected + "\n":
            errors.append({"stream": "stdout", "expected": expected, "actual": observed})
        if process.returncode != case.get("exit", 0):
            errors.append({"exit": process.returncode, "expected_exit": case.get("exit", 0)})
        if process.stderr and not case.get("exit"):
            errors.append({"stderr": text_output(process.stderr)})
        for name, expected_data in case.get("after", {}).items():
            path = sandbox / name
            actual = text_output(path.read_bytes()) if path.is_file() else None
            if actual != expected_data:
                errors.append({"file": name, "expected": expected_data, "actual": actual})
        for name, hex_bytes in case.get("after_hex", {}).items():
            path = sandbox / name
            actual = path.read_bytes().hex() if path.is_file() else None
            if actual != hex_bytes:
                errors.append({"file": name, "expected_hex": hex_bytes, "actual_hex": actual})
        result = {"status": "fail" if errors else case.get("match", "pass")}
        if errors:
            result["details"] = errors
        if "note" in case:
            result["note"] = case["note"]
        return result
    except (OSError, subprocess.TimeoutExpired, UnicodeError) as exc:
        return {"status": "fail", "details": [str(exc)]}


def verify(q, build_dir, edge_cases, adapters, cc):
    number = q["id"]
    exe = build_dir / (f"q{number}.exe" if os.name == "nt" else f"q{number}")
    build = subprocess.run([cc, *FLAGS, ROOT / q["path"], "-o", exe, "-lm"],
                           capture_output=True, text=True, timeout=45)
    result = {"day": q["day"], "id": number, "path": q["path"],
              "source_sha256": hashlib.sha256((ROOT / q["path"]).read_bytes()).hexdigest(),
              "compiled": build.returncode == 0 and not build.stderr.strip()}
    if not result["compiled"]:
        result["compiler_output"] = build.stdout + build.stderr
    groups = {"samples": [sample_case(q, i, t, adapters)
                          for i, t in enumerate(q["testCases"], 1)],
              "edges": edge_cases[str(number)]}
    for group, cases in groups.items():
        rows = []
        for i, case in enumerate(cases, 1):
            if result["compiled"]:
                with tempfile.TemporaryDirectory(dir=build_dir) as temp:
                    row = run_case(exe, case, Path(temp))
            else:
                row = {"status": "untested"}
            row["case"] = case.get("name", i)
            rows.append(row)
        result[group] = rows
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--from-day", type=int, default=1)
    parser.add_argument("--through-day", type=int, default=96)
    parser.add_argument("--report", type=Path, help="write the complete per-case results as JSON")
    parser.add_argument("--cc", default="gcc")
    parser.add_argument("--jobs", type=int, default=4)
    args = parser.parse_args()
    if not (1 <= args.from_day <= args.through_day <= 96 and args.jobs >= 1):
        parser.error("choose a range within Days 01–96 and a positive job count")
    questions = read_json(TESTS / "questions.json")["questions"]
    edges = read_json(TESTS / "edge-cases.json")
    adapters = read_json(TESTS / "sample-adapters.json")
    issues = read_json(TESTS / "source-issues.json")
    selected = [q for q in questions if args.from_day <= q["day"] <= args.through_day]
    version = subprocess.check_output([args.cc, "--version"], text=True).splitlines()[0]
    with tempfile.TemporaryDirectory(prefix="hundred-days-") as temp, \
         concurrent.futures.ThreadPoolExecutor(max_workers=args.jobs) as pool:
        jobs = [pool.submit(verify, q, Path(temp), edges, adapters, args.cc) for q in selected]
        results = [job.result() for job in jobs]

    totals = {"compiled": sum(r["compiled"] for r in results), "programs": len(results)}
    for group in ("samples", "edges"):
        totals[group] = {s: sum(row["status"] == s for r in results for row in r[group])
                         for s in ("pass", "descriptive", "fail", "untested")}
    print(json.dumps(totals))
    outstanding = totals["compiled"] != len(results)
    for r in results:
        if not r["compiled"]:
            print(r["path"], r["compiler_output"])
        for group in ("samples", "edges"):
            for case in r[group]:
                label = f"{r['id']}.{case['case']}"
                if case["status"] == "fail":
                    issue = issues.get(label) if group == "samples" else None
                    details = case["details"]
                    # An example discrepancy is recognized only for its recorded, corrected output.
                    known = (issue is not None and len(details) == 1 and
                             details[0].get("stream") == "stdout" and
                             details[0].get("actual") in (issue["correct"], issue["correct"] + "\n"))
                    print(r["path"], group, case["case"],
                          "documented discrepancy" if known else details)
                    if known:
                        case["source_issue"] = issue["reason"]
                    else:
                        outstanding = True
                elif case["status"] == "untested":
                    outstanding = True
    if args.report:
        write_json(args.report, {"compiler": version, "flags": FLAGS + ["-lm"],
                                 "from_day": args.from_day, "through_day": args.through_day,
                                 "summary": totals, "results": results})
    # 1 = unexpected regression, 2 = only documented literal mismatches, 0 = clean run.
    return 1 if outstanding else (2 if totals["samples"]["fail"] else 0)


if __name__ == "__main__":
    raise SystemExit(main())

