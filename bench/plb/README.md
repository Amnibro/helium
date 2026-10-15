# Programming-Language-Benchmarks in Goose

Goose programs for the problems of
[Programming-Language-Benchmarks](https://github.com/hanabi1224/Programming-Language-Benchmarks)
(PLB), one directory per problem, named as PLB names its sources: `1.goose`
is a single-threaded program, `2-m.goose` a multithreaded one. Every problem
but `http-server` is here; Goose has no networking.

PLB takes its problems and their rules from the Computer Language Benchmarks
Game: each program runs the algorithm the problem prescribes, and within
that it may be as fast as the language allows, with threads (`-m`) and
intrinsics (`-i`) marked in the file name. These programs use what Goose
offers for speed: pools with 4-byte relative links instead of allocations,
`simd fn` for loops that vectorize, `thread_fn` workers and typed queues for
the `-m` programs, and bounds checks proved away in the hot loops. Where
Goose has no library that the other languages take from theirs (big
integers, MD5), the program carries its own.

## Running

`plb.py` builds, tests and times the Goose programs and PLB's own Rust, C and
C++ programs. It reads the problems, inputs, expected outputs, data files and
reference sources from a PLB checkout beside this repository's checkout (or
`$PLB`), and writes everything under `bench/plb/build/`.

```
python bench/plb/plb.py build                      # every Goose program
python bench/plb/plb.py build --langs rust,c,cpp   # the reference programs
python bench/plb/plb.py test                       # outputs against PLB's expected ones
python bench/plb/plb.py bench nbody --reps 5       # timings and peak memory, interleaved
python bench/plb/plb.py report --markdown          # the table below
```

Everything is built as PLB builds C: clang `-O3 -march=broadwell
-fomit-frame-pointer`, for the generated Goose C too, whose `simd fn`s are
then capped at AVX2 like the references (`--cflags=-DGS_SIMD=2` lets them use
AVX-512). Rust uses PLB's Cargo profile and dependencies (LTO, one codegen
unit, `-Ctarget-cpu=broadwell`). On Windows the C and C++ references get a
few POSIX shims (`winshim/`); C's nbody/5.c builds with gcc only. Runs are
pinned (`--cpus`, default 16-31: on the Ryzen 9950X3D these were measured
on, the core complex without the large L3).

## Results

Wall time in ms, best of 5, with the program and its peak memory under each
time; whole-process, so about 11 ms of every row is Windows process start-up.
Measured October 2026 on CPUs 16-31 of a Ryzen 9950X3D under Windows 11.
Each language's fastest program is shown, single-threaded and multithreaded
separately (a reference using OpenMP, rayon or a multithreaded async runtime
counts as multithreaded whatever its name), and "ratio" is the fastest other
language's time over Goose's: above 1 Goose is faster.

