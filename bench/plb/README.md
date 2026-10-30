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
pinned (`--cpus`, default 8-15,24-31: on the Ryzen 9950X3D these were
measured on, the core complex without the large L3. Logical CPUs 0-7 and
16-23 share the 96 MB L3, so the earlier default of 16-31 straddled both
complexes and let a run land on either, which moved nsieve 12 between
about 105 and 190 ms).

## Results

Wall time in ms, best of at least 5 runs, with the program and its peak
memory under each time; whole-process, so about 11 ms of every row is Windows
process start-up.
Measured October 2026 on CPUs 16-31 of a Ryzen 9950X3D under Windows 11.
Each language's fastest program is shown, single-threaded and multithreaded
separately (a reference using OpenMP, rayon or a multithreaded async runtime
counts as multithreaded whatever its name), and "ratio" is the fastest other
language's time over Goose's: above 1 Goose is faster.

| problem | input | Goose | Rust | C/C++ | ratio | Goose -m | Rust -m | C/C++ -m | ratio -m |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|
| binarytrees | 15 | 25 <sub>1 9.2M</sub> | 165 <sub>5 11.5M</sub> | - | 6.56 | 16 <sub>2-m 12.6M</sub> | - | - | - |
| binarytrees | 18 | 108 <sub>1 19.7M</sub> | 1625 <sub>4 40.0M</sub> | - | 15.04 | 30 <sub>2-m 69.7M</sub> | - | - | - |
| coro-prime-sieve | 1000 | 15 <sub>1 7.8M</sub> | 61 <sub>3 9.5M</sub> | - | 4.20 | - | 21 <sub>3-m 10.6M</sub> | - | - |
| coro-prime-sieve | 4000 | 34 <sub>1 8.0M</sub> | 761 <sub>3 14.9M</sub> | - | 22.66 | - | 115 <sub>5 13.0M</sub> | - | - |
| edigits | 100000 | 25 <sub>1 9.3M</sub> | 28 <sub>1 7.9M</sub> | - | 1.11 | - | - | - | - |
| edigits | 250001 | 59 <sub>1 11.3M</sub> | 70 <sub>1 8.5M</sub> | - | 1.20 | - | - | - | - |
| fannkuch-redux | 10 | 45 <sub>1 7.7M</sub> | 78 <sub>3-i 7.7M</sub> | - | 1.74 | 16 <sub>1-m 7.8M</sub> | 18 <sub>3-im 9.0M</sub> | 22 <sub>1-im 9.1M</sub> | 1.10 |
| fannkuch-redux | 11 | 399 <sub>1 7.7M</sub> | 809 <sub>3-i 7.7M</sub> | - | 2.03 | 59 <sub>1-m 7.8M</sub> | 68 <sub>3-im 9.0M</sub> | 87 <sub>1-im 9.1M</sub> | 1.15 |
| fasta | 250000 | 18 <sub>1 8.8M</sub> | 20 <sub>6 7.7M</sub> | - | 1.13 | 18 <sub>1-m 9.3M</sub> | 31 <sub>5c-m 17.6M</sub> | - | 1.76 |
| fasta | 2500000 | 65 <sub>1 8.8M</sub> | 76 <sub>6 7.7M</sub> | - | 1.18 | 60 <sub>1-m 13.2M</sub> | 189 <sub>5-m 17.6M</sub> | - | 3.16 |
| helloworld | QwQ | 12 <sub>1 7.7M</sub> | 12 <sub>1 7.7M</sub> | 12 <sub>1 7.7M</sub> | 0.99 | - | - | - | - |
| json-serde | sample 5000 | 25 <sub>1 12.7M</sub> | 28 <sub>4-i 14.5M</sub> | - | 1.12 | - | - | - | - |
| json-serde | canada 15 | 113 <sub>1 55.7M</sub> | 116 <sub>5-i 62.1M</sub> | - | 1.02 | - | - | - | - |
| knucleotide | 250000_in | 31 <sub>1 16.2M</sub> | 38 <sub>8 16.2M</sub> | - | 1.23 | 22 <sub>1-m 23.7M</sub> | 25 <sub>8-m 21.5M</sub> | 35 <sub>1 20.7M</sub> | 1.12 |
| knucleotide | 2500000_in | 144 <sub>1 38.0M</sub> | 182 <sub>8 26.9M</sub> | - | 1.27 | 69 <sub>1-m 71.0M</sub> | 70 <sub>8-m 32.6M</sub> | 182 <sub>1 31.0M</sub> | 1.02 |
| lru | 100 500000 | 18 <sub>2 7.7M</sub> | 24 <sub>0-unsafe 7.7M</sub> | - | 1.31 | - | - | - | - |
| lru | 1000 1000000 | 27 <sub>2 7.8M</sub> | 29 <sub>0-unsafe 7.7M</sub> | - | 1.10 | - | - | - | - |
| lru | 1000 3000000 | 56 <sub>2 7.8M</sub> | 85 <sub>0-unsafe 7.8M</sub> | - | 1.52 | - | - | - | - |
| mandelbrot | 1000 | 18 <sub>1 7.9M</sub> | 19 <sub>8 7.8M</sub> | - | 1.05 | 14 <sub>1-m 8.4M</sub> | - | - | - |
| mandelbrot | 5000 | 143 <sub>1 10.8M</sub> | 173 <sub>8 10.5M</sub> | - | 1.21 | 29 <sub>1-m 12.4M</sub> | - | - | - |
| merkletrees | 15 | 38 <sub>1 12.0M</sub> | 179 <sub>1 15.5M</sub> | - | 4.76 | - | - | - | - |
| merkletrees | 17 | 127 <sub>1 24.7M</sub> | 770 <sub>1 39.6M</sub> | - | 6.04 | - | - | - | - |
| nbody | 500000 | 25 <sub>1 7.7M</sub> | 22 <sub>4-i 7.7M</sub> | 22 <sub>0-i 7.7M</sub> | 0.89 | - | - | - | - |
| nbody | 5000000 | 132 <sub>1 7.7M</sub> | 103 <sub>4-i 7.7M</sub> | 108 <sub>0-i 7.7M</sub> | 0.78 | - | - | - | - |
| nsieve | 10 | 39 <sub>1 17.5M</sub> | 42 <sub>1 17.2M</sub> | 39 <sub>1 17.2M</sub> | 0.99 | - | - | - | - |
| nsieve | 12 | 135 <sub>2 12.6M</sub> | 168 <sub>2 12.3M</sub> | 137 <sub>1 12.4M</sub> | 1.02 | - | - | - | - |
| pidigits | 8000 | 150 <sub>1 7.9M</sub> | 880 <sub>2 8.8M</sub> | - | 5.85 | - | - | - | - |
| pidigits | 4000 | 45 <sub>1 7.8M</sub> | 218 <sub>2 8.2M</sub> | - | 4.88 | - | - | - | - |
| regex-redux | 250000_in | 65 <sub>1 17.8M</sub> | - | - | - | 32 <sub>2-m 25.1M</sub> | 38 <sub>7 19.6M</sub> | - | 1.16 |
| regex-redux | 2500000_in | 490 <sub>1 105.5M</sub> | - | - | - | 179 <sub>2-m 177.6M</sub> | 239 <sub>7 106.2M</sub> | - | 1.33 |
| secp256k1 | 500 | 31 <sub>1 7.7M</sub> | 29 <sub>0 7.8M</sub> | - | 0.94 | - | - | - | - |
| secp256k1 | 2000 | 76 <sub>1 7.7M</sub> | 70 <sub>0 7.8M</sub> | - | 0.93 | - | - | - | - |
| spectral-norm | 2000 | 32 <sub>2 7.8M</sub> | 63 <sub>7 7.8M</sub> | - | 1.95 | 17 <sub>2-m 8.7M</sub> | 21 <sub>7-m 9.2M</sub> | 19 <sub>8 9.0M</sub> | 1.13 |
| spectral-norm | 4000 | 91 <sub>2 7.8M</sub> | 213 <sub>7 7.7M</sub> | - | 2.35 | 25 <sub>2-m 9.0M</sub> | 40 <sub>7-m 9.4M</sub> | 31 <sub>8 9.1M</sub> | 1.22 |
| spectral-norm | 8000 | 322 <sub>2 7.9M</sub> | 812 <sub>7 7.8M</sub> | - | 2.52 | 52 <sub>2-m 9.7M</sub> | 114 <sub>7-m 9.6M</sub> | 77 <sub>8 9.1M</sub> | 1.47 |

