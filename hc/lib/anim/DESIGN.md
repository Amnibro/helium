# hc/lib/anim — clean-room animation runtime for Helium

Status: local branch `kimahri/anim-runtime` (not pushed, not merged). Proven headless on the Jedi-King and BFME r5B hero GLBs; see "Proof" below.

## Clean-room notice

All code here was written from scratch using published math and public file
format specs only. No code was copied, ported, translated or paraphrased from
Bevy (`bevy_animation`), the Pomling `eng/` modules (Bevy lineage), Unreal,
Unity, Godot, ozz-animation, or any other engine, and those sources were not
consulted for implementation.

Sources used:

| Area | Source |
|---|---|
| Quaternion algebra, slerp | K. Shoemake, "Animating Rotation with Quaternion Curves", SIGGRAPH 1985 |
| nlerp / normalized weighted quaternion sum, hemisphere alignment | standard linear-algebra treatment (sum of sign-aligned unit quaternions, renormalized); e.g. Markley et al., "Averaging Quaternions", J. Guidance 2007 for the averaging rationale |
| Shortest-arc rotation between vectors | half-angle construction from the cross/dot product (textbook) |
| 2D blend space triangulation | A. Bowyer, "Computing Dirichlet tessellations", Comput. J. 1981; D. F. Watson, "Computing the n-dimensional Delaunay tessellation…", Comput. J. 1981 (Bowyer–Watson) |
| Barycentric weights, nearest-edge projection | textbook planar geometry |
| Smoothstep / smootherstep weights | Hermite cubic 3t²−2t³; quintic 6t⁵−15t⁴+10t³ (K. Perlin, "Improving Noise", SIGGRAPH 2002), C² at both ends — used for crossfades, lock engage and IK blend weights |
| Inertialization (foot-lock release) | D. Bollo, "Inertialization: High-Performance Animation Transitions in Gears of War", GDC 2016 — quintic offset decay matching x0, v0 with zero end conditions; T shortened to |5x0/v0| when x0·v0<0 (overshoot guard) |
| Soft reach (two-bone IK) | own construction: d' = s + w·tanh((d−s)/w), s = 0.97·reach, w = reach−s (C² at s, monotone, < reach) |
| Two-bone IK | law of cosines (analytic triangle solve), pole-vector twist about the root→target axis |
| FABRIK | A. Aristidou, J. Lasenby, "FABRIK: A fast, iterative solver for the Inverse Kinematics problem", Graphical Models 73(5), 2011 |
| glTF loading | Khronos glTF 2.0 specification (GLB container, accessors, skins, animation samplers LINEAR/STEP/CUBICSPLINE) |

## Modules

* `math.amni` — quaternions (mul, conj, rotate, axis-angle, from-to, angle,
  nlerp, slerp), `Xf` (TRS transform), column-major `M4`, smoothstep.
* `pose.amni` — `Skeleton` (parent-before-child, ≤128 joints), `Pose`
  (local TRS), `Model` (character-space), FK, `blend2`, the n-way `Accum`
  (normalized weights, sign-aligned quaternion sum), additive deltas
  (`make_additive`/`apply_additive` with per-bone `Mask`), override layers,
  `mask_branch`.
* `clip.amni` — clips resampled to a uniform frame rate in global key pools
  (`CLIPS`, `KT`, `KR`, `KS`), sampling, additive clips, root motion
  (root joint XZ: per-tick delta across loop wraps, in-place pose, natural
  speed).
* `space.amni` — 1D (sorted, piecewise linear) and 2D (Delaunay + barycentric,
  clamped to the hull) blend spaces; optional rate matching.
* `machine.amni` — motions (clip or blend space, phase-synchronized by
  normalized phase with duration Σwᵢ·durᵢ), a state machine (float/bool/trigger
  params, ≤2 ANDed conditions, exit times, any-state transitions, triggers
  consumed on fire), smoothstep crossfades, phase sync across transitions,
  interruption by freezing the on-screen pose (and its root velocity) as the
  new source — so a fade can never jump.
* `ik.amni` — analytic two-bone IK with pole, FABRIK chains, and foot planting
  (ground following, contact lock in world space, pelvis drop). Details:
  - knee solved on the C² soft-reach map (acos has unbounded slope at full
    extension; a hard clamp turns millimetres of target motion into pops);
  - bend plane from the pole, with signed angles, so a knee animated through
    straight (JK idles are hyperextended ~5%) does not flip sides;
  - the pole comes from a hinge axis stored in the thigh frame, refreshed
    while the knee is clearly bent (>15% offset), blended (smootherstep) with
    the live bend direction — stable through straight legs;
  - lock engage eased (lock_rate 8/s, smootherstep weight); release by
    Bollo inertialization over release_t = 0.3 s; always solves (switching
    the solver on/off would toggle the soft-reach change).
* `gltf.amni` — GLB/glTF 2.0 loader written from the Khronos spec: nodes,
  skins, inverse bind matrices, meshes (POSITION/NORMAL/JOINTS_0/WEIGHTS_0),
  animation samplers LINEAR/STEP/CUBICSPLINE resampled to clips.
* `skin.amni` — skinning palette (model × IBM) and CPU linear-blend skinning
  (reference path; GPU skinning uploads the palette).
* `gold.amni` — the "gold" rig: loco 1D blend space (idle → walk → run;
  walk is stretched to 2.6 m/s, run starts at 3.4 m/s, so the walk→run blend
  is centred on 3 m/s; rate-matched), two action states, additive layer, root
  motion, foot planting. Action fades are capped by clip length; exits are
  timed so the fade ends as the non-looping clip ends (a clip clamping on its
  last frame mid-fade pops); interrupting fades last ≥ 0.45 s and the frozen
  source's extrapolated velocity decays over the first 30% of the fade.

