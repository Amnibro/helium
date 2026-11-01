# hc/lib/gfx: a 3D renderer for Helium

An original implementation, written for Helium from public specifications and
textbook formulas only: the glTF 2.0 specification, RFC 1950/1951 (zlib/deflate),
the PNG specification, ITU T.81 (baseline JPEG), the Cook-Torrance microfacet model
with the GGX/Trowbridge-Reitz distribution, Smith-Schlick masking and Schlick's
Fresnel approximation, a multiple-scattering energy compensation for the specular
lobe, cascaded shadow maps with PCF, hemisphere SSAO, and the extended Reinhard
tone curve (papers under [References](#references)). No code, shaders or constant
tables were taken from another engine; the one third-party function is `hash12` in
`shaders/ssao.frag`, David Hoskins' "Hash without Sine" (MIT, credited in the file
and in NOTICE). It sits on top of `hc/lib/gfx.he` (SDL3 GPU).

| module | what it does |
| --- | --- |
| `linalg` | vectors, quaternions, TRS compose, 4x4 inverse, look-at / perspective / ortho helpers |
| `zlib` | inflate (stored, fixed and dynamic Huffman blocks) |
| `codec_png` | PNG decode: all colour types and bit depths, palette + tRNS, Adam7 |
| `codec_jpeg` | baseline JPEG decode: Huffman, 4:4:4 / 4:2:2 / 4:2:0, restart markers |
| `gltf` | `.glb` / `.gltf` loader built on `json.he`: buffers (GLB, data URI, files), accessors incl. sparse and normalized ints, meshes and morph targets, materials (metal-rough, emissive strength, alpha modes, texture transforms), samplers, images, nodes, skins, animations |
| `motion` | animation sampling (step, linear, slerp, cubic spline), node hierarchy, joint palettes, morph weights |
| `shapes` | procedural sphere / plane / box assets in the same pools as glTF assets |
| `scene3d` (`s3d::`) | the frame: cascaded sun shadows, SSAO, MSAA forward shading with point lights and an analytic sky ambient, bloom, tone curve |
| `sparks` | GPU particles: compute-shader integration with drag, gravity and a bouncing ground plane; additive camera-facing quads |
| `sdf_font` | signed-distance-field text (glyphs generated at start-up), outline and weight |

## Using it

```
gfx::open_headless(w, h);            // or gfx::open
let a = gltf::load("ship.glb");       // asset index
let it = s3d::add(a);
s3d::place(it, gfx::translate(float3 { 0.0, 1.0, 0.0 }));
s3d::animate(it, gltf::find_animation(a, "idle"), t);
s3d::add_light(pos, rgb, range);
s3d::view = s3d::Camera { ... };    // also s3d::sun, s3d::sky, s3d::look
s3d::init(w, h);
s3d::render(target);                 // RGBA8 target; s3d::hdr_target() is the linear HDR image
```

The scene is plain data (`view`, `sun`, `sky`, `look`, `lights`, `items`) that the
caller edits between frames. After `gltf::reset()` call `s3d::forget()`.

### Motion vectors, TAA and upscaling

When temporal runs (or `s3d::motion_vectors = true`), the colour pass writes a
second target, `s3d::motion_target()` (RGBA16F, render size): xy is the screen
motion since last frame in uv units (this frame's uv minus last frame's, y down), z
the view depth, w coverage. Skinned meshes use last frame's joint palette; the sky
gives camera-rotation motion only. With both off the motion targets are neither
allocated nor drawn (they cost about 33 bytes a pixel: a 4x MSAA and a resolved
RGBA16F image).

```
s3d::temporal = 1;                   // jittered frames accumulated into a history
s3d::init(1280, 720, 1920, 1080);    // render size, output size: temporal upscaling
s3d::temporal_reset = true;          // after a camera cut
```

With `temporal = 1` the projection is offset each frame by a (2, 3) Halton sample
(`jitter_phases` long) and `shaders/temporal.frag` resolves into the history:
nearest-sample weighting, a YCoCg neighbourhood clip (`temporal_gamma` standard
deviations), motion from the nearest surface in 3x3, Catmull-Rom history fetch and a
blend that rises with motion (`temporal_blend`, `temporal_motion`, `temporal_max`).
Bloom and the tone curve run at the output size after it. Shadow cascades are fitted
to the unjittered view (`setup_cascades` uses only `view` and the render size), so
they do not move with the jitter; the look+taa test checks that.

## Where later features attach

* **Motion blur, reprojection for SSR/GI**: `motion_target()` already holds per-pixel
  motion and view depth at render size; the history (`resolved()`) is last frame's
  anti-aliased HDR image at output size.
* **GTAO, SH probes, SSR**: the AO prepass already writes view normals + depth
  (`nd`, `nd_depth`); a different AO kernel replaces `ssao.frag` only. The ambient
  term is a single function (`ambient_light()` in `surface.frag`) fed by `Sky`; probe
  irradiance (SH) or a prefiltered cube replaces it without touching the lights.
* **More cascades, point/spot shadows, PCSS, contact shadows**: `CASCADES` sizes
  the shadow array and `FrameU.cascade_mat`; `Light.kind` reserves spot lights;
  the shadow lookup is one function (`sun_visibility()` in `surface.frag`) where a
  blocker search (PCSS) or a screen-space contact ray can be added.
* **GPU (meshlet) culling**: `gather()` flattens items into `batch`, one record per
  primitive draw with its matrix, bounds centre and sort depth; a compute pass can
  consume that list and write indirect draws instead of the CPU loop in the passes.

## Shading notes

* Specular: GGX distribution `D(n.h)` times Smith-Schlick masking-shadowing
  `G(n.v, n.l)` (k = alpha / 2) times Schlick's Fresnel `F(v.h)`, over
  `4 n.l n.v + 1e-4`, with alpha = roughness^2 (Walter 2007, Schlick 1994, Karis 2013).
* Multiscatter: single-scatter GGX loses energy as roughness grows (64 % of a white
  rough metal at roughness 1). The specular lobe is scaled by
  `ms = 1 + F0 * (1 / max(E(mu, rough), 0.25) - 1)` (Kulla-Conty 2017, Turquin 2019),
  where `E` is the directional albedo of our own lobe with F = 1.
* Diffuse: Lambert times `(1 - metal)`, weighted per view direction by the energy the
  compensated specular lobe does not reflect, `kd = max(1 - ms * E_F(mu, rough), 0)`,
  where `E_F = F0 * (E - B) + B` is the Fresnel-weighted directional albedo and `B` the
  part of `E` carried by Schlick's `(1 - v.h)^5` term (the scale / bias split). This is
  the directional-albedo coupling described by Fdez-Aguera 2019; the form here was
  derived and implemented from that description for this lobe, not taken from code.
  It replaced the per-light `1 - F(v.h)` weight, which let rough dielectrics reflect
  up to 7 % more than they receive at grazing angles. The analytic sky ambient
  (`ambient_light`, its own roughness-damped Schlick weight that conserves energy in
  a uniform sky) is unchanged and does not use the table.
* `E` and `B` are one 32x32 table (`shaders/ms_lut.glsl`, rows roughness, columns
  sqrt(mu)) of 16-bit unorm pairs packed in a `uint` (`unpackUnorm2x16`), so the shader
  carries one 1024-entry constant array, as it did with `E` alone. It is generated by
  `hc/test/gfx/tools/make_ms_lut.amni`, which integrates the BRDF above numerically;
  regenerating it reproduces the file byte for byte (`gfxtest.sh` checks this):
  `HC_LIB=hc/lib build/hcn run hc/test/gfx/tools/make_ms_lut.amni > hc/lib/gfx/shaders/ms_lut.glsl`.
* The 0.25 floor on `E` caps `ms` at 4 for a white metal. The generator checks the
  grazing corner the GPU furnace cannot resolve (mu down to 0.00007, roughness 0.03
  to 0.3, a 4x finer grid than the table): for mu >= 0.01 every white-metal and
  white-dielectric albedo is within 2.6 % of 1; below mu 0.01 the largest gain is
  5.42 % (mu 0.0023, roughness 0.11, from bilinear interpolation of the table), so the
  floor never overshoots and was kept. Below mu of about 0.001 the `1e-4` guard in the
  denominator turns the lobe off (loss up to 82 %), which is a loss, not a boost.

## Tests

`tools/hc/gfxtest.sh build/hcn` builds `hc/test/gfx/gfx_smoke.amni` and runs:

1. **CPU checks** (math, inflate, PNG and JPEG decoding, the glTF loader, animation
   sampling, procedural shapes, SDF text layout), compared with `gfx_smoke.out`.
2. On a GPU, headless:
   * **Ambient pass-through / fp16 precision.** A white sky with the sun off must
     come back through the HDR target unchanged (bar 2 %). This only checks the
     ambient path and fp16 storage; it is not a furnace test.
   * **LUT check.** `make_ms_lut` is re-run and must reproduce `ms_lut.glsl` byte
     for byte, and its grazing-corner check (above) must print PASS.
   * **Sun-sweep furnace.** A grid of white spheres, roughness 0.0 to 1.0 in steps
     of 0.1 times metal {0, 1}, is lit by a sun swept over 4096 Fibonacci
     directions (sun radiance 4 pi / 4096, sky and ambient off) and the HDR frames
     are summed, so each pixel holds its directional albedo, ideally 1. Sky
     pixels and sphere edges (5x5 erosion of a mask frame) are excluded.
   * **Grazing furnace.** Flat white tiles, the same 11 roughness values times metal
     {0, 1}, each tilted so the camera sees it at n.v = 0.35, 0.2, 0.1 or 0.05
     (n.v per pixel is read back from debug view 8 and printed per tile), swept the
     same way with 4x the directions (16384): at n.v 0.05 the roughness 0.3 lobe is a
     thin sliver, and a CPU replay of the shader over the same directions gives
     +10.3 % at 4096, +1.4 % at 16384 and +0.9 % converged for the white metal.
   * Both furnaces run compensated and with four controls that must fail:
     compensation off, wrong F (F0 = 1 for dielectrics in the specular lobe), the
     older per-light `1 - F(v.h)` diffuse weight, and direct light x0.9. Gates for
     roughness >= 0.3: mean error per sphere or tile < 1.5 %, every pixel
     |albedo - 1| < 2.5 %. Roughness below 0.3 is reported as unresolved: the
     directional samples cannot integrate a lobe that narrow (the grazing corner
     there is covered by the LUT check).
   * **Sphere grid golden.** A 5x5 metal x roughness grid at 480x360 with shadows,
     SSAO and bloom off is compared with `hc/test/gfx/golden/spheres.png`; PSNR must
     be > 40 dB. A missing golden fails (`GFX_MAKE_GOLDEN=1` writes both goldens for
     review and still exits 1).
   * **Shipped-look golden.** The same grid with scene3d's default look (shadows, 3
     cascades at 2048^2, SSAO 16 samples, bloom 0.6) against
     `hc/test/gfx/golden/spheres_default.png` (> 40 dB, required; `GFX_MAKE_GOLDEN=default`
     writes only this one), with light/contrast bars; the effects-off image must fail
     against it (control).
   * **Full frame** (floor, skinned + morphed glTF, point light, particles, text) with
     the shipped look, sun and sky, checked for light and contrast. Before 2026-11-01
     this frame ran with shadows, SSAO and bloom off, left behind by the sphere test.
   * **Timing.** 1280x720 sphere grid, 30 warmup frames then 200 timed frames, each
     render + submit + fence wait with no readback: wall-clock min / median / p95,
     and GPU time from timestamp queries through the `tools/hc/gputime` Vulkan layer
     (`GPUTIME=0` turns it off). Timed three ways: shadows, SSAO and bloom off (the
     recorded baseline), the shipped look with TAA off, and the shipped look with TAA
     on.
   * **Motion vectors.** A moving sphere and a sliding camera are compared with a CPU
     projection (per-pixel error, sky, view depth), and a skinned animation step
     must move pixels while a repeated pose moves none.
   * **Jitter sign.** A sphere's coverage centroid (from the motion target) must move
     by minus the jitter offset in all 16 phases, within 0.1 px: input sample k sits
     at k + 0.5 + jitter, so the image shifts the other way.
   * **TAA.** 60 still frames must settle (frame-to-frame mean abs change over
     frames 30-59 below 0.5/255, sky excluded). A 40-frame camera slide is compared
     with a converged still frame at the final pose, once against the open sky
     (reported only: the disoccluded pixels there are sky, which the metrics leave
     out) and once against a wall behind the grid (gated). Gate: at most 0.5 % of
     pixels off by more than 24/255 and mean abs error at most 0.5/255; the same
     slide with the neighbourhood clip off is a control that must fail one of those
     and show at least 2x the mean error. The no-clip trails are wide but faint, so
     the >24/255 fraction alone does not separate them; these bars were set after
     the first wall run (see results/).
   * **Upscaling (TSR).** 1280x720 rendered, 1920x1080 out, PSNR (sky excluded) of at
     least 30 dB against native 1080p TAA. The native frame, the upscaled frame and
     the resolve alone (`s3d::temporal_repeat(1)` then `gfx::flush()`: one submit
     holding only the resolve) are each timed for 30 warmup + 200 iterations; the
     resolve's GPU p95 must be under 1 ms. This reuses the gputime layer on the real
     engine pass rather than a separate C harness, so a stand-alone bench was not
     kept.
   * **Shadows.** The sphere grid before a wall (960x540), direct light only
     (`debug_view = 5`), shadows off and on. A pixel is shadowed on the GPU when
     shadows on keep less than half its direct light. The reference casts a ray per
     pixel centre through the same camera into the exact spheres and boxes, then one
     toward the sun. Counted: pixels the sun lights with shadows off and whose hit
     faces the sun, outside a 2 px band around shadow and object edges. Gate: IoU of
     the two shadow masks >= 0.9 in the main cascade (the one with most counted
     pixels). Controls that must fail: shadows off, and the render's sun mirrored in
     x. The shadow pass is timed at 1280x720 (off vs on). `GFX_ONLY=shadows` runs
     only this check.
   * **Shipped look with TAA.** Over the 16 jitter phases the rasterising
     `view_proj` must change every frame and the cascade matrices never; the shadow
     mask of converged TAA frames must pass the same 0.9 IoU bar; the wall scene with
     the shipped look must settle (< 0.5/255) and stay within 2/255 mean of the
     TAA-off frame (bloom then reads the temporal result); 720p -> 1080p with the
     shipped look must settle and reach >= 30 dB against native 1080p TAA.

