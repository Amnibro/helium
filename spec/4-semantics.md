# Chapter 4: Dynamic semantics and soundness statements

Status: draft v1, derived from the `hc` source and from runs of `hc` built in this worktree (`build/hc`, HC_LIB=`hc/lib`). The informal guide is `HELIUM.md`; where it disagrees with the compiler, the compiler is recorded as the reference and the disagreement is noted.

## 4.0 Method and conventions

Every test program is a `.amni` file in `spec/probes/ch4/`. Most probes were built twice: once in release (default `hc build`) and once with `--debug`. Evaluation-order probes and the reference-lifetime probes were built in release only, because their behavior does not depend on the mode. Test names below are file stems in that directory. Each has a sibling `.out`, `.err` or `.cerr` file with the observed output. Binaries were deleted after use.

Status keys:

- CONFIRMED: an `hc` run agrees with the rule as stated here.
- UNCONFIRMED: source-only, not run. The reason is given.
- KNOWN GAP: `hc` accepts or behaves in a way that violates the intended rule, or the rule is not documented. Recorded, not treated as a rule.

Notation: `Γ ⊢ e : T` for typing; `⟨e, σ⟩ → ⟨e', σ'⟩` for a small step; `⟨e, σ⟩ ⇓ v` for a big-step result; `⟨e, σ⟩ ↯ k` for a trap of kind `k`. Traps are terminal and print a message to stderr, flush stdout, and exit with status 1 (`lib/rt.he:58`, `sys3(231, 1)`). `exit(n)` exits with status `n`.

Build modes: release wraps signed `+`, `-`, `*` and narrowing `as`, and skips checks listed as debug-only below. `--debug` enables overflow and narrowing checks that name the source line (`HELIUM.md`, `hc.he:81`).

## 4.1 Runtime values and the store

Values are scalars, packed structs, enums, fixed arrays (`T[k]`), slices (`T[:]`), growable arrays (`T[>..]`, `T[>..<]`), and references (`T&`, `T?`). Storage classes: native stack, static data, and a compiler-managed data stack (`HELIUM.md`, Core).

Store: σ maps each live location to bytes. Growable arrays keep their elements in place once placed (`push` returns a stable reference; see M-Push-Stable). The internal header layout is not specified here.

Definite assignment: a scalar local read on a path where it is not yet assigned is rejected (`prov.he:1053`). Aggregates are not checked this way (V-Aggregate-Zero).

- Rule V-Init (CONFIRMED, corrected in review): a scalar local (`int`, `real`, `bool` and the other scalar types) read on any path where it has not been assigned is rejected. The first draft said "before any assignment"; the compiler checks every path. Evidence: `c16_uninit_var` (`var x int; print(x);`) REJECT with `variable x may be used before it is assigned`. Review probes: `r03_var_for_maybe` (assignment only inside `for i in 0..n`) REJECT; `r04_var_while_true` (assignment inside `while true`, then `break`) REJECT; `p18_var_cond_assign` (assignment only under `if`) REJECT; `r05_var_loop_assign` (assignment in a `loop` body before `break`) ACCEPT and prints 2, since a `loop` body always runs once; `r02_var_assign_then_read` ACCEPT and prints 4. Source: `prov.he:869`, `prov.he:1053`.

- Rule V-Aggregate-Zero (CONFIRMED, observed; not documented in HELIUM.md): a `var` of struct or fixed-array type is not checked by V-Init and reads as zero. `p19_var_struct_uninit` (`var p P; print(p.x);`) and `p20_var_arr_uninit` (`var a int[3]; print(a[0]);`) both print 0. `q01_dirty_stack_arr` and `q02_struct_dirty` rule out an accident of fresh stack memory: a first call writes -1s or -7s into its own frame, and a second call's `var a int[3]` or `var p P` still reads 0. The zero stores come from `lzero` calls (for example `lower.he:249`, `lower.he:258`, `lower.he:535`); the zero-fill on the `var` declaration path was not pinned to a line in this pass.

## 4.2 Evaluation order

Every rule below was tested with side effects that append a digit to a global log (`log = log * 10 + s`). Each probe prints the value and the log.