The allocation-heavy problems (binarytrees, merkletrees) say as much about
Windows' heap as about Rust: its `Box` allocations go through `HeapAlloc`,
which is slower than glibc's malloc, where PLB runs.

With AVX-512 allowed, the `simd fn` programs go further: nbody/2 79.7 ms at
5000000 (against 103 for Rust's fastest), spectral-norm/2 126 ms and 2-m
39 ms at 8000, mandelbrot/1-m 21 ms at 5000.

## Helium results (Linux)

Wall time in ms, best of three to five runs, with the program and its peak
memory under each time. Measured under Linux on CPUs 8-15,24-31 of the same
Ryzen 9950X3D (the core complex without the large L3): Helium on 2026-10-30
with the gate-187 compiler (ba3d9302), the other languages on 2026-10-29. Each
program's latest run
(`plb.py report --markdown --last 1`). Single- and multithreaded programs are
split as in the table above, and "ratio" is the fastest of Rust, C and C++
over Helium: above 1 Helium is faster. Goose here is the old Goose compiler on
the same sources. Programs whose names end in `-x` do less work than the
problem's algorithm for the same output (`fasta` generators that jump ahead,
an odd-only sieve, `knucleotide` without hash tables, mirrored `mandelbrot`
rows); they are left out of both tables (`plb.py report --bent` shows them).