### Pre-registered bars (gfx-review2)

Each bar below was committed (code and this text) before the GPU run that measures
it, one commit per item, and is not loosened after the run. A failing result is
reported as a failure and fixed in the renderer, not in the gate.

* **T1 ghost gate** (`ghost_checks`, constants `GH_*`). Scene: 960x540, eye
  (0, 0, 7.5), fov 0.75; a 5x5 grid of bright unlit spheres (rgb 3, r 0.4, spacing
  1) before a dark unlit wall (front face at z = -3) carrying a blob texture.
  Motion of 25 px/frame (0.27336 world units at the grid's depth) for 16 frames,
  after 32 converged still frames: (a) the grid moves, camera still; (b) the camera
  slides, grid still. Reference: 48 converged TAA frames at the final pose.
  Scored only in the disoccluded band: pixels whose centre ray and 8 rays on a
  2 px circle all hit the wall at a point some sphere covered in an earlier frame
  of the move (CPU ray tracer, exact spheres). Error per pixel: the largest channel
  difference. Bars per case: mean <= 1.5/255, p99 <= 12/255, at most 300 pixels
  above 20/255. Controls, run with depth rejection off so that they test the clip
  and the reprojection: clip off (`temporal_gamma` 0), a very loose clip (gamma 4)
  and motion forced to zero (`temporal_motion_scale` 0) must each fail at least one
  bar in both cases. A synthetic 1 px trail, +30/255 added to the innermost ring of
  the band of the passing frame (about 3000 px), must fail. With rejection on the
  band mostly measures the depth rejection; the shipped clip is also reported with
  rejection off (not gated).
* **T1 ghost gate, shipped defaults.** Case (b) again with lit materials and
  scene3d's shipped look on (shadows, SSAO, bloom): the same three bars against 48
  converged frames at the final pose with the same look.

* **T4 motion and depth at silhouettes** (`silhouette_checks`, `T4_*`). The motion
  target is written by the single-sample prepass, so each pixel's motion and depth
  belong to the one surface under its sample point. In case (a) of the ghost scene
  (spheres at view depth 7.1-7.9 moving 25 px/frame before the wall at depth 10.5),
  every pixel of the motion target must hold either a sphere or the wall: pixels with
  depth strictly between 8.0 and 10.4 must number 0, and pixels whose motion is
  between 1 and 20 px must number 0. Control: the same target averaged over 2x2
  pixel blocks (what an averaging resolve does at an edge) must show at least 100
  such mixed pixels. `motion_checks` now requires each pixel's two depths (this
  frame's and last frame's view depth of the same point) to agree within 0.02 on a
  still scene.

