# Chapter 2: Types and static semantics

Status: draft. Derived from the hc front end (`hc/types.he`, `hc/check.he`, `hc/decl.he`, `hc/calls.he`, with `hc/prov.he`, `hc/parse.he` and `hc/lower.he` where a rule is enforced there) and from hc runs on 2026-11-05. Informal reference: `HELIUM.md`. Known gaps: `hc/TODO.md`.

Evidence directory: `spec/probes/ch2/` (test programs `*.amni` and `*.he`; all binaries deleted). Commands: `HC_LIB=this repository/hc/lib ./build/hc build <file> -o <out>`, then run `<out>`. `--debug` is stated where used. Each evidence item names its program. "accepted" means `hc build` exited 0.

Status legend:

- **CONFIRMED**: my hc run agrees with the rule.
- **KNOWN GAP**: hc accepts a program the guide says is invalid, rejects a program the guide says is valid, or does not enforce a documented rule.
- **UNCONFIRMED**: not run, or the run was inconclusive. The reason is given.

Diagnostics are quoted from hc. A rejection with a misleading message is still CONFIRMED when the program is rejected; the message is noted separately.

---

## 2.1 Type language

### 2.1.1 Grammar of types (abstract)

```
τ ::= void | bool | IntS | FltS | byte                 (byte = u8)
    | varint
    | τ[k]            fixed array, k a constant        (AK_FIXED)
    | τ[]             sized at construction, frozen    (AK_VAR)
    | τ[..k]          inline capacity k                (AK_LIM)
    | τ[>..]          grow-only growable               (AK_GROW)
    | τ[>..<]         grow-shrink growable             (AK_GS)
    | τ[:]            slice view (flag: const)
    | τ&  | τ?  | τ&<w>     reference / optional reference / self-relative link
    | S<τ̄>            struct instance (generic arguments)
    | E<τ̄>  | E.V      enum instance, variant type
    | fn              function value (compile-time only)
    | (τ1, ..., τn)   multi-result (calling convention, not a tuple)
    | τ_lit           untyped literal: integer, float, null, string, array literal
```

Sources: `hc/types.he:2` (kinds `TY_*`), `hc/types.he:4` (`struct Ty`), `hc/types.he:60` (`types_init`), `hc/types.he:27` (`tmk`: structurally equal types share one index), `hc/decl.he:194` (`rtype`, surface type to internal type), `hc/types.he:94` (`int_storage_of_tok`, word to storage class).

Word aliases: `int` = i64, `uint` = u64, `byte` = u8, `real` = f64. Others: `i8 i16 i32 u8 u16 u32 u64 i64 f32 f64 bool varint`.

### 2.1.2 Scalars

| Type | Bits | Signed | Range | Source |
|---|---|---|---|---|
| `i8 i16 i32 i64` | 8/16/32/64 | yes | `int_min` to `int_max_u` | `hc/types.he:105`, `hc/types.he:110` |
| `u8 u16 u32 u64` | 8/16/32/64 | no | 0 to 2^bits - 1 | same |
| `f32 f64` | 32/64 | n/a | IEEE | `hc/types.he:60` |
| `bool` | 1 byte | n/a | false, true | `hc/types.he:154` (`tsize`) |
| `varint` | variable | n/a | arbitrary | `hc/types.he:2` |

**TY-Int-Width**. The integer types above, with the stated sizes.
Source: `hc/types.he:60`, `hc/types.he:98` (`prim_type`).
Evidence: `lit_int_acc.amni` (`let b i8 = 100; let c u8 = 255; let d f32 = 3;`, accepted, prints `100 255 3.0`).
Status: CONFIRMED.

**TY-Bool**. `bool` is distinct from integers. Bitwise operators apply to it; arithmetic does not.
Source: `hc/types.he:60` (`T_BOOL`), `hc/check.he:404`, `hc/check.he:405`.
Evidence: `bool_rej.amni` (`let b bool = 1;` rejected, `expected a value of type bool, got i64`); `if_nonbool_rej.amni` (rejected); `bitand_bool_acc.amni` (`true & false`, `true ^ true`, accepted, prints `false false`); `bool_arith_rej.amni` (`true + 1`, rejected).
Status: CONFIRMED.

**TY-Flt-Width**. `f32` and `f64`; `real` is `f64`.
Source: `hc/types.he:60`, `hc/types.he:98`.
Evidence: `f64_f32_rej.amni` (`let r real = 1.5; let f f32 = r;` rejected, `(f64 to f32 requires an explicit as f32 to round the value)`); `float_int_acc.amni` (`let g f32 = 1.5;` accepted).
Status: CONFIRMED.

### 2.1.3 Value kinds

Layout class (`CL_FIXED`, `CL_VAR`, `CL_RES`; `hc/types.he:132` `tclass`) decides whether a value has a compile-time size. Fixed-size values copy on assignment. Variable-size and growable values alias (TY-Copy-Fixed).

Sources: `hc/types.he:132` (`tclass`), `hc/types.he:141` (`is_fixed`), `hc/types.he:154` (`tsize`), `hc/types.he:176` (`si_layout`), `hc/types.he:217` (`ei_layout`).

## 2.2 Typing judgment

Notation: Γ maps each name to `(τ, f)`, where `f` is a set of flags from `hc/check.he:3`: `LV_VAR` (var), `LV_CONST` (const), `LV_REF` (reference binding), `LV_PARAM`, `LV_FOR`, `LV_PEND` (not yet typed). A `let` binding has no `LV_VAR` flag.

`widens(s, t)` is `hc/check.he:135`. `int_fits(n, t)` is `hc/check.he:130`. `common(s, t)` is the operand type chosen by `hc/check.he:350` (`ck_bin`). `narrowed(p)` means `p` is refined by an enclosing `if`, `while`, `guard` or `assert`.

Rules (names are the IDs used in §2.4):

```
(x : τ, f) ∈ Γ
----------------------------- (TY-Var)
Γ ⊢ x : τ

Γ ⊢ e : s     widens(s, t)
------------------------------- (TY-Widen)                  .amni and .he
Γ ⊢ e : t

Γ ⊢ e : s     s and t integer, not widens(s, t)
---------------------------------------------- (TY-Narrow-Amni)   rejected in .amni
Γ ⊢ e : t          (accepted in .he, see TY-Narrow-He)

Γ ⊢ n : ILIT     int_fits(n, t)
-------------------------------- (TY-Lit-Adapt)
Γ ⊢ n : t

Γ ⊢ n : ILIT     not int_fits(n, t)
------------------------------------ (TY-Lit-Fit)           rejected
error

Γ ⊢ e : ILIT     no destination type
----------------------------------- (TY-Lit-Default)
Γ ⊢ e : int

Γ ⊢ e1 : s     Γ ⊢ e2 : t     u = common(s, t) defined
---------------------------------------------------- (TY-Arith-Common)
Γ ⊢ e1 op e2 : u

Γ ⊢ e : τ     τ numeric     σ numeric
------------------------------------ (TY-Cast)
Γ ⊢ e as σ : σ

Γ ⊢ c : bool     Γ ⊢ a : t     Γ ⊢ b : t
------------------------------------- (TY-If)
Γ ⊢ if c { a } else { b } : t

Γ ⊢ f : fn(τ1..τn) σ     Γ ⊢ a_i : τ_i
---------------------------------------- (TY-Call)
Γ ⊢ f(a1..an) : σ

Γ ⊢ f<T>(a) : σ[T := τ]     τ = unify(types of a)    (TY-Generic-Infer, TY-Generic-Unify)

Γ ⊢ p : T?     narrowed(p)
------------------------------ (TY-Opt-Narrow)
Γ ⊢ p.f : type of f in T

Γ ⊢ p : T?     not narrowed(p)
------------------------------ (TY-Opt-Narrow)              must reject; hc accepts (KNOWN GAP)
error
```

