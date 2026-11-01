# bench/beyond results, round 4 (2026-11-01, Antman)

Same machine, sizes and method as round 3 (one full `run.py` pass, `taskset -c 3,19`, hyperfine 1 warmup + 7
runs, **median [min–max] seconds**, Python one run with a 150 s limit, `?` = over the limit, outputs matched
gcc -O2 byte for byte, other users' jobs running, load ~7). `he`/`he-v3`/`he-v4` = compiler at cafa52f
(`he-v4` = `--v4`, AVX-512).

| bench | gcc-O2 | gcc-O3n | clang-O2 | clang-O3n | he | he-v3 | he-v4 | rust | rust-native | go | java | node | python |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| fib | 0.790 [0.754–0.821] | 0.809 [0.773–0.817] | 1.904 [1.893–1.920] | 1.893 [1.877–1.906] | 1.124 [1.074–1.133] | 1.071 [1.042–1.129] | 1.050 [1.038–1.112] | 1.823 [1.813–1.842] | 1.821 [1.795–1.834] | 3.420 [3.381–3.431] | 1.959 [1.926–1.988] | 6.563 [6.507–7.596] | 64.464 |
| nbody | 1.167 [1.166–1.184] | 1.181 [1.169–1.233] | 1.273 [1.268–1.350] | 1.163 [1.160–1.165] | 1.105 [1.100–1.107] | 1.091 [1.090–1.096] | 1.102 [1.093–1.108] | 0.862 [0.861–0.863] | 0.844 [0.840–0.846] | 1.548 [1.543–1.563] | 1.136 [1.132–1.144] | 1.746 [1.743–1.817] | 102.525 |
| spectral | 0.935 [0.931–0.957] | 0.127 [0.127–0.128] | 0.973 [0.958–0.993] | 0.908 [0.902–0.914] | 0.934 [0.932–0.965] | 0.477 [0.476–0.482] | 0.265 [0.265–0.266] | 0.927 [0.926–0.929] | 0.920 [0.918–0.920] | 0.957 [0.955–0.960] | 0.976 [0.972–0.991] | 1.272 [1.267–1.297] | 116.369 |
| fannkuch | 1.919 [1.866–1.945] | 1.578 [1.572–1.636] | 1.853 [1.829–1.889] | 1.851 [1.831–1.870] | 1.799 [1.797–1.807] | 1.783 [1.780–1.797] | 1.802 [1.799–1.815] | 1.668 [1.656–1.686] | 1.694 [1.679–1.724] | 1.731 [1.704–1.768] | 1.788 [1.608–1.821] | 1.678 [1.673–1.693] | 36.737 |
| mandelbrot | 1.358 [1.344–1.359] | 1.265 [1.248–1.281] | 2.356 [2.350–2.361] | 1.260 [1.258–1.265] | 1.574 [1.565–1.580] | 1.588 [1.576–1.591] | 1.585 [1.577–1.593] | 1.425 [1.418–1.426] | 1.380 [1.372–1.395] | 1.494 [1.487–1.498] | 1.508 [1.476–1.540] | 1.389 [1.387–1.397] | 68.775 |
| bintrees | 0.725 [0.721–0.751] | 0.560 [0.556–0.584] | 1.017 [0.994–1.132] | 1.024 [0.977–1.136] | 1.053 [1.044–1.077] | 1.042 [1.034–1.052] | 1.064 [1.043–1.207] | 1.198 [1.191–1.213] | 1.204 [1.194–1.214] | 1.294 [1.273–1.323] | 1.209 [1.202–1.259] | 3.349 [3.332–3.366] | 49.961 |
| hashmap | 1.294 [1.254–1.319] | 1.262 [1.240–1.308] | 1.245 [1.214–1.325] | 1.224 [1.191–1.319] | 1.643 [1.586–1.698] | 1.646 [1.597–1.889] | 1.678 [1.624–1.714] | 1.746 [1.703–1.817] | 1.903 [1.741–1.915] | 2.270 [2.240–2.340] | 8.725 [7.988–8.966] | 5.071 [4.984–5.283] | 20.858 |
| strbuild | 0.784 [0.770–0.808] | 0.781 [0.769–0.829] | 0.744 [0.724–0.783] | 0.763 [0.748–0.811] | 0.564 [0.543–0.584] | 0.553 [0.550–0.572] | 0.556 [0.550–0.560] | 0.551 [0.550–0.577] | 0.539 [0.534–0.541] | 0.931 [0.903–1.043] | 3.405 [2.302–3.452] | 5.060 [4.563–5.120] | 9.618 |
| json | 0.828 [0.819–0.844] | 0.747 [0.737–0.766] | 0.651 [0.647–0.662] | 0.655 [0.647–0.761] | 0.492 [0.479–0.496] | 0.480 [0.477–0.485] | 0.478 [0.472–0.484] | 0.490 [0.478–0.520] | 0.484 [0.476–0.495] | 0.777 [0.766–0.797] | 0.781 [0.762–0.792] | 3.961 [3.830–4.924] | 23.829 |
| regex | 0.624 [0.612–0.662] | 0.493 [0.485–0.519] | 0.789 [0.775–0.800] | 0.790 [0.768–0.799] | 0.920 [0.913–0.944] | 0.922 [0.916–0.945] | 0.940 [0.928–0.944] | 0.770 [0.762–0.782] | 0.776 [0.769–0.782] | 0.822 [0.786–0.848] | 0.910 [0.902–0.947] | 1.552 [1.329–1.561] | 47.126 |
| matmul | 0.975 [0.958–1.018] | 0.718 [0.709–0.759] | 1.002 [0.995–1.036] | 0.742 [0.676–0.756] | 0.631 [0.623–0.634] | 0.631 [0.628–0.647] | 0.593 [0.591–0.616] | 1.065 [1.052–1.077] | 0.755 [0.694–0.787] | 2.485 [2.455–2.505] | 1.745 [1.719–1.775] | 4.786 [4.676–4.882] | ? |
| sort | 1.434 [1.431–1.445] | 1.521 [1.507–1.535] | 0.919 [0.913–0.953] | 0.928 [0.913–0.961] | 0.967 [0.956–0.984] | 0.980 [0.966–0.989] | 0.975 [0.958–0.979] | 1.554 [1.525–1.571] | 1.513 [1.494–1.536] | 1.519 [1.510–1.526] | 2.033 [1.896–2.312] | 3.162 [3.157–3.193] | 55.893 |

| bench | he/gcc-O2 | best C | best he vs best C | best non-Helium | best he vs best overall | he instr / gcc-O2 instr |
|---|---|---|---|---|---|---|
| fib | 1.42x | gcc-O2 0.790 | 1.33x (he-v4) | gcc-O2 0.790 | 1.33x | 1.17 |
| nbody | 0.95x | clang-O3n 1.163 | 0.94x (he-v3) | rust-native 0.844 | 1.29x | 1.07 |
| spectral | 1.00x | gcc-O3n 0.127 | 2.08x (he-v4) | gcc-O3n 0.127 | 2.08x | 1.11 |
| fannkuch | 0.94x | gcc-O3n 1.578 | 1.13x (he-v3) | gcc-O3n 1.578 | 1.13x | 0.73 |
| mandelbrot | 1.16x | clang-O3n 1.260 | 1.25x (he) | clang-O3n 1.260 | 1.25x | 1.28 |
| bintrees | 1.45x | gcc-O3n 0.560 | 1.86x (he-v3) | gcc-O3n 0.560 | 1.86x | 1.51 |
| hashmap | 1.27x | clang-O3n 1.224 | 1.34x (he) | clang-O3n 1.224 | 1.34x | 1.99 |
| strbuild | 0.72x | clang-O2 0.744 | 0.74x (he-v3) | rust-native 0.539 | 1.03x | 0.78 |
| json | 0.59x | clang-O2 0.651 | 0.73x (he-v4) | rust-native 0.484 | 0.99x | 0.63 |
| regex | 1.48x | gcc-O3n 0.493 | 1.87x (he) | gcc-O3n 0.493 | 1.87x | 2.12 |
| matmul | 0.65x | gcc-O3n 0.718 | 0.83x (he-v4) | gcc-O3n 0.718 | 0.83x | 0.42 |
| sort | 0.67x | clang-O2 0.919 | 1.05x (he) | clang-O2 0.919 | 1.05x | 2.50 |

Round-4 notes (interleaved A/B, pinned to one core, identical output, min/median ms)
- (1) Live-range splitting: what landed (9dffc42, 61eab79) changes loop block layout so the hot loop
  body is laid out contiguously and coloured first. It is **not** true region-based live-range splitting.
  regex is 0.970 -> 0.920 s across rounds, but the loop-carried values in `here` still sit in stack slots.
- (2) AVX-512: `--v4` (and `--vhost`, which is the same as `--v4` on this Zen 5 host: detection happens at
  compile time, with no runtime dispatch). spectral he-v3 0.477 -> he-v4 0.265 s (still 2.1x behind gcc-O3n's
  0.127), matmul 0.631 -> 0.593 (now ahead of every C build here), mandelbrot unchanged.
- (3) Call overhead: duplicating the latch header test was neutral; reusing call save/restore gave
  bintrees 1314 -> 1186; a second self-inline round only for small bodies (HSL2=40) gave bintrees
  1165 -> 1088. fib is unchanged. gcc wins fib through a shrink-wrapped prologue and computing the leaves
  arithmetically. Leaf-guard partial inlining for bintrees is not done.
- (4) sort: NOP-patching the 3 bounds checks in the merge loop gained nothing (1130 vs 1124), so they
  were measured as free and left in. Re-issuing the compare before the select so it fuses into cmovcc,
  plus xor-zero + setcc with no movzx: 1138 -> 967 (ablation: both 969, no-xz 1054, no-ssf 1053,
  neither 1139). sort is now 1.05x behind clang-O2, ahead of gcc, Rust, Go, Java and Node.
- Remaining gaps vs best overall (round 4; spectral is 1.07x with 8 lanes, see below): spectral 2.08x, regex 1.87x, bintrees 1.86x, hashmap 1.34x, fib 1.33x,
  nbody 1.29x (vs Rust), mandelbrot 1.25x, fannkuch 1.13x, sort 1.05x. Helium leads or ties on matmul,
  json, and strbuild (1.03x vs rust-native).

`--v4` measured row (interleaved A/B after round 4, compiler b930829, 7 reps alternating, `taskset -c 7`,
**min ms**, identical output; the gcc build was timed in the same interleaved run, gcc-O3n for spectral)

| bench | he --v3 | he --v4 | gcc | he --v4 / gcc |
|---|---|---|---|---|
| spectral | 488 | 271 | 130 | 2.08x |
| matmul | 652 | 607 | 664 | 0.91x |
| mandelbrot | 1586 | 1587 | 1251 | 1.27x |

- spectral: the gap is lane width. gcc-O3n built for 256-bit vectors runs in 253 ms, close to he --v4.
  Measured per-instruction cost of `vdivpd` is the same for ymm and zmm (0.611 vs 0.614 ns), so 8 lanes
  should roughly halve the divide-bound loop. Helium's outer-loop SLP packed 4 lanes at the time of this
  row; 8 lanes is now the default under `--v4` (see the 8-lane row below).
- matmul: --v4 is ahead of gcc-O3n here.
- mandelbrot: --v4 gains nothing over --v3, so its gap is not vector width.
- `--vhost` produces the same binary as `--v4` on Antman (Zen 5, full AVX-512).

8-lane `--v4` row (compiler f4f3eaf: 8 lanes, zmm, is the default under `--v4`/`--vhost`; `HC_VLN4=1`
turns it off and gives the old 4-lane `--v4` binary byte for byte; `--v3` and the default stay 4 lanes and
are byte-identical to before. Interleaved, 7 reps alternating the four binaries, `taskset -c 7`, n=5500,
all printed 1.274224153, gcc 16.2.1, load ~8.6 from other jobs)

| spectral | min ms | median ms |
|---|---|---|
| he --v4, 8 lanes | 138 | 139 |
| he --v4, 4 lanes (`HC_VLN4=1`) | 270 | 271 |
| gcc -O3 -march=native | 129 | 130 |
| gcc -O2 | 940 | 942 |

- spectral: 8 lanes is 1.96x faster than 4 lanes; he --v4 / gcc-O3n is now 1.07x (min), down from 2.08x.
- Every other bench and every test builds to the same binary under `--v4` with 8 or 4 lanes, so nothing
  else changed speed. Only spectral's binary changed; its output matched at n=10/100/1000/5500.
- mandelbrot, nbody and matmul do not take 8 lanes because SLP forms no packs in them (`HC_SLPV=1` prints
  nothing); their vector code comes from the vloop path in vec.he, which is still fixed at 4 lanes.

# bench/beyond results, round 3 (2026-11-01, Antman)

Same machine, toolchains, sizes and method as round 1 and 2 below (Ryzen 9 9950X3D, `taskset -c 3,19`,
hyperfine 1 warmup + 7 runs, **median [min–max] seconds**, Python one run with a 150 s limit, `?` =
over the limit; every variant's stdout matched gcc -O2 byte for byte; no fast-math; other users' jobs
running). `he`/`he-v3` = compiler at 057b627 (round 3: uaj, evd, sstc). Raw data: one full `run.py` pass.

| bench | gcc-O2 | gcc-O3n | clang-O2 | clang-O3n | he | he-v3 | rust | rust-native | go | java | node | python |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| fib | 0.774 [0.765–0.778] | 0.784 [0.776–0.794] | 1.890 [1.884–1.902] | 1.893 [1.872–1.907] | 1.042 [1.007–1.080] | 1.067 [1.040–1.088] | 1.831 [1.824–1.860] | 1.859 [1.839–1.876] | 3.410 [3.404–3.437] | 1.969 [1.954–2.016] | 6.618 [6.536–6.740] | 63.626 |
| nbody | 1.184 [1.180–1.195] | 1.184 [1.177–1.198] | 1.284 [1.279–1.295] | 1.182 [1.181–1.193] | 1.113 [1.105–1.142] | 1.112 [1.105–1.117] | 0.872 [0.869–0.880] | 0.850 [0.845–0.853] | 1.554 [1.551–1.567] | 1.155 [1.147–1.161] | 1.791 [1.740–1.859] | 103.948 |
| spectral | 0.938 [0.931–0.964] | 0.127 [0.127–0.128] | 0.951 [0.949–0.953] | 0.905 [0.904–0.908] | 0.938 [0.937–0.938] | 0.480 [0.479–0.484] | 0.933 [0.928–0.938] | 0.924 [0.923–0.924] | 0.963 [0.962–0.966] | 0.979 [0.971–0.986] | 1.289 [1.282–1.299] | 118.305 |
| fannkuch | 1.896 [1.845–1.923] | 1.598 [1.583–1.612] | 1.839 [1.833–1.880] | 1.855 [1.840–1.865] | 1.923 [1.804–2.061] | 1.788 [1.773–1.829] | 1.650 [1.640–1.662] | 1.757 [1.742–1.763] | 1.710 [1.705–1.737] | 1.723 [1.581–1.796] | 1.669 [1.658–1.677] | 36.366 |
| mandelbrot | 1.330 [1.322–1.344] | 1.239 [1.236–1.243] | 2.381 [2.351–2.442] | 1.276 [1.272–1.289] | 1.569 [1.559–1.583] | 1.570 [1.569–1.583] | 1.414 [1.410–1.422] | 1.353 [1.349–1.360] | 1.469 [1.465–1.472] | 1.507 [1.480–1.561] | 1.418 [1.375–1.448] | 66.649 |
| bintrees | 0.723 [0.716–0.745] | 0.554 [0.550–0.557] | 1.012 [0.993–1.102] | 1.006 [0.997–1.083] | 1.300 [1.284–1.407] | 1.297 [1.294–1.303] | 1.197 [1.187–1.206] | 1.210 [1.198–1.224] | 1.310 [1.295–1.364] | 1.210 [1.201–1.232] | 3.342 [3.319–3.405] | 49.472 |
| hashmap | 1.317 [1.210–1.437] | 1.388 [1.289–1.495] | 1.251 [1.213–1.294] | 1.227 [1.190–1.268] | 1.519 [1.499–1.609] | 1.591 [1.552–1.694] | 1.675 [1.658–1.796] | 1.695 [1.662–1.771] | 2.277 [2.163–2.486] | 8.608 [7.857–9.363] | 5.348 [4.977–5.540] | 20.362 |
| strbuild | 0.779 [0.773–0.814] | 0.752 [0.748–0.797] | 0.733 [0.727–0.752] | 0.740 [0.729–0.779] | 0.555 [0.550–0.568] | 0.559 [0.553–0.580] | 0.552 [0.551–0.569] | 0.553 [0.546–0.558] | 0.935 [0.916–1.084] | 3.459 [2.283–3.523] | 5.100 [4.720–5.654] | 9.356 |
| json | 0.825 [0.809–1.287] | 0.749 [0.737–1.114] | 0.658 [0.643–0.672] | 0.666 [0.649–0.680] | 0.474 [0.469–0.481] | 0.465 [0.461–0.472] | 0.491 [0.486–0.506] | 0.490 [0.484–0.494] | 0.805 [0.760–0.820] | 0.791 [0.759–0.835] | 4.084 [3.822–4.277] | 23.784 |
| regex | 0.630 [0.611–0.644] | 0.481 [0.477–0.486] | 0.774 [0.762–0.829] | 0.762 [0.748–0.773] | 0.970 [0.955–0.982] | 0.963 [0.952–0.972] | 0.758 [0.746–0.792] | 0.779 [0.775–0.795] | 0.836 [0.813–0.850] | 0.962 [0.898–1.034] | 1.549 [1.288–1.558] | 47.448 |
| matmul | 0.950 [0.944–0.962] | 0.689 [0.651–0.758] | 0.993 [0.970–1.003] | 0.538 [0.509–0.553] | 0.629 [0.622–0.644] | 0.647 [0.590–0.666] | 1.089 [1.065–1.106] | 0.667 [0.625–0.700] | 2.393 [2.376–2.414] | 1.764 [1.740–1.789] | 4.801 [4.627–4.953] | ? |
| sort | 1.443 [1.434–1.458] | 1.504 [1.489–1.543] | 0.919 [0.903–0.960] | 0.909 [0.906–0.937] | 1.128 [1.127–1.151] | 1.129 [1.115–1.230] | 1.530 [1.522–1.588] | 1.504 [1.495–1.522] | 1.507 [1.494–1.523] | 1.963 [1.828–2.012] | 3.182 [3.131–3.225] | 60.054 |

| bench | he/gcc-O2 | best C | best he vs best C | best non-Helium | best he vs best overall | he instr / gcc-O2 instr |
|---|---|---|---|---|---|---|
| fib | 1.35x | gcc-O2 0.774 | 1.35x | gcc-O2 0.774 | 1.35x | 1.15 |
| nbody | 0.94x | clang-O3n 1.182 | 0.94x | rust-native 0.850 | 1.31x | 1.07 |
| spectral | 1.00x | gcc-O3n 0.127 | 3.77x | gcc-O3n 0.127 | 3.77x | 1.11 |
| fannkuch | 1.01x | gcc-O3n 1.598 | 1.12x | gcc-O3n 1.598 | 1.12x | 0.73 |
| mandelbrot | 1.18x | gcc-O3n 1.239 | 1.27x | gcc-O3n 1.239 | 1.27x | 1.28 |
| bintrees | 1.80x | gcc-O3n 0.554 | 2.34x | gcc-O3n 0.554 | 2.34x | 1.45 |
| hashmap | 1.15x | clang-O3n 1.227 | 1.24x | clang-O3n 1.227 | 1.24x | 1.99 |
| strbuild | 0.71x | clang-O2 0.733 | 0.76x | rust 0.552 | 1.00x | 0.78 |
| json | 0.57x | clang-O2 0.658 | 0.71x | rust-native 0.490 | 0.95x | 0.63 |
| regex | 1.54x | gcc-O3n 0.481 | 2.00x | gcc-O3n 0.481 | 2.00x | 2.19 |
| matmul | 0.66x | clang-O3n 0.538 | 1.17x | clang-O3n 0.538 | 1.17x | 0.42 |
| sort | 0.78x | clang-O3n 0.909 | 1.24x | clang-O3n 0.909 | 1.24x | 2.49 |

Round-3 notes (interleaved A/B on cpu 3, identical output, min/median ms unless noted)
- (a) spectral, 2641467 `uaj`: unroll-and-jam of simple counted loop nests by 4, so SLP packs the inner
  body into AVX2 lanes (in-order per-lane sums: results are bit-identical, with runtime overlap checks and
  a scalar fallback/tail). `--v3` only. he-v3 0.955 -> 0.480 s (-49%); plain `he` (SSE2 baseline)
  unchanged. Still 3.8x behind gcc -O3 -march=native, which uses AVX-512 (8-wide f64 divide). No
  AVX-512 path is implemented, neither runtime-detected nor behind a flag, so there is no AVX-512 number
  to report for Helium.
- (e) sort, b345887 `sstc`: if-converts a load-compare diamond that stores to the same slot in both arms
  into `sel` + store + branchless counter bumps (the merge step). 1555/1559 -> 1111/1126 (`--v3`
  1550/1560 -> 1115/1122), -28%. Helium is now ahead of gcc (both -O2 and -O3n), Rust, Go, Java and
  Node on sort; 1.24x behind clang. Left over: mid/hi in stack slots, 3 bounds checks per merge step,
  setcc/movzx/test chains where clang fuses cmp into cmov.
- (b) bintrees: neither the C nor the Helium version allocates per node (both use arena indices), so a
  bump/size-class allocator has nothing to replace. The gap is call/prologue overhead in the recursion.
- (c) fib: with `HC_CS=1 HC_CSM=1` (callee-saved steal) the inner call has no spills at all, but 5
  interleaved pairs were all slower (default 1025–1081 vs 1092–1145 ms). Self-inline depth sweep:
  HC_SIR=1 ~1139–1220, 2 (default) ~1037–1054, 3 ~1226–1274, 4 ~1601–1623. Nothing landed. gcc
  wins by computing the leaves arithmetically (fewer calls), not only by register use.
- (c) regex: the loop-carried r/t of the self-tail-loop in `here` and the reloaded RE ptr/len live in
  stack slots (`addq $1,-0x78(%rbp)` on the hot path) because linear scan evicts long whole-function
  intervals. Knob sweep (HC_CS, HC_CSM, HC_NORS, HC_SIR) moved it 3% at most, within noise. A real fix
  needs region-based live-range splitting. Not done.
- (d) shrink-wrapping does not apply to fib: the n<2 guard is already duplicated to the call sites, so
  the function is only entered with n>=2.
- matmul: clang -O3n ran at 0.538 s in this pass (0.669 in round 2, 0.748 in round 1). Helium is
  unchanged at 0.63 s, so Helium is behind clang -O3n in this run.
- Helium beats every C variant on nbody, strbuild and json, and beats gcc (-O2 and -O3n) on sort and
  matmul; it is the fastest language overall on json and ties Rust on strbuild.
- Remaining gaps vs best overall: spectral 3.8x (AVX-512), bintrees 2.3x, regex 2.0x, fib 1.35x,
  nbody 1.31x (Rust), mandelbrot 1.27x, sort 1.24x (clang), hashmap 1.24x, matmul 1.17x, fannkuch 1.12x.

---

# bench/beyond results, round 2 (2026-11-01, Antman)

Same machine, toolchains, sizes and method as round 1 below (Ryzen 9 9950X3D, `taskset -c 3,19`,
hyperfine 2.0.0, 1 warmup + 7 runs, **median [min–max] seconds**, Python one run with a 150 s limit,
`?` = over the limit; every variant's stdout matched gcc -O2 byte for byte; no fast-math; load ~7
from other users' jobs). `he`/`he-v3` = compiler at e5a8443 (round 2: self-inlining of recursion,
fixed-lane list scheduling K=4, parallel-array dictionary). Raw data: one full `run.py` pass.

| bench | gcc-O2 | gcc-O3n | clang-O2 | clang-O3n | he | he-v3 | rust | rust-native | go | java | node | python |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| fib | 0.775 [0.761–0.817] | 0.797 [0.780–0.804] | 1.918 [1.903–1.956] | 1.887 [1.879–1.898] | 1.044 [1.028–1.088] | 1.047 [1.008–1.081] | 1.854 [1.831–1.889] | 1.837 [1.826–1.872] | 3.433 [3.404–3.457] | 1.982 [1.920–2.001] | 6.615 [6.576–7.326] | 63.687 |
| nbody | 1.181 [1.175–1.188] | 1.180 [1.175–1.192] | 1.288 [1.278–1.458] | 1.168 [1.166–1.180] | 1.106 [1.100–1.114] | 1.100 [1.095–1.109] | 0.864 [0.862–0.877] | 0.841 [0.840–0.842] | 1.550 [1.538–1.556] | 1.134 [1.129–1.143] | 1.749 [1.730–1.810] | 102.432 |
| spectral | 0.934 [0.932–0.941] | 0.128 [0.128–0.128] | 0.963 [0.954–1.014] | 0.908 [0.906–0.912] | 0.962 [0.957–0.964] | 0.955 [0.953–0.960] | 0.933 [0.932–0.942] | 0.929 [0.928–0.933] | 0.974 [0.971–0.982] | 0.975 [0.971–1.005] | 1.284 [1.276–1.306] | 117.284 |
| fannkuch | 1.881 [1.853–1.901] | 1.588 [1.584–1.595] | 1.853 [1.837–1.863] | 1.858 [1.829–1.863] | 1.806 [1.799–1.819] | 1.800 [1.796–1.815] | 1.685 [1.676–1.688] | 1.679 [1.672–1.681] | 1.732 [1.677–1.769] | 1.621 [1.600–1.796] | 1.688 [1.682–1.710] | 36.304 |
| mandelbrot | 1.363 [1.351–1.382] | 1.254 [1.249–1.269] | 2.364 [2.362–2.384] | 1.279 [1.277–1.298] | 1.574 [1.569–1.588] | 1.577 [1.571–1.586] | 1.438 [1.425–1.444] | 1.370 [1.370–1.375] | 1.493 [1.488–1.509] | 1.544 [1.527–1.557] | 1.394 [1.388–1.407] | 67.066 |
| bintrees | 0.736 [0.726–0.752] | 0.560 [0.555–0.569] | 1.008 [0.983–1.038] | 0.996 [0.970–1.046] | 1.306 [1.297–1.350] | 1.293 [1.290–1.343] | 1.206 [1.198–1.240] | 1.212 [1.201–1.228] | 1.297 [1.273–1.331] | 1.217 [1.199–1.235] | 3.354 [3.327–3.399] | 49.247 |
| hashmap | 1.300 [1.276–1.337] | 1.400 [1.267–1.562] | 1.186 [1.167–1.235] | 1.186 [1.161–1.232] | 1.611 [1.498–1.708] | 1.589 [1.559–1.707] | 1.824 [1.751–2.434] | 1.852 [1.814–1.893] | 2.329 [2.263–2.489] | 8.885 [8.435–9.309] | 5.552 [5.197–6.038] | 20.814 |
| strbuild | 0.786 [0.777–0.812] | 0.759 [0.749–0.770] | 0.741 [0.724–0.765] | 0.742 [0.736–0.761] | 0.565 [0.557–0.574] | 0.566 [0.563–0.573] | 0.561 [0.554–0.572] | 0.552 [0.541–0.609] | 0.957 [0.938–0.965] | 2.385 [2.347–3.537] | 4.820 [4.712–5.406] | 9.572 |
| json | 0.825 [0.800–0.856] | 0.707 [0.701–0.723] | 0.645 [0.636–0.659] | 0.630 [0.625–0.635] | 0.470 [0.467–0.478] | 0.454 [0.450–0.474] | 0.464 [0.459–0.468] | 0.481 [0.476–0.493] | 0.863 [0.784–0.917] | 0.794 [0.783–0.841] | 3.993 [3.940–4.137] | 23.753 |
| regex | 0.637 [0.628–0.660] | 0.493 [0.476–0.501] | 0.768 [0.764–0.775] | 0.769 [0.760–0.794] | 0.996 [0.992–1.009] | 1.012 [0.992–1.026] | 0.760 [0.752–0.778] | 0.774 [0.765–0.783] | 0.814 [0.805–0.823] | 0.929 [0.882–0.943] | 1.536 [1.263–1.543] | 46.796 |
| matmul | 0.960 [0.949–1.008] | 0.861 [0.749–1.176] | 1.026 [1.007–1.047] | 0.669 [0.638–0.749] | 0.632 [0.628–0.670] | 0.643 [0.625–0.655] | 1.070 [1.060–1.081] | 0.762 [0.756–0.768] | 2.459 [2.408–2.531] | 1.716 [1.715–1.734] | 4.737 [4.585–5.059] | ? |
| sort | 1.415 [1.399–1.436] | 1.508 [1.482–1.522] | 0.908 [0.904–0.924] | 0.915 [0.912–0.933] | 1.581 [1.550–1.612] | 1.572 [1.549–1.629] | 1.574 [1.549–1.615] | 1.514 [1.504–1.551] | 1.526 [1.508–1.534] | 1.960 [1.773–2.027] | 3.155 [3.145–3.202] | 59.500 |

| bench | he/gcc-O2 | best C | he vs best C | best non-Helium | he vs best overall | he instr / gcc-O2 instr |
|---|---|---|---|---|---|---|
| fib | 1.35x | gcc-O2 0.775 | 1.35x | gcc-O2 0.775 | 1.35x | 1.15 |
| nbody | 0.93x | clang-O3n 1.168 | 0.94x | rust-native 0.841 | 1.31x | 1.07 |
| spectral | 1.02x | gcc-O3n 0.128 | 7.46x | gcc-O3n 0.128 | 7.46x | 1.39 |
| fannkuch | 0.96x | gcc-O3n 1.588 | 1.13x | gcc-O3n 1.588 | 1.13x | 0.73 |
| mandelbrot | 1.15x | gcc-O3n 1.254 | 1.26x | gcc-O3n 1.254 | 1.26x | 1.28 |
| bintrees | 1.76x | gcc-O3n 0.560 | 2.31x | gcc-O3n 0.560 | 2.31x | 1.45 |
| hashmap | 1.22x | clang-O2 1.186 | 1.34x | clang-O2 1.186 | 1.34x | 1.99 |
| strbuild | 0.72x | clang-O2 0.741 | 0.76x | rust-native 0.552 | 1.02x | 0.78 |
| json | 0.55x | clang-O3n 0.630 | 0.72x | rust 0.464 | 0.98x | 0.63 |
| regex | 1.56x | gcc-O3n 0.493 | 2.02x | gcc-O3n 0.493 | 2.02x | 2.39 |
| matmul | 0.66x | clang-O3n 0.669 | 0.94x | clang-O3n 0.669 | 0.94x | 0.42 |
| sort | 1.11x | clang-O2 0.908 | 1.73x | clang-O2 0.908 | 1.73x | 1.98 |

Round-2 notes
- c89c93a (branch-on-compare through a bool copy) landed after this table: same-window interleaved
  A/B on cpu 3 (min/median of 7, ms) regex 987/997 -> 953/968; json, fib, sort, bintrees,
  mandelbrot unchanged within noise. The regex cell above predates it.
- Dictionary (e5a8443): keys/vals/states kept as three parallel arrays, so probes walk a 1-byte
  state array; single-probe insert. hashmap 20M: 1941 -> ~1500-1600 ms in same-window runs
  (-20%), now ahead of Rust, Go, Java, Node; 1.34x behind clang.
- Lane scheduling (6ff4529): matmul ~-5%, fib ~-3%, others within ±1%.
- Helium beats every C variant on nbody, strbuild, json, matmul; beats gcc -O2 also on fannkuch;
  is fastest of all languages on matmul and (within noise of Rust) json and strbuild.
- Biggest gaps: spectral vs gcc-O3n AVX-512 division vectorisation (7.5x), bintrees (2.3x, allocator),
  regex (2.0x), sort (1.7x vs clang), fib (1.35x: frame + callee-saved saves on the n<2 path, param
  and result spilled across the recursive calls), mandelbrot (1.26x), hashmap (1.34x).

---

# Round 1 (2026-10-31 / 11-01, Antman)

Machine: Ryzen 9 9950X3D, Linux, everything pinned with `taskset -c 3,19` (one V-cache core + its SMT
sibling), no sudo, other users' jobs running (load ~6–8), so expect ~5% noise between runs taken at
different times. hyperfine 2.0.0, 1 warmup + 7 runs; cells are **median [min–max] seconds**.
Python is a single run with a 150 s limit (`?` = over the limit). Every variant's stdout was checked
byte-for-byte against gcc -O2 before timing; all matched. No fast-math anywhere.

Toolchains: gcc 16.2.1, clang 23.1.1 (`-O2`, and `-O3 -march=native` = O3n), rustc 1.98.1
(`-C opt-level=3 -C codegen-units=1`, native = `-C target-cpu=native`), Go 1.27.3, OpenJDK 17.0.20,
Node 26.12.1, CPython 3.14.8. `he` = `hcn build`, `he-v3` = `hcn build --v3`.
`he`/`he-v3` = compiler at 4398c49 (miscompile fix); `he*`/`he-v3*` = compiler after fb7af9d.

Sizes: fib 45, nbody 30M steps, spectral 5500, fannkuch 11, mandelbrot 6000, bintrees 21,
hashmap 20M ops, strbuild 30M, json 3M records, regex 1M lines, matmul 2000, sort 20M.

| bench | gcc-O2 | gcc-O3n | clang-O2 | clang-O3n | he | he-v3 | he* | he-v3* | rust | rust-native | go | java | node | python |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| fib | 0.801 [0.778–0.817] | 0.797 [0.792–0.803] | 1.902 [1.854–1.907] | 1.860 [1.855–1.882] | 1.485 [1.464–1.503] | 1.495 [1.467–1.537] | 1.462 [1.443–1.478] | 1.478 [1.449–1.491] | 1.832 [1.806–1.852] | 1.808 [1.781–1.825] | 3.380 [3.363–3.409] | 1.943 [1.919–1.976] | 6.564 [6.471–6.732] | 64.029 |
| nbody | 1.169 [1.164–1.171] | 1.164 [1.160–1.172] | 1.265 [1.262–1.270] | 1.161 [1.157–1.171] | 1.106 [1.090–1.114] | 1.106 [1.096–1.162] | 1.104 [1.103–1.119] | 1.102 [1.101–1.111] | 0.864 [0.862–0.871] | 0.849 [0.845–0.852] | 1.554 [1.552–1.568] | 1.146 [1.143–1.222] | 1.746 [1.738–1.763] | 102.517 |
| spectral | 0.938 [0.935–0.943] | 0.128 [0.128–0.129] | 0.954 [0.953–0.968] | 0.923 [0.921–0.927] | 0.969 [0.964–0.971] | 0.973 [0.969–1.023] | 0.957 [0.954–0.965] | 0.955 [0.952–0.959] | 0.941 [0.936–0.943] | 0.924 [0.923–0.926] | 0.962 [0.959–0.965] | 0.986 [0.980–0.994] | 1.317 [1.308–1.487] | 128.742 |
| fannkuch | 1.911 [1.898–1.938] | 1.593 [1.572–1.693] | 1.836 [1.820–1.855] | 1.893 [1.819–2.369] | 2.057 [1.944–2.405] | 1.797 [1.788–1.874] | 1.804 [1.794–1.824] | 1.774 [1.766–1.809] | 1.689 [1.669–1.781] | 1.799 [1.770–1.814] | 1.733 [1.710–1.756] | 1.782 [1.620–1.849] | 1.694 [1.676–1.708] | 36.140 |
| mandelbrot | 1.350 [1.339–1.369] | 1.261 [1.258–1.272] | 2.385 [2.383–2.394] | 1.275 [1.257–1.285] | 1.579 [1.563–1.586] | 1.594 [1.566–1.604] | 1.550 [1.549–1.555] | 1.564 [1.557–1.569] | 1.418 [1.411–1.427] | 1.368 [1.365–1.377] | 1.486 [1.475–1.489] | 1.502 [1.476–1.517] | 1.414 [1.389–1.435] | 66.465 |
| bintrees | 0.727 [0.719–0.758] | 0.561 [0.558–0.569] | 1.007 [0.988–1.129] | 0.996 [0.937–1.085] | 1.299 [1.286–1.345] | 1.281 [1.275–1.344] | 1.292 [1.284–1.335] | 1.315 [1.289–1.348] | 1.205 [1.178–1.468] | 1.209 [1.190–1.264] | 1.295 [1.245–1.324] | 1.233 [1.210–1.344] | 3.379 [3.373–3.504] | 50.321 |
| hashmap | 1.441 [1.318–1.489] | 1.438 [1.296–1.670] | 1.233 [1.187–1.313] | 1.341 [1.194–1.437] | 2.099 [1.919–2.609] | 1.847 [1.797–2.398] | 2.048 [1.942–2.207] | 2.417 [1.955–3.387] | 1.789 [1.701–1.882] | 1.559 [1.534–1.773] | 2.289 [2.243–2.479] | 8.678 [8.284–8.849] | 5.652 [5.362–6.330] | 21.314 |
| strbuild | 0.775 [0.769–0.799] | 0.745 [0.730–0.765] | 0.707 [0.690–0.728] | 0.732 [0.719–0.782] | 0.543 [0.537–0.561] | 0.545 [0.537–0.556] | 0.550 [0.549–0.554] | 0.560 [0.556–0.573] | 0.541 [0.534–0.929] | 0.523 [0.519–0.526] | 0.909 [0.893–0.931] | 2.461 [2.403–3.568] | 5.066 [4.619–5.447] | 9.482 |
| json | 0.796 [0.786–0.811] | 0.700 [0.696–0.726] | 0.619 [0.611–0.646] | 0.599 [0.597–0.608] | 0.454 [0.449–0.459] | 0.442 [0.439–0.451] | 0.489 [0.477–0.496] | 0.476 [0.472–0.486] | 0.464 [0.462–0.473] | 0.461 [0.458–0.464] | 0.816 [0.792–0.835] | 0.815 [0.801–0.851] | 3.963 [3.891–4.103] | 23.588 |
| regex | 0.635 [0.629–0.640] | 0.485 [0.482–0.493] | 0.776 [0.765–0.782] | 0.766 [0.761–0.782] | 1.009 [1.005–1.013] | 1.011 [1.001–1.020] | 0.980 [0.978–0.987] | 0.991 [0.986–1.008] | 0.764 [0.758–0.770] | 0.774 [0.767–0.783] | 0.814 [0.803–0.834] | 0.926 [0.899–0.950] | 1.540 [1.471–1.555] | 47.286 |
| matmul | 0.963 [0.954–0.979] | 0.761 [0.752–0.774] | 1.012 [0.993–1.027] | 0.748 [0.743–0.750] | 0.650 [0.626–0.683] | 0.631 [0.624–0.645] | 0.654 [0.653–0.683] | 0.640 [0.633–0.646] | 1.096 [1.085–1.121] | 0.836 [0.800–0.867] | 2.870 [2.758–2.987] | 2.012 [1.921–2.865] | 4.875 [4.708–5.271] | ? |
| sort | 1.464 [1.431–1.476] | 1.512 [1.495–1.521] | 0.928 [0.922–0.944] | 0.921 [0.910–0.941] | 1.567 [1.535–1.598] | 1.563 [1.537–1.575] | 1.571 [1.541–1.633] | 1.597 [1.572–1.652] | 1.523 [1.511–1.584] | 1.496 [1.482–1.515] | 1.512 [1.500–1.531] | 1.996 [1.901–2.020] | 3.160 [3.131–3.197] | 57.775 |

| bench | he/gcc-O2 time | he*/gcc-O2 time | best C | he* vs best C | he instr / gcc-O2 instr |
|---|---|---|---|---|---|
| fib | 1.85x | 1.82x | gcc-O3n 0.797 | 1.83x | 1.59 |
| nbody | 0.95x | 0.94x | clang-O3n 1.161 | 0.95x | 1.07 |
| spectral | 1.03x | 1.02x | gcc-O3n 0.128 | 7.44x | 1.39 |
| fannkuch | 0.94x | 0.93x | gcc-O3n 1.593 | 1.11x | 0.73 |
| mandelbrot | 1.17x | 1.15x | gcc-O3n 1.261 | 1.23x | 1.28 |
| bintrees | 1.76x | 1.78x | gcc-O3n 0.561 | 2.30x | 1.45 |
| hashmap | 1.28x | 1.42x | clang-O2 1.233 | 1.66x | 2.44 |
| strbuild | 0.70x | 0.71x | clang-O2 0.707 | 0.78x | 0.77 |
| json | 0.55x | 0.60x | clang-O3n 0.599 | 0.80x | 0.63 |
| regex | 1.59x | 1.54x | gcc-O3n 0.485 | 2.02x | 2.42 |
| matmul | 0.65x | 0.66x | clang-O3n 0.748 | 0.86x | 0.42 |
| sort | 1.07x | 1.07x | clang-O3n 0.921 | 1.71x | 1.98 |

Notes
- spectral gcc -O3 -march=native (0.128 s) is real: gcc vectorises the A(i,j) division loop with
  AVX-512; output matches. Nobody else (clang O3n included) does this.
- Ratios use the best Helium variant. Instruction ratio is retired instructions (hyperfine) of `he`
  vs gcc -O2: Helium executes 1.4–2.4x more instructions on fib, bintrees, regex, hashmap, sort.
- fb7af9d alone is small: same-window A/B on cpu 3 gives json 479->467 / 472->464 ms,
  regex 1003->987 / 995->981 ms; the rest is within noise. Cross-run differences in the table above
  (e.g. json 0.454 vs 0.489) are run-to-run load noise, not the change.