* **T6 TAA gain.** On the still sphere grid, PSNR (sky excluded) against the 2x
  supersampled reference: TAA (60 frames) must beat TAA off (4x MSAA, no temporal
  pass) by at least 0.5 dB.

* **T7 resolve cost.** The 1280x720 -> 1920x1080 resolve alone, GPU time from the
  gputime layer, p95 over 200 iterations after 30 warmup: < 0.5 ms (was < 1 ms). The
  last recorded p95 was 0.253 ms (Lulu reproduced 0.2529 ms); 0.5 ms leaves about
  2x headroom for driver and clock variance and is 3 % of a 60 Hz frame (16.7 ms).
  If the GPU time is unavailable (no gputime layer, or the submits cannot be split
  per iteration) the check FAILS; it no longer passes silently. The p95 is taken
  from the sorted times.

* **T8 depth rejection** (`temporal_depth_reject`, default 0.1). The history alpha
  stores the view depth of each output pixel's surface. A pixel drops its history
  when the depth stored where its surface was last frame is nearer than that
  surface's own last-frame depth by more than 10 %, and no pixel of its 3x3 input
  neighbourhood was at that depth last frame (so a still silhouette under jitter is
  not rejected). Bars: on the still sphere grid with the shipped look, converged TAA
  frames with rejection on and off must agree within a mean abs of 0.25/255 (sky
  excluded); in both ghost cases the band's mean error with rejection on must not
  exceed its mean error with rejection off.

