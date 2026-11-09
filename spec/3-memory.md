# Chapter 3: Memory model and safety rules

Status: derived from hc at `this repository` (2026-11-05), compiler sources `hc/check.he`, `hc/prov.he`, `hc/calls.he`, `hc/lower.he`, `hc/gen.he`, `hc/lib/rt.he`, `hc/hrt.h`, `hc/pkg.he`, the informal guide `HELIUM.md`, and `hc/TODO.md`. Test programs: `spec/probes/ch3/` (132 sources: 72 from the writer, 60 from the skeptic pass, prefixed `p`). All tests are `.amni` unless marked `.he`. Compile command: `HC_LIB=hc/lib ./build/hc build FILE -o OUT`.

## 3.0 Method and status key

Each rule has: an ID, the rule, the invariant it protects, the enforcing location, and evidence (test program and observed hc result).

- **CONFIRMED (C)**: the hc run agrees with the rule as stated (or as corrected in this review, marked "corrected").
- **KNOWN GAP (G)**: hc accepts a program the rule forbids, or the rule as written in `HELIUM.md` is not enforced. Gaps are listed in §3.10.
- **UNCONFIRMED (U)**: no hc run settles the rule, or the source was read but not exercised. Reason given.

Runtime failures are reported as `helium runtime error: <message> (<file>:<line>)` and exit with status 1 unless noted. A segmentation fault exits with status 139.

## 3.1 Model summary

- No heap, no GC, no destructors. Storage is the native stack, static data, or the compiler-managed data stack. Storage is freed when its owning scope ends. Growable arrays reserve address space from the runtime (`hc/hrt.h:115`, `MAP_NORESERVE`).
- A reference (`T&`) is transparent: it reads and writes as its target. A nullable reference (`T?`) is a reference that may be `null`.
- A slice (`T[:]`) is a view into any array kind. It never owns storage.
- Fixed-size values (`T[k]`, and structs of fixed-size fields) copy on assignment. Non-fixed values (growable arrays, `T[]`, `T[..k]`, variable-size structs) do not copy implicitly. `let c = xs;` aliases `xs`.
- Safety is enforced by a static provenance pass (`hc/prov.he`), a return check (`hc/check.he`), a mutability pass, and runtime checks in the generated code and runtime library.
- The provenance pass runs for every `.amni` file. For `.he` files it runs only when `HC_HEPROV=1` is set (`hc/prov.he:933`). Gold always sets it (`hc/TODO.md` line 35; `HELIUM.md` does not say this).

## 3.2 Values, copies and aliasing

**MEM-1 Fixed-size values copy on assignment.** (C)
- Rule: assigning a fixed-size value to a new or existing variable copies it.
- Invariant: a write through one fixed-size variable does not change another.
- Enforced at: `hc/check.he:1030-1041` (the `t_ref` decision: fixed-size values in name positions are not wrapped in a reference).
- Evidence: `ok_basic.amni`: `var b = a; b[0] = 9;` leaves `a[0]` at 1. Output `4 1 9`.
- Evidence (skeptic): `p03_struct_fixed_copy.amni`: a struct with a `int[3]` field copied with `var t = s;` keeps `s.a[0]` at 1. Output `1 9`.

**MEM-2 Non-fixed values alias; they never copy implicitly.** (C)
- Rule: `let c = xs;` or `var c = xs;` where `xs` is a growable array makes `c` a second name for the same storage. `copy(xs)` makes a copy.
- Invariant: the programmer sees every copy. No hidden allocation.
- Enforced at: `hc/check.he:1040-1045` (`names_store`: a name in a store position of a non-fixed type becomes a reference), `hc/prov.he:955` (message for a non-fixed value passed where a value is required).
- Evidence: `ok_basic.amni`: `let c = xs; c.push(4);` makes `xs.len` report 4.
- Evidence (skeptic): `p01_var_alias_grow.amni`: the `var` form also aliases. Output `4`.
- Evidence: `t12_alias_args.amni`: `f(x, x)` with two `int&` parameters is accepted. Both references alias one variable and the result is 12. No invariant is claimed against this; it is recorded as permitted aliasing.

**MEM-3 Non-fixed values need `copy` to pass or return by value.** (C)
- Rule: passing a growable array to a by-value parameter, or assigning it from a call that the callee must hand back by value, requires `copy(...)`.
- Invariant: the copy point is visible in source.
- Enforced at: `hc/prov.he:955` (message: "is not fixed-size and is not copied implicitly (§4.1): pass copy(...)"), `hc/check.he:1050-1053` (return form: "return copy(...)").
- Evidence: `r16_assign_self_call.amni`: `xs = f(xs)` with `f(a int[>..]) int[>..]` is rejected with the §4.1 message.
- Evidence (skeptic): `p02_byvalue_grow_param.amni`: `g(xs)` with `fn g(a int[>..])` is rejected with the §4.1 message.
- Evidence: `r32_todo_local_alias_ret.amni`: `var l = l0; return l;` returning a growable array is rejected with "return copy(l)".

