# hc: what's left

Status as of 2026-10-27 (gate 97, the old C++ compiler deleted).

## Where things stand

| | Now |
|---|---|
| hc source | `hc/*.he` and `hc/lib/*.he`, all in the `.he` syntax below; the library was rewritten from scratch, and `json`/`regex` were fuzzed against the old one |
| Self-host | hc builds itself natively, reaches a fixpoint, and emits the same C as the clang-built hc (`hc/bootstrap.sh` checks both) |
| Corpus, native (`--native`) | 645 / 645 pass, the gfx and ui tests included (run on lavapipe, a CPU Vulkan driver: `VK_DRIVER_FILES=<lvp_icd.json> SDL_VIDEO_DRIVER=offscreen HC_GPU=1`) |
| Corpus, C path | 544 / 645 pass in the difftest (which runs no GPU); the C path is the oracle and the bootstrap seed, not the product |
| Corpus, WebAssembly | 628 / 645 (the rest open a GPU, link C libraries, or assume native's 16 GiB regions) |
| hc's own tests | `hc/test/*.he` with `.out` files; `tools/hc/hetest.sh <hc>` runs each one through the C path, `--native` and `--native --debug` |
| Pom-Pom Grove sim | garden, race, mini, load traces bit-identical on both paths |
| Own modules replacing the old C packages | `audio` (hc/lib/audio.he on SDL3: the same mixer, bit-identical to the old C gfx layer offline and live). `gfx` (hc/lib/gfx.he straight on SDL3's GPU API, no C layer: the same checks and messages; every SDL struct's layout is checked field by field against the C compiler's). `ui` (hc/lib/ui.he: Nuklear ported line by line to `.he`, with its own TrueType loader hc/lib/ttf.he; the same checks and misuse messages, all 12 ui tests pass, and canvas output matches the C build command for command). `physics` (hc/lib/physics.he over hc/lib/physics_engine.he: Box3D ported to `.he`, the full API with joints, queries, events, recording and replay; all 9 physics tests pass on both backends). No old C package is loaded any more; inside a package, `import gfx` resolves to hc/lib. Modules that must stay on the main thread declare `MAIN_THREAD := true`, and the thread check rejects a `thread_fn` that reaches their state |
| Full apps | Pom-Pom Grove (`pomling.amni`, gfx + ui) and Waystone (`play.amni`, gfx + ui + audio + C sources) compile natively with hc. On lavapipe, Pom-Pom Grove built by hc with our gfx renders pixel-identical to the old toolchain's build: test_creature, test_render and the app's scripted HUD and menu shots exactly, test_world and test_garden within 1 level on 2 and 4 pixels (libm rounding, as before). With our ui too: Pom-Pom Grove's HUD and menu shots and Waystone's title, lobby, shop, memoir, in-run and HUD screens are 0-pixel-diff vs Goose's ui |
| Driver | `hc run file [-- args]` (native, cached under ~/.cache/hc), `hc build file [-o out]` (`-o out.c` for C, `--web` for `.wasm` plus the `helium.js` host), `hc check`, `hc fetch [--update]` (git packages, cached under `$GOOSE_HOME/pkg`, locked, submodules), `--offline`, `hc lsp`, `hc version`, `hc help`; `hc file` runs; `hc in out [--native]` still works. The library is HC_LIB, else `lib` beside the executable |
| Waystone parity | `HELIUM=hc tools/parity.sh`: 193 of 193 traces identical to the JS original |
| Shaders | `hc/shaderc.he` compiles GLSL to SPIR-V, MSL and HLSL inside hc (no C tool, no cache). It began as a port of cute_spirv and is byte-identical to it on 2698 real and mutated shaders; since then it emits valid SPIR-V where the original did not (sampler parameters, whole-struct buffer stores, `refract`), and every corpus module passes `spirv-val` |
| Language server | `hc lsp` (hc/lsp.he): diagnostics as you type (every error, not just the first), hover, definition, references, rename, document and workspace symbols, completion (scope, and members after `.` on a line that does not parse yet), signature help, inlay type hints, folding. Each request is answered by `hc --query` in a child process over the open buffers. `tools/hc/lsptest.py` runs the fixtures in hc/test/lsp |
| Web target | `hc file out.wasm --web` emits WebAssembly from hc's own optimized IR (hc/wasm.he): structured control flow, interval-colored locals, a checked shadow stack, threads on workers over shared memory, regions in tiers so hundreds fit in 4 GiB. Externs become JS imports and `export` functions become JS-typed exports. Hosts: hc/web/host.mjs (node: files, threads, futexes) and hc/web/web.js (browser: DOM, events, fetch, storage, WebGL 2, JS interop). The corpus runs as WebAssembly 619/645 (the rest open a GPU, link C libraries, or assume native's 16 GiB regions). Amni Prayer builds with hc and renders the same as the Goose build |
| Old toolchain | The C++ compiler (`src/`), the old `stdlib/`, CMake files and `third_party/` are deleted; the corpus in `test/` and `samples/` is `.amni`. Pomling and Waystone still ship from the old toolchain in their own checkouts |

## 0. The `.he` syntax

`.he` files parse with layout; `.amni` files parse exactly as before.

- Blocks: `:` then an indented block, or `: a; b` to the end of the line. Braces still work and switch layout off inside them.
- An inline `else` closes the inline block it follows only when its own branch uses layout (`else:` or `else if c:`); `else {` stays with a braced `if`.
- No `;` at line ends; `x := e` declares, `x ~= e` declares a variable; `fn` is optional; `for i xs` and `for x T in xs`; `use m`; `#` comments.
- A statement-position block discards its tail value. A function with no result type still infers it from its tail, so end such bodies with `;` when the tail is not the result.
- An untyped local whose initializer is a narrower integer (not a cast) is `int`.
- An int converts implicitly to a narrower int at assignments, typed declarations, returns and fields; debug builds check that it fits, exactly like `as`. Arguments still need a cast (overload matching does not narrow).

Converters:

- `hc --to-he in.amni out.he`: syntax only. Safe only for code without narrow untyped locals, since `.he` widens those.
- `HC_OLDLOC=1 hc --slim prog file out.he [keep]`: checks the whole program under the old rules, then prints `file` with types. It drops casts that the new rules make redundant and spells out narrow local types the old code relied on.
- The oracle (`tools/hc/slim.py`) compares the C of the old and new sources after canonical renaming. Any function whose C changes keeps its casts. On hc it kept 57 of about 950 functions.

o200k token counts: hc 243,964 (`.amni`) → 228,365 (`.he`, slimmed), −6.4%. Corpus, syntax only: −10.6% code tokens.

Projects still on `.amni`, because they build with the old toolchain: Pomling and Waystone (their parity suites must pass on hc first), and Amni Prayer (now builds with hc; the site still ships the Goose build).

## 1. Correctness gaps

The native corpus passes completely. What is left:

- **`lut fn`:** done in `.amni` files: CPU tables (lex.he `lut_desugar`) and the GPU fill (hc/lutglsl.he writes GLSL, our shaderc compiles it with int64, hc/lib/lutgpu.he runs it through Vulkan from an optional `extern "libvulkan.so.1?"`). `tools/hc/luttest.sh` checks GPU tables against the CPU. Left: `.he` files (a `lut fn` there is still a plain function).
- **C path** (101 tests): it lags native on variable-mode ADTs, varint values and serialization, contextual generic floats and the newer native fixes. An `if` expression yielding `null` or a pool element into a pool-relative field emits an assignment clang rejects (`hc/test/relref_guard.he` builds its links with statements instead).
- **Rejection parity:** `python3 tools/hc/errtest.py <hc>` runs the 1937 `test/errors_tc` programs, each of which expects the diagnostic in its `// error:` line. hc (2026-10-27): 26 match, 160 rejected with other wording, 1751 accepted, 0 crash (was 2 match and 20 crash that morning). All 20 now stop with the expected diagnostic: cycles in constants, field defaults and parameter defaults (each is re-checked under a stack of the defaults in progress), generic types and recursive specializations capped at 16 in a chain, `const for` expansion capped at 100000 generated nodes. Accepting is not harmless: `var l = l0; return l` compiled to a use-after-free until hc gained the return check. `tools/hc/baseline/err.txt` holds the matching files; CI fails if one stops matching.

## 2. Performance (native vs clang)

- **Work in progress, uncommitted:** a zero-fill idiom (`for i in N { a[i] = 0 }` becomes one `ZERO`) in `lower.amni`. It never fires yet; `lzfill` isn't being reached from `lfor`.
- **`separate`** (obstacle loop): about 40% of garden's instructions. This is the biggest single target.
- **`reachable`** (BFS): 3.8G vs 1.9G instructions. Its neighbor arrays (`i32[4]` literals) should scalarize and the bounds checks should drop.
- **BLAKE3 (`b3compress`)** is 3.6x slower:
  - Store-forwarding stalls: 4-byte stores are followed by 8-byte loads when 64-byte blocks are copied.
  - SRA caps scalarization at 8 fields, and the state and message are 16 words each.
  - Tried and reverted: a cap of 16, and copies chunked to the field width (race −4.5% cycles, garden +2–4%). The fix has to remove the copies, not narrow them.
- **Race branch misses** are about 2x clang's.
- **Bounds checks inside loops:** the range analysis covers constant lengths only. Extend it to loop induction variables vs `len`.
- **Register allocation:** linear scan with heavy spilling in large functions like `main`. Splitting live ranges or graph coloring would help in hot loops.
- **Vectorization (`vec.he`, SSE2):** innermost counted integer loops become `I_VLOOP` kernels. Supported:
  - Unit-stride loads and stores on resizable arrays.
  - Add, sub, and, or, xor, multiply (16-bit lanes and narrower), and shifts by constants.
  - Widening and narrowing between 8-, 16-, 32- and 64-bit lanes.
  - One `int` reduction (`+= -= ^= |= &=`) per loop.
  - `f32`/`f64` lanes: loads, stores, copies, uniform broadcasts and `+ - * /` as packed SSE ops, one op per scalar op with no FMA, so results are bit-identical to the scalar loop. Float reductions, compares, selects and int/float conversions are rejected, since a reduction would change the summation order.
  - Kernels whose narrowest lane is 4 bytes or wider process two registers per value per iteration, falling back to one when XMM registers run out. A 400x400 f64 matmul (`cij += aik * bk[j]`) runs at clang's speed.
  - Runtime guards for bounds and aliasing, with the scalar loop kept as the tail.
  - `HC_NOVEC=1` turns it off.
  - Gate any change to it with `python3 tools/hc/vecfuzz.py <hc> [count] [first seed]`. It runs random loop programs with and without `HC_NOVEC` and compares exit codes and output. Run it with both the C-built `hc` and the natively built `hcn`: the native one runs `vec.he` as native code. In October 2026 that exposed a native double release that the C-built compiler hid.
  - Stores may go through row slices (a data pointer plus a loop-invariant offset), so row-wise blur kernels vectorize too.
  - Blur runs 9x faster. Not yet supported: float reductions and conversions, conditionals (select, e.g. the audio mixer's clamp), gathers, AVX2, and strided or struct-of-arrays access. vecfuzz's `flt` mode covers floats, including inf and NaN from division by zero.
- **Byte gathers:** a counted loop `for k n { v |= (s[i + k] as uint) << (8 * k) }` with n of 2, 4 or 8 (after inlining) becomes one guarded n-byte load. When `i` or `n` falls out of bounds, the original loop runs and traps at the same index (`vlc_loop` in `vec.he`). It covers `std.hash` and `binary.le`. A literal `for k 8` is unrolled during lowering and is not combined yet.
- **Memory forwarding (`lvn`):** addresses are canonicalized to a root base plus constant offset. A store only invalidates earlier loads and stores of the same base whose bytes overlap it, so struct field updates through one reference forward their values. Loads from immutable non-escaping `let` globals (`GADDR` tagged `l = -4` by `gtag`) ignore stores, and LICM hoists them. LICM also hoists loads from globals and stack slots out of loops that contain no stores or calls. `tools/hc/optfuzz.py <hc> [n] [seed]` fuzzes aliasing references, globals and calls, native optimized against `HC_NOOPT` and the C path.
- Data-stack scope markers (`dss`/`dsr`) only move the data-stack top, so LVN gives loads rooted in globals and stack slots their own epoch (`mg`). Markers bump only that epoch, and loads through references and heap pointers survive them.
- Optional relative references: decoding `n.l` yields `p = d != 0 ? base + d : 0`. `rnz` (opt.he) rewrites `p != null` tests to `d != 0`. When every other use of `p` lies in the region reached only through the nonzero edge of such a test, it also drops the `p = 0` arm, so `guard l else {...}` costs a load, an add and a branch (bintrees -5%, tree -9% instructions).
- Signed `/` and `%` by a positive constant become unsigned when the dividend is provably nonnegative (`udv`, opt.he). This is an optimistic fixpoint over every definition with two facts per variable: nonnegative, and small (below 2^40). Release builds do not check ADD/MUL for overflow, so a sum counts only when it cannot wrap: both operands small, a debug-checked op, or a loop counter `i = i + 1` whose loop head tests `i < N` (signed) on every path to the increment. Unsigned loads and zero-extensions, Euclidean `%`, masks and logical shifts are nonnegative. Converted ops carry `l = -7`, and codegen then picks the 63-bit-precision multiplier, which usually avoids the add-fixup form. divcheck adds 40 random sign-mixed loop kernels per seed, plus 16 fixed kernels near 2^63 that wrap on the add.
- Constant division writes its result straight into the destination register and keeps the dividend there (or in RCX when the destination is RAX), instead of copying through RAX/RCX. `cdk` mirrors exactly the divisors `cdivk` accepts.
- LICM hoists loads rooted in stack slots past data-stack scope markers (`dss`/`dsr`), which only touch a private mark slot and the data-stack global. Loads rooted in globals still treat them as writes.
- Address fusion (regalloc kind 7, `[base + index*scale + disp]`) also takes scale-1 indices, bases of the form `base + disp`, and multi-definition indices such as loop counters, provided every use of the address is a load/store in the same straight-line run with no redefinition of the index in between (`win`). tree -10%, push -6%, respond_stream -5%, lru -3.5%.
- Zeroing tails under 8 bytes uses one u32/u16/u8 store each (`lzero`), and the relative-reference range guard is one unsigned compare, `(d + lim) <u 2*lim` (`rel_store`). bintrees -10.6%, graph -4%.
- Every `sguard` still inlines a byte-copy loop for its message. It's cold, but it's a lot of code per guard; a shared runtime call would shrink hot functions.
- A scaled index that cannot join a full address (for example `ptr + len*8` merged with `rt_grow`'s result) is absorbed into its single ADD user as one `lea` (kind 9). `base + disp` addresses (kind 6) are rebuilt at each use only while the value has fewer than two non-address uses; otherwise it gets a register (graph_csr -5%, push -4%).
- **Division by constants:** native `/` and `%` with a constant divisor use multiply-high sequences (Granlund–Montgomery), power-of-two shifts and masks, keeping truncating `/` and Euclidean `%`. Unsigned divisors pick the tightest multiplier (multiply and shift, or pre-shift for even divisors) before the add-fixup form. Power-of-two cases work in any register. Divisors with magnitude of at least 2^62 still use `div`. Check changes with `python3 tools/hc/divcheck.py <seed> <hc>`: it covers every integer type and edge divisors, native against C. `push` went from 2.8x clang's cycles to 1.5x, since every bench rng calls `xs_mod`.
- **Inlining heuristics:** size limits are hand-tuned with no profile feedback.
- **Compile time:** hc self-compile is ~300 ms, up from ~206 ms before the optimizer passes. Main costs: two value-numbering passes, LICM, rebuilding IR after strength reduction.

## 3. Own everything (replacing the old toolchain and third-party C)

- **Graphics (`gfx`):** done: hc/lib/gfx.he, the whole old gfx API on SDL3's GPU API (dlopened libSDL3), with the C layer's checks and misuse messages.
- **Shaders:** done (hc/shaderc.he). Left: the MSL and HLSL banners still name cute_spirv. `lut fn` GPU fills are ported (64-bit ints added to shaderc); the Helium-subset GPU language for `embed_shader` tables is not; no app uses it.
- **`physics`:** done (hc/lib/physics.he, hc/lib/physics_engine.he). Left: starting a recording on a non-empty world, recording queries.
- **`ui`:** done: hc/lib/ui.he (Nuklear under its public-domain option, no C layer) and hc/lib/ttf.he (TrueType outlines, rasterizing, rect packing). ProggyClean is still the built-in default font; ttf.he reads `glyf` outlines only, so CFF (`.otf`) fonts are not loaded yet.
- **Pom-Pom Grove app** (`eng/`, `app/`, `pomling.amni`): builds only with the old toolchain today. It moves once gfx and shaders exist.
- **Driver:** done (see the status table). Not carried over from the old compiler: the TinyCC JIT, C toolchain selection (`--cc`, `toolchain`), `--standalone`, `--multi-test` and the compiler-debugging dumps beyond `--tokens`.
- **Web target:** done (see the status table). Left: threads in the browser need a cross-origin isolated page (COOP/COEP) and a worker host; `gfx`/`ui` on WebGL or WebGPU; the 64 MiB main shadow stack could shrink for small apps; an HTML page beside the host.
- **LSP:** done for the features above. Left: semantic tokens, code lenses, call hierarchy, selection ranges, recovery from parse errors beyond member completion, and a VS Code extension for `.he` and `.amni`.
- **Mail-client libraries** (planned; another session will likely build them, so check git log before starting one):
  - Sockets and TLS: TCP client and server, non-blocking I/O, certificate verification.
  - IMAP and SMTP clients (STARTTLS, AUTH, IDLE).
  - HTTP server.
  - SQLite (database file format and queries).
  - HTML and MIME: parsing, multipart, quoted-printable, base64 and charset decoding, sanitized rendering.
- **More targets:**
  - arm64 code generation.
  - Mach-O for the Mac and iOS (Waystone, TOS Learn).
  - Android arm64 ELF.
- **Bootstrap without C:** hc is still seeded from `hc/seed/hc.c` through clang. Ship a native seed binary so a fresh build needs no C compiler. Keep the C path as the oracle.

## 4. Housekeeping

- `tools/hc/ci.sh` is the gate: bootstrap, corpus native / C / WebAssembly against `tools/hc/baseline/*.txt`, vecfuzz, hetest, lsptest, webtest, pkgtest. Update the baselines when a change gains tests. App parity (Pomling traces, Waystone's `tools/parity.sh` with `HELIUM=hc`) runs from those projects' own checkouts.
- Perf tools still live outside the repo: `pcount`, `psamp`, `attr.py`, `annot.py`.

## Suggested order

1. Rejection parity: the §4.1 copy and lifetime checks (the accepted programs that miscompile).
2. `lut fn` in `.he` files.
3. Performance passes: `separate`, `reachable`, BLAKE3, bounds checks in loops.
4. Editor support for `.he` and `.amni` on `hc lsp`.
5. arm64 and Mach-O.
6. A native seed so a fresh build needs no C compiler.
