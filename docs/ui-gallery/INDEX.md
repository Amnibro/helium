# UI gallery index

Catalog themes: 300
Curated themes: 35
Genres: 41 (24 game, 17 app)
Each sheet: 5 layout variations. Game columns include the 57dbc71a kit (boss, buffs, bars, minimap, inventory, quest, cooldowns, radial or chart, dialogue, damage, Play/Map/Bag) plus genre extras. Leaf count must be at least that commit.
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
- `text/effects-light.png`
- `text/effects-dark.png`
- `widgets/styles.png`
- `fonts/pairings.png`
- `motion.apng`

## Still weak

- Glow and backdrop rectangles are clipped to the widget. `overlap_count` also counts `note_deco` bounds, so a slab painted across another control fails the check.
- Game sheets are seven different screens, but pause/settings still share a short menu, and every map uses the same compass painter.
- The 500 icons are unique 5x5 silhouettes, not 500 named pictograms (no separate sword, potion, and folder metaphors).
- Widget styles are 20 frames on six controls (button, field, toggle, slider, card, badge), not 20 treatments of every chart and table.
- `motion.apng` is eight frames (spring, ripple, typewriter, toast, shimmer). It is not a full transition system.
- `ui.he` and `gfx/hud` still need SDL3, which this machine does not have.