* **N3 grazing furnace replay** (`GZ_REPLAY_BAR`). gfx_smoke replays the shader on
  the CPU over the same 16384 Fibonacci sun directions, with the LUT parsed from
  `ms_lut.glsl` (`GFX_MS_LUT`, set by gfxtest; missing = FAIL), for up to 64 mask
  pixels of every grazing tile, each with its own camera ray, n and v. Bar: for
  every tile with roughness >= 0.3, |GPU tile mean - replay tile mean| < 0.5 % of
  the replay mean. This takes the direction undersampling out of the gate: the GPU
  must match what the shader formulas give for the same directions. The vs-1 bars
  (tile mean < 1.5 %, every pixel < 2.5 %) are kept and are re-justified by the
  replay's own vs-1 error, printed per tile.

* **N4 LUT convergence and the grazing cap** (`make_ms_lut`). The generator samples
  the half-vector polar angle with a graded mapping (u1 = 1 - (1 - s)^3) that
  crowds samples toward grazing half vectors. Check 0, new: every one of the 32 x 32
  stored (16-bit) nodes is compared with an independent integrator using a
  different scheme (theta_h through tan(theta_h) = alpha tan(pi s / 2), D written
  out, phi by a midpoint rule over the analytic valid interval only, 2048 x 48):
  E and the dielectric E_F within 0.25 % relative, B within 0.001 absolute.
  Check 2 now uses that integrator as truth, and the shader caps the metal gain at
  silhouettes: below sqrt(n.v) * 31 < 3 the compensation reads the largest E of the
  four bilinear corners (the diffuse weight keeps the bilinear E_F). Bars of check
  2: every gain and loss < 3 % for n.v >= 0.01 (unchanged), and gain < 3 % below
  0.01 (was 6 %); the loss there is reported.