The judgment describes hc's behavior. It is a sketch, not a calculus with a soundness proof. Where hc departs from the guide, the departure is recorded as a KNOWN GAP in §2.4 and the rule above states the intended behavior.

## 2.3 Implicit conversions

`conv(n, t)` (`hc/check.he:190`) is the single point where a value of type `f` is accepted where `t` is expected. It accepts, in order:

1. identical types (`hc/check.he:194`);
2. an integer literal that fits (`hc/check.he:210`, using `int_fits`, `hc/check.he:130`), and a float literal to a float type (`hc/check.he:212`);
3. a string literal to a byte slice or byte array (`hc/check.he:213`);
4. an array literal to an array or slice (`hc/check.he:214`);
5. `null` to an optional reference (`hc/check.he:215`);
6. `conv_ok` (`hc/check.he:216`, `hc/check.he:221`): `widens`, a slice from an array of the same element type, a string literal to a byte slice, a reference adjustment, a variant to its enum;
7. (`.he` only, `!OLDLOC`) an integer narrowing, checked at run time in `--debug` (`hc/check.he:217`, `set_cvn`).

Otherwise the diagnostic is `expected a value of type T, got U (...)` (`hc/check.he:219`), with a hint naming the fix (`as`, or `f32` rounding).

Implicit narrowing exists only in `.he` files (TY-Narrow-He). In `.amni` it is always an error (TY-Narrow-Amni).

## 2.4 Rules

Each entry gives the rule, its compiler location, the evidence, and the status.

### Types and literals

**TY-Lit-Adapt**. An integer literal takes the type of its destination if it fits. Integer literals are untyped (`TY_ILIT`, `hc/types.he:60`) until converted.
Source: `hc/check.he:210`, `hc/check.he:130` (`int_fits`).
Evidence: `lit_int_acc.amni` (`let b i8 = 100` accepted); `arg_lit_acc.amni` (`h(100)` for an `i8` parameter accepted, prints `100`).
Status: CONFIRMED.

**TY-Lit-Fit**. An integer literal that does not fit its destination is an error.
Source: `hc/check.he:210` (`constant N does not fit T`).
Evidence: `lit_int_rej.amni` (`let b i8 = 300;` rejected, `constant 300 does not fit i8`); `const_overflow_rej.amni` (`let c i8 = 200;` rejected); `neg_lit_u8_rej.amni` (`let u u8 = -1;` rejected, `constant -1 does not fit u8`); `he_lit_rej.he` (`b i8 := 300` rejected in `.he`).
Status: CONFIRMED.

**TY-Lit-Default**. With no destination, an integer literal defaults to `int` (i64). A float literal defaults to `f64` only when no typed destination meets it. A `let`-bound float literal keeps the literal type and adapts to a later `f32` destination (see status).
Source: `hc/check.he:1060` (`ck_vdecl`), `hc/check.he:272` (`default_t`).
Evidence: `lit_default_acc.amni` (`let x = 5; let y = x * 2; print(y);` prints `10`); `lit_default_rej.amni` (`let y i32 = x;` with `x` defaulted to `int`, rejected); `r_floatprec_2.amni` (`let f = 0.1; let back real = f;` prints `true`, so the float stays f64 when no typed destination meets it). `p_litdefault_rej_1.amni` (`let f = 1.5; let g f32 = f;`) is accepted, and `r_floatprec_1.amni` (`let f = 0.1; let g f32 = f; let back real = g;`) prints `false 0.10000000149011612`, so `f` was rounded to f32.
Status: KNOWN GAP for floats. The integer default is CONFIRMED. A `let`-bound float literal is not fixed to f64: it adapts to an `f32` use and bypasses TY-Flt-Width, which rejects a `real` variable at the same point (`f64_f32_rej.amni`).

**TY-Float-Lit**. A float literal converts to `f32` or `f64` without a cast.
Source: `hc/check.he:212` (`TY_FLIT` to `TY_FLT`).
Evidence: `float_int_acc.amni` (`let g f32 = 1.5;` accepted).
Status: CONFIRMED.

**TY-Null**. `null` has type `TY_NULL` and is a value only of an optional reference type.
Source: `hc/check.he:215`, `hc/check.he:218` (`null is only a value of optional types`).
Evidence: `null_int_rej.amni` (`let n int = null;` rejected, `null is only a value of optional types, not i64`); `null_a.amni` and `null_b.amni` (`Node?` field and var initialized with `null`, accepted).
Status: CONFIRMED.

**TY-Opt**. `T?` is a nullable reference. Only optional types take `null`.
Evidence: see TY-Null.
Status: CONFIRMED.

**TY-Str-Lit**. A string literal has type `const u8[:]` (`TY_STRLIT`, `hc/types.he:60`) and converts to a byte slice or byte array (`hc/check.he:213`).
Evidence: the type name `const u8[:]` appears in the diagnostic from `if_branch_mismatch_rej.amni` and `match_arm_type_rej.amni`. No test converted a string literal to a byte array.
Status: UNCONFIRMED (the type name was observed; the conversion was not run as a test).

### Arrays, slices, growable

**TY-Fixed**. `T[k]` is a fixed-size array of `k` elements, `k` a compile-time constant.
Source: `hc/decl.he:214` (`constant integer expression expected for array size`).
Evidence: `fixed_arr_acc.amni` (`let a int[3] = [1, 2, 3]; var b = a; b[0] = 9;` prints `1 9 3`).
Status: CONFIRMED.

**TY-Copy-Fixed**. Fixed-size values copy on assignment. Non-fixed values alias.
Source: `hc/check.he:1107` (`ck_assign`), `hc/check.he:1060` (`ck_vdecl`; `is_fixed` decides `t_ref` for non-fixed inference), `hc/types.he:141` (`is_fixed`).
Evidence: `fixed_arr_acc.amni` (copy: `a[0]` stays `1`); `fixed_copy_struct_acc.amni` (`var q = p; q.x = 9;` leaves `p.x` at `1`, prints `1 9`); `grow_alias_acc.amni` (`let h = g; h.push(2);` makes `g.len` `2`, prints `2 3` with `copy(g)` independent).
Status: CONFIRMED.

**TY-Fixed-Lit-Length** (gap). A fixed array literal shorter than `k` should be an error under the usual reading of `T[k]`. HELIUM.md is silent. hc accepts it and zero-fills the rest.
Source: `hc/check.he:993` (`ck_arr`); no length check in `ck_vdecl` (`hc/check.he:1060`).
Evidence: `fixed_arr_len_rej.amni` (`let a int[3] = [1, 2];` accepted, `a[0]` prints `1`); `fixed_short_lit.amni` (`a[2]` prints `0`).
Status: KNOWN GAP. Decide whether to reject, or document zero-fill as the rule.

**TY-Grow**. `T[>..]` is grow-only; its elements never move. HELIUM.md (Arrays and strings): a struct holds at most one resizable array (`T[>..]` or `T[>..<]`), as its last field.
Source: `hc/types.he:43` (`t_arr`, array kinds), `hc/check.he:1138` (`cannot assign field ... through a reference`). A search of `hc/*.he` for a struct placement or count check found none (`parse.he:133` only parses the `T[>..]` and `T[>..<]` forms).
Evidence: `grow_alias_acc.amni` (`push` through an alias); `varsize_field_through_ref.amni` in `test/errors_tc` (repo test, rejected with `cannot assign field mode through a reference`); `q_growstruct_acc_1.amni` (`struct G { a int[>..], b int[>..] }`, both pushed, prints `1 1`); `q_growstruct_acc_2.amni` (`struct G2 { a int[>..], b int }`, prints `1 3`); `p_grow_acc_3.amni` (`struct G5 { v int, a int[>..<] }`, last field, prints `1`); `q_inlinecap_acc_1.amni` (`struct H { v int, a int[..4] }`, `push`, prints `1`).
Status: KNOWN GAP. hc accepts two resizable fields and a resizable field before a plain field, so the one-per-struct and last-field placement are not enforced. The text "the only resizable array" is also wrong: `T[>..<]` and inline-capacity `T[..k]` are resizable too.

