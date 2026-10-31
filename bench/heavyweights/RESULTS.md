# Helium vs. the heavyweights

Seven small programs, each written once per language with the same algorithm and the
same output. Every build's stdout is compared byte-for-byte with the C (gcc) build at
the benchmark size before it is timed; all 64 builds matched.
Numbers are measured, not estimated; regenerate them with `python3 run.py` (about 30
minutes, most of it CPython) and `python3 report.py`.

![wall time relative to C](chart.png)

## Wall time

Median of 5 timed runs after 1 warmup run (hyperfine), process start-up included.
Fastest per row in bold (the arena variant of C is excluded from that).
The last rows are the geometric mean of each language's time divided by C (gcc)'s, with
and without bintrees (where the allocation strategies differ, see below).

| Program | Helium (hcn) | C (gcc -O2) | C (clang -O2) | C (gcc -O2, arena) | Rust (rustc -O3) | Zig (ReleaseFast) | Go | Java (OpenJDK) | Node.js | Python (CPython) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| fib (40) | 190 ms | **75 ms** | 169 ms | – | 170 ms | 170 ms | 305 ms | 200 ms | 634 ms | 6017 ms |
| nbody (10,000,000) | 368 ms | 371 ms | 386 ms | – | 250 ms | **243 ms** | 516 ms | 409 ms | 440 ms | 30.5 s |
| spectral (3,000) | 287 ms | 273 ms | 286 ms | – | 274 ms | **268 ms** | 290 ms | 353 ms | 404 ms | 34.4 s |
| bintrees (18) | **129 ms** | 683 ms | 759 ms | 81 ms | 1148 ms | 759 ms | 912 ms | 326 ms | 661 ms | 3740 ms |
| fannkuch (11) | 1816 ms | 1800 ms | 1956 ms | – | 1822 ms | 2058 ms | **1790 ms** | 2044 ms | 1857 ms | 64.0 s |
| mandelbrot (4,000) | 656 ms | **602 ms** | 656 ms | – | 614 ms | 625 ms | 630 ms | 691 ms | 676 ms | 31.6 s |
| strmap (5,000,000) | 793 ms | 731 ms | 1114 ms | – | 779 ms | **215 ms** | 801 ms | 535 ms | 2869 ms | 2406 ms |
| **geomean vs C (gcc)** | 0.93× | 1.00× | 1.26× | 0.12× (1 prog.) | 1.16× | 0.92× | 1.37× | 1.08× | 1.82× | 31.09× |
| geomean without bintrees | 1.21× | 1.00× | 1.28× | – | 1.09× | 0.89× | 1.38× | 1.24× | 2.02× | 41.53× |

## Peak resident memory

