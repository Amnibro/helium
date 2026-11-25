# noise

Seeded coherent noise for terrain, textures and organic shapes, in the spirit of FastNoise2: value,
Perlin (gradient), simplex and cellular (Worley: F1, F2, F2 - F1, cell value) base noise; fBm, ridged and
billow fractals; domain warp; and fills of 2D and 3D grids. Every result is in [-1, 1]. Perlin uses the
same lattice hash and gradients as `grow`, which now calls it. Built from `noise.gold`; tested by
`hc/test/noise/noise_test.gold` (CPU only, run by `ci.sh`).

## Bars (registered before the first run)

* **N1 range.** 100,000 random points in [-50, 50]^3 per base kind: every `sample` in [-1, 1], and raw
  `perlin3` (which is not clamped) outside [-1, 1] at under 0.1% of them.
* **N2 balance.** Value, Perlin and simplex: |mean| < 0.05 and standard deviation between 0.1 and 0.6.
  Cellular kinds: standard deviation above 0.1.
* **N3 continuity.** Value, Perlin, simplex, F1, F2 and F2 - F1: over 100,000 point pairs 1e-5 apart the
  largest change is below 1e-3. Control: cell value jumps by more than 0.1 somewhere.
* **N4 seeds.** The same seed gives bit-identical values at 10,000 points; seeds 1 and 2 correlate below
  0.05 (absolute) for every kind.
* **N5 grow.** `grow` makes bit-identical meshes before and after switching to `noise::perlin3` (its own
  checks G1 to G10 still pass and its printed numbers match).
* **N6 exact cells.** With full jitter, F1 and F2 equal a brute-force 7 x 7 x 7 search at 20,000 points.
  Control: searching only the 3 x 3 x 3 block differs somewhere.
* **N7 fractals.** fBm, ridged and billow with 5 octaves stay in [-1, 1] over 100,000 points; 5-octave fBm,
  measured against its own standard deviation, changes at least 1.5 times as much as 1 octave over a 0.01
  step (mean over 10,000 points).
* **N8 warp.** Warp 0 gives exactly the plain field; warp 1 moves values by a mean of more than 0.05.
* **N9 speed.** A 512 x 512 fill of 5-octave Perlin fBm under 150 ms. Reported, no bar: nanoseconds per
  sample of each base kind.

## API

| | |
|---|---|
| `perlin3`, `value3`, `simplex3`, `cellular3(seed, p, kind)` | base noise at a `double3`; seeds are `u64` |
| `base(kind, seed, p)` | any base kind by number: `VALUE`, `PERLIN`, `SIMPLEX`, `CELL_F1`, `CELL_F2`, `CELL_EDGE`, `CELL_VALUE` |
| `make(kind, seed) Noise` | settings: frequency 1, no fractal, 3 octaves, lacunarity 2, gain 0.5, seed step 1, no warp |
| `sample(n, p)` | warp, then the fractal (`NONE`, `FBM`, `RIDGED`, `BILLOW`), clamped to [-1, 1] |
| `layered(n, p)` | the fractal average before mapping and clamping (ridged in [0, 1]); `grow` uses it with seed step 0 |
| `fill2(n, x0, z0, y, step, w, h, out)`, `fill3(n, origin, step, w, h, d, out)` | append `f32` grids, rows of x |

Cellular kinds map distances to [-1, 1]: F1 as 2 F1 - 1, F2 as F2 - 1 and the edge as 2 (F2 - F1) - 1. The
feature point of a cell can sit anywhere in it, so F2 is never above the square root of 3; the search
visits the 27 nearest cells and then only those of the next ring that are closer than the current F2,
which makes F1 and F2 exact.

## Results (first run, 2026-11-25)

| Bar | Result | Needed |
|---|---|---|
| N1 range | 0 of 700,000 samples outside; raw Perlin 0 outside, largest 0.9104 | 0; under 100 |
| N2 balance | means -0.0005, 0.0011, -0.0001; deviations 0.400, 0.271, 0.394; cellular 0.344, 0.143, 0.316, 0.578 | under 0.05; 0.1 to 0.6; above 0.1 |
| N3 continuity | largest change 6.9e-5; control 0.739 | under 1e-3; above 0.1 |
| N4 seeds | 0 differ; largest correlation 0.020 | 0; under 0.05 |
| N5 grow | 42 meshes (14 kinds, 3 seeds) with the same digests; G1 to G10 pass with the same numbers | identical |
| N6 exact cells | 0 wrong; control 1 point of 20,000 needs the outer ring | 0; above 0 |
| N7 fractals | 0 outside; roughness 0.0215 vs 0.0410, ratio 1.91 | 0; at least 1.5 |
| N8 warp | 0 differ; mean move 0.151 | 0; above 0.05 |
| N9 speed | 51.8 ms | under 150 ms |

Cost per sample at random points (each one far from the last, so branches miss often): value 31 ns,
Perlin 155 ns, simplex 117 ns, cellular 565 to 595 ns. In a coherent fill a Perlin octave costs about 39 ns
(the N9 fill: 1,310,720 octaves in 51.8 ms).

First-run notes: before the first run, N7's detail check was changed to divide each field's step change by
its own standard deviation, since 5 octaves averaged by their total amplitude change only about 1.15 times as
much as 1 octave in raw terms while being clearly rougher; N1 gained the raw Perlin check. No bar changed
after running. The N6 control shows the outer ring matters rarely (1 point in 20,000) but does matter.
