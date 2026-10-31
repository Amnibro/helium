# Benchmarks

- [`heavyweights/`](heavyweights/RESULTS.md): Helium against C (gcc and clang), Rust,
  Zig, Go, Java, Node and Python on seven programs, with wall time, peak memory,
  executable size and compile time. This is the current Helium benchmark suite.
- `llm/`: how well language models write Helium.

Everything else here (`summary.md`, `results.md`, `results_linux.md`, `run_bench.py`,
`plb/`, `plb2/`, `kostya/`, `kostya2/`, `bddicken/`, `cpp/`, `rust/`, `goose/`,
`design.md`, `plan.md`, `notes.md`, `adoption.md`, `bce_ab.py`, `bce_fuzz.py`) is inherited from
[Goose](https://github.com/aardappel/goose) (Apache License 2.0, see
[NOTICE](../NOTICE)). Those results measure Goose's C++ compiler, which is no longer
in this repository, not Helium.
