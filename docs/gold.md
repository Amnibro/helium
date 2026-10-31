# Gold: conversational scripts that expand into Helium

Gold is a conversational layer that sits on top of Helium. A Gold script is a
list of plain sentences. Each sentence maps to a verified Helium template, and
the whole script expands into one ordinary Helium program that `hc` type-checks,
compiles and runs. Gold adds no runtime or interpreter. What gets shipped is
Helium code.

## Phrases

Every sentence names a function along four axes: **verb noun modifier
context**. For example, `run function until` in the `core` context. The
vocabulary has 40 verbs, 53 nouns, 25 modifiers and 16 contexts (about 848k
combinations). Each combination can be a step, a function (`int -> int`) or a
predicate (`int -> bool`).

```
x = collatz step
y = reaches one
sub = digit sum
input = 27
Run function x until y.
Check errors and cache results.
Run subfunction.
Return results.
```

* `x = collatz step` binds a name to a function entry. Later sentences that
  mention `x` fill a slot with it.
* Each sentence is normalized: lowercased, filler words dropped, names, numbers
  and quoted strings replaced by `{}`. The result is a *shape*, such as
  `run function {} until {}`. Shapes are globally unique, so every sentence
  resolves to exactly one template.
* Sentences chain with `and`, `then`, `,` or `;`. Steps run in order and share
  state (results, error count, a key-value cache), so a result passes from one
  step to the next without extra wiring. A slot that a sentence leaves out is
  filled by the binding with the same name. That is how `Run subfunction.` picks
  up `sub`.
* Bindings nest. `big = above 100` followed by `keep running x until big` composes
  three levels.

`goldc compose demo.gold <gold_root> demo.amni` writes the Helium program. It
contains a shared prelude, one function per binding, one function per step, and
a `main` that threads the state through them. In the Gold repo's
`examples/demo` (the script above), 9 lines of Gold expand into 169 lines of
Helium, and `examples/nested` expands 7 lines into 160.

## Verification

A template enters the library only after it passes all of these checks:

1. Structure check: correct signature, 3 to 220 code lines, at least 2 phrase
   variants and at least 2 tests with different outputs. Forbidden constructs
   are rejected: process spawning, `extern`/FFI, file I/O, threads and imports.
   Answer-table heuristics are rejected too.
2. Deduplication on the normalized code, on a near-duplicate key, on the
   verb/noun/modifier/context combination, and on every phrase shape.
3. A test harness fills the slots for each test, builds the program with the
   real Helium compiler, and runs it sandboxed (`bwrap`, no network, read-only
   filesystem, CPU and memory limits). Stdout must match the expected output
   exactly. A step that changes nothing is rejected as a no-op.

Expected outputs are checked only by running the compiled Helium. No result is
computed outside Helium.

## Token cost

[bench/gold_tokens](../bench/gold_tokens/RESULTS.md) measures 50 tasks: 28 from
Gold's script corpus, the two examples, and 22 new ones. For each task, the Gold
script and hand-written Helium, Rust, Go and Python programs must build and
print identical output, on the original input and on a second one. Tokens per
program, relative to the Gold script (o200k_base, geometric mean of per-task
ratios; cl100k_base and the Qwen2.5-Coder tokenizer agree within 7%):

| | writing (50 tasks) | a change, diff tokens (11 tasks) |
|---|---|---|
| Python | 2.42× | 3.68× |
| Helium, hand-written | 4.88× | 3.53× |
| Rust | 5.12× | 3.25× |
| Go | 5.86× | 3.46× |
| expanded Helium, without prelude | 18.3× | (regenerated) |

Limits:

* Gold's lead is smallest against Python. On one task, Python ties under two
  tokenizers and wins by one token under the third. On one change, the Rust
  diff is smaller than the Gold diff.
* Writing Gold requires knowing the phrase library: 4,841 phrasings at the
  benchmark's pin, about 34k tokens as a plain list.
* The generated Helium is larger than hand-written Helium (median 3.8×).
* Every task is one the library can express, and all of them are small.

The methodology, per-task tables and fairness notes are in
[RESULTS.md](../bench/gold_tokens/RESULTS.md).

## Why it matters

Programming content such as tutorials, exercises, examples and training data
usually has to be rewritten whenever the language or its idioms change. With
Gold, that content is a set of short sentences over a library of verified
templates. Only the templates are maintained as code, and each one is
re-checked by `hc` and its tests. Every script that uses a template picks up
the fix when its Helium is regenerated.

## Current state

From the Gold repository's history (snapshot `f4a0a1a`, 2026-10-31):

| snapshot | verified conversational entries | verified scripts |
|---|---|---|
| d0490b5 | 495 | 12 |
| a7d8d10 | 653 | 16 |
| 13d86b0 | 897 | 16 |
| b31111e | 1408 | 28 |
| f4a0a1a | 1653 | 28 |

The latest Gold eval run (`gold eval`, recorded in `eval_results.json`) passed 7 of 7
programs.

Gold translates in three tiers: (1) reuse a verified template, (2) a local
Granite 4.2 3B model with a Helium LoRA, (3) a fallback translation with a
repair loop.