### Portable build

PLB's own flags: code for any x86-64 CPU from Broadwell on (`-march=broadwell`,
`-Ctarget-cpu=broadwell`, Helium `--native --v3`).

| problem | input | Helium | Goose | Rust | C/C++ | ratio | Helium -m | Goose -m | Rust -m | C/C++ -m | ratio -m |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| binarytrees | 15 | 10 <sub>1 3.0M</sub> | 9 <sub>1 3.7M</sub> | 77 <sub>4 5.9M</sub> | - | 7.80 | 2 <sub>2-m 6.4M</sub> | 2 <sub>2-m 7.2M</sub> | - | - | - |
| binarytrees | 18 | 112 <sub>1 12.1M</sub> | 96 <sub>1 15.0M</sub> | 888 <sub>4 33.9M</sub> | - | 7.96 | 20 <sub>2-m 85.8M</sub> | 15 <sub>2-m 68.2M</sub> | - | - | - |
| coro-prime-sieve | 1000 | 1 <sub>1 2.0M</sub> | 2 <sub>1 2.4M</sub> | 46 <sub>3 4.1M</sub> | - | 35.32 | - | - | 6 <sub>5 3.1M</sub> | - | - |
| coro-prime-sieve | 4000 | 17 <sub>1 2.0M</sub> | 20 <sub>1 2.4M</sub> | 710 <sub>3 9.1M</sub> | - | 41.38 | - | - | 53 <sub>5 4.9M</sub> | - | - |
| edigits | 100000 | 13 <sub>1 5.3M</sub> | 13 <sub>1 3.9M</sub> | 15 <sub>1 3.1M</sub> | - | 1.20 | - | - | - | - | - |
| edigits | 250001 | 46 <sub>1 6.0M</sub> | 49 <sub>1 7.0M</sub> | 59 <sub>1 3.7M</sub> | - | 1.29 | - | - | - | - | - |
| fannkuch-redux | 10 | 33 <sub>1 2.0M</sub> | 33 <sub>1 2.4M</sub> | 65 <sub>3-i 1.9M</sub> | - | 1.96 | 5 <sub>1-m 2.5M</sub> | 4 <sub>1-m 2.4M</sub> | 6 <sub>3-im 2.0M</sub> | 62 <sub>1-im 4.3M</sub> | 1.22 |
| fannkuch-redux | 11 | 406 <sub>1 2.0M</sub> | 388 <sub>1 2.1M</sub> | 773 <sub>3-i 1.9M</sub> | - | 1.91 | 46 <sub>1-m 2.5M</sub> | 41 <sub>1-m 2.2M</sub> | 53 <sub>3-im 2.1M</sub> | 740 <sub>1-im 4.4M</sub> | 1.16 |
| fasta | 250000 | 5 <sub>2 8.2M</sub> | 5 <sub>1 3.1M</sub> | 5 <sub>6 1.9M</sub> | - | 1.09 | 5 <sub>2-m 4.3M</sub> | 5 <sub>1-m 3.7M</sub> | 6 <sub>5c-m 7.1M</sub> | - | 1.29 |
| fasta | 2500000 | 37 <sub>2 8.0M</sub> | 49 <sub>1 3.1M</sub> | 48 <sub>6 1.9M</sub> | - | 1.28 | 38 <sub>2-m 5.4M</sub> | 46 <sub>1-m 5.5M</sub> | 50 <sub>5c-m 7.3M</sub> | - | 1.33 |
| helloworld | QwQ | 0 <sub>1 2.0M</sub> | 0 <sub>1 2.2M</sub> | 0 <sub>1 1.9M</sub> | 0 <sub>1 2.2M</sub> | 1.46 | - | - | - | - | - |
| json-serde | sample 5000 | 11 <sub>1 10.6M</sub> | 12 <sub>1 6.9M</sub> | 11 <sub>5-i 9.9M</sub> | - | 1.02 | 5 <sub>1-m 17.8M</sub> | - | - | - | - |
| json-serde | canada 15 | 95 <sub>1 54.2M</sub> | 98 <sub>1 50.0M</sub> | 99 <sub>5-i 52.5M</sub> | - | 1.04 | 41 <sub>1-m 77.9M</sub> | - | - | - | - |
| knucleotide | 250000_in | 10 <sub>1 14.1M</sub> | 18 <sub>1 10.6M</sub> | 21 <sub>8 11.5M</sub> | - | 2.13 | 6 <sub>1-m 24.1M</sub> | 10 <sub>1-m 18.0M</sub> | 8 <sub>8-m 16.0M</sub> | 26 <sub>1 9.1M</sub> | 1.37 |
| knucleotide | 2500000_in | 83 <sub>1 36.1M</sub> | 130 <sub>1 34.3M</sub> | 161 <sub>8 23.9M</sub> | - | 1.93 | 31 <sub>3-m 73.4M</sub> | 59 <sub>1-m 65.4M</sub> | 45 <sub>8-m 27.9M</sub> | 240 <sub>1 19.6M</sub> | 1.46 |
| lru | 100 500000 | 4 <sub>2 2.0M</sub> | 6 <sub>2 2.1M</sub> | 13 <sub>0-unsafe 1.9M</sub> | - | 3.36 | - | - | - | - | - |
| lru | 1000 1000000 | 8 <sub>2 2.0M</sub> | 15 <sub>2 2.2M</sub> | 16 <sub>0-unsafe 1.9M</sub> | - | 1.97 | - | - | - | - | - |
| lru | 1000 3000000 | 24 <sub>2 2.0M</sub> | 43 <sub>2 2.2M</sub> | 60 <sub>0-unsafe 1.9M</sub> | - | 2.47 | - | - | - | - | - |
| mandelbrot | 1000 | 6 <sub>1 2.0M</sub> | 6 <sub>1 2.4M</sub> | 7 <sub>8 2.1M</sub> | - | 1.26 | 2 <sub>1-m 10.8M</sub> | 2 <sub>1-m 2.6M</sub> | - | - | - |
| mandelbrot | 5000 | 128 <sub>1 5.1M</sub> | 127 <sub>1 5.1M</sub> | 161 <sub>8 4.9M</sub> | - | 1.26 | 17 <sub>1-m 22.3M</sub> | 15 <sub>1-m 5.3M</sub> | - | - | - |
| merkletrees | 15 | 24 <sub>1 8.0M</sub> | 23 <sub>1 6.4M</sub> | 90 <sub>1 9.9M</sub> | - | 3.83 | - | - | - | - | - |
| merkletrees | 17 | 109 <sub>1 20.0M</sub> | 109 <sub>1 19.2M</sub> | 450 <sub>1 33.9M</sub> | - | 4.13 | - | - | - | - | - |
| nbody | 500000 | 13 <sub>2 2.0M</sub> | 15 <sub>2 2.1M</sub> | 10 <sub>4-i 1.9M</sub> | 10 <sub>0-i 4.0M</sub> | 0.73 | - | - | - | - | - |
| nbody | 5000000 | 133 <sub>2 2.0M</sub> | 134 <sub>2 2.1M</sub> | 98 <sub>4-i 1.9M</sub> | 90 <sub>0-i 4.0M</sub> | 0.68 | - | - | - | - | - |
| nsieve | 10 | 26 <sub>1 13.0M</sub> | 29 <sub>1 11.9M</sub> | 32 <sub>1 11.6M</sub> | 29 <sub>1 11.9M</sub> | 1.10 | 18 <sub>2-m 5.8M</sub> | - | - | - | - |
| nsieve | 12 | 125 <sub>2 7.0M</sub> | 122 <sub>2 7.1M</sub> | 160 <sub>2 6.9M</sub> | 133 <sub>1 8.7M</sub> | 1.07 | 73 <sub>2-m 13.1M</sub> | - | - | - | - |
| pidigits | 4000 | 29 <sub>1 2.0M</sub> | 33 <sub>1 2.1M</sub> | 151 <sub>2 2.4M</sub> | - | 5.18 | - | - | - | - | - |
| pidigits | 8000 | 126 <sub>1 2.0M</sub> | 137 <sub>1 2.4M</sub> | 639 <sub>2 2.6M</sub> | - | 5.07 | - | - | - | - | - |
| regex-redux | 250000_in | 22 <sub>1 14.4M</sub> | 55 <sub>1 13.3M</sub> | - | - | - | 16 <sub>2-m 28.8M</sub> | 21 <sub>2-m 20.8M</sub> | 24 <sub>7 10.7M</sub> | - | 1.47 |
| regex-redux | 2500000_in | 186 <sub>1 104.5M</sub> | 512 <sub>1 99.9M</sub> | - | - | - | 149 <sub>2-m 205.8M</sub> | 215 <sub>2-m 171.4M</sub> | 227 <sub>7 76.7M</sub> | - | 1.52 |
| secp256k1 | 500 | 11 <sub>2 2.0M</sub> | 18 <sub>1 2.1M</sub> | 15 <sub>0 1.9M</sub> | - | 1.39 | - | - | - | - | - |
| secp256k1 | 2000 | 44 <sub>2 2.0M</sub> | 69 <sub>1 2.2M</sub> | 60 <sub>0 1.9M</sub> | - | 1.38 | - | - | - | - | - |
| spectral-norm | 2000 | 24 <sub>2 2.0M</sub> | 29 <sub>1 2.2M</sub> | 50 <sub>7 1.9M</sub> | - | 2.11 | 7 <sub>1-m 15.1M</sub> | 5 <sub>2-m 2.4M</sub> | 7 <sub>7-m 2.1M</sub> | 59 <sub>5-im 2.7M</sub> | 1.03 |
| spectral-norm | 4000 | 94 <sub>2 2.0M</sub> | 115 <sub>1 2.1M</sub> | 200 <sub>7 1.9M</sub> | - | 2.12 | 17 <sub>2-m 12.2M</sub> | 17 <sub>2-m 3.0M</sub> | 27 <sub>7-m 2.3M</sub> | 234 <sub>5-im 2.4M</sub> | 1.59 |
| spectral-norm | 8000 | 375 <sub>2 2.0M</sub> | 460 <sub>1 2.4M</sub> | 799 <sub>7 2.2M</sub> | - | 2.13 | 53 <sub>2-m 14.0M</sub> | 64 <sub>1-m 5.0M</sub> | 103 <sub>7-m 2.2M</sub> | 938 <sub>5-im 3.0M</sub> | 1.94 |

