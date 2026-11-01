# lib/gfx: scene renderer on top of `gfx`

A forward PBR scene layer over `gfx.he` (SDL3 GPU), written in Helium with
its shaders under `shaders/` (compiled by hc's `embed_shader`). Import the
pieces you need:

```
import gfx;          // the GPU API (lib/gfx.he)
import gfx.m3d;      // vectors, quaternions, matrices, sRGB helpers
import gfx.glb;      // glTF 2.0 binary loader (meshes, skins, morphs, clips, materials, images)
import gfx.anim;     // clip sampling and skinning palettes for glb scenes
import gfx.render;   // the renderer
import gfx.png;      // PNG decoder (zlib inflate); gfx.jpeg, gfx.image (either)
import gfx.half;     // f32 <-> f16
import gfx.sdf_font; // procedural SDF font for 2D text
```

Modules share one global namespace (no `ns::` prefix), like the rest of an
.amni program; their globals use upper-case prefixes (`GP`, `MATS_R`, `PT_*`,
`R_*`, `SDF_*`, ...).

## render

- Scene/material layer: `mesh_upload` (GVtx + indices + morph targets) gives a
  GPU primitive; `std_mat` / `pbr_mat` (base colour, roughness, metalness,
  ORM, occlusion and normal maps, alpha modes, double-sided) and `mat_add`
  give a material; per frame call `frame_begin`, then `add_item`,
  `add_ranged`, `add_skinned` or `add_morphed`, then
  `render_frame(target, w, h, is_window)`.
- Lighting: metallic-roughness BRDF, sun with cascaded shadow maps (`SUN`),
  up to 12 point lights (`PL_POS`, `PL_COL`, `PL_N`), image-based lighting
  from a cubemap (`env_generate`, `ENV`), sky box (`SKY`), rim light (`RIM`,
  material flag 1024), fog modes (`CAM.fog_*`).
- SSAO (`CAM.ao`): a normal/depth prepass, a hemisphere AO pass and a
  blur pass.
- HDR pipeline: MSAA (`CAM.msaa`), bloom over a down/up-sample chain (`CAM.bloom`),
  exposure, white balance, saturation, and an analytic hue-preserving filmic
  tonemap (`CAM.tonemap` 1 or 2; 0 = clamp). No LUT data.
- GPU particles: `pt_init`, `pt_emit(pos, dir, colour, kind, n)` (kind 0
  sparks with gravity, drag and floor bounce; 1 dust with drag, buoyancy and
  growth), `pt_step(n, seed)` per simulation step. Spawning and integration
  run in a compute shader; quads are vertex-pulled and drawn premultiplied in
  the HDR pass.
- Custom materials: `kind_add(VS_MESH, embed_shader("my.frag"), casts)`
  after `r_init()` registers a fragment shader built on
  `shaders/pbr_fs.glsl`; use the returned kind in `Mat.kind`. Built in:
  `K_STD` (0) and `K_OUTLINE` (1, inverted-hull outline).

## sdf_font

An original procedural signed-distance-field font: 95 printable ASCII glyphs
defined as vector strokes (segments, arcs, circles) in code, no font files.
`sdf_init()` bakes a 1024x512 atlas (48 px cells, 6 px spread, regular and
bold weights) on the CPU and uploads it; `sdf_bake(pix)` gives the RGBA
bytes without a GPU. Text is built into a `TextVtx` stream (pos, uv, rgba8):
`sdf_text(vs, x, y, px, text, colour, weight, outline)` appends glyph quads
(with a drop shadow) using proportional advances, `sdf_text_w(text, px)`
measures it, `sdf_rect` adds flat quads (uv.x < 0) to the same stream, and
`sdf_draw(target, w, h, vs)` draws it over a target in pixel coordinates
(y down, alpha-blended, no clear). Edges are anti-aliased with `fwidth`, so
text stays sharp from ~8 px to headline sizes; outline quads use uv.x >= 2.

/hc/gfxtest.sh build/hcn` (CPU checks plus one headless GPU frame;
`GPU_LOCK=<file>` serializes the GPU run on shared machines).

Origin: the Pomling Helium engine (`eng/`, commit cbd6348) as vendored and
extended in the Jedi-King Helium PoC (ORM/normal maps, 12 point lights, rim
light, analytic tonemap, GPU particles, SDF HUD font), made game-independent here.
