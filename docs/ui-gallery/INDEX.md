# UI gallery index

Catalog themes: 300
Curated themes: 35
Genres: 41 (24 game, 17 app)
Variations per genre: 5
Icons: 500
Text effects: 100
Widget styles: 20
Font files in the pairing set: 22
Font pairings: 30

## Genres

- `fps/sheet.png` — FPS (ref: Valorant, Counter-Strike)
- `royale/sheet.png` — Royale (ref: Fortnite, Apex Legends)
- `moba/sheet.png` — MOBA (ref: League of Legends)
- `rts/sheet.png` — RTS (ref: StarCraft II)
- `jrpg/sheet.png` — JRPG (ref: Final Fantasy, Persona)
- `souls/sheet.png` — Souls (ref: Elden Ring)
- `mmo/sheet.png` — MMO (ref: World of Warcraft)
- `racing/sheet.png` — Racing (ref: Forza, Mario Kart)
- `fighting/sheet.png` — Fighting (ref: Street Fighter 6)
- `sports/sheet.png` — Sports (ref: EA FC)
- `platform/sheet.png` — Platform (ref: Celeste, Hollow Knight)
- `roguelike/sheet.png` — Roguelike (ref: Hades)
- `deck/sheet.png` — Deck (ref: Slay the Spire)
- `survival/sheet.png` — Survival (ref: Valheim, Minecraft)
- `city/sheet.png` — City (ref: Cities: Skylines)
- `horror/sheet.png` — Horror (ref: Dead by Daylight)
- `space/sheet.png` — Space (ref: FTL, Mass Effect)
- `fantasy/sheet.png` — Fantasy (ref: Skyrim, Genshin)
- `cozy/sheet.png` — Cozy (ref: Stardew Valley)
- `rhythm/sheet.png` — Rhythm (ref: Hi-Fi Rush)
- `puzzle/sheet.png` — Puzzle (ref: Portal, Tetris)
- `novel/sheet.png` — Novel (ref: Steins;Gate, Doki Doki)
- `idle/sheet.png` — Idle (ref: Cookie Clicker)
- `gacha/sheet.png` — Gacha (ref: Genshin Impact banners)
- `dashboard/sheet.png` — Dashboard (ref: Linear, Stripe dashboard)
- `admin/sheet.png` — Admin (ref: Salesforce, Retool)
- `shop/sheet.png` — Shop (ref: Shopify admin)
- `social/sheet.png` — Social (ref: Instagram, X)
- `chat/sheet.png` — Chat (ref: iMessage, Discord)
- `media/sheet.png` — Player (ref: Apple Music, Spotify)
- `editor/sheet.png` — Editor (ref: VS Code)
- `settings/sheet.png` — Settings (ref: iOS Settings, Windows Settings)
- `onboard/sheet.png` — Onboard (ref: Notion onboarding)
- `auth/sheet.png` — Auth (ref: Apple ID, Google sign-in)
- `pricing/sheet.png` — Pricing (ref: Stripe pricing)
- `docs/sheet.png` — Docs (ref: Apple HIG, MDN)
- `calendar/sheet.png` — Calendar (ref: Google Calendar)
- `kanban/sheet.png` — Kanban (ref: Trello, Linear boards)
- `maps/sheet.png` — Maps (ref: Google Maps, Apple Maps)
- `banking/sheet.png` — Banking (ref: Revolut, Apple Cash)
- `health/sheet.png` — Health (ref: Apple Health, Fitbit)

## Other sheets

- `icons/sheet.png`
- `text/effects.png`
- `widgets/styles.png`
- `fonts/pairings.png`

## Counts against the volume target

| Target | This chunk |
| --- | --- |
| ~300 themes, light and dark | 300 generated themes (15 families × 20 variants, 10 dark and 10 light) plus the 35 curated themes. Contrast audit: 300/300 at 4.5 body and 3.0 accent. |
| 24 game genres × 5 | 24 sheets, 5 variations. One shared HUD kit (boss, buffs, bars, minimap, inventory, quests, cooldowns, radial or chart, dialogue, damage, Play/Map/Bag). |
| 17 app genres × 5 | 17 sheets. Settings has the SV square and hue ring. Admin/shop show filter, pin, and a resize grip. Chat, calendar, kanban, and maps swap the middle. The rest are chart + table. |
| ~20 styles per widget | 20 named button styles. Other widgets still use the original 6 looks. |
| ~100 text effects | 100 named effects. Strokes, drop shadows, and colored bloom read on `text/effects.png`. |
| 30 OFL pairings | 20 catalog families + Inter + JetBrains Mono, 30 pairings, all 30 opened and rasterized. |
| ~500 icons | 500 antialiased glyphs from 20 silhouettes × 25 parameter sets. |

## Still weak

- A Valorant HUD, a Slay the Spire reward screen, and a Stardew menu are not separate layouts. Genres recolor one kit.
- The 500 icons repeat those 20 silhouettes. They are not 500 distinct metaphors.
- Several "effects" are the same stroke or shadow with a different color. Gradients on a light page are easy to miss.
- Glass is a box blur over flat color blocks. Neon bloom is two box blurs, not a gaussian. Fantasy frames are tick marks, grain, and corner brackets, not a parchment 9-slice.
- No GIF/APNG yet. `ui.he` / `gfx.hud` need SDL3 (`libSDL3.so.0`); this machine has SDL2 and Vulkan, so those paths were not re-rendered.
- Inter's static face has no `fi`/`fl` glyph. Pair kerning is still on. There is no MSDF atlas; large text is coverage plus the effect blits.
- Variable fonts in the pairing sheet sometimes space a letter oddly. That is the default master, not a shaped instance.
