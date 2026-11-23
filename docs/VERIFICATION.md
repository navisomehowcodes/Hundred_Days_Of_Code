# Verification through Day 96

All 146 source files compiled independently on Windows 11 Home Single Language x64, build 26300. The compiler was gcc (Rev5, Built by MSYS2 project) 16.1.0. The runner used C11 with `-Wall -Wextra -pedantic -Werror` and linked `-lm`. Python 3.14.10 ran each case with its own temporary working directory.

| Check | Result |
| --- | ---: |
| Compiled without warnings | 146 / 146 |
| Published examples attempted | 259 / 259 |
| Matched concrete published output | 247 |
| Passed a descriptive example using its diagram or a fixture | 5 |
| Failed the published expected output | 7 |
| Untested published examples | 0 |
| Additional tests passed | 300 / 300 |

The seven failed samples span six programs. Their failures remain visible in the machine-readable report. It also records the SHA-256 digest of every C file and the outcome of every test. The input manifest preserves the original notes, examples, explanations and website section labels. [Per-case results](verification.json) · [Question and sample manifest](../tests/questions.json)

## Reproduce the results

Run from the repository root with Python 3.10 or newer and GCC available on PATH.

```powershell
python tests/verify.py
python tests/verify.py --from-day 41 --through-day 50
python tests/verify.py --report build-results.json
python tools/audit.py --source
```

Exit code 0 means all selected checks passed. Code 1 indicates a build failure, an unexpected test result or an untested case. Code 2 preserves the failed-sample status when only the listed source discrepancies remain. The runner compares spaces, punctuation, indentation and internal newlines. It normalizes platform line endings and accepts one optional terminal newline. File exercises check the named files and their contents. The binary-copy fixture compares bytes directly. [Test runner](../tests/verify.py) · [File fixtures and descriptive comparisons](../tests/sample-adapters.json) · [Additional cases](../tests/edge-cases.json)

## Published output discrepancies

The program output below comes from the actual run. Each discrepancy is matched to its specific corrected value by the test runner. A different result for the same sample triggers an unexpected failure. [Discrepancy registry](../tests/source-issues.json)

| Question / sample | Published expected output | Program output | Reason |
| --- | --- | --- | --- |
| [Q4](../Day02/Question_4.c) / 1 | `Area=153.94, Circumference=43.96` | `Area=153.94, Circumference=43.98` | Using the same value of π for both formulas gives a circumference of 43.98. |
| [Q9](../Day05/Question_9.c) / 2 | `Simple Interest=1050, Compound Interest=1125.76` | `Simple Interest=1050, Compound Interest=1125.22` | Annual compounding gives 5000 × (1.07³ − 1) = 1125.215 before rounding to cents. |
| [Q44](../Day22/Question_44.c) / 1 | `Approximate sum: 3.3` | `Approximate sum: 2.6` | Adding the 3 terms in the statement gives 31/12 before rounding. |
| [Q45](../Day23/Question_45.c) / 1 | `Approximate sum: 1.56` | `Approximate sum: 1.78` | Adding the 3 terms in the statement gives 412/231 before rounding. |
| [Q45](../Day23/Question_45.c) / 2 | `Approximate sum: 2.22` | `Approximate sum: 2.84` | Adding the 5 terms in the statement gives 20798/7315 before rounding. |
| [Q120](../Day70/Question_120.c) / 1 | `I Am Trying To Build Logic` | `I Am Trying To Build Logic.` | All three examples use title case. Only this expected output drops the input's full stop. The program preserves punctuation and offers `--sentence` for sentence case. |
| [Q123](../Day73/Question_123.c) / 1 | `Characters: 31`<br>`Words: 5`<br>`Lines: 2` | `Characters: 33`<br>`Words: 6`<br>`Lines: 2` | The fixture contains 33 characters including its internal newline, six words and two lines. |

## Descriptive examples

For these five examples, the published expected field contains an instruction or description. The checks below exercise that instruction. Concrete values introduced by the test suite are identified as fixtures.