**TY-Grow-Return**. Returning an owned growable local moves it. The `return copy(...)` diagnostic applies only to non-fixed values that do not outlive the function (`ret_esc`, `hc/check.he:1050`).
Evidence: `growable_return_rej.amni` (`fn mk() int[>..] { var t int[>..] = []; t.push(1); t }`, accepted, prints `1`). The file name says rejected; the program is accepted and the behavior matches the code.
Status: CONFIRMED.

**TY-Slice**. `T[:]` is a view of a fixed or growable array with the same element type. The view does not copy.
Source: `hc/check.he:221` (`conv_ok`), `hc/check.he:600` (`ck_slice`).
Evidence: `slice_acc.amni` (`total(a)` on `int[3]` and `total(g)` on `int[>..]`, prints `6 4`); `test/typing/slice_to_array_param.amni` (accepted, rc 0).
Status: CONFIRMED.

**TY-Slice-Lit**. A scalar is not a slice.
Evidence: `lit_slice_rej.amni` (`let x int[:] = 5;` rejected, `expected a value of type i64[:], got i64`).
Status: CONFIRMED.

**TY-Slice-ReadOnly**. A read-only (const) slice or string literal cannot be passed to a parameter the function writes through. The fix is `copy(...)`.
Source: `hc/prov.he` (provenance pass, §9.5), `hc/prov.he:887-890` (the message is at `prov.he:890`; corrected from 840, which is the `const` assignment check).
Evidence: repo test `test/errors_tc/const_slice_written.amni` (rejected: `cannot pass a read-only slice (const or a string literal) to a parameter the function writes through`). That test rejects only when the view reaches a `const byte[:]` parameter. `p_slicero_rej_1.amni` (`const k int[2] = [1, 2]; w(k);` with `fn w(xs int[:]) { xs[0] = 9; }`) is accepted; it runs and dumps core, also under `--debug`. `p_slicero_rej_2.amni` (`w("abc")` with `fn w(xs byte[:]) { xs[0] = 66; }`) is accepted and dumps core.
Status: KNOWN GAP. A read-only view made directly from a const array or a string literal is accepted by a writing parameter, and the write goes to read-only data.

**TY-Index-Int**. An index must be an integer. Indexing a non-indexable type is an error.
Source: `hc/check.he:593` (`index must be an integer`), `hc/check.he:598` (`cannot index`).
Evidence: `index_type_rej.amni` (`a["x"]` rejected).
Status: CONFIRMED.

### Structs and enums

**TY-Struct-Nominal**. Structs are nominal: two structs with identical fields are different types.
Source: `hc/types.he:52` (`t_struct`, keyed by declaration), `hc/check.he:219` (mismatch diagnostic).
Evidence: `nominal_rej.amni` (`struct A { x int }`, `struct B { x int }`, `let b B = a;` with `a A`, rejected, `expected a value of type B, got A`).
Status: CONFIRMED.

**TY-Struct-Lit-Style**. A struct literal is all named or all positional.
Source: `hc/calls.he:1057` (`struct literal mixes named and positional initializers`).
Evidence: `lit_mixed_rej.amni` (`P { x: 1, 2 }` rejected).
Status: CONFIRMED.

**TY-Struct-Lit-Complete**. Every field without a default must be given. A defaulted field may be omitted.
Source: `hc/calls.he:1078` (`missing field`), `hc/calls.he:1079` (`missing initializer for field`).
Evidence: `lit_missing_rej.amni` (`Q { a: 1 }` rejected, `missing field b in Q`); `lit_nodefault_rej.amni` (`V { }` rejected, `missing field a in V`); repo tests `test/errors/rest_nonoptional_reference.amni` and `test/errors/default_nonoptional_reference.amni` (rejected with the expected text). Not covered by the rule: duplicate fields. `p_litcomplete_rej_3.amni` (`P { x: 1, x: 2 }`) is accepted and prints `1`.
Status: CONFIRMED.

**TY-Struct-Default**. A field may declare a default (`hp i32 = 100`). The default is used when a literal omits the field.
Source: `hc/calls.he:1078` (`!given && f.def < 0` leaves defaulted fields out of the missing-field check; corrected from 1064, which is the field-name lookup), `hc/parse.he:719` (`pfields`).
Evidence: `struct_default_acc.amni` (`U { kind: 1 }`, then `u.hp` prints `100`).
Status: CONFIRMED.

**TY-Struct-Eq**. Structs compare with `==`.
Evidence: `eq_struct_acc.amni` (`a == b` on equal fields, accepted, prints `true`).
Status: CONFIRMED.

**TY-Struct-Order** (gap). `<`, `<=`, `>`, `>=` on structs. The checker allows the operator when every leaf of the struct has one numeric kind (`leaf_kind`, `hc/check.he:336`; check at `hc/check.he:392`), and rejects mixed-kind structs. HELIUM.md defines only `==` for structs. The native backend does not implement the homogeneous case.
Evidence: `cmp_mixed_struct_rej.amni` (`M { a int, b real }`, `x < y`, rejected, `compare fields, as in a.x < b.x`); `cmp_homog_struct_acc.amni` (`V2 { x real, y real }`, `<`, accepted by the checker; the native backend fails: `native backend: unsupported expression (kind 17, op 0, resolved 9)`). `cmp_struct_rej.amni` (`struct P { x int }`, `a < b`: accepted, prints `true`), so a single-int struct runs natively; the backend gap is narrower than the text says.
Status: KNOWN GAP.

**TY-Field**. A field access must name an existing field.
Source: `hc/check.he:577` (`no field`), `hc/check.he:547` (`ck_dot`).
Evidence: `field_unknown_rej.amni` (`p.zz` rejected, `no field zz in P`).
Status: CONFIRMED.

**TY-Enum-Match-Exhaustive** (gap). A `match` on an enum must cover every variant (HELIUM.md: "`match` on enums is exhaustive"). `ck_match` (`hc/check.he:774`) does not check coverage, and no exhaustiveness diagnostic exists in `hc/*.he`.
Evidence: `enum_match_rej.amni` (arms for `Red` and `Green` only; accepted; `name(Color.Blue)` prints `0`); `enum_match_acc.amni` (all three variants, prints `2`).
Status: KNOWN GAP. A missing arm silently yields zero.

**TY-Match-Int-Wildcard** (gap). A `match` on integers requires `_` (HELIUM.md: "on integers needs `_`"). hc accepts it without.
Evidence: `int_match_rej.amni` (`match n { 0 => 1, 1 => 2, }`, accepted); `int_match_out.amni` (`f(5)` returns `0`, no trap).
Status: KNOWN GAP.

**TY-Match-Int-Ok**. An integer `match` with range patterns and `_` is accepted and dispatches correctly.
Evidence: `int_match_acc.amni` (`0 => 1, 1..10 => 2, _ => 3`; `f(1)` and `f(50)` print `23`).
Status: CONFIRMED.

**TY-Match-Arms-Join**. All arms of a `match` must convert to one common type (`ck_match`, `hc/check.he:774`; the join at `hc/check.he:837`). Numeric arms join to the wider kind: `0 => 1, _ => 2.5` is accepted and yields `f64`.
Evidence: `match_arm_type_rej.amni` (`0 => 1, _ => "x"` rejected, `expected a value of type i64, got const u8[:]`); `p_matchjoin_rej_1.amni` (`let x = match n { 0 => 1, _ => 2.5, };`: accepted, prints `1.0`; the name says rej, the result is acc).
Status: CONFIRMED. The rule was corrected from "agree on one type" to the join above.

