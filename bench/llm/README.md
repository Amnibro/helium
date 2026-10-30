# Model-written Helium: correctness, token cost and speed

Can a language model that has never seen Helium in training write it from the
primer alone? How many tokens does that cost next to Python and Rust, and how
fast do the programs run? This directory holds the harness, the 43 tasks,
every model reply and every generated program, measured 2026-10-29.

## Method

- 43 small tasks with one exact expected output each, in nine categories:
  strings 11, basic 8, math 5, search 5, speed 5, dp 4, float 2, parsing 2,
  sim 1. Every task has a Python reference that produced its expected output
  (`tasks.py`).
- Claude Haiku 5.5, Sonnet 5.5 and Opus 5.5 each wrote every task in Helium,
  Python 3 and Rust: 387 programs. Calls went through the Claude Code CLI in
  headless mode with no tools, no project settings and a one-line system
  prompt, so each reply is one plain model turn.
- Helium prompts start with the whole [HELIUM.md](../../HELIUM.md) primer
  (about 7,000 tokens). Python and Rust prompts get nothing extra.
- A program passes when its output matches exactly (trailing spaces ignored).
  A failing program gets one repair turn with the compiler error, the crash or
  the wrong output.
- Output tokens are the model's reported usage, thinking included. Code size
  is the generated program in o200k tokens, a tokenizer-neutral count.
- Cost uses list prices per million tokens (input / output / cache read):
  Haiku 5.5 $0.10 / $0.50 / $0.01, Sonnet 5.5 $2 / $10 / $0.20, Opus 5.5
  $4 / $20 / $0.20. The Helium "cached" column counts the primer as a cache
  read on every call.
- Runtimes: every passing program rebuilt (Helium `hcn` from this commit,
  `rustc -O`, CPython 3.14.8) and run three times on an AMD Ryzen 9 9950X3D
  under Linux; the table takes the fastest run, then the median over the three
  models' programs. Times include process start.

## Results

Correct programs, first try · after one repair

| model | Helium | Python | Rust |
|---|---|---|---|
| Haiku 5.5 | 41/43 · 43/43 | 42/43 · 43/43 | 42/43 · 43/43 |
| Sonnet 5.5 | 42/43 · 43/43 | 43/43 · 43/43 | 43/43 · 43/43 |
| Opus 5.5 | 42/43 · 43/43 | 43/43 · 43/43 | 43/43 · 43/43 |

Median tokens per program, first attempt: output with thinking · code

| model | Helium | Python | Rust |
|---|---|---|---|
| Haiku 5.5 | 997 · 152 | 256 · 102 | 382 · 173 |
| Sonnet 5.5 | 426 · 146 | 155 · 95 | 249 · 168 |
| Opus 5.5 | 438 · 158 | 178 · 121 | 269 · 189 |

Mean cost per finished program in USD, repairs included

| model | Helium, primer cached | Helium, uncached | Python | Rust |
|---|---|---|---|---|
| Haiku 5.5 | 0.00085 | 0.00151 | 0.00027 | 0.00040 |
| Sonnet 5.5 | 0.00843 | 0.02132 | 0.00336 | 0.00456 |
| Opus 5.5 | 0.01419 | 0.04141 | 0.00693 | 0.00967 |

Runtime in ms

| tasks | Helium | Python | Rust |
|---|---|---|---|
| all 43 | 261 | 2,425 | 130 |
| all but collatz | 106 | 2,204 | 125 |
| the six where Python takes over 50 ms | 232 | 2,144 | 60 |

| task | Helium | Python | Rust | Python / Helium |
|---|---:|---:|---:|---:|
| mandelbrot_count | 27.8 | 1,141.3 | 25.3 | 41x |
| leibniz_pi | 20.4 | 533.5 | 8.5 | 26x |
| collatz | 154.6 | 221.1 | 5.3 | 1.4x |
| lcg | 1.4 | 101.4 | 1.0 | 72x |
| double_palindromes | 5.3 | 81.9 | 3.7 | 15x |
| count_primes | 22.3 | 65.1 | 16.5 | 2.9x |

## What it shows

- Models write correct Helium from the primer alone. After one repair turn
  every model passed every task in all three languages; on the first try
  Helium missed 4 of 129, Python 1 and Rust 1.
- Helium costs more tokens than Python today. Output is 2.5 to 3.9 times
  Python's and 1.6 to 2.6 times Rust's, mostly thinking about a language no
  model was trained on. The written code is 12 to 16% smaller than Rust's
  and 31 to 54% larger than Python's (medians).
- The primer adds about 7,000 input tokens per call, which costs 0.05 to 0.1
  of the input price once cached.
- The programs run about 9 times faster than Python across the suite, and 15
  to 72 times faster on four of the six heaviest tasks. Rust's lead in the total comes from collatz,
  where the Rust programs memoized and the Helium ones did not; without it
  Helium's total is below Rust's. On the
  [PLB suite](../plb/README.md), where every language runs the same
  algorithm, Helium beats the fastest of PLB's Rust, C and C++ programs in 29
  of 33 single-threaded cells.

## Caveats

- Small tasks, one run per model and language. The first-try differences are
  a handful of programs and within noise.
- Only Claude models: the Gemini, Codex and Grok CLIs on the test machine had
  no usable access when this ran. `run.py` has adapters for them.
- Totals of a few hundred milliseconds move by 10 to 20% between sessions on
  a desktop (a rerun gave 268, 2,440 and 154 ms); the ratios hold.
- Models chose their own algorithms, so a runtime row compares programs, not
  only compilers (see collatz).
- Code sizes use o200k, not Claude's tokenizer. Claude's own counts are in the
  output-token column.

## Reproduce

```bash
hc/bootstrap.sh                                     # builds build/hcn
python3 bench/llm/tasks.py                          # writes tasks.json
python3 bench/llm/run.py claude:haiku,claude:sonnet,claude:opus helium,python,rust all
python3 bench/llm/retime.py
python3 bench/llm/report.py                         # the tables above, plus runs.csv
```

`run.py` needs the `claude` CLI signed in and Python's `tiktoken`; it skips
jobs already in `results.jsonl`, so delete that file for a fresh run.