| Question / sample | Check performed |
| --- | --- |
| [Q50](../Day25/Question_50.c) / 2 | The second expected output is an indentation note. Compare with the first diagram, including every leading space. |
| [Q52](../Day26/Question_52.c) / 1 | The expected output describes the picture. Use the vertical groups and blank lines in the statement. |
| [Q54](../Day27/Question_54.c) / 1 | The expected output describes the picture. Compare the seven indented diagram rows. |
| [Q126](../Day76/Question_126.c) / 1 | The source omits the content and says to display it. Use a two-line fixture to check the stated behavior. |
| [Q142](../Day92/Question_142.c) / 1 | The source supplies neither records nor literal output. Check five identified test records against a tab-separated table. |

## Input conventions

- Questions 56–70 use a count followed by array values, then any index, target or rotation amount. Indices are zero-based. The second maximum is distinct. Frequency ties in Q64 select the smaller digit.
- Matrix input starts with rows and columns. Q75 and Q80 read dimensions separately for each matrix. Q79 traverses alternating anti-diagonals.
- String exercises use a line of text and preserve meaningful whitespace. Character operations use single-byte characters and the C locale. Fixed buffers support 4,096 array elements, 100 × 100 matrices and 4,096 data bytes for the basic line-based string exercises.
- Logic exercises that show brackets accept the published single-line notation, including labels such as `arr[] =` and `nums1 =`. The parser reads signed C `int` elements and permits up to 65,535 input bytes per line. Most totals use a wider integer type. Q108 uses the question’s stated 32-bit prefix and suffix product guarantee.
- Q17 prints the complex-root classification used in the sample. Run with `--roots` to display the conjugate pair as well. Q120 defaults to the word capitalization common to all three published examples. Run with `--sentence` for the capitalization in the question statement.
- Run file-handling programs in a scratch directory. Q121 creates `info.txt`. Q122, Q123, Q125, Q128 and Q129 accept an optional filename argument and otherwise use the named sample file. Q124 reads two filename lines. Q126 reads one filename. Q127 converts `input.txt` into `output.txt`. Q130 writes and rereads `students.txt`.
- Student records use `name roll marks` with a single-token name in the whitespace-delimited form. Enter a count first in Q130, Q143 and Q145. Q142 reads exactly five records. A tie for highest marks keeps the first student. Q146 accepts the labelled sample or three lines containing the employee name, ID and numeric joining date.
- Fixed patterns and enumerations have one prescribed output. Their additional tests check the complete layout or sequence. Further tests exercise boundary cases, missing files, binary data, empty and repeated values, and independently calculated results on small arrays.

## Ten-day checkpoints

Each row covers the indicated range. The final checkpoint covers the remaining six days. Every program has at least one additional test.

| Days | Compiled | Samples matched | Descriptive | Sample failures | Sample untested | Additional passed |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| 01–10 | 20 | 46 | 0 | 2 | 0 | 29 |
| 11–20 | 20 | 45 | 0 | 0 | 0 | 27 |
| 21–30 | 20 | 25 | 3 | 3 | 0 | 28 |
| 31–40 | 20 | 25 | 0 | 0 | 0 | 36 |
| 41–50 | 20 | 24 | 0 | 0 | 0 | 23 |
| 51–60 | 10 | 31 | 0 | 0 | 0 | 70 |
| 61–70 | 10 | 27 | 0 | 1 | 0 | 40 |
| 71–80 | 10 | 9 | 1 | 1 | 0 | 21 |
| 81–90 | 10 | 10 | 0 | 0 | 0 | 16 |
| 91–96 | 6 | 5 | 1 | 0 | 0 | 10 |

## Source and history verification

The deployed question bank matched revision `3dd9a87323f5a8de608b1bbe2137c8a804db871c`. Its release script flattens the sections in source order, takes two questions per day for 50 days, then one per day. The local audit compares every scoped record to that pinned bank, including optional notes and explanations. [Pinned question bank](https://github.com/maitysoumik/basic-coding-with-c/blob/3dd9a87323f5a8de608b1bbe2137c8a804db871c/questions2.json) · [Release schedule and mapping](https://github.com/maitysoumik/basic-coding-with-c/blob/3dd9a87323f5a8de608b1bbe2137c8a804db871c/script2.js)

The 96 daily commits descend from the original README commit. To check the entire local chain, run `python tools/audit.py`. For a published clone signed in as `navisomehowcodes`, run `python tools/audit.py --source --remote` to compare GitHub’s commit identities, paths, blob hashes and branch head. [History audit](../tools/audit.py) · [Project index](../README.md)
