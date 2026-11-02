# hud: retained game UI (UMG-style)

`gfx.hud` is a retained widget tree for game screens: flexbox layout (CSS subset), canvas-style
anchored children (absolute positioning), panels with radius and border, text and rich text
runs, directional focus navigation for gamepads, tweens, and string tables.

## Pre-registered bars (committed before the first run; never loosened)

* **U1 flex layout vs Chrome.** 300 random trees (seeded generator `hc/test/hud/gen.py`), depth
  <= 3, <= 5 children per node. Per node: flex-direction row or column; justify-content start,
  end, center, space-between, space-around, space-evenly; align-items start, end, center, stretch;
  gap 0-12 px; padding 0-10 px; margin 0-8 px; width and height each auto, 10-200 px or 10-100 %;
  flex-grow 0-3; flex-shrink 0-2; flex-basis auto or 0-150 px; min/max width/height none or px;
  box-sizing border-box; min-width/min-height 0 unless set; no wrap, no auto margins, no text.
  About one child in six is absolutely positioned (left/top px with width/height px, or left
  and right px with height px). Reference: chrome-headless-shell `getBoundingClientRect`. Bar:
  **every** node of **every** tree within **0.5 px** on x, y, width and height.
* **U2 focus navigation.** A 4 x 3 button grid and an irregular 7-button layout with expected
  moves written down before the run: every d-pad move lands on the expected button; moves off the
  edge stay put.
* **U3 tweens.** Linear, ease-in/out quad and cubic, back and elastic-out sampled at 101 points
  match their formulas within 1e-6; a tween reaches its exact end value at its duration and a
  chained tween starts from it.
* **U4 rich text.** `<b>`, `<color=#rrggbb>`, `<size=n>` and nesting parse into the expected
  runs; wrapping at a width never yields a line wider than it unless the line is a single word,
  and never splits a word.
* **U5 string tables.** Lookup falls back from locale to base language to the key wrapped in
  brackets; `{0}`, `{name}` arguments substitute; `{{` and `}}` escape.
* **U6 rendering.** A rendered test screen: the centre pixel of every panel equals its colour
  within 1/255; a pixel 1 px outside a rounded corner (inside the bounding box) shows the
  background; the panel's border pixels show the border colour within 1/255.
