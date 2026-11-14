# Text and UI report

Branch: `cursor/ui-text-aaa-702c` (not merged, no PR opened).

## Commits

- Text library: `1b8c5bbafc50b0ab6ce5c46c65d01b258d273140`
- First UI kit and gallery: `b72ea3b7f86e41b726da57ff7f43cc0bf266c00d`
- Report SHA note: `e6ae72db`
- Vector text, theme materials, motion, contrast: `caae46bb20216f4bf55688a971d83116d687b042`

## What landed

| Piece | Size |
| --- | --- |
| `text` | 1898 lines |
| `uikit` | 1846 lines, including `vtext.amni` |
| Gallery | `hc/apps/gallery/gallery.amni` |
| Themes | 7 families × 5 variations = 35, signatures checked unique |
| Looks | 6 on each widget (filled, tonal, outline, ghost, elevated, sharp) |
| Type presets | 12 |
| Text effects | 10 |
| Fonts | Inter Regular/Medium/Bold/Italic/Bold Italic and JetBrains Mono, OFL, files in `hc/lib/uikit/fonts/` |

Existing `std` and `ui` names are unchanged. The bitmap font is only the retro theme.

## Tests

Compiled and run with `build/hc0` from the checked-in seed (native):

| Program | Result |
| --- | --- |
| `hc/test/text_aaa/core.amni` | 22 PASS |
| `hc/test/text_aaa/more.amni` | 29 PASS |
| `hc/test/uikit_aaa/logic.amni` | 41 PASS |

The UI run covers the earlier widget checks plus sibling overlap on the HUD scene, font load, `AV` kerning, a non-empty ligature list, table filter/pin/resize, the accessibility tree, a 35-theme contrast audit with zero failures, and one spring step.

## Screenshots

Headless PNGs at 2× from `hc/apps/gallery/gallery.amni` (software painter, no GPU). I opened each one.

- `docs/ui-gallery/themes.png` — 35 named buttons. Retro is the pixel font with scanlines. Brutalist has a hard offset shadow. Neon has stacked glow rings. Fantasy has a grain. Glass is a translucent pill with a top highlight; on this sheet the backdrop is flat, so the blur has little to show.
- `docs/ui-gallery/families.png` — the same form in all 35 themes. Glass blurs purple and gold bars behind the controls. Neon glow, fantasy grain, brutalist shadows, and retro scanlines are visible here.
- `docs/ui-gallery/buttons.png` — button, icon, fab, switch, check, radio, slider, six looks, Inter, soft elevation under the Material pills.
- `docs/ui-gallery/inputs.png` — field, area, select, combo, date, time (`15:42`), color bars, stepper.
- `docs/ui-gallery/overlays.png` — modal blurs a rectangle behind it, plus a highlight. Drawer, toast, tooltip, popover, message bar.
- `docs/ui-gallery/data.png` — table, virtual list, tabs (`All` / `Open`), accordion, tree, menu items, pagination `3 / 8`.
- `docs/ui-gallery/content.png` — badge, chip, avatar, card, breadcrumbs, rating, progress.
- `docs/ui-gallery/text.png` — presets from display through damage, italic sample, and the ten effects. Mono is JetBrains Mono.
- `docs/ui-gallery/hud.png` — health and mana on their own rows, then minimap, inventory, and radial, then dialogue. The last dialogue reads "The gate is open." Damage numbers sit on the next row. `overlap_count` is 0 for this scene.
- `docs/ui-gallery/motion.png` — eight frames. The button drops on a spring, a ripple disc grows, and the dialogue types on.

`docs/ui-contrast.md` lists every theme. Body ink against the page and the surface is at least 4.5:1. Accent versus on-accent is at least 3:1. Failures in that file: 0.

## Still below AAA

- Shaping stops at pair kerning and type-4 ligatures. Inter's `fi` / `fl` are contextual, so they do not ligate. No Arabic, no Indic, no mark positioning. The raster is coverage with four horizontal phases, not MSDF.
- Glass is a box blur of the framebuffer, not a live backdrop filter. Neon bloom is three expanded rectangles. Fantasy "9-slice" is corner brackets plus a hash grain, not a drawn stone or parchment tile. Ripple is a disc.
- Several widgets are still diagrams: the color picker is three bars, the radial menu is a few squares, the minimap is a dot on a rectangle, icons are block primitives.
- The data grid's filter, pin, and resize are tested and not drawn as chrome. The accessibility export is a text file, not a platform tree.
- Motion is a strip of eight frames, not a GIF, and nothing else animates.
- `ui.he` and `gfx/hud` were not re-rendered. No OS screen reader. Amni-Gen was not available, so no reference images were generated.
