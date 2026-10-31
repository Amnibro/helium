# Gold token benchmark

How many tokens a Gold script takes compared with the same program written in Helium, Rust, Go and Python, and with the Helium that Gold expands into. Gold is pinned at `b7bc76e5d5a757767f5f92c1e85addcf717d896a`.

![Gold token savings](gold_tokens.png)

## Headline (o200k_base, geometric mean of per-task ratios)

Over 50 tasks, all verified, the same program needs:

* **Python**: 2.42× the tokens of the Gold script (median 2.35×, range 1.00–5.12×)
* **Helium (hand-written)**: 4.88× the tokens of the Gold script (median 4.81×, range 2.24–9.26×)
* **Rust**: 5.12× the tokens of the Gold script (median 4.71×, range 2.18–10.41×)
* **Go**: 5.86× the tokens of the Gold script (median 5.37×, range 2.96–11.10×)
* **Expanded Helium**: 18.28× without the shared prelude, 49.66× with it

For a change to an existing program (11 tasks), the diff is 3.68× in Python, 3.53× in Helium (hand-written), 3.25× in Rust, 3.46× in Go the size of the Gold diff (geomean of diff tokens).

The other two tokenizers put every writing geomean within 7% of these numbers (tables below).

## What it does not show

* **The phrase library is not free.** Writing Gold means knowing which sentences exist. The library index at `b7bc76e` has 4,841 phrasings, which comes to 34,206 o200k_base, 33,772 cl100k_base, 33,772 qwen2.5-coder tokens as a plain list. If a model had to hold the whole list in context, the per-program savings measured here (o200k, on average 59 tokens against Python and 160 against Rust) would only repay it after about 578 programs against Python or 214 against Rust. These counts measure the program text only.
* **The Helium that ships is bigger, not smaller.** Without the prelude, the expanded program is 3.8× the tokens of a hand-written Helium program with the same output (median; range 2.2–8.1×). With the prelude it is larger still. Gold saves on what a person or model writes and edits, not on the size of the generated code.
* **Python is the closest competitor.** Gold's lead is smallest against Python, and on c21 Python ties or wins (see below).
* **Selection bias.** Every task here is one Gold can express. The 28 corpus scripts were produced by Gold's own generator, and the 22 new tasks were written with the library at hand. Programs that need constructs outside the library are not represented at all. The existing `bench/llm` tasks (anagrams, brackets, caesar_crack, ...) could not be expressed with the phrasings available at this commit, so they were not reused.
* **Small programs.** Gold scripts here are 3–8 lines. The references are 2–22 lines in Python, 13–50 in Helium, 9–52 in Rust and 21–68 in Go. The ratios say nothing about large programs.

### Cases where Gold does not win

Every task/tokenizer/language combination where the other language needed no more tokens than Gold (a tie or a loss for Gold):

* c21 writing, Python, o200k_base: 45 vs Gold 45
* c21 writing, Python, cl100k_base: 45 vs Gold 45
* c21 writing, Python, qwen2.5-coder: 46 vs Gold 47
* n05 upkeep, Rust, o200k_base: 12 vs Gold 18
* n05 upkeep, Rust, cl100k_base: 12 vs Gold 18
* n05 upkeep, Rust, qwen2.5-coder: 12 vs Gold 18

## Method

Each task directory under `tasks/<id>/` contains:

* `task.gold`: the Gold script (comment lines removed; e01/e02 come from `examples/demo.gold` and `examples/nested.gold`, where the only change was dropping one comment line)
* `expanded.amni`: the output of `goldc compose`, committed so that changes in expansion are caught
* `expected.txt`: the full stdout of the compiled Gold program
* `ref.amni`, `ref.rs`, `ref.go`, `ref.py`: hand-written programs with no comments. Go is gofmt-clean, Rust is rustfmt-clean and builds with no warnings, and Python uses ordinary idioms such as comprehensions and `sorted`.

`harness.py` does the following for each task:

