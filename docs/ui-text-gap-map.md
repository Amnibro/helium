# Helium text and UI: gap map

Branch `cursor/ui-text-aaa-702c`. This note is the inventory of what Helium had, what this branch adds, and where that now sits against current UI kits and text stacks. Sources were read on 13 Nov 2026.

## What was already in the tree

| Area | Where | What it actually covers |
| --- | --- | --- |
| Byte strings | `hc/lib/std.he` | ASCII case, trim, split, join, find, replace, pad, `format_int` / `format_flt`, UTF-8 encode and decode. No grapheme clusters, no Unicode case, no normalization, no bidi, no display width. |
| Regex | `hc/lib/regex.he` | Byte patterns, groups, lazy quantifiers. `\d` is ASCII. |
| Immediate UI | `hc/lib/ui.he` | Nuklear-style windows, rows, buttons, checks, radios, sliders, progress, color picker, property rows, charts, trees, combos, menus, tooltips, text edit flags. One visual language. No theme families, no virtualized grid, no date/time picker, no game HUD. |
| Retained HUD layout | `hc/lib/gfx/hud.amni` | Flex row/column (no wrap), absolute anchors, rich-text tags, word wrap, focus nav, tweens. Boxes and text, not a widget set. Needs the GPU renderer. |
| Web | `hc/lib/web.he` | DOM bindings. Widgets are the browser's. |
| Fonts | `hc/lib/ttf.he`, `hc/lib/gfx/sdf_font.amni` | TTF parsing and SDF drawing. Not a shaper. |

Public names in `std` and `ui` are unchanged.

## What this branch adds

`import text` (`hc/lib/text.amni` and `hc/lib/text/`):

- UTF-8 decode/encode with rejection of overlongs and surrogates.
- Grapheme clusters for the common UAX #29 cases: controls, extenders, ZWJ emoji, regional-indicator pairs, Hangul jamo and syllables, spacing marks.
- Case mapping for Latin (including ß, İ, ı, ligatures), Greek (final sigma), and Cyrillic. Title case and a simple casefold.
- NFC/NFD for Hangul (full algorithmic) plus a Latin and monotonic-Greek composition table.
- Display width, Unicode whitespace trim, find/replace, split/join, pad by columns.
- Column wrap with a practical line-break subset, slugify, truncate-with-ellipsis.
- `{index:spec}` interpolation (width, alignment, zero pad, grouping, `d/x/b/o/f/e/%`), currency (USD/EUR/GBP/JPY), `YYYY-MM-DD` dates, `HH:mm:ss` times.
- Piece-table rope and an append builder.
- A code-point expression matcher (`.`, classes, groups, `|`, `*+?{m,n}`).
- Spans, a small markdown/tag parser, measurement hooks, and a layout pass that emits glyph boxes.
- 12 type presets and 10 draw effects (plain, bold, outline, shadow, glow, gradient, typewriter, wide, underline, strike).

`import uikit` (`hc/lib/uikit.amni`):

- Layout: flex row/column, grid, stack, scroll, wrap, padding, gap, grow, fixed and percent sizes, breakpoints.
- Widgets, each with six looks (filled, tonal, outline, ghost, elevated, sharp): button, icon button, fab, segmented, toggle, checkbox, radio, slider, range, stepper, text field, text area, dropdown, combobox, date, time, color, tabs, accordion, tree, table (sort + row window), virtual list, menu, context menu, toolbar, modal, drawer, toast, tooltip, popover, progress, spinner, skeleton, badge, chip, tag, avatar, card, breadcrumbs, pagination, split, divider, rating, message bar, nav rail.
- Game HUD: health, mana, minimap frame, inventory grid, radial slots, dialogue with a typewriter count, damage numbers in six styles.
- Themes: 7 families × 5 variations = 35 (flat, glass, neon, fantasy, minimal, brutalist, retro). Tokens cover color, radius, border, shadow/glow, glass fill, pixel snap, padding.
- Input: hit testing, click behavior, focus order, field insert/backspace, undo snapshot, IME composition commit, ticks for typewriter, damage float, and toasts.
- Roles: button, switch, checkbox, radio, slider, textbox, listbox, tablist, grid, dialog, progressbar, navigation, tooltip.
- A software painter and `hc/apps/gallery` write `docs/ui-gallery/*.png` at 2× with no GPU and no third-party art.
- Vector text in `uikit/vtext.amni`: an original coverage raster on top of `ttf` (four horizontal subpixel phases), `kern` / GPOS pair kerning, and GSUB type-4 pair ligatures from `liga`, `dlig`, and `calt`. Faces are Inter Regular, Medium, Bold, Italic, and Bold Italic, plus JetBrains Mono. Licenses are in `hc/lib/uikit/fonts/`. The 5×7 bitmap is used only when a theme sets the pixel flag (the retro family).
- Theme drawing: glass blurs the pixels already in the framebuffer and adds a highlight; neon stacks translucent glow rings; fantasy draws a procedural grain and corner brackets; brutalist draws a hard offset shadow; retro draws scanlines. Material, Fluent, and Apple variants keep their radii and elevation. Ripple, `ease_*`, and `spring_step` drive `docs/ui-gallery/motion.png`.
- Table filter, column pin, and column resize. `overlap_count` fails a test if sibling boxes intersect. `a11y_export` writes a role/name/bounds tree. `docs/ui-contrast.md` is a WCAG relative-luminance audit of all 35 themes (body pairs at 4.5:1, accent buttons at 3:1).

