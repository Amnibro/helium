# Text and UI report

Branch: `cursor/ui-text-aaa-702c` (not merged, no PR opened).

## Commits

- Text library: `1b8c5bbafc50b0ab6ce5c46c65d01b258d273140`
- UI kit, gallery, and these notes: the next commit on this branch (filled in after that commit lands).

## What landed

| Piece | Size |
| --- | --- |
| `text` | 1898 lines, 140 functions |
| `uikit` + gallery | 1397 lines, 150 functions in the kit |
| Themes | 7 families × 5 variations = 35, signatures checked unique |
| Looks | 6 on each widget (filled, tonal, outline, ghost, elevated, sharp) |
| Type presets | 12 |
| Text effects | 10 |

Existing `std` and `ui` names are unchanged.

## Tests

Compiled and run with `build/hc0` from the checked-in seed (native):

| Program | Result |
| --- | --- |
| `hc/test/text_aaa/core.amni` | 22 PASS |
| `hc/test/text_aaa/more.amni` | 29 PASS |
| `hc/test/uikit_aaa/logic.amni` | 30 PASS |

Covered: graphemes, NFC Hangul and `é`, case (ß, İ, final sigma), bidi Hebrew and mixed Latin, wrap, slug, truncate, interpolation, currency, date, time, rope, regex group, markdown spans, advance hook, 35 distinct themes, row layout, button, checkbox, slider, field undo, IME commit, table sort, virtual window, typewriter tick, damage float, breakpoint, role name.

## Screenshots

Headless PNGs from `hc/apps/gallery/gallery.amni` (software painter, no GPU):

- `docs/ui-gallery/themes.png` — 35 theme buttons
- `docs/ui-gallery/families.png` — the same form in all 35 themes
- `docs/ui-gallery/buttons.png` — button, icon, fab, switch, check, radio, slider, six looks
- `docs/ui-gallery/inputs.png` — field, area, select, combo, date, time, color, stepper
- `docs/ui-gallery/overlays.png` — modal, drawer, toast, tooltip, popover, message
- `docs/ui-gallery/data.png` — table, virtual list, tabs, accordion, tree, pagination
- `docs/ui-gallery/content.png` — badge, chip, avatar, card, breadcrumbs, rating, progress
- `docs/ui-gallery/text.png` — 12 presets and 10 effects
- `docs/ui-gallery/hud.png` — health, mana, minimap, inventory, radial, dialogue, damage numbers

## Not verified

- No GPU frame of `ui` or `gfx.hud`. `uikit` is headless on purpose.
- No OS screen reader and no contrast audit.
- Complex-script shaping was not run; there is no HarfBuzz.
- Amni-Gen was not available here, so no reference images were generated. Nothing from an image generator is shipped.
- CI on GitHub was not watched. `.github/workflows` has no push workflows, so the branch push does not start any.

The honest remaining gaps are in `docs/ui-text-gap-map.md`.