### Built for this CPU

`plb.py --arch native`: C, C++ and Goose with `-march=native`, Rust with
`-Ctarget-cpu=native`, Helium with `--native --v4` (AVX-512, whose 32 vector
registers also hold small arrays across a loop). Goose was not rebuilt.

| problem | input | Helium | Goose | Rust | C/C++ | ratio | Helium -m | Goose -m | Rust -m | C/C++ -m | ratio -m |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| binarytrees | 15 | 10 <sub>1 3.0M</sub> | - | 77 <sub>4 5.9M</sub> | - | 8.03 | 2 <sub>2-m 6.9M</sub> | - | - | - | - |
| binarytrees | 18 | 108 <sub>1 12.1M</sub> | - | 886 <sub>4 33.9M</sub> | - | 8.16 | 20 <sub>2-m 85.8M</sub> | - | - | - | - |
| coro-prime-sieve | 1000 | 1 <sub>1 2.0M</sub> | - | 46 <sub>3 4.4M</sub> | - | 35.16 | - | - | 8 <sub>3-m 4.2M</sub> | - | - |
| coro-prime-sieve | 4000 | 16 <sub>1 2.0M</sub> | - | 700 <sub>3 9.4M</sub> | - | 44.57 | - | - | 54 <sub>5 4.5M</sub> | - | - |
| edigits | 100000 | 13 <sub>1 5.3M</sub> | - | 15 <sub>1 3.2M</sub> | - | 1.19 | - | - | - | - | - |
| edigits | 250001 | 45 <sub>1 6.0M</sub> | - | 56 <sub>1 3.7M</sub> | - | 1.25 | - | - | - | - | - |
| fannkuch-redux | 10 | 33 <sub>1 2.0M</sub> | - | 64 <sub>3-i 1.9M</sub> | - | 1.95 | 4 <sub>1-m 2.5M</sub> | - | 5 <sub>3-im 2.5M</sub> | 62 <sub>1-im 4.2M</sub> | 1.18 |
| fannkuch-redux | 11 | 378 <sub>1 2.0M</sub> | - | 759 <sub>3-i 1.9M</sub> | - | 2.01 | 44 <sub>1-m 2.5M</sub> | - | 54 <sub>3-im 2.5M</sub> | 741 <sub>1-im 4.3M</sub> | 1.21 |
| fasta | 250000 | 4 <sub>2 8.2M</sub> | - | 5 <sub>6 1.9M</sub> | - | 1.14 | 4 <sub>2-m 4.3M</sub> | - | 6 <sub>5c-m 7.5M</sub> | - | 1.31 |
| fasta | 2500000 | 37 <sub>2 8.0M</sub> | - | 48 <sub>6 1.9M</sub> | - | 1.30 | 38 <sub>2-m 6.2M</sub> | - | 49 <sub>5c-m 7.3M</sub> | - | 1.30 |
| helloworld | QwQ | 0 <sub>1 2.0M</sub> | - | 0 <sub>1 1.9M</sub> | 0 <sub>1 2.2M</sub> | 0.95 | - | - | - | - | - |
| json-serde | sample 5000 | 11 <sub>1 10.6M</sub> | - | 11 <sub>5-i 10.2M</sub> | - | 1.05 | 5 <sub>1-m 14.3M</sub> | - | - | - | - |
| json-serde | canada 15 | 95 <sub>1 54.2M</sub> | - | 88 <sub>5-i 53.5M</sub> | - | 0.93 | 40 <sub>1-m 77.3M</sub> | - | - | - | - |
| knucleotide | 250000_in | 9 <sub>1 14.1M</sub> | - | 22 <sub>8 11.5M</sub> | - | 2.36 | 5 <sub>1-m 24.1M</sub> | - | 8 <sub>8-m 15.4M</sub> | 27 <sub>1 8.8M</sub> | 1.51 |
| knucleotide | 2500000_in | 84 <sub>1 36.1M</sub> | - | 161 <sub>8 23.7M</sub> | - | 1.92 | 31 <sub>3-m 72.4M</sub> | - | 48 <sub>8-m 28.9M</sub> | 243 <sub>1 19.8M</sub> | 1.53 |
| lru | 100 500000 | 4 <sub>2 2.0M</sub> | - | 13 <sub>0-unsafe 1.9M</sub> | - | 3.51 | - | - | - | - | - |
| lru | 1000 1000000 | 8 <sub>2 2.0M</sub> | - | 14 <sub>0-unsafe 1.9M</sub> | - | 1.65 | - | - | - | - | - |
| lru | 1000 3000000 | 24 <sub>2 2.0M</sub> | - | 69 <sub>0-unsafe 1.9M</sub> | - | 2.86 | - | - | - | - | - |
| mandelbrot | 1000 | 6 <sub>1 2.0M</sub> | - | 7 <sub>8 1.9M</sub> | - | 1.18 | 2 <sub>1-m 11.7M</sub> | - | - | - | - |
| mandelbrot | 5000 | 128 <sub>1 5.1M</sub> | - | 150 <sub>8 5.0M</sub> | - | 1.17 | 16 <sub>1-m 19.6M</sub> | - | - | - | - |
| merkletrees | 15 | 23 <sub>1 8.0M</sub> | - | 85 <sub>1 9.9M</sub> | - | 3.70 | - | - | - | - | - |
| merkletrees | 17 | 108 <sub>1 20.0M</sub> | - | 430 <sub>1 33.9M</sub> | - | 3.99 | - | - | - | - | - |
| nbody | 500000 | 9 <sub>2 2.0M</sub> | - | 9 <sub>4-i 1.9M</sub> | 9 <sub>0-i 4.0M</sub> | 1.04 | - | - | - | - | - |
| nbody | 5000000 | 87 <sub>2 2.0M</sub> | - | 90 <sub>4-i 1.9M</sub> | 88 <sub>0-i 4.0M</sub> | 1.02 | - | - | - | - | - |
| nsieve | 10 | 25 <sub>1 13.0M</sub> | - | 30 <sub>1 11.8M</sub> | 25 <sub>1 12.0M</sub> | 1.00 | 18 <sub>2-m 5.8M</sub> | - | - | - | - |
| nsieve | 12 | 125 <sub>2 7.0M</sub> | - | 181 <sub>1 41.0M</sub> | 126 <sub>1 8.8M</sub> | 1.01 | 73 <sub>2-m 13.0M</sub> | - | - | - | - |
| pidigits | 4000 | 29 <sub>1 2.0M</sub> | - | 144 <sub>2 2.4M</sub> | - | 4.96 | - | - | - | - | - |
| pidigits | 8000 | 125 <sub>1 2.0M</sub> | - | 619 <sub>2 2.7M</sub> | - | 4.94 | - | - | - | - | - |
| regex-redux | 250000_in | 22 <sub>1 14.5M</sub> | - | - | - | - | 17 <sub>2-m 28.7M</sub> | - | 23 <sub>7 11.7M</sub> | - | 1.41 |
| regex-redux | 2500000_in | 186 <sub>1 104.5M</sub> | - | - | - | - | 149 <sub>2-m 204.6M</sub> | - | 213 <sub>7 78.7M</sub> | - | 1.43 |
| secp256k1 | 500 | 11 <sub>2 2.0M</sub> | - | 14 <sub>0 1.9M</sub> | - | 1.28 | - | - | - | - | - |
| secp256k1 | 2000 | 43 <sub>2 2.0M</sub> | - | 57 <sub>0 1.9M</sub> | - | 1.31 | - | - | - | - | - |
| spectral-norm | 2000 | 20 <sub>2 2.0M</sub> | - | 47 <sub>7 1.9M</sub> | - | 2.32 | 6 <sub>2-m 17.1M</sub> | - | 8 <sub>7-m 2.4M</sub> | 59 <sub>5-im 2.6M</sub> | 1.27 |
| spectral-norm | 4000 | 81 <sub>2 2.0M</sub> | - | 188 <sub>7 1.9M</sub> | - | 2.32 | 12 <sub>2-m 16.4M</sub> | - | 27 <sub>7-m 2.4M</sub> | 234 <sub>5-im 2.4M</sub> | 2.15 |
| spectral-norm | 8000 | 324 <sub>2 2.0M</sub> | - | 749 <sub>7 2.2M</sub> | - | 2.31 | 39 <sub>2-m 15.8M</sub> | - | 105 <sub>7-m 2.4M</sub> | 936 <sub>5-im 2.9M</sub> | 2.69 |

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
  loses with AVX2: hc keeps such arrays in registers across a loop only in
  the 16 extra AVX-512 registers, so with AVX2 every array goes to memory
  between steps and back. Rust's `4-i` replaces the square root and division
  with a float estimate and one correction step; written that way (with
  `rsqrt_est`), Helium's program gets slower with either instruction set.