**TY-Variant-Ctor** (gap). A variant with a payload is constructed with braces (`Shape.Circle { r: 2.0 }`). The checker has the diagnostic `a variant with a payload is constructed with { }` (`hc/check.he:442`) for one path, but `Shape.Circle` named without braces is accepted and yields a zero payload.
Evidence: `variant_ctor_rej.amni` (`let s = Shape.Circle;` accepted); `variant_ctor_print.amni` (prints `Circle { 0.0 }`).
Status: KNOWN GAP.

**TY-Variant-Ok**. Payload variants constructed with braces, and `match` binding of the payload.
Evidence: `variant_ctor_acc.amni` (`Shape.Circle { r: 2.0 }`; `area` by `match`; prints `12.0 0.0`).
Status: CONFIRMED.

**TY-Generic-Struct**. Generic structs take arguments in `<...>` at construction, or infer them from the field values. The argument count must match.
Source: `hc/decl.he:249` (`inst_struct`), `hc/decl.he:276` (`inst_enum`).
Evidence: `struct_generic_acc.amni` (`Pair<int> { 1, 2 }`, prints `3`); `struct_generic_rej.amni` (`Pair<int> { 1, 2.0 }` rejected, `expected a value of type i64, got f64`); `p_genstruct_rej_1.amni` (`Pair { 1, 2 }` with no arguments: accepted, prints `1`, so inference works); `p_genstruct_acc_1.amni` (`Pair<real> { 1, 2 }`: prints `1.0`); `p_genstruct_rej_2.amni` (`Pair<int, int>` for one parameter: rejected, `wrong number of type arguments`).
Status: CONFIRMED. The rule was corrected: the earlier text ruled out inference, which hc accepts.

### Optionals and references

**TY-Opt-Narrow** (gap). A `T?` must be narrowed (`if`, `while`, `guard`, `assert`) before member access. hc accepts an unnarrowed access, and the program crashes.
Source: `hc/check.he:547` (`ck_dot`) does not require narrowing; no narrowing diagnostic exists in `hc/*.he`.
Evidence: `opt_nonnarrow_rej.amni` (`fn get(p Node?) int { p.v }`, called with `null`; accepted; the run dumps core).
Status: KNOWN GAP.

**TY-Opt-Narrow-Use** (gap). A narrowed `T?` parameter used inside its `if` branch (`if p { p.v } else { -1 }`, or `guard p else {...}`) is accepted by the checker and rejected by the native backend: `native backend: this branch reference natively (kind 17, resolved 9)`. A narrowed local works (`opt_v3.amni`).
Evidence: `opt_v1.amni`, `opt_v2.amni`, `opt_narrow_acc.amni` (native backend rejection); `opt_v3.amni` (`if r { print(r) }` on a local `int?`, accepted, prints `found 2`; it binds its array first, since `first([1, 2, 3])` returns a reference into a temporary and is rejected under MEM-4).
Status: KNOWN GAP (valid per HELIUM.md, rejected by the backend).

**TY-Opt-Store** (gap, root cause open). `var n Node? = null; n = m; print(n.v);` with `m` a `Node` value is accepted, and the release binary segfaults at run time (rc 139). Not reproduced under `--debug`, and the root cause is not found.
Evidence: `null_c.amni`.
Status: KNOWN GAP.

**TY-Ref-Param**. A `T&` parameter binds an lvalue and writes through to it. The caller passes a plain variable.
Source: `hc/calls.he:246` (parameter binding, `LV_PARAM`), `hc/check.he:1066` (`LV_REF`).
Evidence: `ref_param_acc.amni` (`inc(c)` twice on `var c = 0`, prints `2`); `p_refparam_acc_1.amni` (`inc(p.x)`, a field: prints `2`); `p_refparam_acc_2.amni` (`inc(xs[0])`, an element: prints `2`); `p_refparam_rej_1.amni` (`inc(g())`, a function result: rejected). A `let` variable is also accepted here (`r_letarg_1.amni`). That is the TY-Let-Immutable gap, not a failure of this rule.
Status: CONFIRMED.

**TY-Ref-Literal** (gap). A `T&` parameter binds an lvalue. HELIUM.md: "A reference parameter binds an lvalue without `&`." hc accepts a literal and binds a temporary.
Evidence: `ref_show_lit.amni` (`show(5)` with `show(n int&)` prints `5`); `ref_literal_rej.amni` (`inc(5)` accepted).
Status: KNOWN GAP.

**TY-Ref-Rebind**. `x .= e` rebinds a reference to another place.
Source: `hc/check.he:1066` (`byref`), `hc/check.he:1060` (`ck_vdecl`).
Evidence: `ref_let_acc.amni` (`var r .= xs[0]; r = 11;` changes `xs[0]`, prints `11`).
Status: CONFIRMED.

### Mutability and declarations

**TY-Let-Immutable**. A `let` binding cannot be reassigned. Its contents remain writable (HELIUM.md, Core: "`let` cannot be reassigned (contents still writable)"), so `p.x = 2` and `xs.push(1)` on a `let` are accepted. The earlier wording, limited to references and growable arrays, misquoted HELIUM.md.
Source: `hc/prov.he:833` and `hc/prov.he:835` (`cannot assign to let`), `hc/check.he:3` (flags).
Evidence: `let_assign_rej.amni` (`let x = 1; x = 2;` rejected, `cannot assign to let x (§4.4)`); `p_letassign_acc_1.amni` (`let xs int[>..] = []; xs.push(1);`: prints `1`); `p_letassign_rej_2.amni` (`let p = P { x: 1 }; p.x = 2;`: accepted, prints `2`, consistent with HELIUM.md); `r_letfieldcompound_1.amni` (`p.x += 1` on a `let`: prints `2`). Reassignment by other routes: `q_letcompound_rej_1.amni` (`let c = 1; c += 1;`: accepted, prints `2`); `q_letref_1.amni` (`let r .= xs[0]; r .= xs[1];` rebinds: `xs[1] = 7` then `print(r)` prints `7`); `p_refrebind_rej_1.amni` (same rebind, prints `2`); `r_letarg_1.amni` (`let c = 1; inc(c);` with `fn inc(n int&) { n += 1; }`: prints `2`).
Status: KNOWN GAP. `c = 2` is rejected, but a `let` is reassigned by compound assignment, by `.=` rebinding, and through an `int&` parameter. The `prov.he` check covers `=` only (as far as the evidence shows).

**TY-Var**. A `var` binding can be reassigned and compound-assigned.
Evidence: `var_assign_acc.amni` (`x = 2; x += 3;`, prints `5`).
Status: CONFIRMED.

**TY-Const**. A `const` binding is read-only in its contents.
Source: `hc/prov.he:840` (`cannot assign through this path (const, or a read-only instantiation, §9.5)`), `hc/check.he:1066` (`LV_CONST`).
Evidence: `const_write_rej.amni` (`const k int[3] = [...]; k[0] = 5;` rejected); `p_const_rej_1.amni` (`const c = 1; c = 2;` rejected); `p_const_rej_3.amni` (`const p = P { x: 1 }; p.x = 2;` rejected). Gaps: `p_const_rej_2.amni` (`const c int[>..] = []; c.push(1);`: accepted, prints `1`); `r_constcompound_rej_1.amni` (`const c = 1; c += 1;`: accepted, prints `2`).
Status: KNOWN GAP. Plain assignment to a `const` is rejected, but `push` on a `const` growable array and compound assignment to a `const` scalar both write.

