# kostya/benchmarks in Goose

Goose versions of the five tests of
[kostya/benchmarks](https://github.com/kostya/benchmarks) (Brainfuck,
Base64, Json, Matmul, Primes), laid out as that repository lays out a
language's tests, and `compare.py`, which builds and measures them next to
the suite's own C, C++ and Rust tests the way the suite measures them.

## The rules, and what Goose brings to them

The suite asks for code "as the average software developer would write it":
algorithms as the public sources give them and as the other languages'
tests have them, standard containers and libraries used as their
documentation shows, idiomatic data structures, release builds. Within
that, each test here is written the way Goose code is written, and takes
what Goose's memory model and library give it:

| test | file | written as | Goose in it |
|---|---|---|---|
| Brainfuck | `brainfuck/bf.goose` | `bf.rs`: an op tree, a tape that starts at one cell and grows, run recursively | the ops of every loop body are one run of a single op pool; the parser's unfinished bodies wait on one shared stack, since a recursive function holds no growable array of its own |
| Base64 | `base64/test.goose` | `base64.rs`: the library codec, a new buffer per call | `std`'s `base64`, whose loops the C compiler vectorizes; each buffer is a data-stack bump, freed at the loop body's brace |
| Json | `json/test.goose` | `json_struct.rs` (serde, typed) | `json::Reader` maps the text onto `Coordinate`s as serde's derive does, building no tree |
| Json | `json/test_dom.goose` | `json_value.rs` (serde `Value`), RapidJSON's `Document` | `json::parse`'s tree: fixed-size nodes in one array, linked by 4-byte self-relative offsets, strings as views of the text |
| Matmul | `matmul/matmul.goose` | `matmul.c`/`matmul.rs` (plb): transpose, then a dot product per cell | a matrix is an array of row slices, the rows runs of one `reusable[]` pool; one `assert` per row lets every index in the inner loop go unchecked |
| Primes | `primes/primes.goose` | `primes.rs`: sieve of Atkin, a trie of the primes' digits, a breadth-first walk | trie nodes in one array; each node's map is a run of (digit, node) pairs in a `reusable[]` pool; queue entries hold their prefix inline in a `u8[..16]` |

Two departures the other languages do not need, both forced by the memory
model, so the same as "V and Python don't provide [unordered hashmaps] out
of box" in the suite's own notes:

* Primes: a `dictionary` grows, and a growable value cannot be an element of
  an array, which every trie node is. So a node's map from digit to child is
  an unordered run of at most ten pairs, looked up by scanning it, as Zig's
  `array_hash_map` does below eight entries.
* Brainfuck, Matmul, Primes: what the C++ and Rust allocate one at a time
  (an op vector per loop body, a row, a trie node) lives in pools the
  caller owns, there being no heap.

`common/notify.h` is the suite's measurement protocol (a TCP message to
`localhost:9001` as the measured work starts and one as it ends) for Goose,
which has no sockets: a few lines of C over the suite's
`common/libnotify`, reached through `extern fn` and `--include`. It names
each test `Goose/<C compiler>`, as the C tests name theirs.

## Results

Linux (WSL 2 on Windows 11), Ryzen 9 9950X3D, clang 20.1.8, Rust 1.99.0,
kostya/benchmarks at 5bc68b3, Goose at this commit. Every implementation
built with the suite's flags (`-O3 -march=native -flto=auto`, `-std=c23`
for C, Goose's C included; `-C target-cpu=native` for Rust), timed between
its two notify messages, median of 7 interleaved rounds; memory
is the suite's base + increase of the resident set.

### Brainfuck bench.b

| test | time, s | min | memory, MiB | its time / Goose's |
|---|---:|---:|---:|---:|
| goose | 0.797 | 0.774 | 1.29 + 0.00 | 1.00 |
| c | 0.824 | 0.810 | 1.05 + 0.00 | 1.03 |
| c++ | 0.778 | 0.772 | 2.00 + 0.00 | 0.98 |
| rust | 0.741 | 0.728 | 1.14 + 0.00 | 0.93 |

### Brainfuck mandel.b

| test | time, s | min | memory, MiB | its time / Goose's |
|---|---:|---:|---:|---:|
| goose | 8.838 | 8.747 | 2.30 + 0.00 | 1.00 |
| c | 9.220 | 9.133 | 1.04 + 0.77 | 1.04 |
| c++ | 9.246 | 9.125 | 3.67 + 0.52 | 1.05 |
| rust | 9.879 | 9.836 | 1.16 + 1.04 | 1.12 |