1. Composes `task.gold` with `goldc`, checks that the result is byte-identical to `expanded.amni`, builds it with `hc` and runs it. Stdout must equal `expected.txt` byte for byte.
2. Builds and runs the four references (`hc build`, `rustc --edition 2021 -O`, `go build`, `python3`). Each one's stdout must equal Gold's stdout with the `=> ...` debug state line removed. That line is Gold's internal state dump and is not program output.
3. **Second-input check.** It replaces the input literal (list, start value or text) in the Gold script and in all four references with the values listed in `tasks.json`, rebuilds everything and requires all five outputs to agree again. It also requires that the new output differs from the original, so a program that prints a fixed answer fails.
4. For tasks with an `upkeep/` directory, it verifies the changed version the same way (the change is described in `upkeep/change.txt`).
5. Counts tokens with tiktoken `o200k_base` and `cl100k_base`, and with the Hugging Face tokenizer of Qwen2.5-Coder-7B-Instruct (an open tokenizer). Whole files are counted. "Expanded Helium (program only)" starts at the `// ===== Gold bindings` marker, which drops the shared prelude.
6. Ratio = tokens(other) ÷ tokens(Gold) for each task. Summaries are the median and the geometric mean across tasks.
7. Upkeep cost = tokens on the lines a line diff (`difflib`) adds or removes between the base and changed file. A changed line counts twice, once removed and once added.

Python runs only the build/compare/count steps and the Python reference. No Helium or Gold output is produced by Python.

### Fairness notes

* The references print exactly what Gold prints (for example `no errors in 6 results` and `subfunction ran on N results, H memo hits`), so they carry Gold's output format. A program written from scratch might print less.
* 8 tasks contain a sentence whose only effect is on Gold's internal state (the `=>` line), with nothing visible in stdout. The references leave those steps out, which favours the references. The tasks: c03 ("count duplicates appearing at least 2 times"); c07 ("validate sequence with cache records"); c09 ("Scan items comparing at most 5."); c10 ("Validate all history items with pred."); c11 ("Store history items between 10 through 25."); c21 ("check running condition total under ceiling 50."); c22 ("search cache for any target 72."); c24 ("count numbers at_least threshold 40.").
* Excluded: c19 (gold data/conversational/scripts.jsonl line 19): its only visible output is the debug '=>' state line; no stdout result to reproduce; c20 (gold data/conversational/scripts.jsonl line 20): prints only the subfunction line; the computed values appear only in the debug '=>' line.
* The references assume non-empty input. They do include the data-dependent error branches that Gold prints (pair checks, gap checks, minimum length).
* c28: Gold's digit walk returns 0 for input 0; the Python, Go and Rust refs return 1 (not exercised).
* The upkeep edits are minimal, hand-made edits to each reference (helpers that are no longer needed are deleted), followed by rustfmt/gofmt. The expanded Helium diff is shown for information: nobody edits it, since it is regenerated.

## Summary by tokenizer

### o200k_base: writing

| compared with | median | geomean | min | max | total tokens (Gold total) |
|---|---|---|---|---|---|
| Python | 2.35× | 2.42× | 1.00× | 5.12× | 4,708 (1,751) |
| Helium (hand-written) | 4.81× | 4.88× | 2.24× | 9.26× | 9,074 (1,751) |
| Rust | 4.71× | 5.12× | 2.18× | 10.41× | 9,732 (1,751) |
| Go | 5.37× | 5.86× | 2.96× | 11.10× | 10,725 (1,751) |
| Expanded Helium (program only) | 18.40× | 18.28× | 12.84× | 30.60× | 32,183 (1,751) |
| Expanded Helium (full) | 48.56× | 49.66× | 37.33× | 100.60× | 84,683 (1,751) |

### o200k_base: upkeep (diff tokens)

| compared with | median | geomean | min | max | total tokens (Gold total) |
|---|---|---|---|---|---|
| Python | 3.33× | 3.68× | 1.28× | 23.67× | 534 (154) |
| Helium (hand-written) | 3.33× | 3.53× | 1.62× | 6.69× | 557 (154) |
| Rust | 3.67× | 3.25× | 0.67× | 8.77× | 563 (154) |
| Go | 3.78× | 3.46× | 1.20× | 7.86× | 564 (154) |
| Expanded Helium (full) | 9.92× | 11.32× | 4.06× | 54.67× | 1,659 (154) |