**TY-Global-Init**. A `let` or `const` global needs an initializer. A `var` global may omit it.
Source: `hc/parse.he:702` (`let and const global declarations require an initializer`).
Evidence: `global_noinit_rej.amni` (`let g int;` rejected); `global_var_acc.amni` (`var g int;` accepted, prints `0`).
Status: CONFIRMED.

**TY-Decl-Needs**. A local declaration needs a type or an initializer.
Source: `hc/check.he:1103`.
Evidence: `decl_nothing_rej.amni` (`var q;` rejected, `a declaration needs a type or an initializer`).
Status: CONFIRMED.

**TY-Const-Cycle**. A cycle among global initializers is an error.
Source: `hc/check.he:489` (`cycle in constant initializer`).
Evidence: `global_cycle_rej.amni` (`let a = b; let b = a;` rejected).
Status: CONFIRMED.

**TY-Array-Size-Const**. A fixed array size is a compile-time constant. A `let` global with a constant initializer may be used.
Source: `hc/decl.he:214` (`constant integer expression expected for array size`), `hc/decl.he:305` (`ceval`).
Evidence: `const_arr_size_acc.amni` (`var a int[SIZE] = [1, 2, 3, 4];` with `let SIZE = 4;`, prints `4`); `arr_size_nonconst_rej.amni` (`int[n]` with `n` a parameter rejected).
Status: CONFIRMED.

### Numeric conversions

**TY-Widen**. Implicit widening: same signedness to a wider type; unsigned to a wider signed type; int to float; `f32` to `f64`.
Source: `hc/check.he:135` (`widens`), `hc/check.he:190` (`conv`).
Evidence: `widen_acc.amni` (`i8` to `int`, `u16` to `u32`; prints `-3 7`); `int_to_float_acc.amni` (`int` to `real`, `f32` to `real`; prints `3.0 1.5`).
Status: CONFIRMED.

**TY-Sign-Change**. In `.amni`, changing signedness needs `as`. In `.he`, the same conversion is an implicit narrowing and is governed by TY-Narrow-He.
Source: `hc/check.he:135`, `hc/check.he:219`.
Evidence: `sign_rej.amni` (`let b u32 = a;` with `a i32` rejected, `narrowing and sign changes require an explicit as`). `.he` counterexamples: `p_hesign_rej_1.he` (`b u8 := a` with `a := 9`: accepted, prints `9`); `r_hesign_neg_1.he` (`a := -1; b u8 := a`: accepted; `--debug` traps `-1 as u8`; release prints `255`).
Status: CONFIRMED for `.amni`. The unqualified wording was refuted for `.he`.

**TY-Narrow-Amni**. In `.amni`, narrowing an integer needs `as`.
Source: `hc/check.he:217` (the `.he`-only branch is skipped), `hc/check.he:219`.
Evidence: `narrow_rej.amni` (`let b i16 = a;` with `a int` rejected); `bad_narrow.amni` (`let b i8 = a;` rejected); `lit_default_rej.amni` (`let y i32 = x;` rejected).
Status: CONFIRMED.

**TY-Narrow-He**. In `.he`, an integer converts implicitly to a narrower integer at assignments, typed declarations, returns and struct fields. In `--debug` the value is checked and traps when out of range. In release it wraps, as `as` does. HELIUM.md states this for `.he` (via hc/TODO.md §0).
Source: `hc/check.he:217` (`!OLDLOC && FILES[...].he`, `set_cvn`), `hc/check.he:1058` (`intloc`).
Evidence:
- `he_decl_colon.he` (`b i16 := a`, `a := 9`), `he_assign_narrow.he` (`b = a`), `he_ret_narrow.he` (`fn f(a int) i16`), `he_field_narrow.he` (`P { x: a }` with `x i16`): accepted, print `9`.
- `he_decl_rej.he` (`b i8 := a`, `a := 9`): accepted, prints `9`.
- `he_wrap.he` (`a := 300`, `b i8 := a`): `--debug` aborts with `helium runtime error: as conversion out of range (debug): 300 as i8`; release prints `44`.
- `r_hesign_big_1.he` (`a := 300; b u8 := a`): `--debug` traps `300 as u8`; release prints `44`. `p_henarrowarg_rej_1.he` (an `int` variable passed to an `i8` parameter): rejected, so arguments still need `as`, as `hc/TODO.md` §0 says.
Status: CONFIRMED (for `.he` only).

**TY-Float-Int**. A float converts to an integer only with `as`.
Source: `hc/check.he:219` (`a float converts to an integer only with an explicit as`).
Evidence: `float_int_rej.amni` (`let n int = f;` with `f real` rejected); `assign_type_rej.amni` (`x = 1.5;` into an `int` rejected).
Status: CONFIRMED.

**TY-Int-Float**. An integer converts implicitly to a float.
Evidence: `int_to_float_acc.amni` (`let f real = i;` with `i int`, prints `3.0`); `lit_int_acc.amni` (`let d f32 = 3;`).
Status: CONFIRMED.

**TY-Float-Widen**. `f32` converts implicitly to `f64`. `f64` to `f32` needs `as`.
Evidence: `int_to_float_acc.amni` (`let b real = a;` with `a f32`); `f64_f32_rej.amni`.
Status: CONFIRMED.

**TY-Cast**. `x as T` converts between numeric types. Narrowing truncates in release and is checked in `--debug`. Float to integer truncates toward zero.
Source: `hc/check.he:613` (`ck_as`).
Evidence: `cast_int_acc.amni` (`300 as i8` prints `44`; `2.7 as int` prints `2`); `float_int_acc.amni` (`2.5 as int` prints `2`); `as_debug.amni` (`--debug`: `300 as i8` aborts with `as conversion out of range (debug)`). `t_castparen_1.amni`: `(-1) as u8` prints `255`, `-2.7 as int` prints `-2`, `2.7 as u8` prints `2`, `3.9 as i8` prints `3`. Precedence note: unary minus binds tighter than `as`, so `-1 as u8` is `-(1 as u8)` and is rejected as negating an unsigned value. Gap: `r_castbool_1.amni` (`print(5 as bool)`: accepted, prints `true`).
Status: KNOWN GAP for the target restriction. Truncation and the `--debug` check are CONFIRMED. A `bool` target is accepted from an integer, although the rule requires a numeric `T`.

**TY-Cast-Wrap**. `x as! T` wraps and is not checked in `--debug`.
Source: `hc/check.he:613` (`x.fl & 1` in `ck_as`).
Evidence: `cast_int_acc.amni` (`300 as! u8` prints `44`); `q_wrapdbg_info_1.amni` (`300 as! i8` under `--debug` prints `44`, no check); `q_wrapdbg_info_2.amni` (`300 as i8` under `--debug` aborts, showing the contrast).
Status: CONFIRMED.

**TY-Cast-Source**. `as` needs a numeric source.
Source: `hc/check.he:619` (`as requires a numeric source`).
Evidence: `cast_nonnum_rej.amni` (`xs as int` with an array `xs` rejected); `p_castsrc_rej_2.amni` (`let b = true as int;`: accepted, prints `1`). `hc/check.he:619` lists struct, array, slice, string-literal, array-literal and multi-result sources. `bool` is not in the list.
Status: KNOWN GAP. A `bool` source is accepted.

### Operators

**TY-Arith-Common**. An arithmetic operator takes the common type of its operands: the wider of two same-signedness integers (implicit widening), or a float if either side is a float. Mixed signedness with no common type is an error.
Source: `hc/check.he:327` (`operands of ... have no common type ... (convert one with as)`), `hc/check.he:350` (`ck_bin`).
Evidence: `arith_common_acc.amni` (`i8 + int`, accepted, prints `3`); `arith_sign_rej.amni` (`u32 + i32` rejected, `no common type: u32 and i32`); `q_negcast_info_1.amni` (`let a i8 = 100; print(a + a);`: the result type is `i8`, prints `-56`; under `--debug` it aborts with `integer overflow (debug): 100 + 100 at i8`).
Status: CONFIRMED.