## Comparison

"Matches" means the capability exists and is tested or visible in the gallery. "Beats" is used only where Helium's shape is actually ahead for a language that has to ship its own widgets. It is not a claim about polish.

### Material Design 3

Source: [components](https://m3.material.io/components), [all buttons](https://m3.material.io/components/all-buttons), [text fields](https://m3.material.io/components/text-fields), [lists](https://m3.material.io/components/lists).

M3's catalog is buttons (filled, tonal, elevated, outlined, text, plus FAB, icon, segmented, split), FAB menu, cards, checkbox, chips, date and time pickers, dialogs, divider, lists, menus, navigation bar/rail, progress, radio, bottom/side sheets, sliders, snackbar, switch, tabs, text fields (filled and outlined), toolbars, tooltips.

Helium matches that set at the widget level, and the flat family has five named variations (material, fluent, apple, shadcn, ant) rather than one scheme. Six button looks cover M3's filled / tonal / outlined / text / elevated split, and the sharp look is extra. Text fields, date, time, switch, slider, snackbar-style toasts, and a nav rail are in the gallery.

Helium does not match M3 Expressive motion, shape morph, dynamic color from a wallpaper, or the state layers and density tokens. Lists are a virtual window, not M3's segmented list with slots.

### Fluent 2

Source: [React components](https://fluent2.microsoft.design/components/web/react).

Fluent's web set includes accordion, avatar, badge, breadcrumb, button, card, checkbox, combobox, dialog, divider, drawer, dropdown, input, label, link, list, menu, message bar, persona, popover, progress, radio, rating, select, skeleton, slider, spin button, spinner, switch, tabs, tag, text, textarea, toast, toolbar, tooltip, tree. Helium has those except carousel, persona (avatar is initials only), info label, and a teaching popover. The spin button is the stepper. Message bar and rating are painted.

Fluent's acrylic is a real backdrop blur. Helium's glass family is a translucent fill plus a highlight line over a painted backdrop, which reads as glass in the gallery and is not a sampled blur.

### Apple HIG

Source: [components](https://developer.apple.com/design/human-interface-guidelines/components). The HIG's component groups are menus and actions, selection and input (text fields, pickers, segmented controls, sliders, steppers, toggles, color wells), presentation (alerts, sheets, popovers, scroll views), layout (lists, tables, split views, tabs, sidebars), status (progress, gauges), and system surfaces (widgets, notifications).

Helium matches the application-control slice: segmented control, stepper, toggle, color well, sheet/drawer, popover, split, tabs, sidebar-style nav rail, progress. It does not match platform chrome (menu bar, toolbar extras, Live Activities, widgets, haptics, SF Symbols). The flat "apple" variation is a blue, large-radius theme, not Apple's materials.

### shadcn/ui, Chakra, Ant Design

Sources: [shadcn/ui components](https://ui.shadcn.com/docs/components) (accordion, alert dialog, data table), [Chakra components](https://www.chakra-ui.com/docs/components/concepts/overview), [Ant Design overview](https://ant.design/components/overview).

Shared ground Helium now has: accordion, alert/message, avatar, badge, breadcrumb, button, card, checkbox, combobox, dialog, drawer, pagination, popover, progress, radio, select, skeleton, slider, switch, table, tabs, textarea, toast, tooltip, tree. Ant Design's data-entry list (cascader, transfer, mentions, upload, form) and Chakra's carousel, file upload, clipboard, and code block are absent. shadcn's data table sorts, filters, and paginates through TanStack; Helium sorts a column and windows rows, and does not filter or pin columns.

Where Helium is ahead of these three: they are DOM/CSS kits. They do not include a game HUD, a bidi/grapheme text library, or 35 hand-authored theme variations in the same module. Where they are ahead: real CSS layout, focus rings that follow the platform, and screen-reader trees.

### Unreal UMG / Common UI and Unity UI Toolkit

Sources: [Common UI buttons](https://unreal-garden.com/tutorials/common-ui-button/), [Common UI input routing](https://pixelantgames.com/blog/unlocking-cross-platform-ui-with-unreals-commonui/), [UI Toolkit ListView](https://docs.unity.com/en-us/engine/7000.0/manual/uitoolkits/uielements/uie-element-ref/uie-uxml-element-list-view).

Common UI's advantage is style assets with seven button states, input actions on buttons, activatable widget stacks, and lazy loading. Helium has hover/press/focus/disabled flags and a focus order, not a widget stack or async load. Unity's ListView recycles visual elements; Helium's virtual list computes the visible index window and paints only those rows, which matches the idea and not the binding model.

Helium is ahead of both as a text library: UMG and UI Toolkit do not ship grapheme breaks, NFC, or bidi next to the widgets. They are ahead on authoring tools, animation graphs, and renderer integration. `gfx.hud` remains the GPU path; `uikit` is the headless one.

### Game UI Database and Interface In Game

Sources: [Game UI Database](https://www.gameuidatabase.com/), [player vitals](https://www.gameuidatabase.com/index.php?scrn=133&set=1), [dialogue](https://www.gameuidatabase.com/index.php?scrn=162&series=1&set=1&sort=2), [minimap](https://www.gameuidatabase.com/index.php?scrn=135&set=1&tag=105), [Interface In Game](https://interfaceingame.com/).

Those catalogs are screenshots, not libraries. The genres Helium now paints, each with at least five looks: health and mana bars, minimap frame, inventory grid, radial slots, dialogue box with a typewriter count, damage numbers (normal, crit, heal, poison, miss, burn). Interface In Game's menu, inventory, map, dialogue, and HUD genres are the same families. Helium does not cover their skill trees, quest logs, stores, or scoreboards.

### Dear ImGui, egui, Slint, Qt Quick, Flutter, CSS

`ui` was already an immediate-mode toolkit in the Nuklear shape, which is the same class as Dear ImGui and egui. This branch does not replace it. `uikit` is retained and themed.

Against that class, Helium now has more named themes (35) and a first-class HUD set than Dear ImGui's default style or egui's one theme. It does not have their font atlases, docking, or plot widgets (`ui` still has the charts).

Against Slint, Qt Quick, Flutter, and CSS, Helium's flex/grid/stack/wrap is a small layout engine, not a full style language. There is no constraint solver like Cassowary, no CSS cascade, and no Flutter compositor. Word wrap and span layout exist. Glyph drawing is a coverage raster with pair kerning, not a full shaper.

### HarfBuzz, ICU, fmt, Python `str`

| Need | Helium now | Still behind |
| --- | --- | --- |
| Grapheme clusters | Common cases, tested (CRLF, `e`+acute, Hangul) | Full UAX #29, including Indic grapheme rules |
| Case | Latin, Greek, Cyrillic, ß, İ, final sigma | Full `SpecialCasing` and `CaseFolding` |
| Normalization | Hangul plus Latin/Greek compositions | Full UCD, NFKC, composition exclusions |
| Bidi | Implicit W1–W7, N1–N2, I1–I2, L2 reorder. Hebrew and mixed Latin tests pass | Explicit embeddings, isolates, bracket pairing, mirroring |
| Line break | Spaces, CJK, punctuation guards | Full UAX #14 pair table |
| Format | Width, align, grouping, float, currency, date | Locales, plural rules, ICU calendars |
| Regex | Code points, groups, bounded repeats | Unicode properties, lazy quantifiers (those stay in `regex`) |
| Rope | Piece table insert/delete | Persistent snapshots, very large files |
| Shaping | Coverage raster of Inter and JetBrains Mono, pair kerning, type-4 pair ligatures | HarfBuzz: contextual `calt`, mark positioning, Arabic, Indic. Inter's `fi` ligature is contextual, so it does not collapse |

fmt and Python `str.format` are the model for the `{index:spec}` syntax. Helium covers the spec subset above and not format localization.

## Still open, in priority order

1. Complex-script shaping. Pair kerning and type-4 ligatures are in. There is no mark attachment, no Arabic or Indic shaping, and Inter's `fi`/`fl` ligatures do not fire because they live in contextual lookups. The raster is coverage with four x-phases, not an MSDF atlas.
2. Full Unicode data tables (case, line break, bidi brackets, normalization exclusions).
3. Theme drawing is still a software approximation. Glass is a box blur of what is already in the buffer, neon bloom is three expanded rects, fantasy frames are corner brackets plus a hash grain rather than a sampled 9-slice, and the ripple is a growing disc. Static sheets do not show hover and pressed for every control.
4. The data grid can filter, pin, and resize in the model (tested). The gallery does not draw a filter field or a drag handle, and there is no tree table, upload, carousel, or validation message.
5. Accessibility is a text tree and a contrast report. There is no platform screen reader, no live announcements, and no non-text contrast pass for icons.
6. Motion is an 8-frame strip (`motion.png`): spring, typewriter, and ripple. There is no GIF, and layout changes do not interpolate.
7. The GPU `ui` and `gfx.hud` paths are unchanged. `uikit` does not draw through SDL.