### cl100k_base: writing

| compared with | median | geomean | min | max | total tokens (Gold total) |
|---|---|---|---|---|---|
| Python | 2.36× | 2.42× | 1.00× | 5.12× | 4,690 (1,743) |
| Helium (hand-written) | 4.77× | 4.90× | 2.24× | 9.24× | 9,054 (1,743) |
| Rust | 4.69× | 5.11× | 2.18× | 10.35× | 9,670 (1,743) |
| Go | 5.34× | 5.85× | 2.96× | 11.10× | 10,667 (1,743) |
| Expanded Helium (program only) | 18.49× | 18.47× | 12.94× | 31.40× | 32,374 (1,743) |
| Expanded Helium (full) | 48.86× | 50.10× | 37.50× | 101.67× | 85,074 (1,743) |

### cl100k_base: upkeep (diff tokens)

| compared with | median | geomean | min | max | total tokens (Gold total) |
|---|---|---|---|---|---|
| Python | 3.33× | 3.68× | 1.24× | 23.67× | 530 (153) |
| Helium (hand-written) | 3.33× | 3.54× | 1.62× | 6.69× | 554 (153) |
| Rust | 3.67× | 3.26× | 0.67× | 8.77× | 560 (153) |
| Go | 3.67× | 3.45× | 1.20× | 8.46× | 557 (153) |
| Expanded Helium (full) | 10.08× | 11.53× | 4.11× | 55.33× | 1,677 (153) |

### qwen2.5-coder: writing

| compared with | median | geomean | min | max | total tokens (Gold total) |
|---|---|---|---|---|---|
| Python | 2.27× | 2.31× | 0.98× | 4.84× | 4,862 (1,908) |
| Helium (hand-written) | 4.42× | 4.60× | 2.17× | 8.35× | 9,246 (1,908) |
| Rust | 4.52× | 4.90× | 2.15× | 9.33× | 10,087 (1,908) |
| Go | 5.18× | 5.47× | 2.85× | 10.44× | 10,859 (1,908) |
| Expanded Helium (program only) | 18.03× | 17.79× | 11.13× | 32.07× | 33,975 (1,908) |
| Expanded Helium (full) | 45.60× | 47.87× | 34.33× | 104.67× | 88,425 (1,908) |

### qwen2.5-coder: upkeep (diff tokens)

| compared with | median | geomean | min | max | total tokens (Gold total) |
|---|---|---|---|---|---|
| Python | 3.33× | 3.72× | 1.21× | 25.67× | 573 (164) |
| Helium (hand-written) | 3.95× | 3.56× | 1.56× | 7.00× | 595 (164) |
| Rust | 3.67× | 3.28× | 0.67× | 9.23× | 602 (164) |
| Go | 4.00× | 3.47× | 1.17× | 8.46× | 592 (164) |
| Expanded Helium (full) | 10.38× | 12.50× | 4.96× | 61.33× | 1,896 (164) |

## Per task (o200k_base tokens)