**TY-Shift**. A shift needs integer operands.
Source: `hc/check.he:370` (`shift count must be an integer`), `hc/check.he:373` (`shift of a non-integer`).
Evidence: `shift_float_rej.amni` (`1.0 << 2` rejected).
Status: CONFIRMED.

**TY-Bool-Arith**. Arithmetic on bool is an error. Bitwise `&`, `|`, `^` on bool are allowed.
Source: `hc/check.he:404` (`bitwise operator on a non-integer`), `hc/check.he:405` (`arithmetic on bool`).
Evidence: `bool_arith_rej.amni` (`true + 1` rejected); `bitand_bool_acc.amni`; `p_boolarith_rej_1.amni` (`let b = true; print(-b);`: accepted, prints `true`); `q_negbool_1.amni` (`let b = false; print(-b);`: prints `false`).
Status: KNOWN GAP. Binary arithmetic on bool is rejected, but unary minus is accepted and returns its operand unchanged. The unary check at `hc/check.he:416` tests only `TY_INT`.

**TY-Neg-Unsigned**. Unary `-` on an unsigned value is an error. Convert with `as` first.
Source: `hc/check.he:416`.
Evidence: `neg_unsigned_rej.amni` (`-u` with `u u32` rejected).
Status: CONFIRMED.

**TY-Incdec**. `++` and `--` need an integer.
Source: `hc/check.he:1011`.
Evidence: `incdec_bool_rej.amni` (`b++` with `b bool` rejected, `++/-- needs an integer`).
Status: CONFIRMED.

**TY-Cmp**. A comparison yields `bool`. Numbers, `bool` and strings order with `<` and related operators (`true < false` is accepted and prints `false`). Arrays and slices do not order (`hc/check.he:392`).
Evidence: `eq_struct_acc.amni` (`1 < 2`, prints `true`); `p_cmp_acc_1.amni` (`"a" < "b"`: prints `true`); `p_cmp_info_1.amni` (`true < false`: accepted, prints `false`); `p_cmp_rej_1.amni` (`int[2] < int[2]`: rejected). Struct ordering is TY-Struct-Order.
Status: CONFIRMED. The rule now lists `bool`, which the compiler orders.

**TY-Assign**. The right side of an assignment must convert to the left side's type.
Source: `hc/check.he:1107` (`ck_assign`), `hc/check.he:190` (`conv`).
Evidence: `assign_type_rej.amni` (`var x int = 0; x = 1.5;` rejected).
Status: CONFIRMED.

### Control flow

**TY-If-Cond**. An `if` condition must be `bool`.
Source: `hc/check.he:688` (`ck_if`), `hc/check.he:190` (`conv`).
Evidence: `if_nonbool_rej.amni` (`if 1 { ... }` rejected, `expected a value of type bool`).
Status: CONFIRMED.

**TY-If-Value**. An `if` used as a value needs `else`. Both branches must convert to one common type; numeric branches join to the wider kind (`if c { 1 } else { 2.5 }` and `if c { 2.5 } else { 1 }` both yield `f64`, printing `1.0`).
Source: `hc/check.he:688` (`ck_if`); the join is at `hc/check.he:708` (`branches have mismatched types`).
Evidence: `if_value_noelse_rej.amni` (`let x = if true { 1 };` rejected). The diagnostic is `this expression has no value (the call returns nothing), so there is nothing to bind`, which is misleading; the rejection itself is correct. `if_branch_mismatch_rej.amni` (`1` against `"a"`, rejected). `p_ifvalue_rej_1.amni` (`if c { 1 } else { 2.5 }`: accepted, prints `1.0`); `q_ifjoin_info_1.amni` (`if c { 2.5 } else { 1 }`: accepted, prints `1.0`).
Status: CONFIRMED (rejections; the no-else message needs rewording; the numeric join is the corrected rule).

**TY-Loop-Break**. `break v` is allowed only in `loop` and `block`.
Source: `hc/check.he:954` (`break with a value exits loop/block only`), `hc/check.he:951` (`ck_break`).
Evidence: `loop_break_acc.amni` (`loop { ...; break n; }`, prints `35`); `for_break_value_rej.amni` (`for i in 3 { break i; }` rejected).
Status: CONFIRMED.

**TY-Return**. A function with a declared result must return a value on every path. A bare `return;` in a valued function is an error.
Source: `hc/check.he:865` (`return needs a value`), `hc/calls.he:254` (`must return ... but can reach its end without a value`).
Evidence: `ret_missing_rej.amni` (rejected); `ret_needs_value_rej.amni` (`return;` in an `int` function rejected); repo test `test/errors_tc/missing_return.amni` (rejected, `must return`).
Status: CONFIRMED.

**TY-Result-Infer**. A function without a declared result type infers it from its tail or returns.
Source: `hc/calls.he:189` (sets `rinf`; corrected from 179, which is parameter typing), `hc/calls.he:254` and `hc/check.he:865` (`!rinf` checks), `hc/calls.he:191` (`surely_void`).
Evidence: `ret_void_value_rej.amni` (`fn f(a int) { return a; }` accepted; the name is misleading, because the function is not void). `p_resultinfer_rej_1.amni` (`fn g(a int) { return a; }` with `let x = g(1); print(x);`: accepted, prints `1`).
Status: CONFIRMED.

**TY-Void-Value**. A call with no result has no value to bind.
Source: `hc/check.he:1092`.
Evidence: `void_value_rej.amni` (`let x = f();` with `f` returning nothing, rejected).
Status: CONFIRMED.

### Multiple results

**TY-Multi-Bind**. `let a, b = f();` binds the results of a multi-result call. The name count must equal the result count.
Source: `hc/check.he:1068` (`several names need a call's results`), `hc/check.he:1072` (`result count does not match the names`).
Evidence: `multi_ret_acc.amni` (`let q, ok = d(7, 2);`, prints `3 true`); `multi_count_rej.amni` (`let q, ok, z = d(...)`, rejected).
Status: CONFIRMED.

**TY-Multi-Scalar**. Several names with a scalar initializer is an error.
Source: `hc/check.he:1068` to `hc/check.he:1071`.
Evidence: `fn_multi_bind_rej.amni` (`let a, b = 5;` rejected, `several names need a call with as many results`); `p_multiscalar_rej_2.amni` (`let a, b = x + 1;`: rejected). Not covered by this rule: the list form `let a, b = 1, 2;` is accepted and prints `12` (`p_multibind_rej_2.amni`). It is undocumented.
Status: CONFIRMED.

**TY-Multi-Single** (gap). A multi-result call bound to one name is an error. HELIUM.md: "Several results are a calling convention, not a tuple." hc accepts it and binds the first result.
Evidence: `multi_single_rej.amni` (`let q = d(7, 2);` accepted, prints `3`).
Status: KNOWN GAP.

### Calls and overloads

**TY-Call-Arity**. The argument count must fit a candidate's parameters. Trailing parameters may have defaults.
Source: `hc/calls.he:443` (`ck_call`), `hc/calls.he:332` (`resolve`), `hc/calls.he:763` (`no matching overload for call to`).
Evidence: `arity_rej.amni` (`f(1, 2)` for `f(a int)` rejected, `no matching overload for call to f`).
Status: CONFIRMED.

