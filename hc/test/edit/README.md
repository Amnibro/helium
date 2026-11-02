# edit: scene editor core

`edit` is the editor core behind the Helium scene editor: a scene document (entities with
name, parent, shape or light, translation, rotation, scale, colour), undo/redo with drag
coalescing, JSON save/load, ray picking, translate/rotate/scale gizmos with snapping, and
hierarchy world transforms. The editor app (`hc/apps/editor`) puts it on screen with `ui` panels
and a `gfx.scene3d` viewport.

## Pre-registered bars (committed before the first run; never loosened)

* **E1 save/load.** 200 random documents (1-300 entities; names with quotes, backslashes,
  control and non-ASCII bytes; random floats including -0.0, tiny and huge values): after
  save then load, every field of every entity is bit-identical, and saving the loaded document
  gives byte-identical text.
* **E2 undo/redo.** 50 sessions of 400 random operations (add, delete subtree, rename, move,
  rotate, scale, recolour, reparent; reparenting into its own subtree is refused): undoing
  everything gives the initial document's exact save text, redoing everything gives the final
  one's; after undoing k steps a new operation clears redo. 100 updates of one drag are one undo
  step.
* **E3 picking.** 20 random scenes (cubes, spheres, planes; random translation, rotation,
  non-uniform scale and parent chains), 100 random clicks each, against an independent
  reference that ray-marches inside-tests in 0.002-unit steps: at least 99 % of clicks agree,
  and every disagreeing click has a pixel within 1 px where the pick returns the reference's
  answer.
* **E4 gizmos.** 300 synthetic drags from random camera angles (axes within 10 degrees of the
  view direction are skipped, as gizmos hide them): the mouse is placed at the screen projection
  of the intended result. Translate (axis and plane) recovers the offset within 1e-3 units,
  rotate the angle within 1e-3 rad, scale the factor within 1e-3 relative. With snapping on,
  translation lands exactly on multiples of 0.25 and rotation exactly on multiples of 15 degrees.
* **E5 hierarchy.** World matrices of random 5-deep chains match an independent product of
  per-level T*R*S matrices within 1e-4; reparenting (keep-world, as in UE) leaves every moved
  entity's world translation within 1e-4 and world rotation within 1e-4 per matrix entry for
  rotation-and-uniform-scale chains.
* **E6 viewport.** A random scene rendered by `gfx.scene3d` from the editor camera, entities in
  six well-separated hues: at 400 random pixels at least 2 px from any silhouette (decided with
  the pick), the rendered pixel's nearest hue is the picked entity's hue, or the sky when the
  pick is empty, at **at least 98 %** of pixels.