Raw output of each recorded run is in `hc/test/gfx/results/`; `gfxtest.sh` writes
the header itself (commit, command, driver, GPU, packages) into `$GFX_OUT/results.txt`.
With no GPU it prints `SKIPPED (no GPU)` after the CPU checks (`GFX_REQUIRE_GPU=1`
makes that a failure). `GPU_LOCK=<file>` serializes the GPU part on shared
machines. `tools/hc/ci.sh` runs it only when `HELIUM_GFX_TEST=1`. The test binary
needs SDL3 even for the CPU part (see Known gaps).

### Temporal results (RX 9060 XT, RADV, Mesa 26.2.4; `results/2026-11-01_rx9060xt_radv_10e4813_taa.txt`, rebased on e0a080c)

| check | result | bar |
| --- | --- | --- |
| motion, moving object / sliding camera | 0.006 px / 0.005 px error, depth 3.5 (want 3.5) | |
| skinned step / repeated pose | 18574 of 18594 pixels move / 0 | |
| jitter sign | -jitter in 16/16 phases, worst 0.016 px | 16/16, < 0.1 px |
| still camera, frames 30-59 | max 0.075/255, mean 0.049/255 | < 0.5/255 |
| PSNR vs 2x supersampled | TAA 46.33 dB, no AA 45.33 dB | reported |
| slide on wall: clip on / no-clip control | 0.021 % >24/255, mean 0.305/255 / 0.06 %, mean 0.91/255 (3.0x) | <= 0.5 %, <= 0.5/255; control fails, >= 2x |
| slide on sky (reported) | 0.155 %, mean 0.875/255 / control 0.393 %, mean 1.958/255 | reported |
| 720p -> 1080p PSNR vs native 1080p TAA | 47.41 dB | >= 30 dB |
| resolve alone 720p -> 1080p, GPU | min 0.2353, median 0.2435, p95 0.2533 ms (wall median 0.3009) | p95 < 1 ms |
| 720p -> 1080p frame, GPU | median 0.5195 ms, p95 0.536 (wall median 0.6198) | reported |
| native 1080p TAA frame, GPU | median 1.2171 ms, p95 1.2559 (wall median 1.5865) | reported |

