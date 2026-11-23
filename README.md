# Hundred_Days_Of_Code

**100 Days of Code in C** follows the UPES daily programming challenge from arithmetic and control flow through arrays, strings, files, enumerations and structures. Each exercise has its own C11 program and starts with the original question. The question bank and examples come from the challenge maintained by `maitysoumik`. [Challenge website](https://maitysoumik.github.io/basic-coding-with-c/) · [Original question bank at the revision used](https://github.com/maitysoumik/basic-coding-with-c/blob/3dd9a87323f5a8de608b1bbe2137c8a804db871c/questions2.json)

**Progress** · 96 days · 146 programs · Days 01–50 contain two questions each and Days 51–96 contain one each.

## Compile and run

From the repository root in PowerShell, build Question 1 and pipe in its two numbers. The `build` directory holds the executable.

```powershell
New-Item -ItemType Directory -Force build | Out-Null
gcc -std=c11 -Wall -Wextra -pedantic Day01/Question_1.c -o build/q1.exe -lm
'3 4' | .\build\q1.exe
```

The output is `Sum = 7`. Substitute another file from the index to run a different exercise. The math library option also works with GCC on Linux. For example, run `./build/q1` after compiling with `-o build/q1`. Use a UTF-8 terminal to display the rupee sign in the billing exercises.

## Tests

All 146 programs compiled with warnings treated as errors. The test runner attempted all 259 published samples. **247 matched concrete expected outputs, 5 passed checks of descriptive examples, and 7 differed from the published output.** All 300 additional tests passed. The report lists each mismatch and the source of each fixture. [Verification report](docs/VERIFICATION.md) · [Per-case results](docs/verification.json)

```powershell
python tests/verify.py
python tools/audit.py --source
```

The suite returns exit code 2 when its only failures are documented source discrepancies. To run one day, use `python tests/verify.py --from-day 73 --through-day 73`. The history audit checks every timestamp, daily change, statement and local README link. Add `--remote` with GitHub CLI signed in as the repository owner to check the published tree and commit attribution.

## Historical Git simulation

Each `Day NN` commit represents a **simulated** weekday in a hackathon timeline. The dates and times are synthetic. They do not record when a solution was written, submitted or published.

The schedule uses all 96 Mondays through Fridays from July 13 through November 23, 2026, inclusive. Day 82 falls on Tuesday, November 3. Every author and committer timestamp uses Asia/Kolkata (UTC+05:30). The minute of the day is `600 + ((197 × day + 41) modulo 601)`, where Day 01 has day number 1. This gives a reproducible time between 10:00 and 20:00 IST.

The challenge site's release code starts on August 10 and makes a midsemester adjustment for September 5–10. The July-to-November weekday sequence is the assumption for this simulation. The public UPES calendar supplies no challenge-specific replacement for it. No college holidays were deducted. [Site scheduling code](https://github.com/maitysoumik/basic-coding-with-c/blob/3dd9a87323f5a8de608b1bbe2137c8a804db871c/script2.js) · [UPES academic calendar](https://www.upes.ac.in/admissions/academic-calendar)

The genuine initial README commit, dated November 26, 2026, is the parent of Day 01. Its timestamp is later than its simulated descendants. All 96 daily commits are ordered by their simulated times. [Original README commit](https://github.com/navisomehowcodes/Hundred_Days_Of_Code/commit/3e9d75347edc9a1f25b903469c5a2fe26e43d997)

## Development disclosure

OpenAI Codex generated the C implementations, additional test cases, documentation and simulated Git history with AI assistance. The challenge authors supplied the questions, notes and sample cases. Each implementation was compiled and exercised locally.

## Day-wise question index

Each link opens one standalone program. Dates and times below use the simulated schedule in IST.

### Days 01–20

| Day | Simulated date | IST | Programs |
| --- | --- | --- | --- |
| 01 | 2026-07-13 | 13:58 | [Q1 · Add two numbers](Day01/Question_1.c) · [Q2 · Four integer operations](Day01/Question_2.c) |
| 02 | 2026-07-14 | 17:15 | [Q3 · Rectangle area and perimeter](Day02/Question_3.c) · [Q4 · Circle area and circumference](Day02/Question_4.c) |
| 03 | 2026-07-15 | 10:31 | [Q5 · Celsius to Fahrenheit](Day03/Question_5.c) · [Q6 · Swap with a temporary variable](Day03/Question_6.c) |
| 04 | 2026-07-16 | 13:48 | [Q7 · Swap without a temporary variable](Day04/Question_7.c) · [Q8 · Sum of natural numbers](Day04/Question_8.c) |
| 05 | 2026-07-17 | 17:05 | [Q9 · Simple and compound interest](Day05/Question_9.c) · [Q10 · Seconds to hours, minutes and seconds](Day05/Question_10.c) |
| 06 | 2026-07-20 | 10:21 | [Q11 · Even or odd](Day06/Question_11.c) · [Q12 · Sign of an integer](Day06/Question_12.c) |
| 07 | 2026-07-21 | 13:38 | [Q13 · Leap year](Day07/Question_13.c) · [Q14 · Vowel or consonant](Day07/Question_14.c) |
| 08 | 2026-07-22 | 16:55 | [Q15 · Classify a character](Day08/Question_15.c) · [Q16 · Largest of three numbers](Day08/Question_16.c) |
| 09 | 2026-07-23 | 10:11 | [Q17 · Quadratic roots](Day09/Question_17.c) · [Q18 · Percentage to grade](Day09/Question_18.c) |
| 10 | 2026-07-24 | 13:28 | [Q19 · Classify a triangle](Day10/Question_19.c) · [Q20 · Day of the week](Day10/Question_20.c) |
| 11 | 2026-07-27 | 16:45 | [Q21 · Month name and length](Day11/Question_21.c) · [Q22 · Profit or loss](Day11/Question_22.c) |
| 12 | 2026-07-28 | 10:01 | [Q23 · Library fines](Day12/Question_23.c) · [Q24 · Electricity tariffs](Day12/Question_24.c) |
| 13 | 2026-07-29 | 13:18 | [Q25 · Switch-based calculator](Day13/Question_25.c) · [Q26 · Count from one to n](Day13/Question_26.c) |
| 14 | 2026-07-30 | 16:35 | [Q27 · Sum of odd numbers](Day14/Question_27.c) · [Q28 · Product of even numbers](Day14/Question_28.c) |
| 15 | 2026-07-31 | 19:52 | [Q29 · Factorial](Day15/Question_29.c) · [Q30 · Reverse an integer](Day15/Question_30.c) |
| 16 | 2026-08-03 | 13:08 | [Q31 · Decimal to binary](Day16/Question_31.c) · [Q32 · Integer palindrome](Day16/Question_32.c) |
| 17 | 2026-08-04 | 16:25 | [Q33 · Armstrong number](Day17/Question_33.c) · [Q34 · Primality test](Day17/Question_34.c) |
| 18 | 2026-08-05 | 19:42 | [Q35 · List positive factors](Day18/Question_35.c) · [Q36 · Greatest common divisor](Day18/Question_36.c) |
| 19 | 2026-08-06 | 12:58 | [Q37 · Least common multiple](Day19/Question_37.c) · [Q38 · Sum of digits](Day19/Question_38.c) |
| 20 | 2026-08-07 | 16:15 | [Q39 · Product of odd digits](Day20/Question_39.c) · [Q40 · One’s complement](Day20/Question_40.c) |

### Days 21–40

| Day | Simulated date | IST | Programs |
| --- | --- | --- | --- |
| 21 | 2026-08-10 | 19:32 | [Q41 · Swap outer digits](Day21/Question_41.c) · [Q42 · Perfect number](Day21/Question_42.c) |
| 22 | 2026-08-11 | 12:48 | [Q43 · Strong number](Day22/Question_43.c) · [Q44 · Series beginning with 1 and 3/4](Day22/Question_44.c) |
| 23 | 2026-08-12 | 16:05 | [Q45 · Series beginning with 2/3 and 4/7](Day23/Question_45.c) · [Q46 · Square of stars](Day23/Question_46.c) |
| 24 | 2026-08-13 | 19:22 | [Q47 · Growing star triangle](Day24/Question_47.c) · [Q48 · Growing digit prefix](Day24/Question_48.c) |
| 25 | 2026-08-14 | 12:38 | [Q49 · Growing digit suffix](Day25/Question_49.c) · [Q50 · Indented shrinking triangle](Day25/Question_50.c) |
| 26 | 2026-08-17 | 15:55 | [Q51 · Right-aligned digits](Day26/Question_51.c) · [Q52 · Vertical star groups](Day26/Question_52.c) |
| 27 | 2026-08-18 | 19:12 | [Q53 · Left-aligned star diamond](Day27/Question_53.c) · [Q54 · Centred star diamond](Day27/Question_54.c) |
| 28 | 2026-08-19 | 12:28 | [Q55 · List primes](Day28/Question_55.c) · [Q56 · Read and print an array](Day28/Question_56.c) |
| 29 | 2026-08-20 | 15:45 | [Q57 · Array sum](Day29/Question_57.c) · [Q58 · Array extremes](Day29/Question_58.c) |
| 30 | 2026-08-21 | 19:02 | [Q59 · Count even and odd values](Day30/Question_59.c) · [Q60 · Count signs and zeros](Day30/Question_60.c) |
| 31 | 2026-08-24 | 12:18 | [Q61 · Linear search](Day31/Question_61.c) · [Q62 · In-place array reversal](Day31/Question_62.c) |
| 32 | 2026-08-25 | 15:35 | [Q63 · Concatenate two arrays](Day32/Question_63.c) · [Q64 · Most frequent digit](Day32/Question_64.c) |
| 33 | 2026-08-26 | 18:52 | [Q65 · Binary search](Day33/Question_65.c) · [Q66 · Insert into a sorted array](Day33/Question_66.c) |
| 34 | 2026-08-27 | 12:08 | [Q67 · Insert at an index](Day34/Question_67.c) · [Q68 · Delete at an index](Day34/Question_68.c) |
| 35 | 2026-08-28 | 15:25 | [Q69 · Second distinct maximum](Day35/Question_69.c) · [Q70 · Right rotation](Day35/Question_70.c) |
| 36 | 2026-08-31 | 18:42 | [Q71 · Read and print a matrix](Day36/Question_71.c) · [Q72 · Matrix sum](Day36/Question_72.c) |
| 37 | 2026-09-01 | 11:58 | [Q73 · Row sums](Day37/Question_73.c) · [Q74 · Matrix transpose](Day37/Question_74.c) |
| 38 | 2026-09-02 | 15:15 | [Q75 · Matrix addition](Day38/Question_75.c) · [Q76 · Symmetric matrix](Day38/Question_76.c) |
| 39 | 2026-09-03 | 18:32 | [Q77 · Distinct diagonal entries](Day39/Question_77.c) · [Q78 · Main diagonal sum](Day39/Question_78.c) |
| 40 | 2026-09-04 | 11:48 | [Q79 · Zigzag diagonal traversal](Day40/Question_79.c) · [Q80 · Matrix multiplication](Day40/Question_80.c) |

### Days 41–60

| Day | Simulated date | IST | Programs |
| --- | --- | --- | --- |
| 41 | 2026-09-07 | 15:05 | [Q81 · String length by counting](Day41/Question_81.c) · [Q82 · One character per line](Day41/Question_82.c) |
| 42 | 2026-09-08 | 18:22 | [Q83 · Vowels and consonants](Day42/Question_83.c) · [Q84 · Uppercase without a case function](Day42/Question_84.c) |
| 43 | 2026-09-09 | 11:38 | [Q85 · Reverse a string](Day43/Question_85.c) · [Q86 · String palindrome](Day43/Question_86.c) |
| 44 | 2026-09-10 | 14:55 | [Q87 · Spaces, digits and special characters](Day44/Question_87.c) · [Q88 · Replace spaces with hyphens](Day44/Question_88.c) |
| 45 | 2026-09-11 | 18:12 | [Q89 · Character frequency](Day45/Question_89.c) · [Q90 · Toggle letter case](Day45/Question_90.c) |
| 46 | 2026-09-14 | 11:28 | [Q91 · Remove vowels](Day46/Question_91.c) · [Q92 · First repeating lowercase letter](Day46/Question_92.c) |
| 47 | 2026-09-15 | 14:45 | [Q93 · Anagram check](Day47/Question_93.c) · [Q94 · Longest word](Day47/Question_94.c) |
| 48 | 2026-09-16 | 18:02 | [Q95 · String rotation](Day48/Question_95.c) · [Q96 · Reverse individual words](Day48/Question_96.c) |
| 49 | 2026-09-17 | 11:18 | [Q97 · Name initials](Day49/Question_97.c) · [Q98 · Initials and full surname](Day49/Question_98.c) |
| 50 | 2026-09-18 | 14:35 | [Q99 · Reformat a date](Day50/Question_99.c) · [Q100 · Enumerate substrings](Day50/Question_100.c) |
| 51 | 2026-09-21 | 17:52 | [Q101 · First and last occurrence](Day51/Question_101.c) |
| 52 | 2026-09-22 | 11:08 | [Q102 · Ceiling index](Day52/Question_102.c) |
| 53 | 2026-09-23 | 14:25 | [Q103 · Leftmost pivot index](Day53/Question_103.c) |
| 54 | 2026-09-24 | 17:42 | [Q104 · Pivot integer](Day54/Question_104.c) |
| 55 | 2026-09-25 | 10:58 | [Q105 · Majority element](Day55/Question_105.c) |
| 56 | 2026-09-28 | 14:15 | [Q106 · Next greater element](Day56/Question_106.c) |
| 57 | 2026-09-29 | 17:32 | [Q107 · Previous greater element](Day57/Question_107.c) |
| 58 | 2026-09-30 | 10:48 | [Q108 · Products except self](Day58/Question_108.c) |
| 59 | 2026-10-01 | 14:05 | [Q109 · Maximum fixed-window sum](Day59/Question_109.c) |
| 60 | 2026-10-02 | 17:22 | [Q110 · Maximum in each window](Day60/Question_110.c) |

### Days 61–80

| Day | Simulated date | IST | Programs |
| --- | --- | --- | --- |
| 61 | 2026-10-05 | 10:38 | [Q111 · First negative in each window](Day61/Question_111.c) |
| 62 | 2026-10-06 | 13:55 | [Q112 · Kadane’s maximum subarray sum](Day62/Question_112.c) |
| 63 | 2026-10-07 | 17:12 | [Q113 · Kth smallest element](Day63/Question_113.c) |
| 64 | 2026-10-08 | 10:28 | [Q114 · Longest substring without repetition](Day64/Question_114.c) |
| 65 | 2026-10-09 | 13:45 | [Q115 · Lowercase anagrams](Day65/Question_115.c) |
| 66 | 2026-10-12 | 17:02 | [Q116 · Two-sum indices](Day66/Question_116.c) |
| 67 | 2026-10-13 | 10:18 | [Q117 · Merge sorted arrays](Day67/Question_117.c) |
| 68 | 2026-10-14 | 13:35 | [Q118 · Missing number](Day68/Question_118.c) |
| 69 | 2026-10-15 | 16:52 | [Q119 · Repeated number](Day69/Question_119.c) |
| 70 | 2026-10-16 | 10:08 | [Q120 · Sentence case and title case](Day70/Question_120.c) |
| 71 | 2026-10-19 | 13:25 | [Q121 · Save name and age](Day71/Question_121.c) |
| 72 | 2026-10-20 | 16:42 | [Q122 · Read a file line by line](Day72/Question_122.c) |
| 73 | 2026-10-21 | 19:59 | [Q123 · Count characters, words and lines](Day73/Question_123.c) |
| 74 | 2026-10-22 | 13:15 | [Q124 · Copy a file](Day74/Question_124.c) |
| 75 | 2026-10-23 | 16:32 | [Q125 · Append a line](Day75/Question_125.c) |
| 76 | 2026-10-26 | 19:49 | [Q126 · Open and display a file](Day76/Question_126.c) |
| 77 | 2026-10-27 | 13:05 | [Q127 · Uppercase a file](Day77/Question_127.c) |
| 78 | 2026-10-28 | 16:22 | [Q128 · Count letters in a file](Day78/Question_128.c) |
| 79 | 2026-10-29 | 19:39 | [Q129 · File sum and average](Day79/Question_129.c) |
| 80 | 2026-10-30 | 12:55 | [Q130 · Write and reread student records](Day80/Question_130.c) |

### Days 81–96

| Day | Simulated date | IST | Programs |
| --- | --- | --- | --- |
| 81 | 2026-11-02 | 16:12 | [Q131 · Weekday enumeration](Day81/Question_131.c) |
| 82 | 2026-11-03 | 19:29 | [Q132 · Traffic light signals](Day82/Question_132.c) |
| 83 | 2026-11-04 | 12:45 | [Q133 · Month length with an enum](Day83/Question_133.c) |
| 84 | 2026-11-05 | 16:02 | [Q134 · Operation status messages](Day84/Question_134.c) |
| 85 | 2026-11-06 | 19:19 | [Q135 · Explicit enumeration values](Day85/Question_135.c) |
| 86 | 2026-11-09 | 12:35 | [Q136 · Arithmetic menu choices](Day86/Question_136.c) |
| 87 | 2026-11-10 | 15:52 | [Q137 · Role-based greetings](Day87/Question_137.c) |
| 88 | 2026-11-11 | 19:09 | [Q138 · List enum names and values](Day88/Question_138.c) |
| 89 | 2026-11-12 | 12:25 | [Q139 · Integer values of statuses](Day89/Question_139.c) |
| 90 | 2026-11-13 | 15:42 | [Q140 · Person with a gender enum](Day90/Question_140.c) |
| 91 | 2026-11-16 | 18:59 | [Q141 · Read and print one student](Day91/Question_141.c) |
| 92 | 2026-11-17 | 12:15 | [Q142 · Five-student table](Day92/Question_142.c) |
| 93 | 2026-11-18 | 15:32 | [Q143 · Highest-scoring student](Day93/Question_143.c) |
| 94 | 2026-11-19 | 18:49 | [Q144 · Pass a structure by value](Day94/Question_144.c) |
| 95 | 2026-11-20 | 12:05 | [Q145 · Return the top student](Day95/Question_145.c) |
| 96 | 2026-11-23 | 15:22 | [Q146 · Employee with a nested joining date](Day96/Question_146.c) |