| task | title | Gold | Expanded (program) | Helium | Rust | Go | Python | Python÷Gold | Rust÷Gold |
|---|---|---|---|---|---|---|---|---|---|
| c01 | Collatz sequence from a start value | 29 | 562 | 133 | 141 | 156 | 77 | 2.66 | 4.86 |
| c02 | Subtract last element, swap ends | 32 | 590 | 130 | 133 | 165 | 89 | 2.78 | 4.16 |
| c03 | Count duplicates, check errors | 31 | 584 | 94 | 85 | 109 | 46 | 1.48 | 2.74 |
| c04 | Digit-sum the leading items >= 10 | 31 | 445 | 151 | 143 | 180 | 76 | 2.45 | 4.61 |
| c05 | Repeated digit sum, sum of unique values | 38 | 749 | 93 | 113 | 149 | 57 | 1.50 | 2.97 |
| c06 | Collatz, drop leading items above 4 | 39 | 666 | 145 | 153 | 167 | 92 | 2.36 | 3.92 |
| c07 | Collatz step counts with memo | 37 | 817 | 288 | 321 | 305 | 169 | 4.57 | 8.68 |
| c08 | Last non-zero digit, keep > 4 | 47 | 827 | 274 | 321 | 323 | 161 | 3.43 | 6.83 |
| c09 | Collatz from 12 | 33 | 573 | 121 | 129 | 142 | 59 | 1.79 | 3.91 |
| c10 | Rank consecutive gaps | 35 | 709 | 133 | 147 | 184 | 71 | 2.03 | 4.20 |
| c11 | Sort, keep <= 25, digit sum | 48 | 881 | 265 | 301 | 313 | 129 | 2.69 | 6.27 |
| c12 | Tally of 7, Collatz step counts | 52 | 891 | 319 | 372 | 359 | 202 | 3.88 | 7.15 |
| c13 | Last non-zero digit, sort, keep >= 6 | 42 | 740 | 268 | 304 | 322 | 148 | 3.52 | 7.24 |
| c14 | Collatz, strip trailing 1s | 36 | 692 | 151 | 158 | 187 | 86 | 2.39 | 4.39 |
| c15 | Sum of last two even digits, scaled gaps | 45 | 747 | 333 | 368 | 367 | 205 | 4.56 | 8.18 |
| c16 | Squared-digit sum twice, pair sums | 40 | 910 | 344 | 391 | 444 | 205 | 5.12 | 9.78 |
| c17 | Char codes of second half, shift primes | 31 | 789 | 196 | 203 | 245 | 133 | 4.29 | 6.55 |
| c18 | Squared-digit sum, every other element | 41 | 845 | 309 | 321 | 344 | 142 | 3.46 | 7.83 |
| c21 | Keep > 5, sorted | 45 | 650 | 101 | 98 | 133 | 45 | 1.00 | 2.18 |
| c22 | Every other character code | 24 | 571 | 102 | 82 | 114 | 30 | 1.25 | 3.42 |
| c23 | Small-divisor counts, unique, repeated twice | 40 | 740 | 300 | 314 | 330 | 146 | 3.65 | 7.85 |
| c24 | Doubling sums up to 50 | 41 | 702 | 252 | 287 | 266 | 141 | 3.44 | 7.00 |
| c25 | Collatz, running maxima | 31 | 606 | 154 | 174 | 192 | 88 | 2.84 | 5.61 |
| c26 | Prefix at least the average, double below 40 | 34 | 554 | 147 | 163 | 180 | 96 | 2.82 | 4.79 |
| c27 | Digit sum, scale first minimum by 2^3 | 40 | 753 | 268 | 316 | 303 | 135 | 3.38 | 7.90 |
| c28 | Digit peak counts, sorted insert of count | 34 | 694 | 315 | 354 | 324 | 172 | 5.06 | 10.41 |
| e01 | Gold demo: Collatz 27, digit sums | 40 | 899 | 307 | 348 | 348 | 165 | 4.12 | 8.70 |
| e02 | Gold nested: Collatz until > 50, digit sums | 45 | 820 | 297 | 338 | 336 | 155 | 3.44 | 7.51 |
| n01 | Parse integer tokens from text | 30 | 465 | 147 | 120 | 161 | 65 | 2.17 | 4.00 |
| n02 | Top 3 unique values | 38 | 685 | 148 | 165 | 182 | 42 | 1.11 | 4.34 |
| n03 | Running sum | 24 | 335 | 101 | 107 | 116 | 31 | 1.29 | 4.46 |
| n04 | Prefix within a budget of 100 | 31 | 398 | 147 | 136 | 147 | 63 | 2.03 | 4.39 |
| n05 | Sums of groups of 3 | 35 | 499 | 109 | 103 | 164 | 62 | 1.77 | 2.94 |
| n06 | Digit sums, sum of unique | 35 | 783 | 214 | 259 | 275 | 113 | 3.23 | 7.40 |
| n07 | Pairwise deltas | 30 | 443 | 116 | 104 | 132 | 47 | 1.57 | 3.47 |
| n08 | Running sum of even values | 27 | 380 | 117 | 125 | 135 | 61 | 2.26 | 4.63 |
| n09 | Append primes up to 30 | 16 | 426 | 141 | 123 | 170 | 57 | 3.56 | 7.69 |
| n10 | Clamp to 0..50 | 35 | 597 | 114 | 111 | 132 | 57 | 1.63 | 3.17 |
| n11 | Gap check under 10 | 32 | 611 | 165 | 156 | 196 | 81 | 2.53 | 4.88 |
| n12 | Keep |x| <= 50 | 31 | 514 | 107 | 112 | 145 | 54 | 1.74 | 3.61 |
| n13 | Word lengths minus the last longest | 27 | 553 | 140 | 157 | 181 | 57 | 2.11 | 5.81 |
| n14 | Minimum-length check | 25 | 482 | 109 | 101 | 126 | 58 | 2.32 | 4.04 |
| n15 | Remove last occurrence of the maximum | 24 | 457 | 130 | 133 | 158 | 49 | 2.04 | 5.54 |
| n16 | Keep values in 5..20 | 30 | 389 | 87 | 100 | 131 | 45 | 1.50 | 3.33 |
| n17 | Vowel counts | 15 | 459 | 95 | 100 | 114 | 29 | 1.93 | 6.67 |
| n18 | Lengths of words with 2+ letters | 23 | 345 | 98 | 105 | 119 | 42 | 1.83 | 4.57 |
| n19 | Parse numbers, top 2 unique | 45 | 798 | 204 | 208 | 237 | 68 | 1.51 | 4.62 |
| n20 | Clamp, deltas, gap check | 54 | 1076 | 217 | 221 | 264 | 122 | 2.26 | 4.09 |
| n21 | Collatz until > 1000, keep |x| <= 50 | 38 | 732 | 145 | 154 | 200 | 89 | 2.34 | 4.05 |
| n22 | Drop max, budget 60, running sum | 45 | 750 | 233 | 254 | 253 | 96 | 2.13 | 5.64 |