**MEM-4 Return check for direct references, slices and fixed copies.** (C)
- Rule: a function must not return a reference or slice whose root is a local or a by-value parameter of the function.
- Invariant: no reference or slice outlives the storage it names (use-after-free, §9.2).
- Enforced at: `hc/prov.he:178-187` (message "rooted at ..., which does not outlive it"), `hc/prov.he:321` ("returning a reference rooted in ..., which dies with this function"), `hc/check.he:1046-1053` (`st_dies`, `ret_esc`: a by-value growable local returned).
- Evidence (rejected as predicted): `r01_ret_local_slice.amni` (slice of local array), `r02_ret_local_ref.amni` (`int&` to local), `r03_ret_tail_slice.amni` (tail-expression slice), `s03_struct_slice_ret.amni` (slice inside returned struct), `s04_struct_ref_ret.amni` (`int&` field inside returned struct), `t16_ret_ref_to_param_fixed_copy.amni` (reference into a by-value fixed parameter), `r32_todo_local_alias_ret.amni` (growable returned through a local alias).
- Evidence (skeptic, rejected as predicted): `p05_ret_fixed_param_slice.amni` (slice of a by-value `int[3]` parameter), `p06_ret_if_slice.amni` (slice of a local returned from an `if` branch).
- Evidence (accepted, correct): `r05_fixed_ret_ok.amni` and `r33_local_fixed_alias_ok.amni` return fixed-size arrays by value.
- Evidence (accepted, correct): `t15_ret_writable_from_param_ok.amni` returns `int&` into a growable reference parameter. The root is the caller's storage.
- Evidence (accepted, correct, skeptic): `p04_ret_global_ref.amni`: `fn f() int& { g[0] }` on a global growable array. Globals outlive calls (MEM-32).
- Optional references (`T?`) are covered the same way. Before the fix, `pret` skipped return types that were neither slices nor holders, and `isrs` leaves `T?` out, so `fn find(xs int[:], v int) int? { for i in xs.len { if xs[i] == v { return i; } } return null; }` compiled to a reference to its own loop index. The caller read whatever later reused that stack slot. In JK's rig, every clip lookup after the first landed on a random clip. A range loop's index (`for i in n`, `for i in a..b`, the `i` of `for x, i in xs`) is a fresh local, so it is now rooted in itself rather than in the range expression (`pfrng`). A by-value element or `&x` binding still roots in the iterated storage. Evidence (rejected): `test/errors_tc/optional_return_local.amni`, `test/errors_tc/optional_return_temporary.amni` (`return n * 2` from an `int?` function, formerly a native-backend error). Evidence (accepted, correct): `for &x in xs { return x; }` and `return xs[i]` into a caller's slice.

**MEM-5 Return check through an alias of a growable local.** (G)
- Rule: MEM-4 applies to a slice returned through a local that aliases a local array, whether the alias is bound with `var` or `let`, and whether the slice is produced by `return` or by the tail expression.
- Result: hc accepts the `var` and `let` alias forms when the slice is produced by coercing the alias. The function returns a dangling slice.
- Evidence: `s01_ret_alias_explicit.amni` (`var l = l0; return l;`, `l` a slice-returning function) printed `[91, 2]`, a use-after-free. Same for the tail form `r31_todo_local_alias.amni` (printed `[91, 2]`).
- Evidence (skeptic, narrowed): `p56_var_alias_slice_tail.amni` (`var l = l0; l[..]` as tail) printed `[91, 2]`. `p55_let_alias_slice_tail.amni` (`let l = l0; l[..]` as tail) printed `[91, 2]`. The gap is therefore not limited to `var`.
- Evidence (skeptic, not a gap): `p07_alias_let_slice_ret.amni` (`let s = l0[..]; return s;`) and `p08_alias_let_slice_tail.amni` (`let s = l0[..]; s`) are rejected ("returning a reference rooted in l0"). `p09_alias_ref_ret.amni` (`let r .= l0[0]; r` returned as `int&`) is also rejected. Binding the slice directly is caught. Only the coercion of an alias is not traced.
- Evidence (`.he`): `h02_he_ret_growable.he` (default options, no `HC_HEPROV`) printed `[91, 2, 3]`. With `HC_HEPROV=1` it is rejected: "returning a reference rooted in a, which dies with this function (§9.2)".
- Cause (source): `ret_esc` (`hc/check.he:1051`) returns early when the return type is a slice (`TY[et].k == TY_SLICE`), so the check only covers the growable-by-value form. The reference check at `hc/prov.he:321` does not see the slice produced by coercing the alias.
- Note: `hc/TODO.md` names this family ("`var l = l0; return l` compiled to a use-after-free until hc gained the return check"). The growable-by-value form is fixed. The slice form through an alias is not.

## 3.3 Scope, temporaries and storage lifetimes

**MEM-6 A reference may not be stored in a variable that outlives its root.** (C)
- Rule: storing a reference or slice rooted at an inner-scope variable into an outer-scope variable is rejected.
- Invariant: the destination never refers to freed scope storage.
- Enforced at: `hc/prov.he:308` (`src.d > dst.d`, "which does not outlive the destination"), `hc/prov.he:599`.
- Evidence: `s02_scope_escape_slice.amni`: `s = a[..]` inside a block, read after the block, is rejected.
- Evidence (skeptic): `p10_scope_assign_outer.amni`: `s = a[..]` inside a `for` body, with `s` declared outside, is rejected ("rooted at a").
- Evidence (skeptic): `p46_global_slice_store.amni`: `gs = a[..]` with `gs` a global slice and `a` local is rejected.
- Wording gap: the message says "rooted at <temporary>" for a block-scoped array, not a temporary (see G8).

**MEM-7 A view of a temporary cannot be bound.** (C)
- Rule: a slice or reference rooted at a temporary value must not be bound to a name. The temporary lasts only until the end of its statement.
- Invariant: no reference to a dead temporary.
- Enforced at: `hc/prov.he:178`, `hc/prov.he:185` (message "rooted at a temporary, which does not outlive it (§9.2)").
- Evidence: `r17_temp_view.amni`: `let s = mk()[..];` is rejected.
- Evidence (skeptic, accepted, correct): `p11_temp_print_ok.amni`: `print(mk()[..])` is accepted and prints `[1, 2]`. Only the binding is refused.

**MEM-8 `let` bindings cannot be reassigned.** (C)
- Rule: `let x` may be initialized once. Its contents may still be mutated through a writable path if the type allows it.
- Invariant: a `let` name keeps its value.
- Enforced at: `hc/prov.he:833` and `hc/prov.he:835` ("cannot assign to let ...").
- Evidence: `r09_let_reassign.amni`: `let x = 1; x = 2;` is rejected.
- Evidence (skeptic): `p12_let_deferred.amni`: `let x int; x = 1;` is accepted (deferred single initialization). `p13_let_branch_init.amni`: one assignment on each `if` branch is accepted. `p14_let_double_assign.amni`: `let x int; x = 1; x = 2;` is rejected ("may be assigned already").
- Evidence (skeptic): `p16_let_growable_whole.amni`: `let ys int[>..] = [1]; ys = [5];` is rejected (whole-value assignment to a `let`).

