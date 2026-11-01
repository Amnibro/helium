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
| Two-bone IK | law of cosines (analytic triangle solve), current angles signed in the pole's bend plane, pole-vector twist about the root→target axis |
| Critically damped spring (speed smoothing) | closed-form solution x = target + (c₁ + c₂t)e^(−ωt) of x'' = ω²(target − x) − 2ωx' (standard second-order linear ODE, damping ratio 1) |
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
  skins, inverse bind matrices, meshes (POSITION/NORMAL/TANGENT/JOINTS_0/WEIGHTS_0),
  animation samplers LINEAR/STEP/CUBICSPLINE resampled to clips.
* `skin.amni` — skinning palette (model × IBM) and CPU linear-blend skinning
  of positions, normals and tangents (reference path; GPU skinning uploads
  the palette). See "Normals and tangents" under GPU skinning.
* `gold.amni` — the "gold" rig: loco 1D blend space (idle → walk → run;
  walk is stretched to 1.8 m/s, run starts at 4.2 m/s, so the walk→run blend
  is centred on 3 m/s and 2.4 m/s wide; rate-matched), two action states,
  additive layer, root motion, foot planting. The speed parameter follows the
  command through a critically damped spring (ω = 5.27 rad/s: 95% of a step
  in 0.90 s; C1 in time). Action fades are capped by clip length; exits are
  timed so the fade ends as the non-looping clip ends (a clip clamping on its
  last frame mid-fade pops); interrupting fades last ≥ 0.45 s and the frozen
  source's extrapolated velocity decays over the first 30% of the fade.

## Pop metric (hc/test/anim/anim_pop.amni)

Per joint, model space, 60 Hz. PASS/FAIL uses [A], the second difference
(acceleration per frame²) of rotation angle and position. Threshold per joint
= 1.25 × baseline + floor (0.5° rotation, 2 mm position).

Baselines are per state, not one for the whole rig: the worst [A] seen in
steady loco at every blend-space sample speed, and in each action state at
every sample speed (the action is entered directly and measured up to its
exit, not through it). Every scripted tick is judged against the states that
fed its last three output frames (current state, a live fade source, and the
states behind a frozen fade source): a loco-only tick against the loco
baseline, a loco→act fade against max(loco, act). So the speed sweep is
judged against locomotion alone, and a fast action clip cannot raise the
threshold for an upper-body pop in locomotion. (Before 2026-11-01 one
all-states baseline was used; with it the transition scenario scored
11–11.7× against a loco-only threshold, i.e. the threshold was inflated by
the action clips — review finding M1.) The old all-states ratio is still
printed as a reference line.

What the per-state thresholds do and do not tighten: in the gold rigs the
action clips (act, and especially act2, the dodge) contain the most violent
per-joint motion of any state. A transition tick always has an action in its
context mask, so its threshold is max(loco, action) — and for the joints
that decide the verdict that maximum is the action's value, i.e. the same as
the all-states baseline. That is why the worst transition ratio printed
equals the "all-states reference" line exactly (0.9497 = 0.9497 on jk-h06 in
the 2026-11-01 delta review; 0.986 = 0.986 on jk-h02 after the spring
retune). The per-state thresholds tighten the loco-only ticks — the speed
sweep and the speed changes inside the transition script, where they found
the two real artifacts below — not the action fades themselves. Tightening
those would need per-joint thresholds that follow the fade weights.

[V] (per-frame change) is printed for information. Scenarios: speed sweep
0→6→0 m/s, and a scripted run of state transitions and interrupts (including
speed steps 0→2→5→0 m/s), each with and without foot IK. Controls (each must
FAIL, i.e. ratio ≥ 1, or the test fails, proving the detector is sensitive):
hard cuts (every fade 0), near miss (every fade 0.1 s, a short but real
crossfade), and unsmoothed speed steps. The test covers one fixed script; it
is not randomized.