- Rule E-Binop (CONFIRMED): for `e1 op e2`, `e1` is fully evaluated before `e2`. `⟨e1 op e2, σ⟩ → ... → ⟨v1 op e2, σ1⟩ → ... → ⟨v1 op v2, σ2⟩`. Evidence: `e01_binop_order` prints `7 123`. Source: `lower.he:720` (`a := lx(x.a); b := lx(x.b)`).
- Rule E-AndOr (CONFIRMED): `&&` and `||` short-circuit. `e2` is evaluated only when needed. Evidence: `e06_andor_shortcircuit` prints `false true true 13567`; `e07_andor_guards_trap` shows no index trap when the guard is false. Source: `lower.he:711`, `lower.he:780`.
- Rule E-OpRead (CONFIRMED): the value of a left operand that reads a variable is captured before the right operand runs. Evidence: `e05_compound_read_order` with `g + bump()` (g = 0) gives 1 (left read 0, bump returns 1), and `bump() + g` gives 2. `e10_call_with_mut_arg`: `a + inc(a)` with a = 1 gives 3. Review probes: the same capture holds for array elements and struct fields. `q11_opread_index_nc` (`let r = a[0] + bump()`, where `bump` writes `a[0] = 100`) prints 6. `q12_opread_field_nc` (`p.x + bump()`, `bump` writes `p.x`) prints 6. `p01_idx_compound_order` (`a[0] += bump()`) prints 6, and `q13_opread_field_compound` (`p.x += bump()`) prints 6. Source: `lower.he:720`.
- Rule E-Args (CONFIRMED): call arguments are evaluated left to right, and before the call. Evidence: `e02_args_order` gives `123 123`. Source: `lower.he:942` (`largs`), `lower.he:915` (`lcall_to`).
- Rule E-StructLit (CONFIRMED, corrected in review): struct literal fields are evaluated in declaration order, and named initializers must also be written in declaration order. Writing named fields out of order is a compile error, `field initializers must follow declaration order: x comes before y; reordering may cross a side effect`, so written order and evaluation order coincide. Evidence: `e03_struct_order` (positional and named, in order) gives log `123456`. Review probe `p02_struct_named_order` (`P { y: t(1), x: t(2) }`) REJECT with that message in both modes. Source: `calls.he:1129` (message); literal lowering, not pinned to a line in this pass. The first draft said fields are evaluated "in the order written", which the rejection shows is only accepted when the written order is the declaration order.
- Rule E-IdxAssign (CONFIRMED): in `place[idx] = rhs` and `place[idx] op= rhs`, the index is evaluated before the right side. Evidence: `e04_index_assign_order` gives log `1234`. Source: `lower.he:1435` (`lassign`).
- Rule E-WhileCond (CONFIRMED): a `while` condition is re-evaluated before every iteration, including the final failing check. Evidence: `e09_cond_reeval` gives log `1111` for three iterations. Source: `lower.he:1371` region (`lstmt1`).
- Rule E-ForRange (CONFIRMED): `for i in n` and `for i in a..b` evaluate the bound once, at loop entry. Mutating the bound in the body does not change the iteration count. Evidence: `e08_range_bound_once` gives `3 6` (three iterations, n ends at 6). Review probe `p05_for_hi_mut` (`for i in 0..hi` with `hi += 1` in the body) prints `3 6`. A reversed range `r06_for_reverse_range` (`for i in 5..2`) runs zero iterations and does not trap. Source: `lower.he:1503` (`lfor`).

Summary: `hc` evaluates operands, arguments, struct fields, index places and loop bounds left to right. The left operand's value is fixed before the right side runs. This is stronger than C, where operand order is unspecified; the spec should state it explicitly.

## 4.3 Expressions and big-step rules

Each expression form has one result value or one trap. The rules below are big-step for expressions.

- E-Lit: `⟨n, σ⟩ ⇓ n`, with the literal folded to the destination width (`cval` in `lower.he`).
- E-Var: `⟨x, σ⟩ ⇓ σ(loc(x))`.
- E-Bin-Arith: `⟨e1 op e2, σ⟩ ⇓ v` if both operands evaluate to values and `op` is defined on them (Sections 4.4–4.6); otherwise a trap.
- E-If-Expr: `if c { a } else { b }` evaluates `c`, then exactly one branch. An `if` used as a value needs `else` (`HELIUM.md`, Control flow).

## 4.4 Control flow

