# hc: what's left

Status as of 2026-10-27 (gate 65).

## Where things stand

| | Now |
|---|---|
| hc source | `hc/*.he` and `hc/lib/*.he`, all in the `.he` syntax below; the library was rewritten from scratch, and `json`/`regex` were fuzzed against the old one |
| Self-host | hc builds itself natively, reaches a fixpoint, and emits the same C as the clang-built hc (`hc/bootstrap.sh` checks both) |
| Corpus, native (`--native`) | 625 / 645 pass |
| Corpus, C path | 539 / 645 pass |
| hc's own tests | `hc/test/*.he` with `.out` files; `tools/hc/hetest.sh <hc>` runs each one through the C path, `--native` and `--native --debug` |
| Pom-Pom Grove sim | garden, race, mini, load traces bit-identical on both paths |
| Own modules replacing Goose packages | `audio` (hc/lib/audio.he on SDL3: the same mixer, bit-identical to goose_gfx offline and live). `gfx`, `ui` and `physics` still load the goose_gfx/goose_physics packages |
| Full apps | Pom-Pom Grove (`pomling.amni`, gfx + ui) compiles with hc on both paths; it is not run here, since it opens the GPU |
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
  - Runtime guards for bounds and aliasing, with the scalar loop kept as the tail.
  - `HC_NOVEC=1` turns it off.
  - Gate any change to it with `python3 tools/hc/vecfuzz.py <hc> [count] [first seed]`. It runs random loop programs with and without `HC_NOVEC` and compares exit codes and output. Run it with both the C-built `hc` and the natively built `hcn`: the native one runs `vec.he` as native code. In October 2026 that exposed a native double release that the C-built compiler hid.
  - Blur runs 9x faster. Not yet supported: floats, conditionals (select), gathers, AVX2, and strided or struct-of-arrays access.
- **Inlining heuristics:** size limits are hand-tuned with no profile feedback.
- **Compile time:** hc self-compile is ~300 ms, up from ~206 ms before the optimizer passes. Main costs: two value-numbering passes, LICM, rebuilding IR after strength reduction.

## 3. Own everything (replacing Goose and third-party C)

- **Graphics (`gfx`):** today this is the `goose_gfx` package (~3.9k Goose lines plus vendored C).
  - Replace it with our own Vulkan + SDL3 bindings written in Helium.
  - Needs native dynamic linking (1.4) first.
  - The Pom-Pom Grove frontend uses 43 `gfx::` functions, which sets the minimum API.
- **Shaders (both paths agreed):**
  - Our own shader compiler from the Helium shader subset to SPIR-V for Vulkan, plus GLSL text for WebGL.
  - Replaces `src/shaderc.c` and `src/amni_gpu.h`, plus `embed_shader` / `lut fn` GPU tables.
- **`physics`:** today `goose_physics` (~1.7k Goose lines plus vendored C). Write our own in Helium.
- **`ui`** and **`audio`:** our own modules in Helium (audio on raw ALSA/PipeWire or through SDL3).
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
4. `gfx` on Vulkan + SDL3, then the shader compiler, then the Pom-Pom Grove app on hc.
5. Performance passes alongside: `separate`, `reachable`, BLAKE3, bounds checks in loops.
6. Driver features, packages, web target, LSP.
7. arm64 and Mach-O.
8. Native seed, then delete Goose.
