# Helium

**The lightweight, token-friendly alternative to C++, Rust, and Goose.**

Helium is a systems language tuned for code that language models read and write: no heap, no garbage collector, no lifetime annotations, and native speed from plain C output. Source files use the `.amni` extension, and `.goose` files still compile unchanged.

What `.amni` changes:

- Word types: `int` (i64), `uint` (u64), `byte` (u8), `real` (f64).
- Declarations without `:` or `->`: `fn divide(a int, b int) int, bool`, `struct P { x real, y real }`, `var n int = 0`.
- `import std;` is implicit, and a program's own overloads win ties against it.
- The `helium` command prints only the program's output and errors (`-v` for compiler progress).
- `helium file.amni` compiles to native code with the system C compiler (gcc, clang or MSVC), caches the binary by a hash of the generated C, and runs it. Goose runs through the built-in TinyCC instead, which does not optimize and cannot run threads. `--jit` or `HELIUM_JIT=1` keeps the TinyCC path, which is also the fallback when no C compiler is found.
- `lut fn` turns a pure function of up to 24 bits of small-integer input into a sparse, persistent lookup table: entries are computed on first use in 4096-entry tiles, saved to `~/.goose/lut/`, and loaded by the next run. A Collatz step count over every `u16`, 200 passes, takes 1,149 ms as a plain function and 15 ms as a `lut fn` (10 ms when the table is already on disk); a 24-bit table used at three points is 83 KB.
- When a `lut fn` body is integer code and a CPU fill would take over 30 ms, Helium compiles the body to a Vulkan compute shader and fills the whole table on the GPU, exactly matching the CPU. A 3,000-step hash over every `u16` takes 135 ms on the CPU and 24 ms on a Ryzen 9950X3D's integrated GPU, 15 ms on an RX 9060 XT, including Vulkan start-up. Entries the GPU can't finish fall back to the CPU, and builds without Vulkan or `glslc` stay on the CPU.
- [HELIUM.md](HELIUM.md) teaches the whole language in about 3.9k tokens, against about 169k for the Goose documentation.

Measured with the o200k and Qwen2.5 tokenizers, comments stripped:

| | tokens |
|---|---:|
| Goose documentation needed to write the language | ~169,000 |
| HELIUM.md | ~3,900 |
| 15 benchmark programs, C++ / Rust / Goose / Helium | 1.00 / 0.57 / 0.52 / 0.48 |
| Compiler chatter per run, goose / helium | 85 / 0 |

Speed and memory, Linux, Ryzen, gcc, Goose's own benchmarks at the medium size:

| | goose (TinyCC run) | helium (native, cached) |
|---|---:|---:|
| run time | 1.00 | 1.8x to 4.1x faster (sum 3.4x, graph 2.1x, sexp 2.4x, lru 3.4x, particles 4.1x, words 3.2x) |
| peak memory | 1.00 | 1.08x to 1.37x lighter |
| rerun of an unchanged program | compile + run | run only (7 to 31 ms for the samples) |
| threads | not supported | supported |

Against Rust and C++, all 16 of Goose's benchmarks at the large size (`bench/results_linux.md`; Ryzen 9 9950X3D, Linux, gcc and clang `-O2`, rustc `-O`, every implementation printing the same checksums). Above 1.00 means Helium is faster or smaller:

| Helium vs | speed, gcc | speed, clang | peak memory | tokens to write |
|---|---:|---:|---:|---:|
| idiomatic C++ | 2.37x | 2.15x | 1.74x less | 2.08x fewer |
| expert C++ | 1.04x | 1.08x | 1.26x less | |
| best safe Rust | 1.09x | 1.11x | 1.19x less | 1.19x fewer |

Helium loses to Rust on `scene` (0.84x/0.92x), `calc` (0.92x/0.89x) and `push` (0.91x/0.93x), and gcc builds `blur` 3.9x slower than clang does, for C++ and Helium alike.

The first run of a changed program pays one C compile (about 0.1 s for the benchmarks), so it already beats the TinyCC run on anything that runs longer than about 0.2 s. Building the generated C with `-O3 -march=native` instead of `-O2` gained only 4.5% on average and lost on some benchmarks, so Helium keeps `-O2`.

`tools/amni/goose2amni.py` converts Goose source to `.amni`; `tools/amni/check.py` converts a directory and checks that every program prints what the original does (all 701 test programs and every runnable sample match). `tools/amni/measure.py` counts tokens.

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
build/helium samples_amni/01_tour.amni
```

## License

Apache License 2.0. See [LICENSE](LICENSE).

## Credits

Helium is built on [Goose](https://github.com/aardappel/goose) by Wouter van Oortmerssen. Its compiler, runtime and standard library are currently Goose's, used and modified under the Apache License 2.0, and its memory model, references and data layouts are Goose's design. The original Goose README, which describes those features in depth, is in [docs/goose_readme.md](docs/goose_readme.md).