Image metrics count non-sky pixels only. The same run passes the furnace and grazing bars
(1.5 % / 2.5 %, controls failing) and the golden image (53.53 dB). The earlier runs at
8c351bc (before the rebase), 89a60db and 6713aa8 are kept in `results/`; the last two each failed only the ghost control, which led to the wall scene and
then to the mean-error gate.

### Shadow and shipped-look results (RX 9060 XT, RADV, Mesa 26.2.4; `results/2026-11-01_rx9060xt_radv_3fcea0b_shadowfix.txt`)

Shadow mask against the ray-traced reference, main cascade (cascade 2, 441405 counted
pixels, 44111 shadowed in the reference); earlier libraries were run with the same
test (`results/..._12652cf_shadow_before.txt`, `..._509c26c_shadow_layeronly.txt`):

| library | IoU | bar |
| --- | --- | --- |
| before (12652cf): all cascades in depth layer 0 | 0.0999 | >= 0.9 |
| layer fix only (509c26c) | 0.8343 | |
| layer fix + 1.5-texel normal offset (e4adf92 on) | 0.9952 | |
| same, TAA on (converged, 16 jitter phases) | 0.9952 | >= 0.9 |
| control: shadows off / sun mirrored in x | 0.0 / 0.2367 | must fail |

| check | result | bar |
| --- | --- | --- |
| cascades under jitter | view_proj jittered 16/16, cascade matrices change 0.0 | 16/16, 0 |
| shipped-look golden / effects-off control | 99.0 dB (golden taken in the same batch) / 27.98 dB | > 40 dB / must fail |
| wall scene, shipped look, TAA still | settle max 0.033/255, vs TAA off mean 0.269/255, 46.39 dB | < 0.5, <= 2 |
| 720p -> 1080p, shipped look | settle 0.048/255, 45.63 dB vs native 1080p TAA | < 0.5, >= 30 dB |

Timing, 1280x720, 30 warmup + 200 frames, GPU timestamps min / median / p95 (wall median):