**MEM-9 Parameters: the name is immutable unless declared `var`; the contents are writable.** (C, corrected)
- Rule: a by-value parameter's name cannot be assigned in the body (`var` in the parameter list lifts this). Its contents (fields, elements) may be written, as for a `let` local (MEM-10). Such writes change only the callee's copy.
- Invariant: the caller's value is not affected by any write to a by-value parameter.
- Enforced at: `hc/prov.he:835` (`kd == N_PARAM`) for the name. Contents are not checked; the by-value copy at the call protects the caller.
- Evidence: `r10_param_assign.amni`: `fn f(x int) int { x = 3; x }` is rejected ("cannot assign to let x").
- Evidence: `t09_var_param_ok.amni`: `fn f(var x int)` accepts `x += 1`. Output `2`.
- Evidence (skeptic, corrected): `p17b_param_member_local.amni`: `fn f(p P) int { p.x = 1; p.x }` is accepted and the caller's `q.x` stays 0. Output `1 0`. `p17_param_field_assign.amni` and `p18_param_fixed_assign.amni` (`a[0] = 1` on a by-value `int[3]`) are accepted. The earlier wording "cannot be assigned in the body" was too broad.

**MEM-10 A `let` name cannot be reassigned, but its contents stay writable, including through references and slices.** (C, corrected)
- Rule: `let` forbids reassigning or rebinding the name (MEM-8). It does not make the contents read-only. `HELIUM.md` §Core says "`let` cannot be reassigned (contents still writable)". Read-only contents are `const` (MEM-11).
- Invariant: `let` protects the binding, not the storage. Read-only data is `const`.
- Enforced at: `hc/prov.he:887-891` (writer parameters check write masks; `let` is not a write barrier by design).
- Evidence: `s11_let_to_writer.amni`: `let v = 1; inc(v);` with `fn inc(n int&)` prints `2`. Consistent with the text above.
- Evidence (skeptic): `p15_let_growable_push.amni`: `let xs int[>..] = [1]; xs.push(2);` prints `[1, 2]`. `p19_let_to_slice_writer.amni`: `fill(arr[..])` on a `let arr int[3]` with `fn fill(a int[:])` prints `[7, 2, 3]`. `p20_let_ref_bind_write.amni`: `let v = 1; var r .= v; r = 3;` prints `3` for `v`.
- Open question for the language owner: whether a scalar `let` should resist writes through a reference (`s11`, `p20`). The text of `HELIUM.md` says the contents are writable; the scalar case is a judgment call. This is recorded as a question, not a gap. The earlier gap G4 is withdrawn.
- Compare: `t14_global_ref_store.amni` (global reference variable) is rejected, with an unrelated message (G8).

**MEM-11 `const` contents are read-only.** (C)
- Rule: a `const` binding, a `const` slice, and a `const` element cannot be written, pushed, popped or cleared, directly or through a reference.
- Invariant: read-only views cannot change the data they name.
- Enforced at: `hc/prov.he:840` ("cannot assign through this path (const, or a read-only instantiation, §9.5)"), `hc/prov.he:887` (mutating member calls on non-writable values), `hc/prov.he:891` (print/str/format of non-writable values into writers).
- Evidence (rejected): `r08_const_write.amni` (`const byte[:]` element write), `t10_const_fixed_write.amni` (`const int[3]` element write), `s10_const_growable_param_write.amni` (`push` through `const int[>..]&`, "cannot .push through a non-writable value").
- Evidence (skeptic, rejected): `p21_const_growable_push.amni` (`const xs int[>..]`, `xs.push(2)`).

**MEM-12 A read-only slice passed to a writing parameter is rejected, but a string literal passed directly is not.** (G, corrected)
- Rule: a `const` slice name, or a name bound to a string literal, may not be passed to a parameter the callee writes through (`byte[:]` without `const`). Passing `copy(...)` is the fix.
- Invariant: string literals and `const` data are never written.
- Enforced at: `hc/prov.he:890` ("cannot pass a read-only slice (const or a string literal) ...; pass copy(...) for a writable copy").
- Evidence (rejected as predicted): `test/errors_tc/const_slice_written.amni` produces the expected message at line 4 (`f` passes its `const` parameter to `g`, which writes). `p22c_const_param_writer.amni` (same shape, literal through `const` parameter) and `p22d_let_literal_writer.amni` (`let s = "abc"; w(s);`) are rejected at the call inside the writer chain.
- Evidence (skeptic, not rejected): `p22_literal_writer.amni`: `fn w(a byte[:]) { a[0] = 120; }` with `w("abc");` is accepted and the program exits 139. `p22e_for_ref_literal.amni`: `lower_all("Hi")` with a `for &c in s` writer is accepted and exits 139. The string literal argument is written in place. Gap G10.
- Evidence (correct fix): `p23_copy_writer_ok.amni`: `var b byte[>..] = copy("abc"); w(b[..]);` prints `xbc`.

**MEM-13 Locals must be assigned before use.** (C)
- Rule: a `var` or `let` without an initializer must be assigned on every path before it is read.
- Invariant: no read of an indeterminate value.
- Enforced at: `hc/prov.he:869` (use before assignment), `hc/prov.he:1018` (path analysis), `hc/prov.he:1053` (global initialization order, §11.1).
- Evidence: `r20_uninit.amni`: `var x int; print(x);` is rejected ("variable x may be used before it is assigned").
- Evidence (skeptic): `p24_uninit_branch.amni`: `var x int;` assigned on only one `if` branch, then read, is rejected.
- Note: `var a int[3];` with no initializer is accepted and reads `[0, 0, 0]` (`t11_uninit_array.amni`). Fixed-size arrays without an initializer are zeroed; this is not an uninitialized read.