| problem | input | Goose | Rust | C/C++ | ratio | Goose -m | Rust -m | C/C++ -m | ratio -m |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|
| binarytrees | 15 | 22 <sub>1 9.2M</sub> | 150 <sub>4 11.5M</sub> | - | 6.89 | 15 <sub>2-m 12.3M</sub> | - | - | - |
| binarytrees | 18 | 105 <sub>1 19.7M</sub> | 1506 <sub>4 39.9M</sub> | - | 14.37 | 30 <sub>2-m 64.9M</sub> | - | - | - |
| coro-prime-sieve | 1000 | 15 <sub>1 7.8M</sub> | 61 <sub>3 9.5M</sub> | - | 4.20 | - | 22 <sub>3-m 10.6M</sub> | - | - |
| coro-prime-sieve | 4000 | 33 <sub>1 8.0M</sub> | 743 <sub>3 14.9M</sub> | - | 22.81 | - | 111 <sub>3-m 15.9M</sub> | - | - |
| edigits | 100000 | 26 <sub>1 9.3M</sub> | 29 <sub>1 8.0M</sub> | - | 1.12 | - | - | - | - |
| edigits | 250001 | 59 <sub>1 11.3M</sub> | 70 <sub>1 8.5M</sub> | - | 1.19 | - | - | - | - |
| fannkuch-redux | 10 | 45 <sub>1 7.7M</sub> | 78 <sub>3-i 7.7M</sub> | - | 1.73 | 17 <sub>1-m 7.9M</sub> | 18 <sub>3-im 9.0M</sub> | 21 <sub>1-im 9.0M</sub> | 1.10 |
| fannkuch-redux | 11 | 392 <sub>1 7.7M</sub> | 794 <sub>3-i 7.7M</sub> | - | 2.03 | 55 <sub>1-m 7.8M</sub> | 68 <sub>3-im 9.0M</sub> | 83 <sub>1-im 9.1M</sub> | 1.23 |
| fasta | 250000 | 18 <sub>1 8.8M</sub> | 19 <sub>6 7.7M</sub> | - | 1.07 | 18 <sub>1-m 9.3M</sub> | 35 <sub>5c-m 17.6M</sub> | - | 1.95 |
| fasta | 2500000 | 63 <sub>1 8.8M</sub> | 74 <sub>6 7.7M</sub> | - | 1.16 | 60 <sub>1-m 13.2M</sub> | 199 <sub>5c-m 17.6M</sub> | - | 3.33 |
| helloworld | QwQ | 13 <sub>1 7.7M</sub> | 13 <sub>1 7.7M</sub> | 13 <sub>1 7.7M</sub> | 0.97 | - | - | - | - |
| json-serde | sample 5000 | 26 <sub>1 12.7M</sub> | 29 <sub>4-i 14.4M</sub> | - | 1.10 | - | - | - | - |
| json-serde | canada 15 | 106 <sub>1 55.7M</sub> | 114 <sub>5-i 62.1M</sub> | - | 1.07 | - | - | - | - |
| knucleotide | 250000_in | 31 <sub>1 16.2M</sub> | 38 <sub>8 16.2M</sub> | - | 1.25 | 22 <sub>1-m 23.3M</sub> | 23 <sub>8-m 21.7M</sub> | 33 <sub>1 20.3M</sub> | 1.04 |
| knucleotide | 2500000_in | 145 <sub>1 38.0M</sub> | 184 <sub>8 26.9M</sub> | - | 1.27 | 73 <sub>1-m 71.2M</sub> | 71 <sub>8-m 32.4M</sub> | 185 <sub>1 31.0M</sub> | 0.97 |
| lru | 100 500000 | 18 <sub>2 7.7M</sub> | 24 <sub>0-unsafe 7.7M</sub> | - | 1.33 | - | - | - | - |
| lru | 1000 1000000 | 26 <sub>2 7.8M</sub> | 25 <sub>0-unsafe 7.7M</sub> | - | 0.98 | - | - | - | - |
| lru | 1000 3000000 | 54 <sub>2 7.8M</sub> | 78 <sub>0-unsafe 7.7M</sub> | - | 1.45 | - | - | - | - |
| mandelbrot | 1000 | 18 <sub>1 7.9M</sub> | 19 <sub>8 7.8M</sub> | - | 1.04 | 14 <sub>1-m 8.4M</sub> | - | - | - |
| mandelbrot | 5000 | 149 <sub>1 10.8M</sub> | 176 <sub>8 10.5M</sub> | - | 1.18 | 30 <sub>1-m 12.3M</sub> | - | - | - |
| merkletrees | 15 | 37 <sub>1 12.0M</sub> | 183 <sub>1 15.5M</sub> | - | 4.90 | - | - | - | - |
| merkletrees | 17 | 127 <sub>1 24.7M</sub> | 758 <sub>1 39.6M</sub> | - | 5.99 | - | - | - | - |
| nbody | 500000 | 23 <sub>1 7.7M</sub> | 21 <sub>4-i 7.7M</sub> | 21 <sub>0-i 7.7M</sub> | 0.89 | - | - | - | - |
| nbody | 5000000 | 132 <sub>1 7.7M</sub> | 103 <sub>4-i 7.7M</sub> | 106 <sub>0-i 7.7M</sub> | 0.78 | - | - | - | - |
| nsieve | 10 | 37 <sub>1 17.5M</sub> | 39 <sub>1 17.2M</sub> | 38 <sub>1 17.2M</sub> | 1.04 | - | - | - | - |
| nsieve | 12 | 155 <sub>2 12.6M</sub> | 162 <sub>2 12.3M</sub> | 129 <sub>1 12.4M</sub> | 0.84 | - | - | - | - |
| pidigits | 4000 | 44 <sub>1 7.8M</sub> | 183 <sub>2 8.3M</sub> | - | 4.18 | - | - | - | - |
| pidigits | 8000 | 148 <sub>1 7.9M</sub> | 879 <sub>2 8.8M</sub> | - | 5.96 | - | - | - | - |
| regex-redux | 250000_in | 65 <sub>1 17.8M</sub> | - | - | - | 32 <sub>2-m 25.1M</sub> | 38 <sub>7 19.7M</sub> | - | 1.19 |
| regex-redux | 2500000_in | 483 <sub>1 105.5M</sub> | - | - | - | 178 <sub>2-m 177.2M</sub> | 237 <sub>7 106.1M</sub> | - | 1.33 |
| secp256k1 | 500 | 29 <sub>1 7.7M</sub> | 27 <sub>0 7.8M</sub> | - | 0.92 | - | - | - | - |
| secp256k1 | 2000 | 76 <sub>1 7.7M</sub> | 70 <sub>0 7.8M</sub> | - | 0.91 | - | - | - | - |
| spectral-norm | 2000 | 33 <sub>2 7.8M</sub> | 63 <sub>7 7.8M</sub> | - | 1.91 | 18 <sub>2-m 8.6M</sub> | 22 <sub>7-m 9.3M</sub> | 23 <sub>8 9.0M</sub> | 1.20 |
| spectral-norm | 4000 | 89 <sub>2 7.8M</sub> | 210 <sub>7 7.8M</sub> | - | 2.35 | 26 <sub>2-m 8.8M</sub> | 40 <sub>7-m 9.4M</sub> | 40 <sub>8 9.1M</sub> | 1.50 |
| spectral-norm | 8000 | 321 <sub>2 7.9M</sub> | 796 <sub>7 7.7M</sub> | - | 2.48 | 57 <sub>2-m 9.7M</sub> | 114 <sub>7-m 9.6M</sub> | 92 <sub>8 9.2M</sub> | 1.61 |

