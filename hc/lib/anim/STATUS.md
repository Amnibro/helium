# Gap #5: clean-room Helium animation runtime. STATUS (newest first)

Owner: Anthony Reffelt · Lead: Kimahri · Review: **Lulu (accepted with items; items fixed; nothing pushed)**
Repo: Amnibro/helium, worktree `/workspace/helium-anim`, local branch `kimahri/anim-runtime` (cut from main c188cec).
**Local commits only, not pushed.** main and CI workflows are untouched.

## 2026-11-01 ~04:00 AST: delta review items fixed (local commits, not pushed)

Lulu's delta review of 2f71ddc7 / 7ac10db ("Delta review" in `/workspace/lulu_reviews/helium-anim/REVIEW.md`) was "accept with items, no blocker". Both MEDIUM items and all five LOW items are done.

**Commits on `kimahri/anim-runtime`** (author Amnibro):
- `ab16343f`: **D-M1 + D-L5.** Tangents are skinned on the CPU and GPU paths: xyz goes through the blended 3x3, is renormalized, and keeps w. Normals use the inverse-transpose: cof(A3)·n·sign(det), normalized. Shader output is 3 vec4 per vertex. The GPU-vs-CPU test checks tangents and puts a non-uniform scale on odd characters. Setup rejects more than 255 joints.
- `28b7958d`: **D-L2.** `gpuskin_bench.amni` fails loudly when spirv-val is missing (exit 1). `GSK_NO_SPIRV_VAL=1` skips it explicitly, logs SKIPPED and exits 3. It logs the spirv-val version and the exact command.
- `dc6eb742`: **D-L6.** The speed spring reaches 95% in **0.90 s** (ω 5.27, was 2.37 s). The walk→run band is widened to 1.8–4.2 m/s (was 2.6–3.4); see below.
- Next commit: **D-M2 + D-L3 + D-L4.** Adds `hc/test/anim/gpuskin_results_9060xt_2026-11-01.txt` (the raw Antman output, spirv-val log included) and deletes the stale 300-frame `gpuskin_results_2026-11-01.txt`, which showed the vulkan1.0 spirv-val failure. Also updates DESIGN.md and this file.

On `kimahri/jk-anim`, RESULTS.md is updated to match (separate commit).

**Correction.** The earlier entry said add2ab8d used ω 2.5. The code actually had ω 2.0 (95% in 2.37 s), which matches Lulu's 2.4 s.

**D-M1: tangent and normal test** (`anim_gpuskin`, 32 characters × 8 checkpoints, every vertex). Odd characters get a non-uniform scale diag(1.4, 0.7, 1.15).

| device | mesh | verts checked | max \|dp\| | max \|dn\| | max \|dt\| | max \|dw\| | max \|n'·t'\| | linear-3x3 control (scaled / unscaled) |
|---|---|---|---|---|---|---|---|---|
| box lavapipe | jk-h02 | 7,680,000 | 0 | 0 | 0 | 0 | 4.8e-7 | 0.991 / 0.9999 |
| box lavapipe | bfme-hr01 | 6,064,896 | 0 | 0 | 0 | 0 | 3.7e-7 | 0.9994 / 0.992 |
| RX 9060 XT | jk-h02 | 7,680,000 | 4.9e-7 m | 3.6e-6 | 7.0e-7 | 0 | 1.4e-6 | 0.992 / 0.9988 |
| RX 9060 XT | bfme-hr01 | 6,064,896 | 4.8e-7 m | 1.4e-6 | 1.3e-6 | 0 | 3.3e-7 | 0.999 / 0.988 |

- Tolerance is 1e-4 for the diffs and 1e-3 for n'·t'. All four runs PASS.
- lavapipe matches the CPU bit for bit, because it evaluates in the same order.
- The control is the plain linear 3x3 normal, and it must exceed tolerance. It trips even on unscaled characters, because a blend of rotations shears A3. So the inverse-transpose matters for every rig, not just scaled ones.