## Pop metric (hc/test/anim/anim_pop.amni)

Per joint, model space, 60 Hz. PASS/FAIL uses [A], the second difference
(acceleration per frame²) of rotation angle and position. Threshold per joint
= 1.25 × baseline + floor (0.5° rotation, 2 mm position), where the baseline
is the worst [A] seen in steady states (loco at every sample speed, plus each
action at every sample speed) — i.e. "no worse than the animation content
itself". [V] (per-frame change) is printed for information. Scenarios: speed
sweep 0→6→0 m/s, and a scripted run of state transitions and interrupts, each
with and without foot IK. Controls (must FAIL, proving the detector is
sensitive): hard cuts (fade 0) and unsmoothed speed steps.

## Perf (hc/test/anim/anim_perf.amni)

`hcn anim_perf.amni -- <glb> [frames]`: 32 characters, phase-shifted crowd
script, full anim (blend space + machine + additive + root + IK + palette)
per frame, plus CPU LBS skinning timed separately.

## GPU skinning (gpuskin.he + skin.comp, test hc/test/anim/anim_gpuskin.amni)

Linear blend skinning on the GPU: v' = sum_k w_k M_k v, where M_k is the joint
palette matrix (model * inverseBind), the standard LBS formula
(Magnenat-Thalmann et al. 1988). Dual-quaternion skinning (Kavan et al. 2007)
is not implemented; the CPU reference is LBS, so the GPU path is LBS too.

* `skin.comp`: GLSL 450 compute shader, 64 threads per group, one thread per
  vertex per character; dispatch (ceil(nv/64), nchar, 1). Compiled by
  Helium's own GLSL->SPIR-V compiler: `hcn --spv skin.comp skin.spv`.
* Palette is uploaded as the top three rows of each 4x4 (12 floats per joint
  per character); the CPU anim tick packs it straight from `Palette.m`.
* Normals are blended without renormalizing, as `skin_cpu` does, so the two
  paths compare exactly; a renderer normalizes in its vertex/fragment shader.
* `gpuskin.he` is a self-contained Vulkan 1.0 compute backend written from
  the Vulkan spec struct layouts (own `extern "libvulkan.so.1?"` block). It
  does **not** use `hc/lib/gfx`: gfx sits on SDL3 GPU (not installed on the
  box) and its internals are Bevy-lineage and off-limits. Porting to the
  clean-room gfx core (gap #1) is a small adapter: create the six storage
  buffers in the layout documented at the top of `gpuskin.he`, bind them at
  bindings 0..5 of one set, dispatch `skin.comp`, then bind `out` as the
  vertex buffer (it is created with STORAGE|VERTEX|TRANSFER_SRC usage). In
  gfx public-API terms that is `compute_pipeline` + `bind_storage_buffer` x6
  + `dispatch`.
* The skinning command buffer is recorded once and resubmitted each frame;
  two timestamp queries give the GPU time. Device pick: discrete > integrated
  > virtual > cpu, or an explicit physical-device index.
* Correctness (anim_gpuskin): 32 characters, 8 checkpoints over 4 s of crowd
  motion, every vertex vs `skin_cpu`; tolerance 1e-4 m (positions) and 1e-4
  (normals). Measured on lavapipe: max |dp| 5.0e-7 m, max |dn| 2.7e-7.
* Bench harness: `hc/test/anim/gpuskin_bench.sh <results.txt> <frames>
  <hero.glb>...` builds the shader and test binary, runs each hero headless
  and writes a text report (optional `GSK_SHA` checks the GLBs before and
  after, `GSK_DEVICE` picks a GPU).

## Running

`HC_LIB=<repo>/hc/lib build/hcn hc/test/anim/anim_pop.amni -- <file.glb>`.
Program arguments MUST follow `--`: a bare positional argument after the
source file is taken as hcn's OUTPUT path and is overwritten.

## Helium constraints and how they were handled

* No function values / closures: the blend graph is data (`Motion` kinds,
  transition tables with op codes) evaluated by one interpreter function,
  instead of node callbacks.
* One growable array per struct (and it must be last): clip keys live in
  global pools (`var KT float3[>..]`) indexed by `Clip.base`; per-object
  arrays are fixed-size (`MAXJ = 128`, `SPACE_MAX = 16`, 16 states, 48
  transitions).
* No heap/pointers: poses are value structs passed by `&`; callers own scratch
  poses (`machine_update(..., scratch, scratch2, acc)`).
* A root `.amni` file with `fn main()` cannot share a namespace, so tests keep
  their body in a namespaced module (`hc/test/anim/unit_body.amni`).
* Overloads are strict about `int` vs `i32`; clip handles are `int` at the API.
* No threads/SIMD in the language surface used here: perf numbers are
  single-threaded scalar.
* `hcn` treats a positional argument after the source as the output path
  (foot-gun; see Running).
* `json::Doc` holds two growable arrays per node and the runtime maps a
  separate 2 GB reservation (plus guard) for each, so parsing a hero GLB's
  JSON (~55k nodes) pins the process at `vm.max_map_count` (65531). Any later
  `mmap` from a foreign library then fails: the Vulkan loader reports "failed
  to map segment from shared object" for every driver. `glb_close()` drops
  the document once the skeleton, clips and meshes are extracted (back to
  ~27k mappings), and the GPU test calls it before touching Vulkan.
* `from_bytes<f32[>..]>` expects Helium's own serialized form, not raw bytes;
  raw GPU readbacks are decoded with `binary::read_f32le`.