### Base64

| test | time, s | min | memory, MiB | its time / Goose's |
|---|---:|---:|---:|---:|
| goose | 0.088 | 0.088 | 2.55 + 0.00 | 1.00 |
| c | 0.606 | 0.604 | 2.11 + 0.00 | 6.90 |
| c aklomp | 0.044 | 0.043 | 2.16 + 0.00 | 0.50 |
| rust | 0.467 | 0.464 | 2.44 + 0.00 | 5.31 |

### Json

| test | time, s | min | memory, MiB | its time / Goose's |
|---|---:|---:|---:|---:|
| goose | 0.062 | 0.059 | 113.11 + 12.28 | 1.00 |
| goose dom | 0.082 | 0.081 | 113.19 + 183.07 | 1.33 |
| rust serde typed | 0.081 | 0.079 | 111.81 + 10.85 | 1.32 |
| rust serde untyped | 0.441 | 0.381 | 112.12 + 839.50 | 7.13 |
| rust serde custom | 0.079 | 0.079 | 111.54 + 0.00 | 1.28 |
| c++ rapidjson | 0.131 | 0.128 | 114.93 + 129.34 | 2.12 |
| c++ rapidjson precise | 0.174 | 0.170 | 114.20 + 129.68 | 2.80 |
| c++ simdjson | 0.040 | 0.028 | 113.90 + 60.26 | 0.65 |
| c++ simdjson dom | 0.088 | 0.045 | 113.75 + 177.33 | 1.42 |
| c yyjson | 0.074 | 0.057 | 112.00 + 229.96 | 1.20 |

### Matmul (1500)

| test | time, s | min | memory, MiB | its time / Goose's |
|---|---:|---:|---:|---:|
| goose | 1.218 | 1.205 | 2.72 + 69.06 | 1.00 |
| c | 2.385 | 2.360 | 2.56 + 68.06 | 1.96 |
| rust | 1.235 | 1.213 | 2.52 + 68.32 | 1.01 |

### Primes

| test | time, s | min | memory, MiB | its time / Goose's |
|---|---:|---:|---:|---:|
| goose | 0.033 | 0.032 | 2.32 + 23.13 | 1.00 |
| c++ | 0.037 | 0.036 | 4.00 + 71.62 | 1.12 |
| rust | 0.085 | 0.083 | 2.38 + 72.68 | 2.60 |

## Where Goose is behind, and why

Goose is fastest of the four languages on Brainfuck mandel.b, Matmul (with
Rust) and Primes, and of the implementations that are not SIMD libraries on
Base64 and Json. It is behind in three places:

* **Brainfuck bench.b, 7% behind Rust** (level with C and C++). Not the
  bounds checks the tape's indexing keeps (Rust's test uses
  `get_unchecked`): taking them out of the generated C moved it by 0-4%,
  inside the spread code placement alone gives (builds of the same source
  differ by up to 10%). About half of it is the op loop: `for op in
  program` keeps the slice's data, its length and an index, three
  registers, two of which the recursive interpreter spills and reloads per
  op, where Rust walks a pointer; the same C with the loop walking a
  pointer was 3% faster on bench.b and 1-2% on mandel.b. Two other ways of
  writing it were slower overall: a reference to the current cell, which in
  Goose stays valid as the tape grows (13% faster on bench.b, 14-30% slower
  on mandel.b), and the head's position
  passed into and out of each `run` (10% slower on bench.b).
* **Base64, 2x behind aklomp/base64**, a C library of hand-written SSSE3,
  AVX2 and AVX-512 intrinsics (the suite lists it apart from plain C, as
  "C (aklomp)"); 5.3x ahead of Rust's base64 crate and 6.9x of plain C.
  Goose's codec is plain Goose that clang vectorizes: the bytes' regrouping
  vectorizes well, the translation of 6-bit values to characters and back
  is compares and selects where aklomp uses table shuffles. About 10% of
  Goose's time is the zero fill that `resize` gives the output before the
  codec overwrites it.
* **Json, 1.5-2x behind simdjson** On-Demand (median 0.040 s, min 0.028 s,
  against 0.062 s and 0.059 s), which finds the document's structure 64
  bytes at a time with SIMD; 1.3x ahead of serde typed, 2.1x of RapidJSON,
  and the tree version 5x ahead of serde's `Value` on under a quarter of its
  memory. Half of the numbers (`"x": -1.34e-30`) lie outside the exact
  fast path (19 digits and a power of ten up to 22); `std`'s `json` reads
  those with the Eisel-Lemire algorithm, as Go, Rust's core and fast_float
  do, and keeps its big-integer rounding for the rare number that cannot
  settle. With the big integers for all of them it took 0.133 s. Goose's
  means are Python's to the last digit; serde's default parser is one ulp
  off in z.