**D-M2: RX 9060 XT rerun.** File: `hc/test/anim/gpuskin_results_9060xt_2026-11-01.txt`, raw and unedited, timestamps in Antman's EST, 120 frames.
- Run: on Antman-PC in `~/kim7_gate`, synced to dc6eb742's hc/lib and tests. The hcn binary sha matches the box build.
- Command, run from `~/kim7_gate` (D = that directory): `HCN=$D/build/hcn HC_LIB=$D/hc/lib GSK_SHA=$D/glb.sha.abs timeout 600 nice -n 5 $D/build/hcn hc/test/anim/gpuskin_bench.amni -- $D/results_9060xt.txt 120 $D/glb/jk-h02.glb $D/glb/bfme-hr01.glb`.
- Headless and CLI only; about 6 s. Nothing was left running.
- spirv-val: SPIRV-Tools v2026.4, `--target-env vulkan1.1`, **OK**. GLB sha256 OK before and after. Both heroes PASS.

| mesh (32 chars) | anim tick | palette pack | GPU skin (timestamps) | submit+wait (worst) | frame (worst) | fps |
|---|---|---|---|---|---|---|
| jk-h02 (30000 verts) | 0.377 ms | 0.010 ms | **0.152 ms** | 0.228 (0.516) ms | **0.615 (1.21) ms** | ~1626 |
| bfme-hr01 (23691 verts) | 0.405 ms | 0.009 ms | **0.118 ms** | 0.191 (0.462) ms | **0.606 (0.889) ms** | ~1651 |

- GPU time roughly doubled against the pre-tangent shader (0.06–0.08 ms). The causes: 48 rather than 32 bytes out per vertex, plus the cofactor.
- Box comparison: CPU skinning of jk-h02 × 32 now takes 30.9 ms (was 20.4 ms; tangents and cofactor added). The anim tick is unchanged at 0.49 ms.

**D-L1: why the worst transition equals the old bound.** The action clips, the dodge above all, carry the most violent per-joint motion. Every transition tick has an action in its context, so for the joints that decide the verdict its threshold is max(loco, action), which is the all-states value. The per-state thresholds therefore tighten only loco-only ticks: the speed sweep and the speed changes, where they found the two real artifacts. This is noted in DESIGN.md and RESULTS.md.

**D-L6: spring.**
- Going faster than ω 2.0 with the old 0.8 m/s band failed: ω 2.1–5.9 passed between 0 and 36 of 39, and not monotonically in ω. The cause was the same as the old slew: braking from a run crossed the narrow walk/run band in about 0.1 s, which is a near-miss crossfade (forearm/hand rotation up to ~1.5×).
- Rejected: a two-stage C2 spring and smoothstep weights, both worse; bands of 2.2–3.8, 30/39.
- Bands of 2.0–4.0 and 1.8–4.2 pass 39/39. With 1.8–4.2, every ω from 4.74 to 6.5 (95% in 1.0–0.73 s) passes 39/39.
- **Chosen: ω 5.27, 95% in 0.90 s.**

**Pop test at dc6eb742** (39/39 PASS, GLB sha256 identical, anim_unit ALL PASS):

| scenario | ratio range over 39 files |
|---|---|
| speed sweep, no IK / IK | 0.768–0.904 / 0.794–0.899 |
| transitions + interrupts, no IK / IK | 0.833–0.986 / 0.834–0.985 (worst: jk-h02 forearm_l pos vs loco+act; equals the all-states reference, see D-L1) |
| CONTROL hard cut (fade 0) | 14.6–32.2 |
| CONTROL near miss (fade 0.1 s) | 2.06–5.57 |
| CONTROL unsmoothed speed steps | 12.8–21.4 |

The transition margin is now thinner: 0.986, against 0.950 before.

## 2026-11-01 03:27 AST: Lulu review items fixed (local commits, not pushed)

Lulu's review of 5724a716 / 3a73b35 was "accept with items, no blocker" (`/workspace/lulu_reviews/helium-anim/REVIEW.md`). All four MEDIUM items and the optional LOW item are done. 370293ad (GPU skinning) is still unreviewed.