- Rule C-Block-Value (CONFIRMED): a block is an expression whose value is its tail expression. `block { break v }` exits with `v`. Evidence: `c01_loop_break_value` prints `35 9`. Source: `check.he:954`, `lower.he:1371` region (`lstmt`).
- Rule C-Loop-Value (CONFIRMED): `loop { break v; }` evaluates to `v`. Evidence: `c01_loop_break_value` (value 35) and `r09_loop_value` (`let k = loop { break 3; }` prints 3). Review probe `p09_loop_novalue_as_value` (`let k = loop { break; };`) REJECT with `this expression has no value`, so a `loop` used as a value needs `break v`. Source: `lower.he:1371` region.
- Rule C-BreakVal-Restrict (CONFIRMED, refined in review): `break v` is rejected when the innermost break target is a `for` or `while`. It is accepted when that target is a `block` or a `loop`, even inside an enclosing `for` or `while`. Message: `break with a value exits loop/block only`. Evidence: `c02_for_break_value` and `c03_while_break_value` both REJECT. Review probes: `q08_for_block_breakval` (`let x = block { break 5 };` inside `for`) ACCEPT and prints 15; `p08_break_value_in_block_in_while` (same inside `while`) ACCEPT and prints 5. Source: `check.he:954`, `check.he:725` (`ck_loop` pushes a loop target), `check.he:979` (`N_EBLOCK` pushes a block target).
- Rule C-Break-Innermost (CONFIRMED, corrected in review): a plain `break` (no value) exits the innermost `block` or loop, whichever is nearer. `continue` acts on the innermost loop and does not stop at a `block`. There are no labels. Evidence: `c05_break_outer_nested` prints `3` (nested loops). Review probes: `p06_break_in_block` (`for i in 0..3 { block { break; } n += 1; }`) prints 3, so the `break` left only the block and the loop ran all three times; `q06_while_block_break` prints `3 3` for the same shape in `while`; `q09_for_break_in_block_nested_loop` prints 206 (the inner loop ran all three iterations in each of the two outer iterations). `p07_continue_in_block` (`for` body with `block { continue; } n += 10;`) prints 0, and `q07_while_block_continue` prints `0 3`, so `continue` skipped the rest of the loop body. Source: `check.he:979` (block pushes a break target), `check.he:725` (loop pushes a break target). HELIUM.md says `break` and `continue` act on the innermost loop; the compiler's plain `break` also stops at a `block`. The compiler is the reference here and the disagreement is recorded in the summary.
- Rule C-Continue (CONFIRMED): `continue` skips the rest of the body and re-tests a `while` condition. Evidence: `c04_continue_while` prints `9` (sum of odd values 1 to 5).
- Rule C-Return-Block (CONFIRMED): `return` inside a block passed to a generic function returns from the enclosing named function. Evidence: `c06_return_from_block` prints `28 -1`: the first multiple of 7 in `[10, 40)` at step 3 is 28. Source: `lower.he:1398` (`lret`).
- Rule C-Return-From (CONFIRMED): `return v from f` returns `v` from the innermost active call of `f`. Evidence: `c19_return_value_from` prints `1`. Review probes: `p11_return_from_ancestor` (`return 1 from f` inside a callee `g` of `f`) prints `9 1`; `p10_return_from_nonactive` (`return 1 from h` where `h` is not on the call path) REJECT with `return from h: no enclosing call of h on this compile-time call path`. Source: `lower.he:1398`, `check.he:861`.
- Rule C-MissingReturn (CONFIRMED): a function with a declared result whose body can reach its end without a value is rejected. Message: `f must return i64 but can reach its end without a value`. Evidence: `c20_fallthrough_no_return` REJECT, `missing_return` in `test/errors_tc` REJECT. Source: `calls.he:254`. The check is syntactic. Review probes: `p12_missing_ret_loop` (`fn f() int { loop { return 1; } }`, no path reaches the end) ACCEPT and prints 1; `p13_missing_ret_while_true` (`while true { return 1; }`) REJECT, since `true` is not treated as a constant; `p14_missing_ret_if_else` ACCEPT; `r01_match_block_arms_missing` (`match` with a `return` in each block arm) ACCEPT and prints 11.
- Rule C-Guard-Fallthrough (CONFIRMED, undocumented): `guard c else { S }` continues with the rest of the enclosing block only when `c` holds. If `S` falls through instead of leaving, control goes to the end of the innermost enclosing block, skipping the rest of that block only. That block is the function body only when the guard sits directly in it; inside an `if` or loop body the code after that block still runs (review probes below). Evidence: `d01_guard_nondiverge` prints `neg ` for `chk(-1)` and `pos ` for `chk(2)`, so the `pos` in the failing call was skipped. `g08_guard_opt_marker` shows the same for an optional reference: `after-guard` is not printed. In a value-returning function, `g05_guard_bool_fallthrough` is rejected by C-MissingReturn. Source: `parse.he:670` (`pguard`), `parse.he:674`. HELIUM.md says only that `guard c else { ... }` "continues only if c" and does not state the fall-through behavior. Review probes: `p16_guard_nested_fall` (`fn f(n int) { if true { guard n > 0 else { print("a") } print("b") } print("c"); }`) prints `a` then `c` for `f(-1)`: the `if` body's tail was skipped, and the `print("c")` after the `if` still ran. `p17_guard_loop_fall` (`guard i != 1 else { print("x") }` inside `for i in 0..3`) prints `0`, `x`, `2`: the failing iteration skipped its tail and the loop went on. `q14_guard_fn_unit_block` (guard directly in a unit function) skips the tail and returns to the caller, as in `d01`.
- Rule C-Match-Enum-Exhaustive (KNOWN GAP): HELIUM.md says `match` on enums is exhaustive. `hc` does not enforce this. `c08_match_enum_exhaustive` (missing `Dot`) is accepted. `d03_enum_unmatched` prints `0` for `Shape.Dot`, which matches no arm and yields 0 with no trap. No exhaustiveness check was located in `check.he`, `prov.he` or `calls.he`. The `match` arm dispatch is in `lower.he:749` (`lmatch`).
- Rule C-Match-Int-Default (KNOWN GAP): HELIUM.md says `match` on integers needs `_`. `hc` accepts `c07_match_int_needs_default` (no `_`). `d02_match_int_unmatched` gives `g(3) = 0` with no trap. Correctly handled cases: `c09_match_int_range` (ranges and lists, with `_`) prints `0123`.

## 4.5 Functions and generics (monomorphization)

- Rule F-Mono (CONFIRMED): a generic function is instantiated per distinct argument type set. Evidence: `c11_generic_mono` prints `42 3.0 12`, so `scale<int>`, `scale<real>` and `scale<int>` with an explicit second argument each compile separately.
- Rule F-Mono-Check (CONFIRMED): the body is type-checked at each instantiation, not against a bound. Evidence: `c12_generic_bad_op` REJECT with `expected a value of type i64, got const u8[:]` at the instantiation with `T = int`. HELIUM.md says there are no trait bounds, which matches. Review probe `p41_generic_uninst_bad` (`fn g(x) int { x + "a" }`, never called) is ACCEPTED: a generic body that is never instantiated is not type-checked at all.
- Rule F-Overload (CONFIRMED): overloads are resolved by parameter types. Evidence: `c22_overload_pick` prints `12` for `f(int)` and `f(real)`.
- Rule F-NarrowArg (CONFIRMED): an argument of wider type does not narrow to a narrower parameter; the call needs an explicit `as`. Evidence: `c23_narrow_int_arg` REJECT, `no matching overload for call to f`. HELIUM.md says the same. Literals adapt instead: `h(5)` with `fn h(x u8)` is ACCEPTED (`p43_literal_arg_u8`, prints 5), and a `byte` argument to an `int` parameter is ACCEPTED (`p42_widen_arg`, prints 3).
- Rule F-Recursion-Mark (KNOWN GAP): HELIUM.md says recursion must be marked `recursive fn` on the cycle entry. `hc` does not enforce it. `c13_recursive_unmarked` is accepted and prints `120`. The flag is parsed (`parse.he:775`, `F_REC` in `parse.he:9`) and printed (`fmt.he:199`), but no checker reads it. `c14_recursive_marked` works as documented.

