# Helium specification (draft)

This is a draft formal specification of Helium, derived from the compiler (`hc`) rather than from intent. It defines the grammar, the type system, the memory and safety rules, and the run-time behavior, and states the soundness theorems the language is meant to satisfy.

**Status, plainly:** nothing here is proven. Every rule is backed by a small Helium program that was compiled and run with `hc` (at commit `5ec5501`, 2026-11-05), and a second pass tried to break each rule with new programs and corrected what it broke. The theorems in chapter 4 are conjectures, and the known gaps below are counterexamples to them in today's compiler. The written spec comes first; an executable reference semantics, and later a machine-checked proof of the core language, are the next steps.

| Chapter | Rules | Confirmed | Unconfirmed | Known gaps |
|---|---|---|---|---|
| [1. Lexical structure and grammar](1-grammar.md) | 131 | 124 | 1 | 6 |
| [2. Types and static semantics](2-types.md) | 86 | 63 | 3 | 20 |
| [3. Memory model and safety rules](3-memory.md) | 33 | 25 | 0 | 8 |
| [4. Dynamic semantics and soundness statements](4-semantics.md) | 64 | 56 | 1 | 7 |
| Total | 314 | 268 | 5 | 41 |

## Reading the rules

Each rule has a name, the rule itself (EBNF for syntax, inference rules for typing, reductions for evaluation), the place in `hc` that implements or enforces it (`file:line`), and its evidence: the probe program and whether `hc` accepted or rejected it as the rule predicts.

- **CONFIRMED**: `hc` agrees with the rule on its probes.
- **UNCONFIRMED**: the rule is stated but no probe settled it.
- **KNOWN GAP**: `hc` accepts a program the rule (or `HELIUM.md`) says is invalid, or behaves differently than documented. Where `HELIUM.md` and `hc` disagree, the spec describes `hc` and records the disagreement.

## Most serious known gaps

- A slice returned through an alias of a local growable array is a use-after-free (3.10 G1).
- Member access on an unnarrowed optional compiles and dereferences null (3.10 G2).
- `qput` accepts references and slices, so a thread can read through a dangling reference (3.10 G3).
- A string literal passed to a writing `byte[:]` parameter is written in place and crashes (3.10 G10).
- `.he` lifetime checks are off unless `HC_HEPROV=1` is set (3.10 G9).
- A column-0 line inside a `.he` triple-quoted string switches the file to the Python front end, which compiles a program that silently prints nothing (1, G8).

## Re-running the evidence

The probes are in [`probes/`](probes/), one folder per chapter (`ch1-review` holds the second pass for chapter 1). From the repository root:

```
HC_LIB=hc/lib ./build/hc build spec/probes/ch3/s01_ret_alias_explicit.amni -o /tmp/p && /tmp/p
```

Programs a rule says must be rejected should stop with a diagnostic; the others should build and print what the chapter records.