What the per-state thresholds found, and fixed:
* Two-bone IK sign test: the "knee past straight" test compared 3D angles,
  which jumped by 2·a0 and 2·(π − b0) when a near-straight animated knee
  swung sideways across the pole plane, a one-frame thigh/shin pop of up to
  36° [A] (jk-h02, locked foot with the leg over-reached). The current
  angles are now signed and measured in the bend plane (continuous).
* Speed command smoothing: the linear 8 m/s² slew started and stopped
  accelerating instantly; through the 0.8 m/s wide walk/run blend this was a
  ~0.1 s cross-blend of walk and run arm swing (up to 2.4× the loco
  threshold on a 5→0 m/s stop). The gold speed now follows a critically
  damped spring (x'' = ω²(target − x) − 2ωx', exact closed-form step), so
  the speed is C1. From rest a step reaches 95% at ωt = 4.744.
  - First fix (add2ab8d) was ω = 2.0 (95% in 2.37 s; the docs said 2.5),
    which was sluggish. Faster springs with the 0.8 m/s band failed the
    test for the same reason as the slew (ω 2.1–6: 0–36/39 pass, not
    monotonic in ω; the failures were forearm/hand rotation pops while braking 5→0 m/s, up to ~1.5×).
    A two-stage (C2) spring and smoothstep blend weights both made it worse:
    the pop scales with how fast the blend weight moves, not with the speed
    acceleration.
  - Fix: the walk→run band is widened to 1.8–4.2 m/s (still centred on
    3 m/s), so braking from a run crosses it in ~0.3 s. With it ω 4.74–6.5
    (95% in 1.0–0.73 s) all pass 39/39; ω = 5.27 (0.90 s, peak 9.7 m/s² on
    a 5 m/s step) is used. Walk is also stretched less (to 1.8 m/s, was
    2.6).

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
* Normals and tangents. Per vertex both paths form the blended 3x4
  A = Σ w_k M_k (rows r0, r1, r2) and output p' = A p,
  t' = normalize(A3 t.xyz) with the glTF handedness t.w kept, and
  n' = normalize(cof(A3) n · sign det A3), where cof(A3) = det(A3) · A3^-T
  has rows r1×r2, r2×r0, r0×r1 (the inverse-transpose up to scale, no
  division). So n' stays perpendicular to t' (and to the surface) under
  non-uniform joint scale — and also under the shear that blending two
  rotations produces, where the plain linear 3x3 is off as well. Both are
  unit length (a degenerate vector gives 0, not NaN). Meshes without
  TANGENT get (1,0,0,1).
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
  motion, every vertex vs `skin_cpu`: position, normal, tangent xyz and w;
  tolerance 1e-4 m (positions) and 1e-4 (unit normal/tangent). Odd
  characters get a non-uniform scale diag(1.4, 0.7, 1.15) on their palette;
  for every vertex whose rest normal and tangent are perpendicular the GPU
  n'·t' must stay < 1e-3, and a control (the linear 3x3 normal on the same
  palette) must exceed it. jk-h02 and bfme-hr01: lavapipe max |dp|, |dn|,
  |dt| 0 (bit-identical), 9060 XT max |dp| 4.9e-7 m, |dn| 3.6e-6,
  |dt| 1.3e-6; |n'·t'| ≤ 1.4e-6; the control reaches 0.99.
* Bench harness (Helium): `HC_LIB=<repo>/hc/lib build/hcn
  hc/test/anim/gpuskin_bench.amni -- <results.txt> <frames> <hero.glb>...`
  builds the shader and test binary, runs each hero headless and writes a
  text report (optional `GSK_SHA` checks the GLBs before and after,
  `GSK_DEVICE` picks a GPU, `HCN` overrides the compiler path). The shader
  is validated with `spirv-val --target-env vulkan1.1` (hcn emits SPIR-V
  1.3); the version and command line are logged. spirv-val missing or
  failing exits 1; `GSK_NO_SPIRV_VAL=1` runs without it, logs
  "spirv-val: SKIPPED" and exits 3. Child tools
  run through `os.run_command` with output redirected to a private work dir
  that is removed at the end.

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