Call evaluation: arguments are evaluated and passed by value (`largs`, `lower.he:942`). A reference parameter binds the lvalue without copying (`inc(a)` in `e10`). Overload selection and instantiation are compile-time, so the dynamic semantics of a call are those of the instantiated function.

## 4.6 Integer arithmetic

Integer types: `int` = i64, `uint` = u64, `byte` = u8, plus `i8 i16 i32 u16 u32`. `varint` is handled separately.

- Rule I-Unsigned-Wrap (CONFIRMED): unsigned `+`, `-`, `*` wrap modulo 2^w in both modes. Evidence: `a07_uwrap` prints `u=0 w=18446744073709551615` in release and debug.
- Rule I-Signed-Ovf-Release (CONFIRMED): signed `+`, `-`, `*` wrap modulo 2^w in release builds. Evidence: `a04_sovf_add` (i64 max + 1 gives i64 min), `a05_sovf_i32` (i32 max + 1 gives -2147483648), `a06_sovf_mul`. Source: `ir.he:630` emits the check only when `x.l >= 0`, and `x.l` is set only under `DBG` (`lower.he:658`).
- Rule I-Signed-Ovf-Debug (CONFIRMED): in `--debug`, signed overflow traps. Message: `integer overflow (debug): 9223372036854775807 + 1 at i64` (`lib/rt.he:62`, `ir.he:630`). Evidence: `a04`, `a05`, `a06` in debug, exit 1.
- Rule I-Div-Trunc (CONFIRMED): `/` on integers truncates toward zero. Evidence: `a08_euclid`: `-7 / 2 = -3`, `7 / -3 = -2`.
- Rule I-Mod-Euclid (CONFIRMED): integer `%` gives a nonnegative remainder for a positive divisor and a value with `0 <= r < |d|` in general. Evidence: `a08_euclid`: `-7 % 3 = 2`, `7 % -3 = 1`, `-7 % -3 = 2`.
- Rule I-Div0 (CONFIRMED): integer `/` or `%` by zero traps in both modes. Message: `division by zero`, exit 1. Evidence: `a02_div0`, `a03_mod0`. Source: `ir.he:635` (`K_DIV0`), with `locs(n)` set for division regardless of `DBG` (`lower.he:658`).
- Rule I-DivOverflow (CONFIRMED for `int`, corrected in review): `MIN / -1` on `int` (i64) traps in both modes with `division overflow`. Evidence: `a10_intmin_div`; review probe `q05_i64_min_div` gives the same in both modes. Narrow signed widths do not follow this rule (I-DivOverflow-Narrow). `MIN % -1` at any width gives 0 with no trap (review probes `p24_i8_min_mod`, prints 0 in both modes). Source: `ir.he:638` (`K_DOVF`; the `B_MOD` branch yields 0), `lib/rt.he:59` (`k == 7`).
- Rule I-DivOverflow-Narrow (KNOWN GAP): `MIN / -1` on `i8`, `i16` and `i32` does not trap in release. It wraps to `MIN`: `p23_i8_min_div` gives -128, `q03_i32_min_div` gives -2147483648, `q04_i16_min_div` gives -32768. In `--debug` the same expressions trap with `helium runtime error: integer overflow` (no `(debug)` tag and no `division overflow` text): `p23`, `q03`, `q04`, and `r10_i8_div_neg1_runtime`. So the division-overflow trap exists for `int` only, and the narrow case follows the wrap-in-release rule of I-Signed-Ovf-Release. HELIUM.md does not define it. The same `MIN / -1` either traps or wraps, depending on width.
- Rule I-Shift-Mask (CONFIRMED): a shift count is masked to `width - 1` and does not trap. `1 << 65` is `2` and `256 >> 66` is `64` for int. Evidence: `a09_shift_mask`. Source: `lower.he:657` (`bin(B_AND, imm(ibits(t) - 1))`). HELIUM.md does not mention this. Shifts are arithmetic for signed types: `-8 >> 1 = -4`.
- Rule I-As-Debug (CONFIRMED): in `--debug`, `x as T` traps when the value does not fit. Message: `as conversion out of range (debug): 300 as u8`. Evidence: `a13_narrow_as` in debug. Source: `ir.he:659` (`K_NARD`), `lib/rt.he` (`rt_nard`).
- Rule I-As-Bang (CONFIRMED): `x as! T` wraps in both modes. Evidence: `a13_narrow_as` gives `44` for `300 as! u8` in release.
- Rule I-Literal-Fit (CONFIRMED): a literal that does not fit its destination type is rejected at compile time: `constant 300 does not fit u8`. Evidence: `c17_u8_var_literal_overflow` REJECT. Source: `check.he:210`.
- Rule I-Implicit-Narrow (CONFIRMED, corrected in review): a non-literal integer converts implicitly in a typed declaration only when every value of the source fits the destination, that is, the destination's value set contains the source's. This holds for the same signedness with at least the same width, and for an unsigned source into a signed destination of strictly greater width. Every other case needs `as`. Evidence: `c24_narrow_assign_implicit` (narrowing `i64` to `u8`) REJECT. Accepted (review): `s03_i16_from_byte` (`byte` to `i16`, prints 200), `s04_int_from_i8` (`i8` to `int`, prints -5), `s05_uint_from_byte` (`byte` to `uint`, prints 200), `s06_i32_from_u16` (prints 60000). Rejected (review): `p44_sign_change_assign` (`i64` to `uint`, same width), `p45_byte_to_i8` (`byte` to `i8`, same width), `t01_i8_to_u16` and `t02_i8_to_uint` (signed to unsigned, not value-preserving), `t03_u32_to_i32` (same width, sign change), `t04_i16_to_i8` (narrowing), `s08_u8_from_int_var` (`int` variable to `u8`). Message: `narrowing and sign changes require an explicit as`. Source: `check.he:219`, `check.he:210`. HELIUM.md says "implicit widening only"; the compiler also accepts a value-preserving unsigned-to-signed widening, which the guide does not mention.
- Rule I-ConstFold-Range (KNOWN GAP): a constant expression whose intermediate result overflows its destination is not range-checked. `let a u8 = 200 + 100;` is accepted and yields `44`, with no diagnostic in either mode (`a14_int_lit_range`). Only a literal written directly at the destination is checked (I-Literal-Fit).