**TY-Call-Default**. A trailing parameter default is used when the argument is omitted.
Source: `hc/calls.he:490` (`ck_pdef`).
Evidence: `default_arg_acc.amni` (`g(1)` and `g(1, 10)` for `g(a int, b int = 2)`, prints `3 11`). A default cannot name an earlier parameter: `fn g(a int, b int = a + 1)` is rejected with `unknown identifier: a` (`p_calldefault_info_1.amni`).
Status: CONFIRMED.

**TY-Call-Arg-Narrow**. An argument converts by widening or a literal fit only. Narrowing needs a cast at the call site, because overload matching does not narrow (`arg_rank`).
Source: `hc/calls.he:140` (`arg_rank`), `hc/calls.he:149` (integer-literal rank).
Evidence: `arg_narrow_rej.amni` (`h(x)` with `x int` and `h(a i8)` rejected, `no matching overload`); `arg_lit_acc.amni` (`h(100)` accepted).
Status: CONFIRMED.

**TY-Overload**. Overloads are ranked by `arg_rank` (`hc/calls.he:140`); the best rank wins. Two candidates at the best rank, both non-generic, make the call ambiguous.
Source: `hc/calls.he:332` (`resolve`), `hc/calls.he:394` (`ambiguous call to ...`).
Evidence: `overload_acc.amni` (`o(int)` and `o(real)`: `o(i)` returns `1`, `o(2.0)` returns `2`); `overload_tie_rej.amni` (`o(int, int)` and `o(int, int = 0)` called as `o(1, 2)`, rejected, `ambiguous call to o`).
Status: CONFIRMED.

**TY-Generic-Infer**. Untyped parameters make a function generic. `T` is inferred from the arguments and the function is monomorphized per instantiation. No trait bounds exist.
Source: `hc/calls.he:169` (`sig_inst`), `hc/calls.he:385` (`gen`, generic flag in `resolve`).
Evidence: `generic_acc.amni` (`id(3)`, `id(2.5)`, `idu("s")`, prints `3 2.5 s`).
Status: CONFIRMED.

**TY-Generic-Unify**. Two parameters declared with the same explicit type parameter (`fn same<T>(a T, b T)`) must agree after literal adaptation. A non-literal mismatch is an error. Untyped parameters (`fn same(a, b)`) get separate types and are not unified.
Source: `hc/calls.he:385` to `hc/calls.he:400` (candidate scoring with `GB` bindings).
Evidence: `generic_mismatch_var.amni` (`fn same<T>`, `let i = 1; same(i, 2.0)` rejected, `no matching overload for call to same`). Untyped form: `p_genunify_rej_1.amni` (`fn same(a, b)`, `same(2.0, i)` with `i` an `int`: accepted, prints `2.0`); `p_genunify_rej_3.amni` (`same(x_i8, y_int)`: accepted, prints `1`).
Status: CONFIRMED for the `<T>` form only.

**TY-Generic-Lit-Unify**. An integer literal argument adapts to the type of a sibling argument bound to the same `T`.
Source: `hc/calls.he:149` (`arg_rank`, `TY_ILIT`).
Evidence: `generic_mismatch_rej.amni` (`same(1, 2.0)` accepted, prints `1.0`, so `T = f64`); `s_genlit_info_1.amni` (`fn same<T>(a T, b T)`, `same(1.5, 2)`: prints `2.0`); `s_genlit_rej_1.amni` (`same<T>(x_i8, 300)`: rejected, `no matching overload`); `s_genlit_info_2.amni` (`same<T>(x_i8, 2)`: prints `2`).
Status: CONFIRMED (observed behavior; HELIUM.md does not state it).

**TY-Generic-Depth** (UNCONFIRMED). A chain of more than 16 instantiations of one generic declaration is an error.
Source: `hc/decl.he:246` (`ichain`, message `instantiating ... would chain more than 16 instantiations`), `hc/decl.he:260`, `hc/calls.he:230` (`more than 16 specializations`).
Evidence: none run.
Status: UNCONFIRMED (source only).

**TY-Recursion-Mark** (gap). Recursion must be marked `recursive` on the cycle's entry (HELIUM.md, Functions). hc accepts an unmarked self-recursive function.
Evidence: `recursive_missing_rej.amni` (`fn fact` calling itself, no `recursive`, accepted, prints `120`); `recursive_ok.amni` (the marked form, prints `120`).
Status: KNOWN GAP.

**TY-Recursion-Result** (UNCONFIRMED). A recursive call whose result type is not yet known is an error (`recursive call to ... needs its result type written`, `hc/calls.he:781`).
Evidence: `recursive_untyped_rej.amni` (`recursive fn` with no result type, accepted, prints `120`). The diagnostic did not fire.
Status: UNCONFIRMED (the diagnostic path was not reached by any program tried).

**TY-Fn-Value**. A function name is not a value. HELIUM.md: "Function values are compile-time only."
Source: `hc/calls.he:763` (`a function value must be a function name or block literal`), `hc/lower.he:156` (`unsupported variable`).
Evidence: `fnvalue_rej.amni` (`let g = f;` rejected by the native backend, `native backend: unsupported variable 3`). The front end accepts it.
Status: CONFIRMED (rejected). The diagnostic comes from the backend, so it is a poor message.

### Program structure and syntax

**TY-Main**. A program has exactly one global `fn main()`.
Source: `hc/calls.he:1158` (`if md < 0`: checks only that a `main` exists, and the message is `program needs exactly one global fn main()`).
Evidence: `fn_nomain_rej.amni` (no `main`: rejected); `q_main_info_1.amni` (two `fn main()`: accepted, prints `2`, so the last definition runs); `q_main_info_2.amni` (`fn main(a int)` and `fn main()`: accepted, prints `2`).
Status: KNOWN GAP. The absence of `main` is rejected. A second `main` is accepted and nothing diagnoses it.

**TY-He-Decl-Syntax**. In `.he`, a typed declaration is written `name T := e`; a typed variable is written `name T ~= e`. `name T = e` is a parse error.
Source: `hc/TODO.md` §0 (`.he` syntax), `hc/parse.he` (declarations).
Evidence: `he_decl_colon.he` (`b i16 := a`, accepted); `he_decl_typed.he` (`b i16 = a`, rejected, `';' expected after expression, found 'i16'`).
Status: CONFIRMED.

**TY-Repo-Corpus**. The repo's rejection tests reject with the diagnostic named in their `// error:` line.
Evidence, all rejected with the expected text: `test/errors_tc/bind_no_value.amni` (`this expression has no value`), `test/errors_tc/const_slice_written.amni` (`cannot pass a read-only slice`), `test/errors_tc/missing_return.amni` (`must return`), `test/errors_tc/varsize_field_through_ref.amni` (`cannot assign field mode through a reference`), `test/errors/default_nonoptional_reference.amni` and `test/errors/rest_nonoptional_reference.amni`. `test/typing/slice_to_array_param.amni` is accepted. Re-run in review: all six repo rejection programs reject, and each `// error:` text appears in the hc output.
Status: CONFIRMED.

---

## 2.5 Summary

Counts from the §2.4 status lines, after the skeptic review (see Review):

- CONFIRMED: 63
- KNOWN GAP: 20
- UNCONFIRMED: 3
- Total rules: 86 (each with one status line)

KNOWN GAP entries: TY-Fixed-Lit-Length, TY-Struct-Order, TY-Enum-Match-Exhaustive, TY-Match-Int-Wildcard, TY-Variant-Ctor, TY-Opt-Narrow, TY-Opt-Narrow-Use, TY-Opt-Store, TY-Ref-Literal, TY-Multi-Single, TY-Recursion-Mark, TY-Lit-Default (float part), TY-Grow, TY-Slice-ReadOnly, TY-Let-Immutable, TY-Const, TY-Cast (bool target), TY-Cast-Source, TY-Bool-Arith, TY-Main.