**Commits on `kimahri/anim-runtime`** (author Amnibro):
- `8526dfac`: two-bone IK measures the current angles signed in the bend plane, so they stay continuous (fixes a one-frame pop, see below).
- `add2ab8d`: the gold speed follows a critically damped spring (C1) instead of a linear 8 m/s² slew. The code had ω 2.0, not the 2.5 written here; superseded by dc6eb742 (ω 5.27).
- `17fe23ed`: **M1 + M2.** The pop test uses per-scenario thresholds and a gated 0.1 s near-miss control (the fade-0 hard cut is kept). DESIGN.md is updated.
- `36002642`: **M4.** `hc/test/anim/gpuskin_bench.amni` (Helium, `os.run_command`) replaces the earlier shell harness, with the same steps. It was checked on the box and on Antman (spirv-val OK, both heroes PASS).
- `98ae7f40`: **L4.** `Acc` is renamed `Accessor` and `comp_size` is renamed `component_bytes`, with a glTF 2.0 §3.6.2 citation. eng/ was not read.

On `kimahri/jk-anim`: `7ac10db` covers **M3 + M4**. `anim_proof/run.amni` replaces the earlier shell runner: it runs the pop test on jk-h0*, does perf on h02/h02.lod2, and checks sha256 before and after. RESULTS.md now gives a plain coverage statement and the new numbers.

**Pop metric now.** Every tick is judged against 1.25 × the steady baseline of the states that fed its last 3 frames, plus the floor. The speed sweep is therefore judged against loco only, and a loco→act fade against max(loco, act). Action baselines stop before the exit transition. The old all-states ratio is still printed as a reference. Three controls are gated and must trip: hard cut (fade 0), near miss (all fades 0.1 s), and unsmoothed speed steps.

**Coverage, stated plainly.** There is one fixed script, and it is not randomized. The 39 files contain **8 distinct rigs** (5 BFME + 3 JK). The rest are copies:
- LOD copies (.lod1/.lod2), whose numbers are byte-identical to the base file.
- BFME .mobile variants, a reduced 37-joint skeleton of the same hero. Their sweep and transition numbers are identical to the base, but their control ratios differ.

The earlier note above, "full/lod/mobile identical", was wrong about mobile. In total that is 13 skeleton/clip combinations.

**Results** (39/39 PASS; GLB sha256 identical before and after; anim_unit ALL PASS):

| scenario | ratio range over 39 files |
|---|---|
| speed sweep, no IK / IK | 0.742–0.871 / 0.744–0.872 (superseded, see the ~04:00 entry) |
| transitions + interrupts, no IK / IK | 0.811–0.896 / 0.864–0.950 (worst: jk-h06 calf_r vs loco+act2) |
| CONTROL hard cut (fade 0) | 14.7–32.5 (must be ≥ 1) |
| CONTROL near miss (fade 0.1 s) | 2.09–5.60 |
| CONTROL unsmoothed speed steps | 12.8–21.4 |

**The stricter thresholds exposed two real artifacts** that the single all-states threshold had hidden. Both are fixed:
1. jk-h02, IK transitions: 3.9×, a one-frame thigh_l spike.
   - Cause: the "past straight" test compared 3D angles, which jumped as a locked, over-reached, near-straight knee swung across the pole plane.
   - Fix: projected signed angles (atan2 in the bend plane).
2. jk-h04, transitions: 2.0× on spine_03 during a 5→0 m/s stop.
   - Cause: the linear slew crossed the 0.8 m/s walk/run blend band in ~0.1 s, which acts like a near-miss cross-blend.
   - Fix: the critically damped speed spring.
   - Rejected: smoothstep blend weights (made it worse) and ω 3–4 (1.2–1.5×).

**Perf after the fixes**, box, jk-h02 × 32 characters: anim 0.49 ms/frame (unchanged); full-res CPU skinning 20.4 ms; lod2 5.7 ms. The Antman numbers quoted here (GPU skin 0.068 ms, frame 0.52 ms) were never committed as a file. They are superseded by the committed `gpuskin_results_9060xt_2026-11-01.txt` (~04:00 entry).

## 2026-11-01 03:13 AST: GPU skinning stage done (local commits, not pushed)