## 4.7 Floating point

Floats: `real` = f64, `f32`. Literals default to `real`.

- Rule FL-Div0-Inf (CONFIRMED): float division by zero does not trap. It gives IEEE infinities. Evidence: `a11_float_div0`: `1.0 / 0.0 = inf`, `-1.0 / 0.0 = -inf`, `0.0 / 0.0 = nan`, in both modes.
- Rule FL-NaN (CONFIRMED): NaN compares unequal to itself. Evidence: `a11_float_div0` prints `false` for `nan == nan` and `true` for `nan != nan`.
- Rule FL-Mod-Fmod (CONFIRMED): float `%` is C `fmod`, so the result takes the sign of the dividend. This differs from integer `%`. Evidence: `a19_float_mod`: `-7.5 % 2.0 = -1.5`. Source: `lower.he:655` (`rt_fmod`, via `arith`). HELIUM.md says `%` is "Euclidean (never negative)", which is true for integers only. The compiler wins here: float `%` is not Euclidean.
- Rule FL-Trunc (CONFIRMED for release, corrected in review): in release, float to int conversion truncates toward zero when the truncated value fits. In `--debug` the same cast traps unless the float is exactly integral (FL-F2I-Debug). Evidence (release): `a12_float_to_int`: `-2.7 as int = -2`; `d12_cast_probe`: `3.9 as int = 3`. Review probe `u07_float_trunc_neg` (`-2.7 as int`) gives -2 in release and traps in debug with `cast changes the value`; `v02_f2i_half` (`3.5 as int`) and `v03_f2i_negfrac` (`-0.5 as int`) give 3 and 0 in release and trap in debug. Integral floats do not trap: `v01_f2i_integral_ok` (`3.0`, `-4.0`, `9007199254740992.0`) prints the same values in both modes.
- Rule FL-F2I-Debug (CONFIRMED, corrected in review): in `--debug`, float to int traps when the cast would change the value. That is when the float has a nonzero fraction, when it is NaN or infinite, or when it is outside the int range. The check is a round-trip comparison: the integer converted back to float must equal the source float (`lower.he:740`, `rt_die` kind 4). Message: `cast changes the value`. The first draft said only "truncated value out of range", which missed the fraction case. Evidence: `d09_float_to_int_big` and `d12_cast_probe` in debug (exit 1), and `a12` in debug (the `-2.7` value in `a12` is fractional). Review probes: NaN (`p31_nan_to_int`) and +inf (`p32_inf_to_int`) also trap with `cast changes the value` in debug. `p34_2p63_edges` in debug prints -9223372036854775808 for -2^63 (fits, no trap) and traps for +2^63.
- Rule FL-F2I-Release (KNOWN GAP): in release, a float out of the int range converts to the exact integer value reduced modulo 2^64 into the signed range. Evidence: `d12_cast_probe` gives `1.0e30 as int = 5076964154930102272`. A one-off check computed `int(1e30) mod 2^64` as signed, which gives the same value. `1.0e19 as int = -8446744073709551616` matches the same rule. `-1.0e30 as int = -5076964154930102272`. HELIUM.md does not define this case, and the result is neither a trap nor a saturating value. Review: the modular description does not cover NaN or infinity. In release `p31_nan_to_int` gives 0 for NaN and `p32_inf_to_int` gives 0 for +inf, so there is a separate zero result for non-finite values. `p33_1e300_to_int` gives 0; that agrees with the modular rule (1e300 is a multiple of 2^64), so it does not separate the two. `p34_2p63_edges` in release gives -9223372036854775808 for both -2^63 and +2^63, which matches the modular rule. Recorded as a gap; the modular claim holds only for finite values.
- Rule FL-F32-Round (CONFIRMED): `f32` arithmetic rounds to single precision. Evidence: `d08_float_fmt`: `16777216.0f32 + 1.0 == 16777216.0f32` gives `true`.
- Rule FL-IntToFloat (CONFIRMED): an int converts implicitly to a float type. Integer literals adapt, so `let x real = 3; x / 2 = 1.5`, while `1 / 2 = 0` and `1.0 / 2 = 0.5`. Evidence: `d08_float_fmt`. HELIUM.md says ints convert implicitly to floats. Matches.
- Rule FL-NegZero (CONFIRMED): `-0.0` is distinct from `0.0`, and `1.0 / -0.0 = -inf`. Evidence: `d11_neg_zero_float` prints `-0.0 -inf`.

## 4.8 Traps

All traps print `helium runtime error: <message> (<file>:<line>)` to stderr, after flushing stdout, and exit with status 1 (`lib/rt.he:58`). stdout written before the trap is kept (`a01_oob_read` prints `before`).

