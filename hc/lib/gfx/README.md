# hc/lib/gfx: a 3D renderer for Helium

An original implementation, written for Helium from public specifications and
textbook formulas only: the glTF 2.0 specification, RFC 1950/1951 (zlib/deflate),
the PNG specification, ITU T.81 (baseline JPEG), the Cook-Torrance microfacet model
with the GGX/Trowbridge-Reitz distribution, Smith-Schlick masking and Schlick's
Fresnel approximation, cascaded shadow maps with PCF, hemisphere SSAO, and the
extended Reinhard tone curve. No code, shaders or constant tables were taken from
another engine. It sits on top of `hc/lib/gfx.he` (SDL3 GPU).

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

## Where later features attach

* **Velocity buffer, TAA/TSR**: every Item keeps `prev_place`, the frame keeps
  `prev_view_proj`, and `DrawU` already carries `prev_model`; a velocity target is
  one more colour attachment of the colour pass plus a jitter on `proj_mat` in
  `setup_view`.
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

## Tests

`tools/hc/gfxtest.sh build/hcn` builds `hc/test/gfx/gfx_smoke.amni`: CPU checks
(decoders, glTF, animation, shapes, text layout) against `gfx_smoke.out`, then on a
GPU a white-furnace test (energy error must stay under 2%), a 5x5 metal/roughness
sphere grid compared with `hc/test/gfx/golden/spheres.png` (PSNR >= 40 dB), a full
frame with every feature, and a 720p timing. `tools/hc/ci.sh` runs it only when
`HELIUM_GFX_TEST=1`.

## Known gaps

No progressive JPEG, no point/line primitives (skipped and counted), Adler-32 is
not verified, ambient is an analytic sky (no image-based lighting yet), spot lights
are reserved but not shaded.