## 3.4 Growable arrays, slices and invalidation

**MEM-14 Grow-only arrays never move their elements.** (C, dynamic)
- Rule: a reference or slice into a `T[>..]` remains valid across `push` and `append`.
- Invariant: element addresses are stable for the life of the array (`HELIUM.md` §Arrays: "elements never move").
- Evidence: `t02_grow_elem_stable.amni`: `var r .= xs[0]`, then one million pushes, then `r = 42`. Output `42 42 1000001`. `s16_ref_elem_then_grow.amni` shows the same at 1000.
- Evidence: `s18_ref_then_callee_push.amni`: a reference survives a callee's `push`.
- Evidence (skeptic): `p26_append_live_ref.amni`: a live reference survives `append`. Output `[9, 5, 6] 9`. `r11_push_while_slice.amni`: a live slice survives `push`.

**MEM-15 Pop, pop_n, resize, clear and whole-value assignment are rejected while a reference or slice is live.** (C)
- Rule: `pop`, `pop_n`, `resize`, `clear`, and whole-value assignment to a growable array (`xs = ...`) are rejected when a reference or slice into the array is still used afterwards. Grow-shrink arrays (`T[>..<]`) and grow-only arrays both follow this for the listed operations.
- Invariant: no reference into shrunk or replaced storage is read afterwards.
- Enforced at: `hc/prov.he:567-575` ("cannot ... while ... is still used"), `hc/prov.he:639-640` (`pop`/`clear`/`pop_n`/`resize`, the §5.1/§5.2 checks).
- Evidence (rejected): `r12_pop_while_ref.amni` (pop on `>..<`), `r13_resize_while_ref.amni` (resize on `>..`), `s19_whole_assign_while_ref.amni` (whole assign with live `int&`), `s20_slice_then_assign.amni` (whole assign with live slice).
- Evidence (skeptic, rejected, grow-only and other ops): `p28_pop_grow_only_live.amni` (pop on `>..`), `p29_clear_live_ref.amni` (clear on `>..<`), `p30_pop_n_live_ref.amni` (pop_n on `>..<`).
- Evidence (accepted, correct): `r15_assign_self.amni` (`xs = copy(xs[1..])` with no live reference) prints `[2, 3]`.

**MEM-16 `push` never moves existing elements of a growable array, grow-only or grow-shrink.** (C, corrected)
- Rule: `push` on `T[>..<]` does not invalidate a live reference or slice into it. The element keeps its address, as for `T[>..]` (MEM-14).
- Invariant: element addresses are stable across growth in both growable forms.
- Enforced at: runtime. The array reserves address space with `mmap(..., MAP_NORESERVE)` (`hc/hrt.h:115`) and grows within it. Growth past the reservation aborts with "array grew past 16 GiB (push)" (`hc/lib/rt.he:59`).
- Evidence (skeptic): `p27_addr_stable_gs.amni`: `var r .= xs[0]` on `int[>..<]`, then 1,000,000 pushes, then `var q .= xs[0]`. `r .== q` prints `true`. `p27b_addr_stable_go.amni` gives `true` for `int[>..]`. An address that moved would make `r .== q` false.
- Evidence: `s17_ref_grow_shrink_push.amni` (one push with a live reference) is accepted and reads `1`. `t01_grow_shrink_realloc_ref.amni` (100,000 pushes, then a write through the reference) prints `42 42`.
- Caveat: the evidence covers 1,000,000 pushes (several capacity doublings) in one run per form. The mmap path was read, not traced end to end.

**MEM-17 A reference into a grow-shrink array is never stored.** (C)
- Rule: references into `T[>..<]` live in a variable, are passed down, or are returned. They are never stored in a field or global.
- Invariant: a stored reference cannot outlive a pop or shrink.
- Enforced at: `hc/prov.he:204-210` ("storing a reference into ..., which holds a grow-shrink array"), `hc/prov.he:206` (`pnst`, the store check). Corrected: the earlier citation to `hc/check.he:1107` was wrong; that line is `ck_assign`.
- Evidence: `r26_store_ref_grow_shrink.amni`: a `int[:]` slice of a global `int[>..<]` stored in a struct field is rejected with the §5.2 message.

**MEM-18 Iterating an array while mutating it.** (G)
- Rule (inferred): MEM-15 applies to a `for` loop over an array, which keeps a live use of that array for the duration of the loop. `HELIUM.md` §Arrays says only "A `T[>..]` may `pop`/`clear`/`resize` only where no reference or slice into it is still used afterwards". The `for`-loop extension is not written in `HELIUM.md`; it is this chapter's reading.
- Result: hc accepts mutation of the iterated array inside the loop.
- Evidence: `s15_iter_pop.amni`: `for x in xs { xs.pop(); }` on `T[>..<]` is accepted and prints `[1]`. No crash was observed.
- Evidence (skeptic): `p32_for_clear.amni`: `for x in xs { xs.clear(); }` on `T[>..<]` is accepted and prints `0`.
- Evidence: `r14_iter_push.amni` and `s08_for_ref_push.amni`: `push` inside `for x in xs` / `for &x in xs` is accepted. The loop does not terminate; the program aborts with `helium runtime error: array grew past 16 GiB (push)` and exits 1. This is a bounded failure, not memory corruption, but it is a liveness hazard the rule should catch.

## 3.5 Bounds checks and runtime limits