- Rule T-Bounds (CONFIRMED): reading or writing `a[i]` with `i < 0` or `i >= len` traps in both modes. Message: `index I out of bounds (length N)`. Evidence: `a01_oob_read` (index 5, length 3), `d05_neg_index` (index -1). Review probe `p37_const_index_oob` (constant index 5 on a 3-element array) is a runtime trap in both modes, not a compile-time error. Source: `ir.he:656` (`I_BCHK`, `K_OOB`), `lib/rt.he:67` (`rt_oob`).
- Rule T-Slice-Bounds (CONFIRMED, extended in review): a slice range past the end traps with the same message. Evidence: `d06_slice_oob` gives `index 10 out of bounds (length 3)`. Review probe `p36_slice_reversed` (`a[lo..hi]` with lo = 2, hi = 1) also traps in both modes, so a reversed range is a trap too. Its message is `index 1 out of bounds (length 3)`, which names an index that is in range. The trap is right; the message is misleading (message gap only).
- Rule T-Pop-Empty (CONFIRMED): `pop()` on an empty array traps with `pop of an empty array`. Evidence: `d07_pop_empty`. The message string appears in the C backend (`gen.he:1399`). The native site is `rt_pop` in `lib/rt.he:83` (located in review).
- Rule T-Assert (CONFIRMED): `assert(c)` with `c` false traps: `assert failed`. Evidence: `a15_assert_fail`. Source: `lib/rt.he:59` (`rt_die` kind 6).
- Rule T-Abort (CONFIRMED): `abort(msg)` traps with the given message. Evidence: `a18_abort`.
- Rule T-Exit (CONFIRMED): `exit(n)` exits with status `n` without a trap message. Evidence: `a17_exit_code` exits 7.
- Rule T-Grow-Limit (CONFIRMED): a growable array cannot exceed the runtime limit; `push` past it traps with `array grew past 16 GiB (push)`. Evidence: `c15_for_grow_while_iter` (a loop that pushes to the array it iterates). Source: `lib/rt.he:59` (`rt_die` kind 5).
- Rule T-RelRef (UNCONFIRMED): relative-reference offsets out of range trap with `relative reference offset out of range` or `pool-relative reference offset out of range`, or a null relative reference traps with `a relative reference would encode as null` under `opt`. Source: `lower.he:492` (`sguard`), `lower.he:508`–`515`. Not run: no test program was built for relative references in this pass.
- Rule T-Output-Flush (CONFIRMED): a trap flushes buffered stdout before printing its message. Evidence: `a02_div0` prints `start ` on stdout, then the trap.

## 4.9 Memory safety of references and growable arrays

No program in the probe set escaped its reference root. Every escape attempt was rejected at compile time. The rules are checked statically, so these are compile-time rejections that make the dynamic invariant hold.

- Rule M-Clear-Live (CONFIRMED): `clear()` on a growable array is rejected while a reference or slice into it is still used afterward. Evidence: `m01_ref_after_clear` (`cannot clear xs while r is still used`), `m02_slice_after_clear` (same, for a slice). Review: the same check covers `pop()`, which this rule did not list. `p39_pop_live_ref` (`xs.pop()` while `r` is used later) REJECT with `cannot pop xs while r is still used: it may hold a reference or slice into it (§5.1)`. `p38_clear_unused_ref` (clear after the last use of `r`) ACCEPT. `p40_append_live_ref` (`xs.append` while `r` is live) ACCEPT, since growth does not move elements (M-Push-Stable). Source: `check.he` and `prov.he` (region checks, §5.1 in the message).
- Rule M-Resize-Live (CONFIRMED): `resize` is rejected while a reference into the array is still used. Evidence: `m05_ref_after_resize` (`cannot resize xs while r ... is still used`).
- Rule M-Ret-Local (CONFIRMED): returning a reference rooted in a local is rejected. Evidence: `m03_ref_to_local_return` (`returning a reference rooted in v, which dies with this function`).
- Rule M-Temp-Slice (CONFIRMED): binding a slice rooted at a temporary is rejected. Evidence: `d10_slice_from_temp` (`... rooted at a temporary, which does not outlive it (§9.2)`). `prov.he:178`, `prov.he:185`.
- Rule M-Push-Stable (CONFIRMED): `push` does not move existing elements, so a reference into a growable array survives later pushes. Evidence: `m07_nested_ref_into_struct` prints `1` after a push, and `m04_slice_after_push_realloc` prints `1` after 100000 pushes. This matches HELIUM.md ("elements never move").
- Rule M-ForIn-Live (KNOWN GAP): `for x in xs` over a growable array does not reject mutation of `xs` in the loop body. Observed behavior: the loop re-reads the live length each iteration. `m06_iter_clear` clears the array inside the loop and the loop stops after one iteration (output `1`). `c15_for_grow_while_iter` pushes into the array inside the loop and grows until the runtime limit traps (T-Grow-Limit). The intended semantics are not in HELIUM.md, and the mutation is not rejected statically.

Caveat from the source (not run here): `hc/TODO.md` §0 says lifetime checks for `.he` files are off by default and need `HC_HEPROV=1`. Every probe above used `.amni`, where the checks are on.

## 4.10 Soundness statements (CONJECTURES)

These are the intended theorems, stated precisely. None is proven. Each lists what a proof needs and the counterexamples that `hc` today produces.

### S-Progress

Conjecture. If `Γ ⊢ e : T`, `σ` is well typed for `Γ`, and `e` is not a value, then either `⟨e, σ⟩ → ⟨e', σ'⟩` for some `e'`, `σ'`, or `⟨e, σ⟩ ↯ k` for some trap kind `k` in the trap set of 4.8 (T-Bounds, T-Slice-Bounds, T-Pop-Empty, T-Assert, T-Abort, T-Grow-Limit, I-Div0, I-DivOverflow, I-Signed-Ovf-Debug, the `as` and float-to-int debug traps, and the relative-reference guards of T-RelRef). Non-termination is allowed.