| frame | GPU ms | wall median |
| --- | --- | --- |
| sphere grid, effects off (baseline) | 0.1524 / 0.159 / 0.162 | 0.2473 |
| sphere grid, shipped look, TAA off | 0.7247 / 0.7488 / 0.759 | 0.9314 |
| sphere grid, shipped look, TAA on | 0.9194 / 0.9509 / 0.9718 | 1.1467 |
| 720p -> 1080p TSR, shipped look | 1.1174 / 1.1569 / 1.1733 | 1.5978 |
| wall scene, shadows off / on (3 x 2048^2) | median 0.2159 / 0.5305 | 0.3062 / 0.6691 |

The old "1.21 ms at 720p" figure was a wall-clock mean over 20 frames with one
readback and broken shadows; the comparable number now is 0.93 ms wall (0.75 ms GPU)
for the shipped look with TAA off. The shadow fix itself costs nothing measurable
(wall scene, shadows on: GPU median 0.6198 ms on the old library vs 0.6239 ms fixed, both
in the e4adf92 batch, before the motion change). Between 12652cf and fc9f014 the motion target was always allocated and
drawn, which put the effects-off frame at 0.2295 ms (+44 %); it is now made only when
temporal runs or `motion_vectors` is set, and the frame is back at 0.159 ms.

### Furnace results (RX 9060 XT, roughness >= 0.3)

Spheres, 4096 directions (`results/2026-11-01_rx9060xt_radv_7ae7cce.txt`; before =
0302b74, which weighted diffuse by `1 - F(v.h)`):

| | worst material mean | mean over materials | worst pixel |
| --- | --- | --- | --- |
| before (0302b74), compensated | 2.61 % (dielectric, rough 1.0) | 0.63 % | 7.01 % gain, 2.7 % loss |
| now, compensated | 0.06 % | 0.04 % | 0.45 % (dielectric 0.1 %, metal 0.45 %) |
| control: compensation off | 64.25 % | 16.47 % | 69.32 % loss |
| control: wrong F | 98.27 % | 48.37 % | 98.59 % gain |
| control: legacy `1 - F(v.h)` | 2.61 % | 0.63 % | 7.01 % gain |
| control: x0.9 | 10.06 % | 10.04 % | 10.41 % loss |

Grazing tiles, 16384 directions:

| | worst tile mean | worst pixel |
| --- | --- | --- |
| now, compensated | 1.37 % (metal, rough 0.3, n.v 0.05) | 1.88 % (dielectric 0.46 %) |
| control: compensation off | 54.44 % | 54.48 % loss |
| control: wrong F | 97.52 % | 97.52 % gain |
| control: legacy `1 - F(v.h)` | 21.71 % | 22.04 % gain (dielectric, n.v 0.05) |
| control: x0.9 | 10.38 % | 10.39 % loss |

Every control fails on both furnaces. The bars (1.5 % mean, 2.5 % pixel) sit just
above the measured worst case, which is the one grazing tile the sweep still
undersamples; every other resolved sphere and tile is under 0.5 %. The ambient
pass-through mean error is 0.0106 % (max 0.0488 %).

## Provenance

* `sdf_font.amni` is Auron's own: glyphs defined as strokes in code, no font files.
  It was written for the earlier `hc/lib/gfx` (commit 0230ee4) and is byte-identical
  to the copy in d149bb5, where it was already listed as original; it was carried
  over unchanged.