**MEM-19 Indexing and slicing are checked at run time.** (C)
- Rule: `a[i]` and `a[x..y]` are checked against the current length. A failed check prints a runtime error and exits with status 1.
- Invariant: no read or write outside the array.
- Failure: `helium runtime error: index I out of bounds (length N) (file:line)`, from `rt_oob` (`hc/lib/rt.he:67`).
- Evidence: `r06_oob_const.amni` (index 5 on `int[3]`, exit 1), `r07_oob_runtime.amni` (index 9, exit 1), `r30_slice_oob.amni` (slice end 9, exit 1), `t05_neg_index.amni` (index -1, exit 1).
- Evidence (skeptic): `p34_write_oob.amni`: a write `xs[5] = 1` on `int[>..]` of length 1 exits 1 with the same message. The write path is checked too.
- Evidence (wording gap): `t04_slice_reversed.amni`, `a[2..1]`, reports "index 1 out of bounds (length 3)". The failure is caught, but the message names the wrong index (see G8).
- Note: a constant out-of-range index is not a compile-time error. `r06_oob_const.amni` compiles and fails at run time. `p39_const_div_zero.amni` (`1 / 0`) behaves the same way. This is by design per the runtime-check model, recorded as observed behavior.

**MEM-20 `^` indices are only valid in slices.** (C)
- Rule: `xs[^k]` is a slice form. A plain index with `^` is rejected.
- Evidence: `t06_from_end.amni`: `xs[^5]` on an array is rejected ("'^' bounds are only valid in slices").
- Evidence (skeptic, accepted, correct): `p35_caret_slice.amni`: `xs[^2..]` on `int[>..]` prints `[3, 4]`.

**MEM-21 Fixed-capacity arrays fail when full.** (C)
- Rule: `push` and `append` on `T[..k]` past `k` elements abort at run time.
- Invariant: capacity is never exceeded.
- Failure: `helium runtime error: limited array capacity exceeded` (push; C emitter `hc/gen.he:1022`, `1397`, `1411-1412`); `helium runtime error: append past a limited array's capacity` (append; C emitter `hc/gen.he:1398` and `1413`, `B_APPEND` branches).
- Evidence: `s14_small_cap_overflow.amni` (third push into `int[..2]`, exit 1).
- Evidence (skeptic): `p36_append_cap.amni`: `append` of three elements into `int[..2]` exits 1 with the append message.

**MEM-22 Popping an empty array, or `pop_n` outside the length, aborts.** (C)
- Rule: `pop` on an empty array and `pop_n(n)` with `n` less than zero or greater than the length abort.
- Failure messages: "pop of an empty array", "pop_n past the length" (`hc/gen.he:1399-1400`, `1414-1415`).
- Evidence: `r28_pop_empty.amni` (exit 1), `t07_pop_n_over.amni` (exit 1).
- Evidence (skeptic): `p37_pop_n_neg.amni`: `pop_n(-1)` exits 1 with "pop_n past the length".

**MEM-23 Division and remainder by zero abort in all builds.** (C)
- Rule: integer `/` and `%` with a zero divisor abort.
- Failure: `helium runtime error: division by zero` (`hc/lib/rt.he:59`).
- Evidence: `r27_div_zero.amni`, with and without `--debug`, exits 1.
- Evidence (skeptic): `p38_mod_zero.amni` (`5 % z`, `z = 0`) exits 1 with the same message.

**MEM-24 Overflow and `as` out-of-range checks apply only with `--debug`.** (C)
- Rule (`HELIUM.md` §Basics): signed overflow wraps in release and aborts in `--debug`. `x as T` is checked in `--debug`. `x as! T` always wraps.
- Failure, debug: `helium runtime error: integer overflow (debug): 127 + 1 at i8` (`hc/lib/rt.he:62`). `as conversion out of range (debug): 300 as u8` (`hc/lib/rt.he:65`).
- Evidence: `s09_int8_overflow.amni` prints `-128` in release and aborts with `--debug`. `r29_checked_as.amni` prints `44` in release and aborts with `--debug`.
- Evidence (skeptic): `p40_mul_overflow.amni` (`i8` `100 * 2`): prints `-56` in release, aborts with `integer overflow (debug): 100 * 2 at i8` under `--debug`. `p41_asbang_debug.amni` (`v as! u8` with `v = 300`) prints `44` under `--debug` too; `as!` does not abort.

## 3.6 Optional references

**MEM-25 `T?` must be narrowed before use.** (G)
- Rule (`HELIUM.md` §References): a nullable reference is narrowed with `if`, `while`, `guard` or `assert` before any member access or dereference.
- Narrowing that works: `s07_null_narrow_ok.amni`: `if p { print(p.v); }` prints `none` for null.
- Evidence (skeptic, narrowing forms): `p42_guard_assert_narrow.amni`: `guard n else { return -1; } n.v` and `assert(n); n.v` both work. Output `-1 4 4`.
- Result: an unnarrowed member access compiles and crashes. No diagnostic is produced.
- Evidence: `r19_opt_deref.amni` (`var p N? = null; print(p.v);`) compiles; exit 139 in release. The same program with `--debug` also exits 139, so the `--debug` checks do not cover this.
- Evidence: `t03_opt_param_deref.amni` (`fn val(n N?) int { n.v }` called with `null`) exits 139, also with `--debug`.
- Note: no diagnostic string for this rule was found in `hc/check.he`, `hc/calls.he`, `hc/prov.he`, `hc/lower.he` or `hc/gen.he`. The only nullable-related checks are the narrowing checks that accept valid code.

**MEM-26 A reference parameter binds an lvalue.** (G, low)
- Rule (`HELIUM.md` §References): "A reference parameter binds an lvalue without `&`." The reading that a literal is not an lvalue is this chapter's; `HELIUM.md` does not say it.
- Result: `r24_pass_const_to_writer.amni`: `inc(5)` with `fn inc(n int&)` is accepted. The callee writes a temporary; the program exits 0. No memory is corrupted, but the documented rule does not hold as this chapter reads it.

## 3.7 Recursion, references across calls and threads