Proof needs: a small-step semantics for the typed core (the expressions and statements of 4.2–4.6), canonical forms for each type (scalar, struct, enum, array, slice, reference, optional), and the definite-assignment invariant from V-Init.

Counterexamples to the stated form:
- Non-exhaustive `match` (C-Match-Enum-Exhaustive, C-Match-Int-Default): `d03_enum_unmatched` steps to `0` through no rule. The stated progress form does not hold for a well-typed `match` that has no matching arm. Fails the intended "exhaustive" typing.
- Non-diverging `guard` in a value-returning function is rejected with a misleading message (C-MissingReturn), not a progress failure. Recorded for the message only.

### S-Preservation

Conjecture. If `Γ ⊢ e : T`, `Γ ⊢ σ`, and `⟨e, σ⟩ → ⟨e', σ'⟩`, then `Γ ⊢ σ'` and `Γ ⊢ e' : T`.

Proof needs: a substitution lemma for `let`, `var`, and reference binding, plus the region invariant that every reference in `σ'` is rooted in a live location.

Counterexamples to the stated form:
- Unmarked recursion (F-Recursion-Mark): the typing rule as written in HELIUM.md requires a `recursive` marking that the checker never requires, so programs outside the stated typing rule are well typed under `hc`.
- Constant folding (I-ConstFold-Range): `let a u8 = 200 + 100` is typed as `u8` with the value `44`, which is in range for `u8`, so preservation holds for the value. The rule that the constant `300` does not fit `u8` is applied to literals only, so the typing rule is not uniform across constant and non-constant expressions. Recorded as an inconsistency, not a counterexample to preservation.
- Mutation during `for x in xs` (M-ForIn-Live): `c15_for_grow_while_iter` is well typed and its loop stays well typed while the array grows, so the iterator's region invariant is not stated.

### S-MemSafe

Conjecture. For a well-typed program without `unsafe` operations, no execution reads or writes outside an allocated location, and no reference or slice is used after its root is freed, cleared, resized, or dropped. Each reference's root is inferred and checked statically.

Proof needs: root inference that is sound for references, slices, and optionals; the invariant that `push` never moves an element (M-Push-Stable); the bounds checks in T-Bounds and T-Slice-Bounds; and, for relative references, the range guards in `lower.he:508`–`515`.

Counterexamples and caveats:
- The conjecture is false for `hc` today. Chapter 3 (3.10) shows accepted programs that break it: a slice returned through an alias of a local growable array is a use-after-free (G1, `spec/probes/ch3/s01_ret_alias_explicit.amni` prints `[91, 2]` for `[1, 2]`), member access on an unnarrowed optional dereferences null (G2), `qput` hands a thread a dangling reference (G3), and a string literal passed to a writing `byte[:]` parameter is written in place (G10). The escape attempts in 4.9 were rejected, but they do not cover those forms. `hc/TODO.md` §1 records that `var l = l0; return l` compiled to a use-after-free until a return check was added. The same file records 1751 of the `errors_tc` programs as accepted by `hc` as of 2026-10-27.
- M-ForIn-Live: mutation of the iterated array is accepted, so the statement "no use after clear" depends on the loop re-reading the length. It does not read freed memory in the observed cases, but the rule is not stated or enforced.
- `.he` files: lifetime checks are off unless `HC_HEPROV=1` (`hc/TODO.md` §0). The conjecture applies to `.amni` files, or `.he` with `HC_HEPROV=1`.

### S-ModeAgree

Conjecture. For a well-typed program, the release and `--debug` builds produce identical output and identical exit status unless the debug build traps with one of the debug-only traps (I-Signed-Ovf-Debug, I-As-Debug, FL-F2I-Debug). In particular, the two modes agree on every program that does not overflow or narrow.

Proof needs: a simulation between the two lowerings, showing that the only difference is the extra checks guarded by `DBG` (`lower.he:658`, `ir.he:630`, `ir.he:659`).

Review note: `MIN / -1` on `i8`, `i16` and `i32` (I-DivOverflow-Narrow) is a debug-only trap, so it falls under the stated exception list (I-Signed-Ovf-Debug). For `int`, both modes trap and no difference arises. Float to int is a second source of difference beyond overflow: `-2.7 as int` gives -2 in release and traps in debug (`u07_float_trunc_neg`). That is also a debug-only trap, listed as FL-F2I-Debug, but the exception is wider than "out of range": it covers any fractional value. The conjecture's exception list stays valid with the corrected FL-F2I-Debug trigger.

Counterexample: FL-F2I-Release. In release, `1.0e30 as int` yields a value, while in debug it traps. The debug-only trap has no release counterpart, which is an intended difference. But the release value is itself undefined by the spec, so the two modes agree only on the value of the mode with the check. Recorded as a gap in FL-F2I-Release.

## 4.11 Rule summary and counts

| Family | Rules | CONFIRMED | UNCONFIRMED | KNOWN GAP |
|---|---|---|---|---|
| Evaluation order (E) | 8 | 8 | 0 | 0 |
| Control flow (C) | 11 | 9 | 0 | 2 |
| Functions and generics (F) | 5 | 4 | 0 | 1 |
| Integers (I) | 14 | 12 | 0 | 2 |
| Floats (FL) | 9 | 8 | 0 | 1 |
| Traps (T) | 9 | 8 | 1 | 0 |
| Memory and references (M) | 6 | 5 | 0 | 1 |
| Total | 62 | 54 | 1 | 7 |

Plus two variable rules outside the table, V-Init and V-Aggregate-Zero (both CONFIRMED). That makes 64 rules, 56 confirmed, 1 unconfirmed and 7 known gaps. (Counts updated in review: I-DivOverflow-Narrow added as a gap; V-Aggregate-Zero added.)