Median over the timed runs (hyperfine's `memory_peak_resident`).

| Program | Helium (hcn) | C (gcc -O2) | C (clang -O2) | C (gcc -O2, arena) | Rust (rustc -O3) | Zig (ReleaseFast) | Go | Java (OpenJDK) | Node.js | Python (CPython) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| fib | 2.0 MB | 2.2 MB | 2.2 MB | – | 2.2 MB | 1.3 MB | 1.8 MB | 40.9 MB | 54.7 MB | 9.6 MB |
| nbody | 1.3 MB | 2.1 MB | 2.1 MB | – | 2.2 MB | 1.3 MB | 3.5 MB | 47.8 MB | 57.8 MB | 10.3 MB |
| spectral | 2.0 MB | 2.1 MB | 2.2 MB | – | 2.1 MB | 1.3 MB | 5.4 MB | 40.5 MB | 57.8 MB | 10.3 MB |
| bintrees | 8.0 MB | 34.1 MB | 34.1 MB | 18.0 MB | 34.2 MB | 16.2 MB | 38.0 MB | 632.9 MB | 182.7 MB | 42.0 MB |
| fannkuch | 2.0 MB | 2.1 MB | 2.4 MB | – | 2.1 MB | 1.3 MB | 3.5 MB | 41.6 MB | 57.3 MB | 10.1 MB |
| mandelbrot | 2.0 MB | 2.2 MB | 2.1 MB | – | 2.2 MB | 1.3 MB | 1.8 MB | 39.5 MB | 57.3 MB | 9.7 MB |
| strmap | 20.5 MB | 23.9 MB | 24.0 MB | – | 17.8 MB | 10.7 MB | 22.6 MB | 164.6 MB | 91.8 MB | 31.5 MB |

## Executable size

Size after `strip`. Java: the `.class` files (the JVM itself is not counted). Node and
Python: no build artifact.

| Program | Helium (hcn) | C (gcc -O2) | C (clang -O2) | C (gcc -O2, arena) | Rust (rustc -O3) | Zig (ReleaseFast) | Go | Java (OpenJDK) | Node.js | Python (CPython) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| fib | 32 KB | 14 KB | 14 KB | – | 345 KB | 9 KB | 1488 KB | 1 KB | – | – |
| nbody | 116 KB | 14 KB | 14 KB | – | 372 KB | 28 KB | 1500 KB | 3 KB | – | – |
| spectral | 96 KB | 14 KB | 14 KB | – | 370 KB | 27 KB | 1500 KB | 1 KB | – | – |
| bintrees | 44 KB | 18 KB | 14 KB | 18 KB | 347 KB | 14 KB | 1500 KB | 2 KB | – | – |
| fannkuch | 36 KB | 14 KB | 14 KB | – | 348 KB | 11 KB | 1500 KB | 1 KB | – | – |
| mandelbrot | 32 KB | 14 KB | 14 KB | – | 345 KB | 9 KB | 1488 KB | 1 KB | – | – |
| strmap | 52 KB | 14 KB | 14 KB | – | 362 KB | 17 KB | 1488 KB | 2 KB | – | – |

## Compile time

Median of 3 builds (hyperfine). Before each Go and Zig build the toolchain cache is
reset to a copy that holds only the prebuilt standard runtime (made by compiling a
hello-world), so the timing covers compiling the program, not a cache hit. gcc, clang,
rustc, javac and hcn keep no cache between runs.

| Program | Helium (hcn) | C (gcc -O2) | C (clang -O2) | C (gcc -O2, arena) | Rust (rustc -O3) | Zig (ReleaseFast) | Go | Java (OpenJDK) | Node.js | Python (CPython) |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| fib | 43 ms | 45 ms | 45 ms | – | 76 ms | 146 ms | 33 ms | 269 ms | – | – |
| nbody | 104 ms | 60 ms | 64 ms | – | 95 ms | 306 ms | 34 ms | 283 ms | – | – |
| spectral | 97 ms | 53 ms | 68 ms | – | 98 ms | 355 ms | 35 ms | 298 ms | – | – |
| bintrees | 41 ms | 95 ms | 70 ms | 110 ms | 80 ms | 260 ms | 44 ms | 253 ms | – | – |
| fannkuch | 33 ms | 47 ms | 62 ms | – | 101 ms | 185 ms | 33 ms | 267 ms | – | – |
| mandelbrot | 33 ms | 32 ms | 96 ms | – | 77 ms | 152 ms | 40 ms | 214 ms | – | – |
| strmap | 46 ms | 50 ms | 62 ms | – | 159 ms | 359 ms | 35 ms | 277 ms | – | – |

## What each program does

| Program | Work (argument N) | Output |
|---|---|---|
| fib | naive doubly recursive `fib(N)` on 64-bit ints | the number |
| nbody | Benchmarks Game n-body, 5 bodies, N steps of dt = 0.01 | energy before and after, `%.9f` |
| spectral | Benchmarks Game spectral-norm, N×N, 10 power iterations | the norm, `%.9f` |
| bintrees | Benchmarks Game binary-trees, depth N, min depth 4 | the standard check lines |
| fannkuch | Benchmarks Game fannkuch-redux (single-threaded), N | checksum and max flips |
| mandelbrot | N×N grid over [-1.5, 0.5]×[-1, 1], 50 iterations, count of points in the set | the count |
| strmap | N inserts/increments of string keys `"key" + (x mod 200000)` from an LCG into a string→int hash map | distinct keys, max count, sum of counts of key0…key999 |

All programs are single-threaded.

## Differences between implementations that affect the numbers

- **bintrees.** Helium has no per-object heap; its program builds each tree in a
  pool local to the function that builds it, freed in one step when that function
  returns. The C, Rust, Zig, Go, Java, Node and Python programs allocate and free
  every node individually (malloc/free, `Box`, the smp allocator, the GC). Because
  that is a different allocation strategy, `c/bintrees_arena.c` ("C (gcc -O2, arena)")
  is the same program with one bump arena per tree: compare Helium with that column
  for the code generator, and with the others for the language as idiomatically used.
- **strmap.** Each language uses its standard string-keyed hash map: Helium
  `dictionary<const byte[:], int>` (keys copied into one growing byte array),
  Rust `HashMap<String, i64>` (SipHash), Zig `std.StringHashMap` (Wyhash), Go
  `map[string]int`, Java `HashMap<String, Integer>`, JS `Map`, Python `dict`. C has no
  standard map, so `c/strmap.c` is a 35-line FNV-1a open-addressing table.
- **fib.** gcc -O2 inlines `fib` into itself several levels deep (its `fib` is about
  250 instructions with one remaining recursive call; clang's is about 30), which is
  why gcc is twice as fast as everything else here. fib measures call overhead and
  how far a compiler unrolls recursion.
- **Instruction set.** Every ahead-of-time build targets baseline x86-64 (SSE2, no
  AVX): the gcc, clang, rustc and Go defaults, Zig with `-mcpu=baseline` (its default
  is the host CPU), Helium without `--v3`/`--v4`. The JVM and V8 JITs use whatever the
  host CPU supports.
- **Start-up.** Times include process start-up and, for Java and Node, JIT warm-up
  inside the single run: the programs are measured as a user runs them.
- **Not included.** Kotlin (no `kotlinc` on the machine; a system install was out of
  scope), PyPy (not installed). Rust is built with `rustc` directly using the flags
  `cargo --release` would use, plus `codegen-units=1`.

## Machine and versions

- CPU: AMD Ryzen 9 9950X3D 16-Core Processor (32 hardware threads), 60.5 GiB RAM
- OS: Amni OS, Linux 7.2.9-arch1-1
- Every build and run: `nice -n 10 taskset -c 8-11` (4 cores of the CCD without the stacked L3 cache, low priority; the desktop
  was in normal use, so expect a few percent of noise)
- Measured 2026-10-30 23:42 -0400 to 2026-10-31 00:08 -0400. During the published run another job (an LLM evaluation
  harness that calls model APIs and compiles and runs the programs they write) was
  pinned to CPUs 24-31, which include the SMT siblings of the cores used here
- gcc: gcc (GCC) 16.2.1 20260810
- clang: clang version 23.1.1
- Helium: hcn built from this repository at f5a599c
- rustc: rustc 1.98.1 (48a229cea 2026-09-01)
- Zig: 0.17.0
- Go: go version go1.27.3 linux/amd64
- Java: openjdk version "17.0.20.1" 2026-08-18
- Node: v26.12.1
- Python: Python 3.14.8
- hyperfine: hyperfine 2.0.0

## Exact commands

`$REPO` is the repository root, `$BUILD` is `/tmp/helium-heavyweights` (`HW_BUILD`),
`PROG` is the program name and `N` the argument from the wall-time table. Per-run
raw data (every timing, the exact command lines, outputs) is in `results/*.json`.

| Language | Build | Run |
|---|---|---|
| Helium (hcn) | `HC_LIB=$REPO/hc/lib $REPO/build/hcn build $REPO/bench/heavyweights/helium/PROG.amni -o $BUILD/helium/PROG` | `$BUILD/helium/PROG N` |
| C (gcc -O2) | `gcc -O2 -o $BUILD/c-gcc/PROG $REPO/bench/heavyweights/c/PROG.c -lm` | `$BUILD/c-gcc/PROG N` |
| C (clang -O2) | `clang -O2 -o $BUILD/c-clang/PROG $REPO/bench/heavyweights/c/PROG.c -lm` | `$BUILD/c-clang/PROG N` |
| C (gcc -O2, arena) | `gcc -O2 -o $BUILD/c-gcc/bintrees_arena $REPO/bench/heavyweights/c/bintrees_arena.c -lm` | `$BUILD/c-gcc/bintrees_arena N` |
| Rust (rustc -O3) | `rustc -C opt-level=3 -C codegen-units=1 -o $BUILD/rust/PROG $REPO/bench/heavyweights/rust/PROG.rs` | `$BUILD/rust/PROG N` |
| Zig (ReleaseFast) | `~/.local/opt/zig-x86_64-linux-0.17.0/zig build-exe -O ReleaseFast -mcpu=baseline --global-cache-dir $BUILD/zigcache-run --cache-dir $BUILD/zigcache-local -femit-bin=$BUILD/zig/PROG $REPO/bench/heavyweights/zig/PROG.zig` | `$BUILD/zig/PROG N` |
| Go | `GO111MODULE=off CGO_ENABLED=0 GOCACHE=… ~/.local/opt/go1.27.3/bin/go build -o $BUILD/go/PROG $REPO/bench/heavyweights/go/PROG.go` | `$BUILD/go/PROG N` |
| Java (OpenJDK) | `javac -d $BUILD/java/PROG $REPO/bench/heavyweights/java/PROG.java` | `java -cp $BUILD/java/PROG PROG N` |
| Node.js | `–` | `node $REPO/bench/heavyweights/js/PROG.js N` |
| Python (CPython) | `–` | `python3 $REPO/bench/heavyweights/python/PROG.py N` |

Reproduce:

```bash
hc/bootstrap.sh                     # builds build/hcn
cd bench/heavyweights
python3 run.py --quick              # small sizes: checks every program builds and agrees
python3 run.py                      # full run, writes results/*.json
python3 report.py                   # writes RESULTS.md and chart.png
```

`run.py` finds hyperfine, go and zig on `PATH` or under `~/.local/opt`; override with
`HYPERFINE=`, `GO=`, `ZIG=`, `HCN=`, and the pinning with `HW_CPUS=` / `HW_NICE=` /
`HW_RUNS=`.