**MEM-27 Element and array type restrictions.** (C)
- Rule: arrays of variable-size elements (`byte[][>..]`) can be iterated but not indexed. `push`, `append`, `pop`, `resize` and `clear` need a growable array.
- Enforced at: native backend diagnostics (text begins "native backend:").
- Evidence: `s12_index_bytes_list.amni` (index on `byte[][>..]`) is rejected. `s13_frozen_push.amni` (`push` on `int[]`) is rejected.
- Evidence (skeptic, accepted, correct): `p51_iter_var_elems.amni`: `for s in xs` over `byte[][>..]` is accepted and prints `hi`.

**MEM-28 A growable local must not be live across a recursive call.** (G)
- Rule (`HELIUM.md` §Functions): "`recursive fn` ... no growable local in scope at a recursive call (pass storage in by reference)".
- Result: hc accepts it. The program runs and prints the expected value at small depth.
- Evidence: `r25_rec_growable.amni`: `recursive fn walk(n int)` declares `var t int[>..]`, then calls `walk(n - 1)` with `t` in scope. Output `3`.
- Evidence (skeptic, consequence): a `recursive fn` with a growable local per frame runs to depth 30,000 (`p48e_rec_growable_30k.amni`, prints `450015000`) and fails at depth 100,000 with `helium runtime error: out of address space` (`p48c_rec_growable_100k.amni`, exit 1). The same program with a fixed `int[1]` local runs to depth 1,000,000 (`p48b_rec_fixed_deep.amni`, prints `500000500000`). Each live growable takes its own reserved address range (MEM-16), so depth multiplies reservations. This is a runtime failure, not a stack overflow, and it is the consequence the rule exists to prevent.
- Note: the compiler does not check the rule.

**MEM-29 References are passed down, not stored, inside a recursive cycle.** (G, corrected)
- Rule (compiler message, `hc/prov.he:306`, "(§7.8)"): "references may only be passed down, not stored, inside a recursive cycle".
- Result: hc accepts four store shapes inside a recursive cycle. None is rejected, although the check exists.
- Evidence (skeptic): `p49_rec_store_ref.amni`: `var r .= p;` in a `recursive fn` taking `p int&`, then `f(n - 1, r)`. Accepted, prints `5`. `p52_rec_struct_ref.amni`: a reference stored in a struct local (`H { r: p }`). Accepted, prints `5`. `p53_rec_rebind_param.amni`: `q .= p;` rebinds a reference parameter. Accepted, prints `5`. `p54_rec_store_not_passed.amni`: `var r .= p;` where the cycle passes a global instead of `p`. Accepted, prints `0`.
- Status: the check's trigger is narrower than its message, or it is disabled; it was not traced further. Gap G11.

**MEM-30 Threads share nothing.** (C, observed)
- Rule (`HELIUM.md` §Program): threads share no state. Values cross threads only through queues.
- Observed: `s05_thread_global.amni`: a `thread_fn` that does `counter += 5` on a global leaves `counter=0` in `main`. `r21_global_shared_thread.amni`: a thread's `g.push(1)` is not visible in `main`, which prints `[]`.
- Mechanism: not established by this run. The observed behavior is consistent with per-thread global storage.

**MEM-31 Only flat (reference-free) values cross queues.** (G, critical)
- Rule (`HELIUM.md` §Program): "Only flat (reference-free) values cross queues."
- Result: hc accepts a reference-bearing value through `qput`, and the reference is copied as a raw pointer.
- Evidence: `s06_qput_uaf.amni`: `send()` calls `qput(J { p: v })` with `struct J { p int& }` and `v` local to `send`. After `send` returns, the thread reads `j.p` and prints `3`. The read is through a dangling reference, so the value is not guaranteed.
- Evidence: `r22_thread_ref_queue.amni` (same shape, `main` owns `v`): accepted, prints `3`.
- Evidence: `r23_thread_slice_queue.amni`: `qput(a[..])` with a slice; the thread's `qget<int[:]>` dereference exits 139.
- Source: the type check for `qput` (`hc/calls.he:878`) checks only the argument type. Variable-size packing (`pneeds`, `hc/gen.he:1141`) returns false for `TY_REF` fields, so the pointer is copied as-is (`hc/lower.he:1225-1230`).
- Positive control: `t08_qput_flat_ok.amni` (`qput(41)`, `qget<int>()` in a thread) prints `got 41`.

**MEM-32 Global storage.** (C)
- Rule: a global value lives for the program. A slice or reference of a global may be returned. A global may not hold a reference variable.
- Evidence: `t13_global_slice_ret_ok.amni`: `fn f() int[:] { g[..] }` with global `g` prints `[4, 5]`.
- Evidence: `t14_global_ref_store.amni`: `var gp int& = 0;` is rejected. The message comes from the native backend (`hc/lower.he:182`, "native backend: this branch reference natively"), not from the provenance pass (G8).
- Enforced at: `hc/prov.he:379-386` (global bindings: "is a global var, which any function may bind").

**MEM-33 Lifetime checks are off by default for `.he` files.** (C, behavior)
- Rule (`hc/TODO.md` line 35): lifetime checks are disabled for `.he` by default, and `HC_HEPROV=1` enables them. `HELIUM.md` does not state this.
- Evidence: `h02_he_ret_growable.he` runs with a dangling slice by default (`[91, 2, 3]`) and is rejected with `HC_HEPROV=1`. `h01_he_ret_local.he` is accepted by default (`[1, 2, 3]`) and rejected under `HC_HEPROV=1` (skeptic re-run, both forms).
- Source: `hc/prov.he:932` reads `HC_HEPROV` (`0` off, `2` also libraries, otherwise on); `hc/prov.he:933` skips `.he` files unless it is set.
- Consequence: every `.he` program built without `HC_HEPROV=1` is outside the safety rules in this chapter. Gold sets the variable.

## 3.8 Safety invariants at a glance