The allocation-heavy problems (binarytrees, merkletrees) say as much about
Windows' heap as about Rust: its `Box` allocations go through `HeapAlloc`,
which is slower than glibc's malloc, where PLB runs.

With AVX-512 allowed, the `simd fn` programs go further: nbody/2 79.7 ms at
5000000 (against 103 for Rust's fastest), spectral-norm/2 126 ms and 2-m
39 ms at 8000, mandelbrot/1-m 21 ms at 5000.

## Notes on the programs

* **binarytrees** builds every tree in a pool local to the function that
  makes it: 8-byte nodes, 4-byte self-relative links, freed by one pointer
  reset when the function returns, which the rules allow (the C and C++
  programs use memory pools). `2-m` runs each depth's iterations on workers.
* **merkletrees** forbids arenas ("every tree node needs to be either
  separately freed or GCed"), so its nodes come one at a time from a
  `reusable` pool with a freelist, and each tree is freed node by node.
* **coro-prime-sieve**: Goose has no coroutines, and its queues are one per
  element type, so the chain of thousands of filters cannot be a chain of
  threads either. The program builds the chain the generator programs
  (C#, D, Python) build: one lazy filter stage per prime, each pulling from
  the one before it, a pull being a call and a value handed on a return.
  It is not the channel-and-coroutine structure of the Rust programs, so its
  ratio says little about coroutines.
* **nbody/1** is the plain scalar algorithm in a form clang unrolls
  completely; **nbody/2** keeps the five bodies in the lanes of 8-wide arrays
  and handles the ten pairs as two rotations, which wins with AVX-512 and
  loses with AVX2.
* **spectral-norm/1** computes the products exactly as a row-by-row loop
  does, eight rows per vector; **/2** also sums four columns' fractions over
  the product of their denominators, one division per four columns, as C's
  `6-im` does.
* **fannkuch-redux** keeps a permutation in one u64, a nibble per element,
  and flips two permutations at once for the instruction-level parallelism.
* **fasta** uses the prescribed linear congruential generator as written,
  and integer thresholds for the cumulative probabilities.
* **knucleotide/1** counts in a hash table of its own, as C's program does;
  **/2** counts with the stdlib `dictionary`.
* **lru/1** uses the stdlib `dictionary`; **/2** a table made for the cache.
* **json-serde** reads into typed records with the stdlib `json` reader and
  writes with its writer, numbers included, but for the integral values the
  Rust programs' `MyF64` writes as integers.
* **pidigits**, **edigits** and **secp256k1** carry their own big-integer
  arithmetic on 64-bit limbs: the spigot's products and sums fused into one
  pass each (GMP's addmul kind), Toom-3 and Karatsuba multiplication and
  divide-and-conquer division for edigits as the Rust crates have them, and
  fixed 4x64-bit field elements for secp256k1, which follows the algorithm of
  the hand-written `1.rs`.

## Where Goose is behind, and why

* **nbody** (0.78 against intrinsics, 0.89 against plain C++): the `-i`
  programs avoid the divider with a float reciprocal square root estimate and
  Newton steps, which Goose cannot express (no intrinsics, no float bit
  casts). Against the plain C++ program, 132 against 118 ms, the generated C
  is the same loop; clang's result for it moves by 10-20% with unrelated
  changes around it.
* **nsieve/2 at 12** (0.84 against C++'s `vector<bool>`): two bounds checks
  stay in the bit-array loops (the analysis cannot derive `j >> 5 <
  (n + 31) >> 5` from `j < n`), and elements are addressed as byte offsets,
  `base + (j >> 5) * 4`, which costs clang the scaled addressing mode.
  Removing both by hand brings it level with hand-written C.
* **secp256k1** (0.91): Rust's `0.rs` uses the k256 crate, whose scalar
  multiplication uses precomputed tables of signed windows; the Goose program
  follows the hand-written algorithm (`1.rs`, which it beats by 18x). Its
  field arithmetic is faster than k256's.
* **regex-redux/1**: the stdlib regex engine is a DFA that takes one table
  lookup per byte, and its prefilter rates byte pairs by English letter
  frequencies, useless on DNA. Rust's regex crate finds these alternations of
  short literals with a SIMD multi-literal search (Teddy). Rust's `7.rs`
  runs on two threads; forced to one it takes about 255 ms against Goose's
  483.
* **knucleotide/1-m at 2500000** (0.97): workers share no memory, so each
  gets a copy of the sequence, and `thread_spawn` copies a growable argument
  twice (on the spawner's data stack, then into the new thread).

## Limitations found

In the compiler, runtime and library, while writing these programs:

* **No 64x64->128-bit multiply.** The 32-bit-halves idiom compiles to one
  `mulx` only while clang sees it on its own; inlined, clang rewrites the
  halves of an operand it knows something about and the pattern is lost.
  The bignum programs declare it `recursive` to keep it out of line.
* **A loop-invariant divisor** gets its reciprocal precomputed before the
  loop (`gs_divu_gen`, a 128/64-bit division) even where the loop runs about
  once per entry, and a u32 divisor gets a 64-bit reciprocal. In
  coro-prime-sieve this took 138 ms instead of 31.
* **Bounds checks kept** for `a[j >> 5]` given `a.len == (n + 31) >> 5` and
  `j < n`; for `r[2 * i + 1]` given `r.len == 2 * n` and `i < n`; for a
  stride loop not starting at 0 (`var j = 1; while j + 4 <= xs.len`); for a
  slice made inside an outer loop; for a loop-carried masked index
  (`i = (i + 1) & mask`); and after a whole-struct store through a reference
  to an element, which drops the array's length facts.
* **Element addressing** as `base + i * size` byte offsets, which loses the
  scaled addressing mode where the index is shifted.
* **A lifetime false positive**: a slice returned by a function reading a
  field of a struct passed by reference is tied to an unrelated local
  cleared later.

  ```goose
  struct Rd { text: const u8[:] }
  fn read(r: Rd&) -> const u8[:] { r.text[0..1] }
  fn main() {
      var text: u8[>..] = []; text.append("xyz");
      var r = Rd { text: text };
      var kinds: (const u8[:])[>..] = [];
      var res: u8[>..] = [];
      kinds.push(read(r));
      res.clear();   // error: cannot clear res while kinds is still used
      print(kinds.len, res);
  }
  ```
* **Definite assignment** does not see a fixed array filled element by
  element (`var a: f64[8]; for l in 8 { a[l] = 1.0; } return a;`).
* **No `bool` to integer cast**, and `x as! i64 & mask` parses `i64 &` as a
  reference type, with an error that does not say so.
* **regex** has no multi-literal search, and its prefilter's byte
  frequencies suit English text only.
* **dictionary** grows at 2/3 load with 16-byte slots, which costs miss-heavy
  workloads (lru/1 122 against lru/2 54 ms); std's `hash(u64)` scatters
  small dense keys into probe collisions (knucleotide/2 336 against 220 ms
  with a simpler hash).
* **os** has no streaming file read, so knucleotide and regex-redux hold the
  whole input file.
