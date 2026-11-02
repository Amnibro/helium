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

## Results (2026-11-02, RX 9060 XT for U6)

| Bar | Result |
| --- | --- |
| U1 | **PASS**: 300 trees, 9082 nodes, 0 off by more than 0.5 px, worst 0.025 px |
| U2 | **PASS**: every grid and irregular-layout move as written down |
| U3 | **PASS**: worst easing error 6.7e-16; end value exactly 37.5; chained tween 23.75 at half, exactly 10 at the end |
| U4 | **PASS**: runs as expected; 1277 wrapped lines over 200 trials, 0 too wide, 0 split words |
| U5 | **PASS**: fr-CA → fr → `[key]`, `{name}`/`{0}`, `{{`/`}}` |
| U6 | **PASS**: centres, outside-corner pixels and all four border sides within 1/255 |

Honest notes:

* U1 was developed against the seed-7 fixture: the first run had 4872 nodes off, and the layout
  was fixed (never the bar) until 0. Rules found on the way: shrink is scaled by the inner
  (content-box) flex base size; an item's intrinsic main contribution uses flex-basis, clamped
  toward its content size only in the direction it can flex; stretch applies only when the cross
  size property is `auto` and makes the item's cross size definite; a definite flex-basis makes
  a column item's height definite for percentage children.
* Because of that tuning, three **held-out** seeds were checked afterwards (post-hoc, not part of
  the bar): seeds 11, 23 and 1234, 300 trees each (8776, 9584, 9124 nodes), **0** nodes off by more
  than 0.5 px, worst 0.029 px.
* U4's first run failed on a real bug (`<color=#rrggbb>` tag length off by one); fixed in the
  parser.
* The fixture is committed gzipped (`trees.txt.gz`) so CI does not need Chrome; regenerate with
  `python3 hc/test/hud/gen.py OUT 300 7`.

## API

`hud::node(parent)` adds a widget and returns its id; set fields on `hud::N[id]` (`dir`, `jus`,
`ali`, `gap`, `pd`, `mar`, `wm`/`wv`, `hm`/`hv` with `AUTO`/`PX`/`PCT`, `grow`, `shrink`, `basis`,
`minw`/`maxw`/`minh`/`maxh`, `abs` with `l`/`t`/`r`, `color`, `border`, `bw`, `radius`,
`focusable`, `visible`, and the tweenable `ox`, `oy`, `opacity`, `scale`). `layout_root(id, x, y,
w, h)` lays out the tree; `nav(id, LEFT|UP|RIGHT|DOWN)` returns the next focus; `tween(id, P_X|
P_Y|P_OPACITY|P_SCALE, to, secs, ease)` and `then(tween, to, secs, ease)` animate, advanced by
`tick(dt)`; `set_text(id, rich)` attaches rich text (`<b>`, `<color=#rrggbb>`, `<size=n>`);
`put_string(locale, key, text)`, `set_locale`, `tr(key, names, values)` localize; `draw(target,
w, h, clear, bg)` renders panels (SDF rounded rectangles with border) and text.