KNOWN GAPS, with the test that shows each:
1. C-Match-Enum-Exhaustive: `c08_match_enum_exhaustive`, `d03_enum_unmatched`.
2. C-Match-Int-Default: `c07_match_int_needs_default`, `d02_match_int_unmatched`.
3. F-Recursion-Mark: `c13_recursive_unmarked`.
4. I-ConstFold-Range: `a14_int_lit_range`.
5. FL-F2I-Release: `d12_cast_probe`, `d09_float_to_int_big`, `p31_nan_to_int`, `p32_inf_to_int`.
6. M-ForIn-Live: `m06_iter_clear`, `c15_for_grow_while_iter`.
7. I-DivOverflow-Narrow: `p23_i8_min_div`, `q03_i32_min_div`, `q04_i16_min_div`.

Documentation disagreements (the compiler is the reference):
- HELIUM.md says `match` on enums is exhaustive. `hc` does not check it.
- HELIUM.md says `match` on integers needs `_`. `hc` does not check it.
- HELIUM.md says recursion must be marked. `hc` does not check it.
- HELIUM.md says `%` is Euclidean. That holds for integers. Float `%` is `fmod`.
- HELIUM.md says `break` and `continue` act on the innermost loop. `hc` also lets a plain `break` leave a `block` (C-Break-Innermost).
- HELIUM.md says `let` cannot be reassigned. `hc` allows one assignment to a `let` declared without an initializer (`r08_let_then_assign` ACCEPT), and rejects a second one (`s02_let_deferred_twice`). `s01_let_reassign` (`let x = 1; x = 2;`) REJECT.
- HELIUM.md says `implicit widening only`. `hc` also accepts a value-preserving unsigned-to-signed widening, such as `byte` to `i16` (I-Implicit-Narrow).
- HELIUM.md does not mention shift masking, guard fall-through, or float-to-int wrap in release. These are recorded above as CONFIRMED (undocumented) or KNOWN GAP.

Related prior work: `hc/TODO.md` §1 reports rejection parity of 26 matching, 160 rejected with other wording, 1751 accepted, and 0 crashes out of 1937 `errors_tc` programs (2026-10-27). That is the corpus-level basis for the gaps above.

## Review

Skeptic pass, 2026-11-05. Method: rebuilt every evidence program in release and `--debug` and diffed the output against the stored `.out` files (60 release files matched; the stored debug files matched too). Wrote 50 edge probes (`p01`–`p50`) and 37 more (`q01`–`q14`, `r01`–`r10`, `s01`–`s08`, `t01`–`t05`), plus 16 (`u01`–`u13`, `v01`–`v03`) aimed at CONFIRMED rules that had no new program before (E-AndOr, I-Unsigned-Wrap, I-Div-Trunc, FL-F32-Round, FL-NegZero, I-As-Bang, FL-Trunc, T-Assert, T-Abort, T-Exit, F-Overload, M-Ret-Local) under `spec/probes/ch4/rv/`, each run in both modes where it compiles. Checked each cited file:line against the source.

Changes:
- V-Init: corrected from "before any assignment" to "on any path" (definite assignment). Evidence added.
- V-Aggregate-Zero: new rule (CONFIRMED, observed). Struct and fixed-array `var` locals are not checked and read as zero.
- E-StructLit: corrected. Named initializers must be in declaration order (out-of-order is rejected, `calls.he:1129`).
- E-OpRead: evidence added for array elements and struct fields.
- E-ForRange: reversed range checked (zero iterations, no trap).
- C-BreakVal-Restrict: refined. `break v` is accepted when the innermost target is a block or a loop.
- C-Break-Innermost: corrected. A plain `break` exits the innermost block or loop. `continue` still targets the loop. HELIUM.md disagreement recorded.
- C-Guard-Fallthrough: corrected. The fall-through target is the innermost enclosing block, not always the function.
- C-MissingReturn: syntactic check; `while true` rejected, `loop` accepted. Evidence added.
- C-Loop-Value and C-Return-From: evidence added.
- F-Mono-Check: uninstantiated generic bodies are not checked (evidence added).
- I-DivOverflow: corrected to `int` only. New rule I-DivOverflow-Narrow (KNOWN GAP): `i8`, `i16` and `i32` `MIN / -1` wrap in release and trap with a different message in debug.
- I-Implicit-Narrow: corrected. Acceptance is value-set inclusion. Signed-to-unsigned and same-width sign changes are rejected; unsigned-to-wider-signed is accepted.
- FL-Trunc: corrected for debug. A fractional float traps under `--debug` (`u07_float_trunc_neg`, `v02`, `v03`), so the truncation rule holds in release only.
- FL-F2I-Debug: corrected trigger. The debug check is a round-trip comparison, so any fraction, NaN, infinity or out-of-range value traps (`lower.he:740`). Evidence added.
- FL-F2I-Release: the modular rule covers finite values only. NaN and infinity give 0 in release (KNOWN GAP extended).
- T-Bounds: constant out-of-range index is a runtime trap (evidence added).
- T-Slice-Bounds: reversed ranges trap too, but the message names an in-range index (message gap recorded).
- T-Pop-Empty: native site corrected to `lib/rt.he:83` (`rt_pop`).
- M-Clear-Live: the check also covers `pop()` (evidence added).
- S-ModeAgree: note that narrow `MIN / -1` is a debug-only trap, which fits the stated exception list.
- Counts (4.11) and the known-gap list updated.

Runtime citations now name `lib/rt.he`; the file is `hc/lib/rt.he`, and the line numbers were read from it.