* **spectral-norm/1** computes the products exactly as a row-by-row loop
  does, eight rows per vector; **/2** also sums four columns' fractions over
  the product of their denominators, one division per four columns, as C's
  `6-im` does.
* **fannkuch-redux** keeps a permutation in one u64, a nibble per element,
  and flips two permutations at once for the instruction-level parallelism.
* **fasta/1** uses the prescribed linear congruential generator as written,
  and integer thresholds for the cumulative probabilities. **/2** makes the
  same numbers with the generator's quotient by IM as a fixed-point multiply
  (checked exact for every seed), which shortens the chain from one number
  to the next, and takes each letter from a table of the letter for every
  random number; **/2-m** is 1-m's split with 2's generator and tables.
* **knucleotide/1** counts the k of 12 and 18 in a hash table of its own,
  as C's program does; a k of at most 6 has at most 4096 keys, each counted
  in a counter of its own indexed by the key. **/1-m** runs the k on four
  workers, each with a copy of the sequence packed four codes a byte.
  **/2** counts with the stdlib `dictionary`.
* **lru/1** uses the stdlib `dictionary`; **/2** a table made for the cache,
  a sixteenth full, whose nodes keep their slot so eviction takes no lookup.
* **json-serde** reads into typed records with the stdlib `json` reader and
  writes with its writer, numbers included, but for the integral values the
  Rust programs' `MyF64` writes as integers.
