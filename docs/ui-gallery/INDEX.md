# UI gallery index

Catalog themes: 300
Curated themes: 35
Genres: 41 (24 game, 17 app)
Each game genre has 7 screens (title, pause, settings, hud, shop, map, results), 5 variations each. HUD columns include the 57dbc71a kit (boss, buffs, bars, minimap, inventory, quest, cooldowns, radial or chart, dialogue, damage, Play/Map/Bag) plus genre extras. Leaf count must be at least that commit. App genres are one sheet of 5 variations.
Icons: 500 (500 named pictograms)
Text effects: 100
Widget styles: 20
Font files in the pairing set: 22
Font pairings: 30

## Genres

- `fps/` — FPS title pause settings hud shop map results (ref: Valorant, Counter-Strike)
- `royale/` — Royale title pause settings hud shop map results (ref: Fortnite, Apex Legends)
- `moba/` — MOBA title pause settings hud shop map results (ref: League of Legends)
- `rts/` — RTS title pause settings hud shop map results (ref: StarCraft II)
- `jrpg/` — JRPG title pause settings hud shop map results (ref: Final Fantasy, Persona)
- `souls/` — Souls title pause settings hud shop map results (ref: Elden Ring)
- `mmo/` — MMO title pause settings hud shop map results (ref: World of Warcraft)
- `racing/` — Racing title pause settings hud shop map results (ref: Forza, Mario Kart)
- `fighting/` — Fighting title pause settings hud shop map results (ref: Street Fighter 6)
- `sports/` — Sports title pause settings hud shop map results (ref: EA FC)
- `platform/` — Platform title pause settings hud shop map results (ref: Celeste, Hollow Knight)
- `roguelike/` — Roguelike title pause settings hud shop map results (ref: Hades)
- `deck/` — Deck title pause settings hud shop map results (ref: Slay the Spire)
- `survival/` — Survival title pause settings hud shop map results (ref: Valheim, Minecraft)
- `city/` — City title pause settings hud shop map results (ref: Cities: Skylines)
- `horror/` — Horror title pause settings hud shop map results (ref: Dead by Daylight)
- `space/` — Space title pause settings hud shop map results (ref: FTL, Mass Effect)
- `fantasy/` — Fantasy title pause settings hud shop map results (ref: Skyrim, Genshin)
- `cozy/` — Cozy title pause settings hud shop map results (ref: Stardew Valley)
- `rhythm/` — Rhythm title pause settings hud shop map results (ref: Hi-Fi Rush)
- `puzzle/` — Puzzle title pause settings hud shop map results (ref: Portal, Tetris)
- `novel/` — Novel title pause settings hud shop map results (ref: Steins;Gate, Doki Doki)
- `idle/` — Idle title pause settings hud shop map results (ref: Cookie Clicker)
- `gacha/` — Gacha title pause settings hud shop map results (ref: Genshin Impact banners)
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
- `text/effects-light.png`
- `text/effects-dark.png`
- `widgets/styles.png`
- `fonts/pairings.png`
- `motion.apng`

## Still weak

- FPS and MOBA are real 1920x1080 stages. Screen-anchored HUD text is centered on the frame and the align gate checks that. JRPG, Souls, Royale, Racing, Fighting, and Deck are still the narrow column.
- The minimap painter is still the compass disc. The shield glyph still reads a bit like a tag. The skyline is block rectangles.

- Glow and backdrop rectangles are clipped to the widget. `overlap_count` also counts `note_deco` bounds, so a slab painted across another control fails the check.
- Game sheets are seven different screens, but pause/settings still share a short menu, and every map uses the same compass painter.
- All 500 icons are named pictograms. Thin marks (arrows, plus, minus) are geometric on purpose. A few complex metaphors are still coarse.
- Widget styles are 20 frames on six controls (button, field, toggle, slider, card, badge), not 20 treatments of every chart and table.
- `motion.apng` is eight frames (spring, ripple, typewriter, toast, shimmer). It is not a full transition system.
- `ui.he` and `gfx/hud` still need SDL3, which this machine does not have.
