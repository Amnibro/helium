# hc: what's left

Status as of 2026-10-27 (gate 76).

## Where things stand

| | Now |
|---|---|
| hc source | `hc/*.he` and `hc/lib/*.he`, all in the `.he` syntax below; the library was rewritten from scratch, and `json`/`regex` were fuzzed against the old one |
| Self-host | hc builds itself natively, reaches a fixpoint, and emits the same C as the clang-built hc (`hc/bootstrap.sh` checks both) |
| Corpus, native (`--native`) | 635 / 645 pass, the gfx and ui tests included (run on lavapipe, a CPU Vulkan driver: `VK_DRIVER_FILES=<lvp_icd.json> SDL_VIDEO_DRIVER=offscreen HC_GPU=1`) |
| Corpus, C path | 541 / 645 pass in the difftest (which runs no GPU); the 10 gfx and ui tests also pass on the C path on lavapipe |
| hc's own tests | `hc/test/*.he` with `.out` files; `tools/hc/hetest.sh <hc>` runs each one through the C path, `--native` and `--native --debug` |
| Pom-Pom Grove sim | garden, race, mini, load traces bit-identical on both paths |
| Own modules replacing Goose packages | `audio` (hc/lib/audio.he on SDL3: the same mixer, bit-identical to goose_gfx offline and live). `gfx` (hc/lib/gfx.he straight on SDL3's GPU API, no C layer: the same checks and messages; every SDL struct's layout is checked field by field against the C compiler's). `ui` (hc/lib/ui.he: Nuklear ported line by line to `.he`, with its own TrueType loader hc/lib/ttf.he; the same checks and misuse messages, all 12 ui tests pass, and canvas output matches the C build command for command). `physics` (hc/lib/physics.he over hc/lib/physics_engine.he: Box3D ported to `.he`, the full API with joints, queries, events, recording and replay; all 9 physics tests pass on both backends). No Goose package is loaded any more; inside a package, `import gfx` resolves to hc/lib. Modules that must stay on the main thread declare `MAIN_THREAD := true`, and the thread check rejects a `thread_fn` that reaches their state |
| Full apps | Pom-Pom Grove (`pomling.amni`, gfx + ui) and Waystone (`play.amni`, gfx + ui + audio + C sources) compile natively with hc. On lavapipe, Pom-Pom Grove built by hc with our gfx renders pixel-identical to the Goose build: test_creature, test_render and the app's scripted HUD and menu shots exactly, test_world and test_garden within 1 level on 2 and 4 pixels (libm rounding, as before). With our ui too: Pom-Pom Grove's HUD and menu shots and Waystone's title, lobby, shop, memoir, in-run and HUD screens are 0-pixel-diff vs Goose's ui |
| Driver | `hc build file [-o out]`, `hc run file [-- args]` (native, cached under ~/.cache/hc), `hc check`, `hc version`, `hc help`; `hc file` runs; `hc in out [--native]` still works. The library is HC_LIB, else `lib` beside the executable |
| Waystone parity | `HELIUM=hc tools/parity.sh`: 193 of 193 traces identical to the JS original |
| Still on the Goose C++ compiler | Pomling, Waystone and Amni Prayer (web target); LSP; shader compilation |

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

Projects still on `.amni`, because they build with the Goose toolchain: Pomling and Waystone (their parity suites must pass on hc first), and Amni Prayer (needs hc's web target).

## 1. Correctness gaps in the corpus

### 1.1 Missing modules (33 tests)

- `gfx`: 11 tests.
- `ui`: 9 tests.
- `physics`: 8 tests.
- `audio`: 2 tests.
- `greet`, `cmk`, `cmath2` (1 each): test-only packages. These need a package and import-path story in hc.

### 1.2 Checker gaps (73 tests, same on both backends)

- **Implicit copies of resizable values (§4.1), not in the corpus:** `g(x)` with `g(o H)` and `x` a variable of a struct holding a `[>..]` array, and `h ~= o; ...; h` returned by value, compile without the error §4.1 asks for (`copy(x)`), and the native build then reads freed memory. Make both an error that suggests `copy(x)`.
- **Overload resolution** (17 tests, "no function X matches"):
  - array adaptation at calls: `call_array_adaptation`, `limited_array_adaptation`, `literal_array_arguments`
  - nested overloads, typeless argument order, member parameters
  - `exception::try` with fn arguments
- **`const for`** (7 `typing/const_for_*` tests): not implemented.
- **Generics:**
  - explicit type arguments ("wrong number of type arguments", 3 tests)
  - `Pair` to `Pair<i64>` conversion
  - contextual generic floats
  - generic return-from
  - reference type arguments
- **Never-returning functions:** `never_returns`, `never_returns_arguments`, `never_returns_exit`, `unreachable_statements`.
- **Empty `[]` with no element type** (3 tests): branch arguments, slice arguments.
- **`return` from a block target**: reported as "return outside a function" (3 tests).
- **Captures:** funval body captures, initializer block captures, funval return roots.
- **Recursive and self-referencing types:**
  - `render_recursive_types`, `render_adt_self_references`
  - `self_relative_adt_payloads`, `resizable_adt_payload_links`
  - `recursive_dispatch_fixed_variant`
- **Misc typing:**
  - rest defaults, self-constructing defaults, struct literal default inference
  - variant aliases, lexical names, int/float conversions
  - bitnot constant patterns, literal conditionals
  - const len extents, const shallow paths, const struct slots
  - slice destinations, variable element literals
  - optional recursive calls, nested fn declaration scope
  - namespace type precedence, branch reference arguments
- **Lifetimes:** `branch_array_whole_slices`, `held_refs_tail_shrinks`, `tree_copied_from_struct`, `tree_in_struct_rerun`.
- **stdlib modules:** `stdlib_dictionary_model`, `stdlib_dictionary_refs`, `stdlib_exception`, `stdlib_sort`, `stdlib_std`.
- **Self-tests:** `lexer_tokens`, `parser_all`, `typecheck`, `codegen_exec`, `errors_tc/recovery/roots`.
- **Other:** `bce` (optimizer test), `free_u64`, `pool_branch_values`, `relative_destination_results`, `exit_value_destination`, `fieldless_variant_values`, `reference_element_results`, `render_fixed_payload_copies`.

### 1.3 Wrong output (39 native tests)

- **Pool-relative references** (~12 tests):
  - Runtime error "pool-relative reference": `storage/alloc_*`, `inpool_lru`, `relative_known_null`, `unreached_pool_links`
  - `relative_declarations`, `relative_results`, `stdlib_relative_elements`
  - `adt_self_references`, `appended_literals`, `fill_evaluation`
- **Evaluation order and aliasing on whole-value assignment:** `evaluation_order`, `whole_assign_apart`, `limited_assign_sources`.
- **Aborts that should fire but don't:** `bound_type_abort`, `index_type_abort`, `format_hook_bounds`.
- **Rendering and format hooks:**
  - `render_self_relative_hooks`, `render_reference_cycle`
  - `rendered_reference_results`, `rendered_copies`
  - `format_reference_pointees`, `format_slice_ref_slots`, `format_storage_keeps`
- **Runtime:**
  - `native_stack_overflow`: stack overflow is not detected.
  - `f32_casts_unchecked`: cast rounding.
  - `slice_pool`.
  - `frame_pool_references`.
  - `zero_length_values`: call count.
- **Layout and values:** `large_fixed_values`, `limited_string_literals` (capacity), `bytes_value_equality`, `pad_only_layouts`.
- **stdlib os:** `stdlib_os_dirs`, `stdlib_os_replace`.
- **Other:**
  - `namespaces`: a global initialized twice.
  - `branch_slice_joins`: string capitalization lost.
  - `index_types`.
  - `thread_contained`: assertion message.

### 1.4 Native-only gaps (18 tests; the C path handles these)

- Nested arrays of variable-size elements (3).
- `to_bytes` / `from_bytes` of variable-size elements and limited arrays (4).
- Calling and exporting C `extern` functions natively (4: `export`, `bce_export_entry`, `pkg_float_abi`, `pkg_own_c`). This needs dynamic linking in the ELF writer: `DT_NEEDED`, PLT/GOT and the SysV call ABI for floats and structs. **The same work unlocks Vulkan and SDL3 (section 3).**
- "Constructing a value" for some type kinds (3).
- `embed_file` with a non-literal path, one float operation (`flexible_shifts`), parameter defaults that capture, and variant payloads that are themselves variants.

### 1.5 C path (46 tests whose emitted C fails to compile)

Lower priority, since the C path is the oracle and not the product. It still matters because every native result is checked against it.

- An `if` expression yielding `null` or a pool element into a pool-relative field (`Link{to: if c { null } else { cells[i] }}` with `to Cell&<u16 in cells>?`) emits an assignment of `void*`/the struct to the `int16_t` storage, so clang rejects it. Not in the corpus; `hc/test/relref_guard.he` builds its links with statements instead.

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
  - Stores may go through row slices (a data pointer plus a loop-invariant offset), so `bench/goose/blur_rows.goose` vectorizes too.
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

## 3. Own everything (replacing Goose and third-party C)

- **Graphics (`gfx`):** done: hc/lib/gfx.he, the whole goose_gfx API on SDL3's GPU API (dlopened libSDL3), with the C layer's checks and misuse messages.
- **Shaders (both paths agreed):**
  - Our own shader compiler from the Helium shader subset to SPIR-V for Vulkan, plus GLSL text for WebGL.
  - Replaces `src/shaderc.c` and `src/amni_gpu.h`, plus `embed_shader` / `lut fn` GPU tables.
- **`physics`:** done (hc/lib/physics.he, hc/lib/physics_engine.he). Left: starting a recording on a non-empty world, recording queries.
- **`ui`:** done: hc/lib/ui.he (Nuklear under its public-domain option, no C layer) and hc/lib/ttf.he (TrueType outlines, rasterizing, rect packing). ProggyClean is still the built-in default font; ttf.he reads `glyf` outlines only, so CFF (`.otf`) fonts are not loaded yet.
- **Pom-Pom Grove app** (`eng/`, `app/`, `pomling.amni`): builds only with Goose today. It moves once gfx and shaders exist.
- **Driver features in `src/main.cpp` that hc lacks:**
  - hc has `--native` and `--debug` only.
  - Missing: build files and `helium build`, packages (`--update`, `--refresh`, `--offline`), cached and JIT runs, `--check`, `--dump`/`--tokens`/`--parse`, `--stack-reserve`, `--multi-test`, `--standalone`, `--compile-shader`.
- **Web target:** `main` has `--web` through clang + WASI. hc needs its own wasm32 emitter plus `web`, `webgl` and `web.js` in `hc/lib`; those are the only stdlib modules hc lacks.
- **LSP:** ~3.6k lines of C++ in `src/lsp*.h`, to be rewritten on hc's parser and checker.
- **More targets:**
  - arm64 code generation.
  - Mach-O for the Mac and iOS (Waystone, TOS Learn).
  - Android arm64 ELF.
- **Bootstrap without C:** hc is still seeded from `hc/seed/hc.c` through clang. Ship a native seed binary so a fresh build needs no C compiler. Keep the C path as the oracle.
- **Last step:** delete the Goose C++ compiler (`src/`, ~67k lines) and the `stdlib/*.goose` duplicates. Keep the License and Credits.

## 4. Housekeeping

- Move the gate and perf tools from the session scratchpad into `tools/hc/` so they survive: `parity.sh`, `pcount`, `psamp`, `attr.py`, `annot.py`. The gate runs C corpus, then parity, then native corpus.
- Branches:
  - `selfhost` is frozen at `48753be8`.
  - `amni` has 1 commit not on `main`: the checker change for static strings in `let` tables.
  - `web` has 2 commits not on `main`.
  - Merge or retire both.

## Suggested order

1. Native dynamic linking and the C ABI (1.4). This unblocks externs, Vulkan and SDL3.
2. Pool-relative references and the aliasing output bugs (1.3).
3. Checker gaps, biggest groups first: overloads, `const for`, generics (1.2).
4. `gfx` on SDL3 (done), `ui` (done), `physics` (done), then the shader compiler, then the Pom-Pom Grove app on hc.
5. Performance passes alongside: `separate`, `reachable`, BLAKE3, bounds checks in loops.
6. Driver features, packages, web target, LSP.
7. arm64 and Mach-O.
8. Native seed, then delete Goose.