* `shaders/ms_lut.glsl` is generated by `hc/test/gfx/tools/make_ms_lut.amni`.
* Test fixtures in `hc/test/gfx/fixtures/` were made by Auron for these tests
  (commit 44c323d), from synthetic pixels only, with no third-party imagery:
  * `scene.glb`: written by `make_scene.py` (Python; hc/TODO.md says why it is not
    ported to Helium).
  * `palette.png`: 37x23, 8-bit indexed, a 200-entry palette quantized from a
    colour ramp, tRNS alpha equal to the palette index, non-interlaced.
  * `photo420.jpg`: 61x45 baseline JFIF 1.01 with 4:2:0 chroma, 1458 bytes, made from
    a red/green ramp.

  The PNG and JPEG came from a one-off encoder script that was not kept (their
  headers match Pillow's defaults). They are committed as data; the test only needs
  their decoded checksums to stay the same.

## References

* B. Walter, S. Marschner, H. Li, K. Torrance, "Microfacet Models for Refraction
  through Rough Surfaces", EGSR 2007 (GGX distribution).
* C. Schlick, "An Inexpensive BRDF Model for Physically-based Rendering",
  Computer Graphics Forum 13(3), 1994 (Fresnel approximation, Smith-Schlick G).
* B. Smith, "Geometrical Shadowing of a Random Rough Surface", IEEE Trans.
  Antennas and Propagation, 1967 (masking-shadowing).
* E. Heitz, "Understanding the Masking-Shadowing Function in Microfacet-Based
  BRDFs", JCGT 3(2), 2014.
* B. Karis, "Real Shading in Unreal Engine 4", SIGGRAPH 2013 course notes
  (k = alpha / 2 for Smith-Schlick).
* E. Reinhard, M. Stark, P. Shirley, J. Ferwerda, "Photographic Tone Reproduction
  for Digital Images", SIGGRAPH 2002 (extended Reinhard curve).
* SSAO: M. Mittring, "Finding Next Gen: CryEngine 2", SIGGRAPH 2007 course;
  L. Bavoil, M. Sainz, "Screen Space Ambient Occlusion", NVIDIA 2008 (normal-
  oriented hemisphere kernel, the form used here).
* C. Kulla, A. Conty, "Revisiting Physically Based Shading at Imageworks",
  SIGGRAPH 2017 course (energy compensation).
* E. Turquin, "Practical Multiple Scattering Compensation for Microfacet Models",
  Industrial Light & Magic tech report, 2019.
* C. J. Fdez-Aguera, "A Multiple-Scattering Microfacet Model for Real-Time
  Image-Based Lighting", JCGT 8(1), 2019.
* D. Hoskins, "Hash without Sine", https://www.shadertoy.com/view/4djSRW, 2014
  (MIT; `hash12` in `ssao.frag`).

## Known gaps

No progressive JPEG, no point/line primitives (skipped and counted), Adler-32 is
not verified, ambient is an analytic sky (no image-based lighting yet), spot lights
are reserved but not shaded. Also:

* The furnaces do not resolve roughness below 0.3 (metal roughness 0 shows 12.75 %
  mean error on the spheres at 4096 directions); the LUT check covers the shading
  math there on the CPU, not the GPU.
* The rough 0.3 metal tile at n.v 0.05 is still 0.5 % above its converged value at
  16384 directions; the bars include that.
* Until 2026-11-01 (auron/gfx-shadowfix) sun shadows were wrong whenever they were
  on, not only in one run: `gfx::begin_pass` ignored the depth target's layer, so
  all three cascades were drawn into layer 0, each clearing the last, while
  `sun_visibility()` read each cascade's own layer (never written, or stale). The
  result was misplaced, slab-shaped shadows (shadow-mask IoU 0.10 against a
  ray-traced reference) or a sphere grid with no sun at all. A normal offset that
  grew as `0.02 (c+1)^2` (0.18 units in cascade 2, about 11 texels) also detached
  shadows from their casters. Both are fixed (IoU 0.995) and the shadow check
  above guards them. The effects-off sphere golden and timing baseline still run
  with shadows off; the shipped look has its own golden and timing.
* The golden was made on one GPU and driver; other GPUs are untested (hc/TODO.md,
  JK-M3).
* The CPU-only part of `gfx_smoke` still needs SDL3 installed: `gfx.he` declares its
  SDL3 functions in an `extern "libSDL3.so.0"` block that is loaded at start-up, and
  most gfx modules import `gfx`. Splitting that out is not a small change (hc/TODO.md).
* glTF data-URI and external-file buffers are implemented but not covered by a test
  fixture.
* TAA ghosting is measured on one slide (about 7 px/frame); fast rotation, thin
  geometry and disocclusion of high-contrast detail are not covered. Sky pixels are
  left out of every image metric, so ghosts over the sky are only reported.
* Motion vectors ignore morph-target changes (last frame's weights are not kept),
  and transparent (blended) surfaces write no motion, so the surface behind them is
  reprojected.
