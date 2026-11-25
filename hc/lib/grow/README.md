# grow: organic shapes as short programs

`grow` builds plants, rocks, shells, fungi and corals as triangle meshes from a seed and a few
sizes, the way sand3d's organic verbs do, but natively in Helium. The same seed always gives
the same bytes, so a game can grow its props on the device from the world seed instead of
shipping models. Amni-CAD calls the same code through `--web` wasm.

```
import grow.grow
grow::clear(); grow::seed(7177)
grow::fern(double3 { 0.0, 0.0, 0.0 }, 0.7)
grow::glb("fern.glb")
```

Meshes are one vertex list: position, normal and color per vertex (`grow::P`, `grow::N`,
`grow::C`, three floats each) and `grow::I` (three vertex ids per triangle, counter-clockwise
seen from outside). Lengths are in meters, Y up.

## Verbs

| family | verbs |
|---|---|
| randomness | `seed` `rnd` `range` `vary` `noise` `fbm` `ridged` |
| building | `vert` `tri` `quad` `tube` `revolve` `sheet` `normals` `move` `spin` |
| placement | `phyllo` `scatter` `on_surface` |
| forms | `leaf` `blade` `tuft` `rock` `shell` `mushroom` `cactus` `tree` `pine` `bush` `fern` `flower` `coral` `brain_coral` `moss` `succulent` |
| output | `glb` `glb_bytes` `bounds` `open_edges` `volume` `stats` |

`grow::make(kind, seed, size)` builds any form by name, for tools and Amni-CAD.

## Pre-registered bars (committed before the first run; never loosened)

Each bar runs on every form with seeds 1, 7 and 7177. A control must fail for the bar to count.

* **G1 same seed, same mesh.** Building a form twice with one seed gives identical P, N, C and
  I (FNV-1a over the raw floats and ids). Control: seed 7 vs seed 7177 must differ.
* **G2 closed solids.** `rock`, `shell`, `mushroom`, `cactus`, `brain_coral` and a capped
  `tube` have zero open edges (every edge shared by exactly two triangles). Control: the same
  tube without caps has open edges.
* **G3 facing out.** Closed solids have positive signed volume and every normal is unit length
  within 1e-3 with no NaN. Control: the rock with its triangles flipped has negative volume.
* **G4 asked size.** The bounding box's largest side is within 15 % of the size asked for
  (rock, tree, pine, fern, shell, mushroom, cactus, coral, flower).
* **G5 phyllotaxis.** `phyllo` points step by 137.5078 degrees, and in a 377-point disc the
  ratio of the smallest to the largest nearest-neighbor distance is at least 0.47. Control:
  stepping by 90 degrees gives a ratio under 0.47.
* **G6 scatter spacing.** `scatter` keeps every pair at least the asked distance apart and
  places at least 70 % of the asked count when that count fits. Control: uniform random points
  break the spacing.
* **G7 branch thickness.** In `tree`, at every fork the squared radii of the children add up to
  the squared radius of the parent within 2 % (Leonardo's rule).
* **G8 GLB round trip.** `glb_bytes` loads back through `gfx.gltf::load_bytes` with the same
  vertex and index counts, and POSITION min/max equal `bounds`. Control: the bytes cut in half
  fail to load.
* **G9 phone budget.** Triangles per form: rock 2,700, shell 7,000, mushroom 4,700, cactus
  7,000, fern 7,700, flower 4,700, tuft 700, tree 27,000, pine 27,000, bush 17,000, coral
  17,000, brain_coral 7,000, moss 7,000, succulent 4,700.
* **G10 speed.** Every form at seed 7177 builds in under 20 ms on the PC (best of 3).

## Tests and pictures

`hc/test/grow/grow_test.amni` runs G1 to G10 (`tools/hc/ci.sh` step `grow`), and
`grow_test --glb kind seed size out.glb` writes one form. `hc/test/grow/grow_look.amni <dir>`
renders `lineup.png` (every form at seed 7177) and `glade.png` (a small woodland) through
`gfx.scene3d`; it runs on lavapipe as well as on a GPU.
