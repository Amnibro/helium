# UI gallery index

Catalog themes: 300
Curated themes: 35
Genres: 41 (24 game, 17 app)
Each genre has 7 screens (title, pause, settings, hud, shop, map, results), 5 variations each, on a 1920x1080 stage. Game HUD columns include the 57dbc71a kit (boss, buffs, bars, minimap, inventory, quest, cooldowns, radial or chart, dialogue, damage, Play/Map/Bag) plus genre extras. Leaf count must be at least that commit.
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
- `dashboard/` — Dashboard title pause settings hud shop map results (ref: Linear, Stripe dashboard)
- `admin/` — Admin title pause settings hud shop map results (ref: Salesforce, Retool)
- `shop/` — Shop title pause settings hud shop map results (ref: Shopify admin)
- `social/` — Social title pause settings hud shop map results (ref: Instagram, X)
- `chat/` — Chat title pause settings hud shop map results (ref: iMessage, Discord)
- `media/` — Player title pause settings hud shop map results (ref: Apple Music, Spotify)
- `editor/` — Editor title pause settings hud shop map results (ref: VS Code)
- `settings/` — Settings title pause settings hud shop map results (ref: iOS Settings, Windows Settings)
- `onboard/` — Onboard title pause settings hud shop map results (ref: Notion onboarding)
- `auth/` — Auth title pause settings hud shop map results (ref: Apple ID, Google sign-in)
- `pricing/` — Pricing title pause settings hud shop map results (ref: Stripe pricing)
- `docs/` — Docs title pause settings hud shop map results (ref: Apple HIG, MDN)
- `calendar/` — Calendar title pause settings hud shop map results (ref: Google Calendar)
- `kanban/` — Kanban title pause settings hud shop map results (ref: Trello, Linear boards)
- `maps/` — Maps title pause settings hud shop map results (ref: Google Maps, Apple Maps)
- `banking/` — Banking title pause settings hud shop map results (ref: Revolut, Apple Cash)
- `health/` — Health title pause settings hud shop map results (ref: Apple Health, Fitbit)

## Other sheets

- `icons/sheet.png`
- `text/effects-light.png`
- `text/effects-dark.png`
- `widgets/styles.png`
- `fonts/pairings.png`
- `motion.apng`

## Still weak

- All 24 game genres and all 17 app genres are 1920x1080 stages. Each app has its own home, menu, settings, main screen, list, browse, and summary.
- Each genre backdrop has its own sky and ground colors. Cozy is a warm pastel, sports is a bright pitch, space is deep blue with stars, gacha is saturated magenta. Silhouettes are small shapes on the horizon. Scene labels on a light sky or ground are dark. They are still flat shapes, not painted scenes.
- Panels have a gradient, a bevel, and an inner shadow. Bars have segment ticks. Scene text has a one-pixel drop shadow. Results tables use 22px cells. Stage labels and buttons are at least 20px. The tall boss bar no longer paints a second small name.
- Each game genre has its own minimap diagram: roads, rooms, lanes, or nodes drawn as ellipses. It is still a diagram, not a captured level.
- The damage trail shrinks and fades from variation 0 to 4 (a wide bright chip, then a short dull one). It is that offset, not a simulated hit. Other pictograms stay coarse. Ability icons are the nearest metaphor, not spell art.
- Body text is 16 to 18px and titles are 24 or 32px. Chart axis labels are 16px. Cards use a 12px radius, a 1px border, and a blurred shadow on the larger surfaces. Small controls skip the blur.
- Shop drawings are a few shapes (cup, shade, bag, pen, bowl, cloth), not rendered products. The map roads are sine curves and the parks are clusters of ellipses. Kanban avatars are a letter in a circle. The checklist is a count, not a list of items.
- The calendar is a five-week month beside one day. Chat bubbles are one line plus a timestamp. Settings groups are a title, one description line, and two toggles. Several list screens are still full-width rows.
- Glow and backdrop rectangles are clipped to the widget. `overlap_count` also counts `note_deco` bounds, so a slab painted across another control fails the check.
- All 500 icons are named pictograms. Thin marks (arrows, plus, minus) are geometric on purpose. A few complex metaphors are still coarse.
- Widget styles are 20 frames on six controls (button, field, toggle, slider, card, badge), not 20 treatments of every chart and table.
- `motion.apng` is eight frames (spring, ripple, typewriter, toast, shimmer). It is not a full transition system.
- `ui.he` and `gfx/hud` still need SDL3, which this machine does not have.