**Commits on `kimahri/anim-runtime`** (author Amnibro):
- `370293ad`: GPU linear-blend skinning. Adds `hc/lib/anim/gpuskin.he` (a self-contained Vulkan compute backend), `hc/lib/anim/skin.comp` (compiled by Helium's own `hcn --spv`), `glb_close()` in gltf.amni, the GPU-vs-CPU test (`hc/test/anim/anim_gpuskin.amni` + `gskin_body.amni`), a headless bench harness (now `hc/test/anim/gpuskin_bench.amni`), and a GPU section in DESIGN.md.
- `0d44474a`: the harness now validates the SPIR-V 1.3 shader as vulkan1.1; box and 9060 XT results were recorded in `gpuskin_results_2026-11-01.txt`. That file has been deleted and superseded by `gpuskin_results_9060xt_2026-11-01.txt`.
- A copy of this STATUS.md is committed as `hc/lib/anim/STATUS.md`, because /workspace/bfme is not a git repo.

**Design.** Standard LBS (v' = Σ w_k M_k v), written clean-room from the published formula and the Vulkan 1.0/1.1 spec struct layouts. DQS (Kavan 2007) is not done, because the CPU reference is LBS.
- The shader uses one thread per vertex per character. The palette is 3×4 rows per joint per character, and the command buffer is recorded once and resubmitted each frame. Two timestamp queries measure the GPU time.
- **It does not use `hc/lib/gfx`.** gfx runs on SDL3 GPU, which is not installed on the box, and its internals are off-limits. So the skinning code has its own shader, its own buffer layout (documented at the top of gpuskin.he) and its own Vulkan FFI. This makes it portable to Auron's clean-room gfx core.
- The adapter contract: 6 storage buffers at bindings 0..5, dispatch (ceil(nv/64), nchar, 1). `out` is created with STORAGE|VERTEX usage, so a renderer can bind it directly as the vertex buffer. In gfx public-API terms that is compute_pipeline + bind_storage_buffer ×6 + dispatch.

**Correctness.** All 32 characters, every vertex, at 8 checkpoints over 4 s of crowd motion, against CPU `skin_cpu`. Tolerance is 1e-4 m. All four runs PASS:

| Device | Mesh | max \|dp\| | max \|dn\| |
|---|---|---|---|
| lavapipe | jk-h02 (30000 verts) | 5.0e-7 m | 2.7e-7 |
| lavapipe | bfme-hr01 (23691 verts) | 4.9e-7 m | 2.7e-7 |
| 9060 XT | jk-h02 | 5.0e-7 m | 3.0e-7 |
| 9060 XT | bfme-hr01 | 6.4e-7 m | 2.7e-7 |

**Bench, superseded** by the ~04:00 entry (pre-tangent shader; 32 full-res characters, 300 frames, serialized frame = anim tick + palette pack + GPU submit/wait):

| Device | Mesh | anim | GPU skin (timestamps) | submit+wait | frame | fps |
|---|---|---|---|---|---|---|
| box lavapipe (CPU Vulkan, shared box) | jk-h02 | 0.58 ms | 11.2–13.9 ms | 11.7–14.3 ms | 12.3–14.9 ms | 67–81 |
| box lavapipe | bfme-hr01 | 0.58 ms | 8.7 ms | 9.2 ms | 9.8 ms | ~101 |
| **Antman RX 9060 XT (RADV GFX1200)** | jk-h02 | 0.36 ms | **0.077 ms** | 0.13 ms | **0.49 ms** | **~2034** |
| **Antman RX 9060 XT** | bfme-hr01 | 0.39 ms | **0.059 ms** | 0.18 ms | **0.58 ms** | **~1732** |

- For comparison, CPU skinning took 20.6–21.4 ms for jk-h02 and 18.8 ms for hr01.
- Antman was shared with other jobs during the run (load ~6, amni-browse and trellis-cli running).

**Antman run** (Shell via the registered machine Antman-PC; prior gates used ~/kim2..6_gate):
- Package in `~/kim7_gate`: static hcn, hc/lib, test files, and the 2 GLBs with sha256 checks.
- It ran CLI only with no window in ~4 s (300 frames). Today the same run is the Helium harness `gpuskin_bench.amni`; the command is in the ~04:00 entry.
- The GLB sha256 matched before and after, and nothing was left running.
- On the first run, spirv-val ran with target vulkan1.0 and failed because the shader is SPIR-V 1.3. It validates OK with vulkan1.1, and the harness is fixed. The rerun log is committed in `gpuskin_results_9060xt_2026-11-01.txt`.

**GLB integrity.** All 39 hero GLB checksums matched before and after every bench run (baseline /tmp/gsk taken 03:04 AST).
- Disclosure: one early read-only test run at about 03:00 happened before that baseline. BFME files are git-clean and JK mtimes are unchanged (2026-10-31 05:43).

**Helium gaps found**
1. **Address-space and mapping blow-up.** The runtime reserves 2 GB plus a guard per growable array. `json::Doc` holds 2 arrays per node, and a hero glTF has ~55k JSON nodes, so the process sits at `vm.max_map_count` (65531) after glb_open.
   - Effect: every later foreign `mmap` fails. The Vulkan loader printed "failed to map segment" for every driver (vkCreateInstance -9), and lavapipe segfaulted on submit.
   - Workaround: `glb_close()` drops the document before Vulkan init (~27k maps remain).
   - The real fix belongs in the runtime (smaller reservations or a pooled allocator) or in `json` (no per-node arrays).
2. `from_bytes<T[>..]>` expects Helium's serialized form, not raw bytes. GPU readback is decoded with `binary::read_f32le`.
3. There is no SDL3 on the box, so `hc/lib/gfx` can't be exercised there. This is why the backend is self-contained.
4. Helium's GLSL compiler emits SPIR-V 1.3, so the instance requests Vulkan 1.1.

**Not done / next**
- Dual-quaternion skinning.
- A vertex-shader draw path consuming `out`; it waits for Auron's gfx core.
- A gfx public-API adapter on Antman (SDL3 is present there).
- Async overlap of the anim tick with the GPU (the frame is currently serialized).


## 2026-11-01 02:58 AST: proofs complete, ready for Lulu review

### Commits (author Amnibro, newest first)
| hash | what |
|---|---|
| 5724a716 | DESIGN.md: sources, module docs, pop metric, perf, the hcn `--` gotcha |
| 6a982c85 | IK/gold/machine fixes: signed pole bend plane, stored-hinge pole, interrupt_min 0.45, extrapolation decay over 30% of the fade, exit_at timing |
| 59b22a10 | 32-character perf test (`hc/test/anim/anim_perf.amni`) |
| caa63169 | inertialized foot-lock release (Bollo) + C2 tanh soft reach |
| 94fa7728 | gold rig + joint-delta pop test |
| f12a4943 | GLB loader + skinning |
| 930b61a4 | core (pose, blend, additive, 1D/2D blend spaces, state machine, root motion, 2-bone IK, FABRIK) + unit tests |

JK: `/workspace/jk-anim`, local branch `kimahri/jk-anim` @ **3a73b35** (cut from auron/jk-helium-poc 0759773):
adds `apps/jedi-king-he/anim_proof/RESULTS.md` and the runner, now `anim_proof/run.amni`. Auron's branch is untouched.

### What's proven
- Unit tests (`hc/test/anim/anim_unit.amni`): ALL PASS.
- Gold angle: walk blends into run around 3 m/s (1D space: idle 0, walk at its natural speed up to 2.6, run 3.4 to 6.0, rate-matched; since dc6eb742 walk tops out at 1.8 and run starts at 4.2), with feet planted (2-bone IK + eased foot lock + inertialized release) on rolling ground.
- **(a) No pops:** the metric is the per-joint second difference in model space at 60 Hz. The threshold is 1.25 × the worst steady-state content value (loco + every action at every sample speed) + a floor of 0.5° / 2 mm. Ratio < 1 means PASS.
  - Why this threshold: a pop is a delta the clip content itself never produces.
  - Hard-cut and unsmoothed-step controls must trip, and they do, by 6–19×.
  - 39/39 GLBs PASS, with and without IK:

| hero (all variants) | worst ratio, sweep + transitions | weakest control |
|---|---|---|
| BFME hr01 ×6 | 0.833 | 7.98 |
| BFME hr02 ×6 | 0.801 | 7.56 |
| BFME hr03 ×6 | 0.854 | 7.74 |
| BFME hr04 ×6 | 0.800 | 7.34 |
| BFME hr05 ×6 | 0.800 | 6.07 |
| JK h02 ×3 | 0.884 | 7.29 |
| JK h04 ×3 | 0.992 (IK speed sweep, calf_r pos) | 6.25 |
| JK h06 ×3 | 0.824 | 7.65 |

  - Variants (full/lod/mobile) share skeleton and clips, so their numbers are identical: 8 distinct rigs in total.
  - BFME: 30 GLBs, 34 clips each (= 990 clips in total incl. variants); 65 joints, or 37 for mobile.
  - JK: 56/58/54 joints, 67 clips.
- **(b) 32 characters:** measured on the **box, not the target machine**: Intel Xeon, 8 vCPU, single-threaded, CPU only, llvmpipe/lavapipe (no real GPU).

| mesh | anim, 32 chars (blend + machine + additive + root + IK + palette) | + CPU LBS skinning |
|---|---|---|
| jk-h02 (30k verts) | 0.50 ms/frame | 20.6–21.4 ms → ~47–49 fps |
| jk-h02.lod2 (6k verts) | 0.49–0.51 ms | 4.3–5.0 ms → ~200–209 fps |
| bfme-hr01 (23.7k verts) | 0.53 ms | 18.8 ms → ~53 fps |
| bfme-hr01.mobile.lod2 (2.6k verts) | 0.42 ms | 2.5 ms → ~402 fps |

  - Animation for 32 characters uses ~3% of a 16.7 ms frame.
  - 60 fps at full res needs GPU skinning (the per-frame palette is already produced). That path was measured later on Anthony's RX 9060 XT: 0.15 ms GPU, 0.61 ms frame (see the ~04:00 entry).
  - On this box, 60 fps is met with lod1/lod2 meshes, not with full-res CPU skinning.

### Incident (disclosed)
- ~02:28 AST: a test run without `--` made hcn treat the GLB path as its output path, which overwrote GLBs.
- They were restored, and all 39 sha256 were re-verified against the pre-run hashes.
- After the final proof run, the 39 sha256 were re-checked: 0 mismatches.
- `hcn` gotcha: program args must follow `--`. This is documented in DESIGN.md and in the runners.

### Rejected / discarded attempts (noted, not committed)
- Capping action fades by clip length: made pops worse (ratios 1.05–1.6).
- smootherstep for extrapolation decay.
- SOFT_K 0.94 / 0.90: made hr02 worse.
- Storing the knee-frame forward direction for the pole.
- Hinge capture at bf > 0.05: broke JK h02, because the hyperextended idle knees captured the wrong side.
- SOFT_BAND residual: removed; it gave identical results.

### Helium gaps hit (worked around)
- No closures or function values: blend trees and machines are data-driven tables.
- One growable array per struct, and no heap or pointers: flat pools indexed by int.
- Root-file namespace limit: module-qualified helpers.
- Strict int/i32: explicit casts everywhere.
- No threads or SIMD: 32 characters run single-threaded. Skinning would benefit most.
- The hcn output-path foot-gun (above).

### What's left / blockers
- **Lulu review**: done (accept with items; items fixed in the 03:27 and ~04:00 entries). Nothing has left the branch.
- GPU skinning path and the RX 9060 XT measurement: done (see the 03:13 and ~04:00 entries).
- Lavapipe visual proof (screenshots/video of walk→run + planted feet): not done.
- In-client integration into the JK view/sim and the BFME arena: not done (JK `eng/` is off-limits under clean room).
- Nothing pushed. BFME GLBs (arena-wire) are read-only and unchanged. Rikku's contact.py is untouched.
