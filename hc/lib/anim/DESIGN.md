# hc/lib/anim — clean-room animation runtime for Helium

Status: under construction on the local branch `kimahri/anim-runtime`.

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
| Smoothstep crossfade weight | Hermite cubic 3t²−2t³ (C¹ at both ends) |
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
  (ground following, contact lock in world space with weighted release, pelvis
  drop).

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