| Invariant | Rules | Status |
|---|---|---|
| Fixed-size values are copied, not aliased | MEM-1, MEM-2 | C |
| Non-fixed values are never copied silently | MEM-2, MEM-3 | C |
| No reference or slice to a local outlives its scope | MEM-4, MEM-6, MEM-7 | C for direct and scope forms; G for alias slice (MEM-5, G1) |
| Immutable names stay immutable | MEM-8, MEM-9, MEM-10 | C; `let` contents are writable by design (MEM-10, corrected) |
| Read-only data is not written | MEM-11, MEM-12 | C for `const` names; G for string literal arguments (MEM-12, G10) |
| No read of uninitialized values | MEM-13 | C |
| Growable element references stay valid across growth | MEM-14, MEM-16 | C (dynamic, both growable forms) |
| Shrinking invalidates live references | MEM-15, MEM-17, MEM-18 | C for pop/pop_n/resize/clear/assign; G for `for`-loop mutation (MEM-18) |
| Array accesses are in bounds | MEM-19 to MEM-22 | C (runtime checks) |
| Optional references are checked before use | MEM-25 | G |
| Values crossing threads hold no references | MEM-31 | G |
| Live growable locals are not recursed over | MEM-28 | G (runtime failure at depth 100,000) |

## 3.9 Compiler disagreements with HELIUM.md

The compiler wins for the purpose of this chapter. Each row is a statement in `HELIUM.md` that hc does not satisfy, or a statement that the chapter had attributed to `HELIUM.md` but that `HELIUM.md` does not make.

| HELIUM.md statement | hc result |
|---|---|
| "References can never dangle ... the compiler ... rejects code that could outlive it." | False for slices returned through a growable alias (MEM-5, `s01`, `r31`, `p55`, `p56`), and for references passed through queues (MEM-31, `s06`). |
| "`T?` ... narrow it ... before use." | False for member access without narrowing (MEM-25, `r19`, `t03`). |
| "Only flat (reference-free) values cross queues." | False (MEM-31). |
| "no growable local in scope at a recursive call." | False (MEM-28, `r25`; a runtime failure at depth 100,000, `p48c`). |
| "A reference parameter binds an lvalue without `&`." | False for literal arguments (MEM-26, `r24`). |
| "A `T[>..]` may `pop`/`clear`/`resize` only where no reference or slice into it is still used afterwards." | Holds for direct uses (MEM-15, `p28`-`p30`). Not enforced for `for`-loop iteration (MEM-18). |
| "Assigning a whole growable array clears it first, so `xs = f(xs)` is an error." | Holds: `r16` is rejected. The diagnostic cites §4.1, not the clearing rule. |
| "`let` cannot be reassigned (contents still writable)." | Holds (MEM-8, MEM-10). Writes through references and slices to `let` contents are accepted. |
| "`let c = xs;` aliases; `copy(xs)` copies." | Holds (MEM-2). |
| "signed overflow aborts in `--debug`" and "`x as T` (checked in `--debug`)" | Hold (MEM-24). |
| "`T[>..]`: elements never move." | Holds for `push` on both growable forms (MEM-14, MEM-16). |
| "A view of a temporary cannot be stored." | Holds (MEM-7). |
| "Recursion ... no growable local in scope at a recursive call." | Not enforced (MEM-28, G5). |

## 3.10 Known gaps (hc accepts unsafe or undocumented programs)

Gaps are ordered by severity. G4 was withdrawn in the skeptic pass; the number is kept so references stay stable.

| ID | Gap | Rule | Evidence | Severity |
|---|---|---|---|---|
| G1 | Slice returned through an alias (`var` or `let`) of a local growable array is returned as a dangling slice. Prints garbage. Direct `let s = l0[..]` returns are rejected. | MEM-5 | `s01_ret_alias_explicit.amni`, `r31_todo_local_alias.amni`, `p55_let_alias_slice_tail.amni`, `p56_var_alias_slice_tail.amni`, `h02_he_ret_growable.he` (default) | Critical: use-after-free |
| G2 | Unnarrowed `T?` member access compiles and crashes, in release and `--debug`. | MEM-25 | `r19_opt_deref.amni`, `t03_opt_param_deref.amni` (exit 139) | Critical: null dereference |
| G3 | `qput` accepts reference-bearing values and slices. A thread reads through a dangling reference, or crashes. | MEM-31 | `s06_qput_uaf.amni`, `r22_thread_ref_queue.amni`, `r23_thread_slice_queue.amni` (exit 139) | Critical: use-after-free across threads |
| G4 | WITHDRAWN. A `let` local passed to a writable reference parameter is mutated. This matches the text of `HELIUM.md` (contents of `let` stay writable). Not a gap; see MEM-10 and the open question there. | MEM-10 | `s11_let_to_writer.amni`, `p19_let_to_slice_writer.amni` | Not a gap |
| G5 | Growable local live across a recursive call is accepted, and each live growable reserves address space. | MEM-28 | `r25_rec_growable.amni`, `p48c_rec_growable_100k.amni` (exit 1: `out of address space`), `p48e_rec_growable_30k.amni` (ok) | High at depth: runtime failure at 100,000 frames |
| G6 | Mutation of an array inside a `for` loop over it (`pop`, `clear`, `push`) is accepted. Push leads to a 16 GiB abort. | MEM-18 | `s15_iter_pop.amni`, `p32_for_clear.amni`, `r14_iter_push.amni`, `s08_for_ref_push.amni` | Medium: liveness; not corruption |
| G7 | A literal argument is accepted for a writable reference parameter. | MEM-26 | `r24_pass_const_to_writer.amni` | Low: documentation mismatch |
| G8 | Diagnostic wording misleads or is internal. Scope escape says "<temporary>" for a block-scoped array (`s02`). Reversed slice reports the wrong index (`t04`). A global reference variable is rejected with "native backend: this branch reference natively (kind 1, resolved 0)" (`t14`, from `hc/lower.he:182`). | MEM-6, MEM-19, MEM-32 | `s02_scope_escape_slice.amni`, `t04_slice_reversed.amni`, `t14_global_ref_store.amni` | Low: rejected or caught, message is wrong |
| G9 | `.he` lifetime checks are off unless `HC_HEPROV=1` is set. | MEM-33 | `h02_he_ret_growable.he` | High for `.he` users: all `.he` safety rules are opt-in |
| G10 | A string literal passed directly to a writing `byte[:]` parameter is accepted and written in place. Segmentation fault. | MEM-12 | `p22_literal_writer.amni` (exit 139), `p22e_for_ref_literal.amni` (exit 139) | High: write to read-only data |
| G11 | A reference is stored inside a recursive cycle (local, struct field, rebind, not-passed-down), which the compiler's own message forbids. | MEM-29 | `p49_rec_store_ref.amni`, `p52_rec_struct_ref.amni`, `p53_rec_rebind_param.amni`, `p54_rec_store_not_passed.amni` | Medium: rule unenforced; memory impact not established |