UNCONFIRMED entries: TY-Str-Lit, TY-Generic-Depth, TY-Recursion-Result.

## 2.6 Items for the owner

1. Exhaustive `match` on enums is documented but not enforced. A missing arm yields zero (`enum_match_rej.amni`). Enforce it, or change HELIUM.md.
2. An integer `match` without `_` is accepted (`int_match_rej.amni`), contrary to HELIUM.md.
3. An unnarrowed `T?` access is accepted and crashes (`opt_nonnarrow_rej.amni`). Add the narrowing check at `hc/check.he:547` (`ck_dot`).
4. Access through a narrowed `T?` parameter fails in the native backend (`opt_v1.amni`). This is valid per HELIUM.md.
5. A payload variant named without braces is accepted (`variant_ctor_rej.amni`).
6. A reference parameter accepts a literal (`ref_show_lit.amni`), contrary to HELIUM.md.
7. A multi-result call bound to one name is accepted (`multi_single_rej.amni`), contrary to HELIUM.md.
8. Unmarked self-recursion is accepted (`recursive_missing_rej.amni`), contrary to HELIUM.md.
9. A short fixed-array literal is accepted with zero-fill (`fixed_short_lit.amni`). Decide whether that is the rule.
10. The `if` value without `else` gets a misleading diagnostic (`if_value_noelse_rej.amni`).
11. The segfault in `null_c.amni` is unexplained. Find the cause before a rule for optional stores is written.
12. Struct ordering is accepted for homogeneous structs and fails in the backend (`cmp_homog_struct_acc.amni`). Define it, or reject it in the checker.
13. A function value (`let g = f;`) is rejected only by the native backend (`fnvalue_rej.amni`). Move the check into the front end.
14. A `let` is reassigned by compound assignment (`c += 1`), by `.=` rebinding, and through an `int&` parameter (`q_letcompound_rej_1.amni`, `q_letref_1.amni`, `r_letarg_1.amni`). Extend the `let` check beyond `=` (`hc/prov.he:833-835`).
15. A `const` growable array accepts `push`, and a `const` scalar accepts `+=` (`p_const_rej_2.amni`, `r_constcompound_rej_1.amni`). Extend the const check (`hc/prov.he:840`).
16. A read-only view made directly from a const array or string literal passes to a writing parameter and writes read-only data (`p_slicero_rej_1.amni`, `p_slicero_rej_2.amni`, core dumps). Extend the check at `hc/prov.he:887-890` to direct arguments.
17. Unary minus on `bool` is accepted (`p_boolarith_rej_1.amni`). Reject it at `hc/check.he:416`.
18. `as bool` from an integer, and `as` from a `bool` source, are accepted (`r_castbool_1.amni`, `p_castsrc_rej_2.amni`). Decide whether `bool` is numeric for casts, and enforce it in `ck_as` (`hc/check.he:613-619`).
19. A `let`-bound float literal adapts to `f32` (`p_litdefault_rej_1.amni`, `r_floatprec_1.amni`). Pin it to `f64`, or document the adaptation.
20. A struct may hold several resizable arrays, and a resizable array need not be last (`q_growstruct_acc_1.amni`, `q_growstruct_acc_2.amni`). Enforce the HELIUM.md rule, or change HELIUM.md.
21. A second `fn main` is accepted, and the last definition runs (`q_main_info_1.amni`). Diagnose duplicates next to the check at `hc/calls.he:1158`.
22. Duplicate struct fields are accepted (`p_litcomplete_rej_3.amni`). Reject them.
23. Untyped generic parameters do not unify (`p_genunify_rej_1.amni`). State this in HELIUM.md, or require `<T>`.
24. Numeric `if` and `match` branches join to the wider kind (`p_ifvalue_rej_1.amni`, `p_matchjoin_rej_1.amni`). Document the join. Section 2.2 still shows equal branch types.
25. In `.he`, implicit narrowing also changes sign (`r_hesign_neg_1.he`: `-1` into `u8` traps only under `--debug`, and wraps to 255 in release). Document it in HELIUM.md, or reject sign-changing narrowing in `.he`.

## Review

Skeptic pass, 2026-11-05, by the `ch2` skeptic agent.

What I ran:
- Re-ran all 116 evidence programs in `spec/probes/ch2/`. Every accept or reject verdict matched the chapter. Printed outputs matched wherever the chapter quotes them.
- Wrote 157 probe programs in the same directory (`p_*`, `q_*`, `r_*`, `s_*`, `t_*`). Names carry the expected verdict (`_acc_`, `_rej_`, `_info_`). Where a probe's verdict differed from its name, the probe was read and the result recorded above. Binaries were deleted.
- Spot-checked file:line citations for every CONFIRMED rule against the source, and grepped every quoted diagnostic. The citations listed below were wrong. The quoted diagnostics all exist in `hc/*.he`.
- Re-ran all six repo rejection tests (`test/errors_tc/*.amni`, `test/errors/*.amni`). Each rejects, and each `// error:` text appears in the hc output.

Status changes (CONFIRMED to KNOWN GAP, each refuted by a probe):
- TY-Lit-Default: float part. A `let`-bound float literal adapts to `f32`.
- TY-Grow: two resizable fields, and a resizable field before a plain field, are accepted. The text "only resizable array" is also wrong.
- TY-Slice-ReadOnly: a const array or string literal passed to a writing `[:]` parameter is accepted and writes read-only data.
- TY-Let-Immutable: compound assignment, `.=` rebinding and `int&` parameters reassign a `let`.
- TY-Const: `push` on a const growable array and `+=` on a const scalar are accepted.
- TY-Cast: `as bool` from an integer is accepted.
- TY-Cast-Source: `true as int` is accepted.
- TY-Bool-Arith: unary minus on `bool` is accepted.
- TY-Main: a duplicate `main` is accepted.

Rule text corrected (status stays CONFIRMED, with the probe as evidence):
- TY-If-Value, TY-Match-Arms-Join: numeric branches join to the wider kind.
- TY-Generic-Struct: arguments may be inferred from the fields.
- TY-Sign-Change: scoped to `.amni`. In `.he` the conversion is governed by TY-Narrow-He.
- TY-Cmp: `bool` orders.
- TY-Generic-Unify: sharing a type needs the explicit `<T>` form.
- TY-Let-Immutable: contents are writable, which matches HELIUM.md's wording. The earlier text misquoted it.

Evidence added (status unchanged):
- TY-Cast-Wrap: the no-check half of `as!` under `--debug` is now run and confirmed (`q_wrapdbg_info_1.amni`). The UNCONFIRMED note is gone.
- TY-Narrow-He: sign-changing narrowing and the `--debug` trap (`r_hesign_big_1.he`, `r_hesign_neg_1.he`).
- TY-Arith-Common: the result type is `i8` (`q_negcast_info_1.amni`).
- TY-Result-Infer: the value is printed (`p_resultinfer_rej_1.amni`, prints `1`).
- TY-Struct-Order (still KNOWN GAP): a single-int struct compares natively (`cmp_struct_rej.amni`).
- TY-Struct-Lit-Complete, TY-Call-Default, TY-Multi-Scalar: undocumented cases noted.

Citation fixes:
- TY-Slice-ReadOnly: `hc/prov.he:840` to `hc/prov.he:887-890`.
- TY-Struct-Default: `hc/calls.he:1064` to `hc/calls.he:1078`.
- TY-Result-Infer: `hc/calls.he:179` to `hc/calls.he:189`.

Counts: CONFIRMED 63, KNOWN GAP 20, UNCONFIRMED 3, total 86 (section 2.5 updated).

Not done: TY-Opt-Store root cause (out of scope). The TY-If judgment in section 2.2 still shows equal branch types.
