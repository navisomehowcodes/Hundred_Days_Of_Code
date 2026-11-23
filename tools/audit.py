"""Audit the source tree, question mapping, tests, simulated commits and optional GitHub copy."""
import argparse
from datetime import date, datetime, timedelta, timezone
import hashlib
import json
from pathlib import Path
import re
import subprocess
import urllib.request

ROOT = Path(__file__).resolve().parents[1]
ACCOUNT = "navisomehowcodes"
REPOSITORY = ACCOUNT + "/Hundred_Days_Of_Code"
ORIGIN = "https://github.com/" + REPOSITORY + ".git"
EMAIL = "316471552+" + ACCOUNT + "@users.noreply.github.com"
BASE = "3e9d75347edc9a1f25b903469c5a2fe26e43d997"
REVISION = "3dd9a87323f5a8de608b1bbe2137c8a804db871c"
IST = timezone(timedelta(hours=5, minutes=30), "Asia/Kolkata")


def require(condition, message):
    if not condition:
        raise ValueError(message)


def run(*args):
    return subprocess.check_output(args, cwd=ROOT, text=True, encoding="utf-8").strip()


def git(*args):
    return run("git", *args)


def read(path):
    return json.loads((ROOT / path).read_text(encoding="utf-8"))


def timestamp(day):
    # July 13 was a Monday. Each full block of five challenge days advances one calendar week.
    weeks, weekday = divmod(day - 1, 5)
    d = date(2026, 7, 13) + timedelta(days=7 * weeks + weekday)
    minute = 600 + ((197 * day + 41) % 601)
    return datetime(d.year, d.month, d.day, minute // 60, minute % 60, tzinfo=IST)


def question_ids(day):
    return [2*day-1, 2*day] if day <= 50 else [day+50]


def message(day):
    ids = question_ids(day)
    task = f"Questions {ids[0]} and {ids[1]}" if len(ids) == 2 else f"Question {ids[0]}"
    return f"Day {day:02d}: Complete {task}"


def schedule_and_questions():
    questions = read("tests/questions.json")["questions"]
    expected_dates = []
    current = date(2026, 7, 13)
    while current <= date(2026, 11, 23):
        if current.weekday() < 5:
            expected_dates.append(current)
        current += timedelta(days=1)
    require(len(expected_dates) == 96, "Weekday count")
    require([d.day for d in expected_dates[81:]] == [3,4,5,6,9,10,11,12,13,16,17,18,19,20,23], "November milestones")
    require([q["id"] for q in questions] == list(range(1, 147)), "Question IDs or source order")
    for day, expected_date in enumerate(expected_dates, 1):
        moment = timestamp(day)
        require(moment.date() == expected_date and moment.weekday() < 5 and
                600 <= moment.hour*60 + moment.minute <= 1200, f"Schedule for Day {day}")
        require([q["id"] for q in questions if q["day"] == day] == question_ids(day), f"Mapping for Day {day}")
    return questions


def audit_files(questions):
    expected_paths = {q["path"] for q in questions}
    expected_days = {f"Day{d:02d}" for d in range(1, 97)}
    days = {p.name for p in ROOT.iterdir() if p.is_dir() and p.name.lower().startswith("day")}
    require(days == expected_days, "Day directories differ")
    tracked = set(git("ls-tree", "-r", "--name-only", "HEAD").splitlines())
    require({p for p in tracked if p.lower().endswith(".c")} == expected_paths, "Tracked source files differ")
    require({p.relative_to(ROOT).as_posix() for d in days for p in (ROOT/d).iterdir()} == expected_paths,
            "Unexpected file in a day directory")
    require(not any(p.lower().endswith((".exe", ".o", ".obj", ".pyc", ".tmp")) for p in tracked),
            "Tracked build artifact")
    report = read("docs/verification.json")["results"]
    issues = read("tests/source-issues.json")
    extra = read("tests/edge-cases.json")
    require([row["id"] for row in report] == list(range(1, 147)), "Results missing or unordered")
    seen_issues = set()
    for q, row in zip(questions, report):
        num = q["id"]
        path = ROOT/q["path"]
        expected = f"Day{q['day']:02d}/Question_{num}.c"
        require(q["path"] == expected and row["path"] == expected, f"File mapping Q{num}")
        require(path.read_text("utf-8").startswith(f"/*\nQuestion {num}\n{q['text']}\n*/\n"), f"Statement Q{num}")
        require(row["compiled"] and hashlib.sha256(path.read_bytes()).hexdigest() == row["source_sha256"],
                f"Source differs from its tested version Q{num}")
        require(len(row["samples"]) == len(q["testCases"]), f"Missing sample attempt Q{num}")
        require(len(row["edges"]) == len(extra[str(num)]) > 0, f"Edge test coverage Q{num}")
        require(all(c["status"] == "pass" for c in row["edges"]), f"Edge result Q{num}")
        for c in row["samples"]:
            if c["status"] == "fail":
                key = f"{num}.{c['case']}"
                seen_issues.add(key)
                require(key in issues and "source_issue" in c, f"Undocumented mismatch {key}")
            else:
                require(c["status"] in ("pass", "descriptive"), f"Untested sample Q{num}")
    require(seen_issues == set(issues), "Mismatch registry differs from actual results")
    readme_links = set()
    for md in [ROOT/"README.md", ROOT/"docs/VERIFICATION.md"]:
        for target in re.findall(r"\[[^\]\n]+\]\(([^)\s]+)\)", md.read_text("utf-8")):
            if target.startswith(("https://", "http://", "#")):
                continue
            require((md.parent/target).is_file(), f"Broken link in {md.name}: {target}")
            if md.name == "README.md" and target.endswith(".c"):
                readme_links.add(target)
    require(readme_links == expected_paths, "README program index")
    base_readme = subprocess.check_output(["git", "show", f"{BASE}:README.md"], cwd=ROOT)
    require((ROOT/"README.md").read_bytes().startswith(base_readme.rstrip(b"\r\n")), "Original README heading")
    require("simulation" in (ROOT/"README.md").read_text("utf-8").lower(), "Disclosure missing")
    return tracked


def audit_commits():
    rows = git("log", "--reverse", "--topo-order",
               "--format=%H%x09%P%x09%an%x09%ae%x09%cn%x09%ce%x09%aI%x09%cI%x09%s",
               f"{BASE}..HEAD").splitlines()
    require(len(rows) == 96, "Expected 96 challenge commits")
    parent = BASE
    commits = []
    for day, row in enumerate(rows, 1):
        sha, parents, author, ae, committer, ce, ad, cd, subject = row.split("\t")
        require(parents == parent, f"Commit chain Day {day}")
        require((author, ae, committer, ce) == (ACCOUNT, EMAIL, ACCOUNT, EMAIL), f"Identity Day {day}")
        require(ad == cd == timestamp(day).isoformat() and ad.endswith("+05:30"), f"IST dates Day {day}")
        require(subject == message(day), f"Subject Day {day}")
        changes = dict(line.split("\t")[::-1] for line in git("diff", "--no-renames", "--name-status", parent, sha).splitlines())
        daily = {f"Day{day:02d}/Question_{n}.c" for n in question_ids(day)}
        require(all(changes.get(path) == "A" for path in daily), f"Daily additions Day {day}")
        others = set(changes) - daily
        if day == 1:
            require(others == {"README.md", ".gitignore", ".gitattributes"}, "Initial configuration")
            require("simulation" in git("show", sha+":README.md").lower(), "First-commit disclosure")
        elif day == 96:
            require("README.md" in others and all(p == "README.md" or p.startswith(("docs/", "tests/", "tools/"))
                                                  for p in others), "Final documentation and tests")
        else:
            require(not others, f"Unexpected changes Day {day}: {others}")
        parent = sha
        commits.append(sha)
    return commits


def audit_source(questions):
    url = f"https://raw.githubusercontent.com/maitysoumik/basic-coding-with-c/{REVISION}/questions2.json"
    with urllib.request.urlopen(url, timeout=30) as response:
        contents = response.read()
    require(hashlib.sha256(contents).hexdigest() == read("tests/questions.json")["source_file_sha256"],
            "Pinned upstream checksum")
    upstream = json.loads(contents)["questionBank"]
    flat = [dict(section=s["section"], **q) for s in upstream for q in s["questions"]][:146]
    local = [{k:v for k,v in q.items() if k not in ("path", "day")} for q in questions]
    require(local == flat, "Source statements, samples, notes or explanations differ")


def audit_remote(tracked, commits):
    require(run("gh", "api", "user", "--jq", ".login") == ACCOUNT, "GitHub account")
    metadata = json.loads(run("gh", "api", f"repos/{REPOSITORY}"))
    require(metadata["owner"]["login"] == ACCOUNT and metadata["full_name"] == REPOSITORY and
            not metadata["private"] and metadata["default_branch"] == "main", "Destination metadata")
    require(git("remote", "get-url", "--push", "origin") == ORIGIN, "Push URL")
    require(git("ls-remote", "--heads", "origin", "main").split()[0] == commits[-1], "Remote main differs")
    tree = json.loads(run("gh", "api", f"repos/{REPOSITORY}/git/trees/{commits[-1]}?recursive=1"))
    require(not tree["truncated"], "Incomplete remote tree")
    remote = {entry["path"]:(entry["mode"],entry["sha"]) for entry in tree["tree"] if entry["type"] == "blob"}
    local = {}
    for line in git("ls-tree", "-r", "HEAD").splitlines():
        details, name = line.split("\t", 1)
        mode, _, oid = details.split()
        local[name] = (mode, oid)
    require(set(remote) == tracked and remote == local, "Remote blob paths, modes or hashes differ")
    remote_days = {p["path"] for p in tree["tree"] if p["type"] == "tree" and p["path"].startswith("Day")}
    require(remote_days == {f"Day{d:02d}" for d in range(1, 97)}, "Remote day directories")
    # 96 daily commits plus the original README all fit into one response.
    history = json.loads(run("gh", "api", f"repos/{REPOSITORY}/commits?sha=main&per_page=100"))
    require([c["sha"] for c in history] == list(reversed(commits)) + [BASE], "Remote ancestry")
    for c in history[:-1]:
        require((c["author"] or {}).get("login") == ACCOUNT and
                (c["committer"] or {}).get("login") == ACCOUNT, "GitHub account attribution")
    return len(remote)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--source", action="store_true", help="also check the pinned upstream bank online")
    parser.add_argument("--remote", action="store_true", help="also check the published repo using gh and Git")
    args = parser.parse_args()
    questions = schedule_and_questions()
    tracked = audit_files(questions)
    commits = audit_commits()
    require(not git("status", "--porcelain"), "Working tree has changes")
    if args.source:
        audit_source(questions)
    if args.remote:
        audit_remote(tracked, commits)
    print(f"96 days, 146 indexed programs, {len(tracked)} tracked files, {len(commits)} simulated commits")
    print(f"Original {BASE}\nDay 01   {commits[0]}\nDay 96   {commits[-1]}")
    print("Passed local checks" + (", pinned source" if args.source else "") +
          (", remote tree and GitHub attribution" if args.remote else ""))


if __name__ == "__main__":
    main()