Items G1, G2 and G3 contradict the statement in `HELIUM.md` that references cannot dangle. Items G1 and G3 are the same family as the use-after-free that `hc/TODO.md` says hc gained a check for; that check covers only the growable-by-value form.

## 3.11 Counts

- Rules stated: 33 (MEM-1 to MEM-33).
- CONFIRMED: 25 (after the skeptic pass; MEM-9, MEM-10 and MEM-16 were corrected and then confirmed).
- UNCONFIRMED: 0.
- KNOWN GAP rules: 8 (MEM-5, MEM-12, MEM-18, MEM-25, MEM-26, MEM-28, MEM-29, MEM-31).
- Known gaps listed in §3.10: 11 (G1 to G11). G4 is withdrawn, so 10 are active.
- Test programs: 132 under `spec/probes/ch3/` (72 from the writer, 60 from the skeptic pass). Each rejection or acceptance above cites its file.
- Built binaries removed after each run.

## 3.12 Open items for the next pass

1. Settle the scalar `let` question in MEM-10: should a `let` scalar resist writes through a reference (`s11`, `p20`)? This is a language decision, not a compiler bug.
2. Settle the MEM-29 trigger: find the shape that makes the `hc/prov.he:306` check fire (or remove the check). Until then, G11 stands.
3. Find the null-deref diagnostic, if it exists. A search of `hc/check.he`, `hc/calls.he`, `hc/prov.he`, `hc/lower.he` and `hc/gen.he` found none. If none exists, G2 is a compiler gap, and the fix belongs in `hc/check.he` or `hc/prov.he`.
4. Fix G1 by extending `ret_esc` (`hc/check.he:1051`) to slice return types, and by tracing alias coercion in `hc/prov.he:321`. The `let` and `var` alias forms both need the trace.
5. Fix G3 by rejecting, in `hc/calls.he:878`, any `qput` argument whose type contains `TY_REF` or `TY_SLICE`.
6. Fix G10 by rejecting a string literal argument to a parameter the callee writes through (`hc/prov.he:890`).
7. Fix G5 by rejecting a growable local live at a recursive call, or by charging it to the recursion depth. Gold could avoid the case by convention.
8. Make Gold always run with `HC_HEPROV=1`, and add a test that `.he` builds without it fail the dangling-slice test.

## Review

Skeptic pass, 2026-11-05. Every CONFIRMED rule was re-run with its evidence program, and each rule got at least one new probe (60 new programs, `spec/probes/ch3/p*.amni`). Every cited file:line was checked against the source.

Changed:
- MEM-9: rule narrowed. The name is immutable; member and element writes to a by-value parameter are accepted and stay local (`p17`, `p17b`, `p18`). Still CONFIRMED.
- MEM-10: rule corrected. `HELIUM.md` says `let` contents are writable, and hc agrees (`p15`, `p19`, `p20`). Gap G4 withdrawn. Scalar-`let` question left open in §3.12.
- MEM-12: changed from CONFIRMED to KNOWN GAP (G10). The `const`-name and `let`-literal cases are rejected; a direct string literal to a writer is accepted and segfaults (`p22`, `p22e`). The errors test only covers the `const` chain.
- MEM-16: changed from UNCONFIRMED to CONFIRMED with a corrected rule: `push` does not move elements in either growable form (`p27`, `p27b`).
- MEM-5 and G1: narrowed. `let` aliases also escape (`p55`); direct `let s = l0[..]` returns are caught (`p07`, `p08`, `p09`). Citation corrected to `hc/check.he:1051`.
- MEM-18: attribution corrected. The `for`-loop rule is not in `HELIUM.md`. Evidence added (`p32`).
- MEM-28 and G5: evidence added. A growable local per frame fails at depth 100,000 (`p48c`), and works at 30,000 (`p48e`).
- MEM-29: changed from UNCONFIRMED to KNOWN GAP (G11). Four store shapes accepted (`p49`, `p52`, `p53`, `p54`).
- MEM-17: citation corrected. `hc/check.he:1107` is `ck_assign`, not a global-slot check.
- MEM-32: the `t14` message is from `hc/lower.he:182`, not the provenance pass.
- MEM-2, MEM-4: citations moved to the lines that hold `names_store` (1040-1045), `st_dies` and `ret_esc` (1046-1053).
- MEM-21, MEM-22, MEM-24, MEM-25, MEM-3, MEM-6, MEM-13, MEM-20, MEM-27, MEM-33: evidence added. No rule status changed. MEM-33 source changed from HELIUM.md to `hc/TODO.md` line 35, which is where the `.he` default is stated.
- MEM-26: the "literal is not an lvalue" reading is marked as this chapter's, not HELIUM.md's.
- §3.1: Gold's `HC_HEPROV` setting is cited to `hc/TODO.md`, not `HELIUM.md`.
- §3.8 to §3.12: tables, gap list and counts updated. Counts now: 25 CONFIRMED, 0 UNCONFIRMED, 8 KNOWN GAP rules, 10 active gaps (11 listed, G4 withdrawn).
- Probe binaries and outputs removed from `spec/probes/ch3/`; sources kept.