Matmul: C's 2x is the multiply and add of `t += p[k] * r[k]` fused into one
FMA, which clang does by default under `-march=native`; on Zen 5 that is a
4-cycle chain per step where a separate add is 2. Goose, like Rust, rounds
each operation on its own (so the two print the same digits), and the
dot products, one long dependency chain each, set the time for both. The
loop order of the suite's Julia test (`c[i][j] += a[i][k] * b[k][j]` with
j innermost, no transpose) adds the same products in the same order, so
the result is the same to the bit, and vectorizes: 0.27 s here. It is not
the version above, since the C and Rust tests follow plb's transposed dot
products.

Memory: Primes takes a third of what the C++ and Rust take, its trie being
one array of 17-byte nodes and one of 9-byte map entries where each C++ and
Rust node is a hash map with allocations of its own. Elsewhere Goose's
numbers are within half a MiB of the others', but for the Json tree, which
takes 183 MiB against serde `Value`'s 840.

## Running it

`compare.py` reads the suite's checkout from `$KOSTYA`, or from a
`kostya-benchmarks/` or `benchmarks/` directory next to this repository's
checkout, and builds under `bench/kostya2/build` (or `--build-dir`). It
fetches the C libraries the suite's Makefiles fetch (RapidJSON, simdjson,
yyjson, aklomp/base64) and needs clang, cargo and git. `/tmp/1.json`, the
Json test's input, is written by `json/generate_json.py`, a seeded Python
copy of the suite's `generate_json.rb`, where it is missing.

```
python3 bench/kostya2/compare.py build                  # Goose, C, C++ and Rust
python3 bench/kostya2/compare.py check                  # every output, once
python3 bench/kostya2/compare.py run --reps 5           # the tables above
python3 bench/kostya2/compare.py run --only json --langs goose,rust
python3 bench/kostya2/compare.py ab bench.b old/bf new/bf --reps 10
```

`ab` runs several builds of one test in turn, round after round: on this
machine code placement alone moves the Brainfuck tests by up to 10% between
builds of the same source, so a change to one is only worth believing
across several builds of each side (vary `-falign-functions` to get them).

Measure on Linux. On Windows `compare.py` builds the C and C++ tests over
the shims in `common/win`, but every implementation, C included, ran
Brainfuck 6x and Matmul 2.7x slower there than under WSL on the same
machine, so Windows numbers neither compare with the suite's nor say much
about the code.

## In the suite itself

The files go where the suite keeps each language's tests (`brainfuck/bf.goose`,
`base64/test.goose`, `json/test.goose`, `json/test_dom.goose`,
`matmul/matmul.goose`, `primes/primes.goose`), `common/notify.h` to
`common/goose/notify.h`, and the suite needs:

* `common/commands.mk`:
  ```make
  GOOSE_BUILD = goose -O2 --standalone --include ../common/goose/notify.h -o $@.c $< \
      && clang $(CLANG_FLAGS) -std=c23 -o $@ $@.c $(LIBNOTIFY_FLAGS) -lm -pthread
  ```
* in each test's `Makefile`, its binary in `executables` and a rule, for
  example in `brainfuck/Makefile`:
  ```make
  target/bin_goose: bf.goose | target libnotify
  	$(GOOSE_BUILD)
  ```
  (`target/json_goose` from `test.goose` and `target/json_dom_goose` from
  `test_dom.goose`, and so on.)
* `docker/Dockerfile`, Goose built from source:
  ```dockerfile
  # https://github.com/aardappel/goose
  ARG GOOSE=<a goose commit>
  RUN git clone https://github.com/aardappel/goose /opt/goose \
      && cd /opt/goose && git checkout $GOOSE \
      && cmake -B build -DCMAKE_BUILD_TYPE=Release -DGOOSE_LIBTCC=OFF \
      && cmake --build build --target goose -j \
      && ln -s /opt/goose/build/goose /usr/local/bin/goose
  ```
* `docker/versions.rb`:
  ```ruby
  'Goose' => -> { `git -C /opt/goose log -1 --format='%h %cs'` },
  ```