* **pidigits**, **edigits** and **secp256k1** carry their own big-integer
  arithmetic on 64-bit limbs: the spigot's products and sums fused into one
  pass each (GMP's addmul kind), Toom-3 and Karatsuba multiplication and
  divide-and-conquer division for edigits as the Rust crates have them (with
  a schoolbook base case that adds two rows at a time, as GMP's `addmul_2`),
  and fixed 4x64-bit field elements for secp256k1, which follows the
  algorithm of the hand-written `1.rs`; its field addition and subtraction
  fold the modulus in under a mask rather than branching on the carry, which
  goes either way at random.

## Where Goose is behind, and why

* **nbody** (0.78 against intrinsics, 0.90 against plain C++): the `-i`
  programs avoid the divider with a float reciprocal square root estimate and
  Newton steps, which Goose cannot express (no intrinsics, no float bit
  casts). Against the plain C++ program, 132 against 119 ms, the generated C
  is the same loop; clang's result for it moves by 10-20% with unrelated
  changes around it.
* **secp256k1** (0.93): Rust's `0.rs` uses the k256 crate, whose scalar
  multiplication uses precomputed tables of signed windows; the Goose program
  follows the hand-written algorithm (`1.rs`, which it beats by 18x). Its
  field arithmetic is faster than k256's.
* **regex-redux/1**: the stdlib regex engine is a DFA that takes one table
  lookup per byte, and its prefilter rates byte pairs by English letter
  frequencies, useless on DNA. Rust's regex crate finds these alternations of
  short literals with a SIMD multi-literal search (Teddy). Rust's `7.rs`
  runs on two threads; forced to one it takes about 255 ms against Goose's
  490.
* **knucleotide/1-m's memory** (39 MB against Rust's 27 at 2500000, 22
  against 16 at 250000, at the same speed or better): workers share no
  memory, so each of the four gets its own copy of the packed sequence and
  its own tables.

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
* **Bounds checks kept** in an inner loop over a slice made inside the outer
  loop (`let cols = src[1..];` there, `cols[j]` and `cols[j + 3]` under
  `while j + 4 <= cols.len`); made before the outer loop, they go.
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