## Upkeep per task (o200k_base diff tokens)

| task | change | Gold | Expanded Helium | Helium | Rust | Go | Python |
|---|---|---|---|---|---|---|---|
| c01 | Also cache the results before returning them. | 3 | 131 | 10 | 10 | 12 | 10 |
| c06 | Drop leading items above 8 instead of above 4. | 12 | 57 | 32 | 44 | 28 | 28 |
| e01 | Use the sum of squared digits instead of the digit sum. | 13 | 118 | 87 | 114 | 59 | 59 |
| n02 | Return only the top 2 values, and cache them. | 19 | 205 | 63 | 70 | 68 | 66 |
| n03 | Report errors before returning the running sums. | 3 | 164 | 12 | 12 | 14 | 71 |
| n04 | Raise the budget from 100 to 150 and report errors. | 25 | 248 | 63 | 69 | 72 | 32 |
| n05 | Group items in fours instead of threes. | 18 | 73 | 76 | 12 | 68 | 50 |
| n07 | Keep only the increases (positive deltas). | 11 | 208 | 59 | 79 | 85 | 59 |
| n12 | Lower the budget limit from 50 to 30. | 16 | 77 | 26 | 34 | 24 | 60 |
| n13 | Return running totals of the word lengths instead of removing the longest. | 14 | 283 | 71 | 89 | 110 | 37 |
| n16 | Widen the accepted range from 5..20 to 10..30. | 20 | 95 | 58 | 30 | 24 | 62 |

## Reproducing

```sh
# Helium: hc/bootstrap.sh produces build/hcn
git clone <gold repo> gold && git -C gold checkout b7bc76e
build/hcn build gold/goldc.amni -o goldc
python3 -m venv venv && venv/bin/pip install tiktoken tokenizers matplotlib
# tokenizer.json from Qwen/Qwen2.5-Coder-7B-Instruct on Hugging Face
HC_LIB=$PWD/hc/lib venv/bin/python bench/gold_tokens/harness.py \
    --gold-root gold --goldc ./goldc --hc build/hcn --qwen-tokenizer tokenizer.json
venv/bin/python bench/gold_tokens/report.py
```

Last run: 50/50 tasks verified, 11/11 upkeep variants verified. Tools: rustc, go and python3 versions: rustc 1.99.1 (58cf8f9c3 2026-10-13), go version go1.27.3 linux/amd64, 3.13.5 (python).
