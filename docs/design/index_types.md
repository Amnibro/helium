# Index types and bounds-check-free functions

<details>
<summary>Table of contents</summary>

- [1. The check no analysis removes](#1-the-check-no-analysis-removes)
- [2. Index and bound types](#2-index-and-bound-types)
- [3. Why it is sound](#3-why-it-is-sound)
- [4. What bounds-check elimination gets from it](#4-what-bounds-check-elimination-gets-from-it)
- [5. Index types and relative references](#5-index-types-and-relative-references)
- [6. `checkfree` functions](#6-checkfree-functions)
- [7. Worked example: CSR breadth-first search](#7-worked-example-csr-breadth-first-search)
- [8. Implementation](#8-implementation)
- [9. Testing](#9-testing)
- [10. Open questions](#10-open-questions)

</details>

This proposal adds two features that are meant to ship together. An *index
type* `u32 in nodes` is an integer that is a valid index of the global array
`nodes` wherever it can be named, so indexing with it needs no check. A
`checkfree fn` is a function the compiler rejects if any bounds check is left
in it. Together they let a programmer move the bounds checks of a hot loop to
where its data enters the program, and have the compiler confirm that the
loop is left with none. Neither is implemented. This is TODO 0e of the spec,
and the answer to the indirect-indexing gap TODO 0f lists.

## 1. The check no analysis removes

The bounds-check pass (§10.5, `src/bce.h`) proves most checks in ordinary
loops. The common case it keeps is an index read out of another array:

```goose
fn relax(adj: i32[>..]&, dist: i32[>..]&, u: i64) {
    for k in adj.len {
        let w = adj[k];                              // elided
        if dist[w] < 0 { dist[w] = dist[u] + 1; }    // the first dist[w] is kept
    }
}
```

The same shape is graph edges (`dist[adj[k]]`), mesh index buffers
(`verts[tri.a]`), sort permutations (`vals[order[i]]`), union-find
(`parent[x]`) and handle tables. `bench/goose/graph_csr.goose` keeps a check
per edge on `out[k]` and on `dist[w]`, per vertex on `dist[u]` and on
`start[u + 1]` (an `i32` sum, which may wrap), and two in the build loop on
`cursor[s]` and `out[cursor[s]]` (`goose --check --bce-lines`).

Proving `dist[w]` takes `∀k: 0 <= adj[k] < dist.len`, a fact about the
*contents* of one array relative to the *length* of another. A smarter
analysis does not get there:

* Where `adj` came from outside the program (an edge list or a mesh read from
  a file), the fact is false until something checks it. That check is the
  program's input validation. It can be moved, but not removed, and where it
  belongs (once at load, or at every traversal) is the programmer's
  knowledge.
* Where the program built `adj`, a proof needs an invariant over every write
  into `adj` anywhere it is reachable, against a length that is often a run
  time value and belongs to an array allocated elsewhere. A summary of the
  range of values stored into each array would prove `graph_csr`, where the
  bound is a constant `V` and every pushed value is `% V`, but not the
  general case.

Pool-relative references (§3.9) already cover part of this. `adj:
Node&<u32 in nodes>[>..]&`, with `dist` moved into `Node`, compiles `relax`
with no checks at all, because a link is validated where it is stored and a
load is `base + off - 1`. What they cannot do is reach a *parallel* array:
`dist`, `visited` and `parent` are indexed by the same node id and are
usually allocated per query, not part of the node.

## 2. Index and bound types

### 2.1 Spelling

```
type        := "const"? (prim | qname tyargs? | "(" type ")") postfix*
             | indextype
indextype   := ("u8" | "u16" | "u32" | "u64") ("in" | "upto") qname
```

`u32 in nodes` is an *index type* of `nodes`, `u32 upto edges` a *bound type*
of `edges`. An index type takes no postfix directly: an array of them is
`(u32 in nodes)[>..]`, a cast to one is `x as (u32 in nodes)`. An alias reads
better at every use and is the expected style:

```goose
type NodeId = u32 in nodes;
var edges: NodeId[>..] = [];
```

`upto` is a keyword only directly after an unsigned type name in a type, as
`in` already is inside `T&<u32 in pool>`. `qname` resolves as a pool's name
does, in the namespace of the declaration the type is written in.

### 2.2 What a value means

A value of `uN in a` is an integer `v` with `0 <= v < a.len`, at every point
of the program where it can be observed. A value of `uN upto a` has `0 <= v
<= a.len`: the end of a range, such as a CSR offset.

`a` names a global `var` or `reusable var` of a grow-only type `T[>..]` whose
elements are fixed-size, so that it can be indexed. Anything else is a
compile error: a local or parameter has no name where a field's type is
written (as for `in pool`), a grow-shrink or limited array can shrink, and a
sequential array cannot be indexed. Unlike `in pool`, the element type is
unrestricted.

The array is part of the type's identity: `u32 in nodes` is neither `u32`
nor `u32 in edges`, and two widths of one array are different types. The
representation is the plain unsigned integer. The array is not stored and the
generated C does not see the type.

### 2.3 Making one

* **A conversion.** `x as (uN in a)`, for `x` of any integer type, aborts
  unless `0 <= x < a.len`, with the ordinary index-out-of-bounds error that
  `a[x]` would give. Where `a`'s reservation (§10.4) can hold more elements
  than `uN` can number, it also aborts unless `x` fits `uN`. `x as (uN upto
  a)` is the same with `x <= a.len`.
  * Unlike every other `as`, this one is checked in every build: it is a
    bounds check moved, not a debug conversion check.
  * The bounds-check pass judges it as it judges `a[x]` and elides it
    wherever that would be elided.
  * There is no unchecked form: `x as! (uN in a)` is an error.
* **A read.** Reading storage of the type (an element, a field, a variable)
  gives the type, as does a call whose result type is it.
* **A loop.** `for i in lo..hi`, where both bounds are index or bound types
  of the same `a`, gives `i` the index type `uN in a` at the bounds' joined
  width. Every value it takes satisfies `lo <= i < hi <= a.len`. A count loop
  `for i in n` with `n` of an index or bound type of `a` gives the same.
* **Within one array's types.** A wider width of the same array converts
  implicitly (`u16 in a` to `u32 in a`), and so does an index type to the
  bound type of the same array (`u32 in a` to `u32 upto a`). The other
  directions, a narrower width and `upto` to `in`, take an `as` and are
  checked as above.
* **Nothing else.** A constant never has an index type and never adapts to
  one, since its value says nothing about `a.len`.

### 2.4 Using one

* **Indexing.** `a[v]`, and `&a[v]`, with `v` of an index type of `a` need no
  check, whatever the analysis knows. Indexing another array `b[v]` is
  checked unless the analysis proves `a.len <= b.len` (§4), which it does
  from a counted fill, a `resize`, an `assert` or call-site facts. A slice
  `a[lo..hi]` with bound-type ends still checks `lo <= hi` unless proven.
* **As a number.** It converts implicitly to its plain type, and from there
  wherever that converts (`u32 in a` to `u32`, `u64` and `i64`). It is
  compared, printed, hashed, passed to an `i64` parameter and used in
  arithmetic as that type.
* **Arithmetic** sees only the plain value. `w + 1`, `w << 3`, `w & m`, `-w`
  and `~w` are plain integers, `w + 0` included. Compound assignment and
  `++`/`--` on a place of an index type are errors, since their result would
  be a plain integer stored back.

### 2.5 How values pass through

* **Declarations.** A `let` or `var` with no written type takes the index
  type of its initializer. A later `x = 0` to such a `var` is then an error,
  and the message suggests writing the plain type (`var x: u32 = adj[k];`).
* **Calls.** Parameters and results may have index types, and arguments and
  `return` values are checked against them like any other type.
* **Branches.** An `if`, a `match`, a block or a `break` value has an index
  type where every branch value has an index or bound type of the same `a`:
  the widest width, and `upto` if any branch is. Otherwise it has the join of
  the plain types. `if c { 0 } else { w }` is a plain `u32`.
* **Storage.** Fields, ADT payloads, array elements, locals and globals may
  have index types, and every store into one needs a value of that type.
* **References and slices.** A reference to index-typed storage is `(u32 in
  a)&`, a slice of it `(u32 in a)[:]`. They are not `u32&` or `u32[:]`,
  since a write through those could store any `u32`. A `u32[:]` parameter
  does not accept a `NodeId[:]` argument.
* **Generics.** A type argument may be an index type, and is inferred as one.
  Each instantiation is checked with it (§7.7). A generic body that moves `T`
  values works (`swap_at`, `fill`, `sort`, `max`). One that stores arithmetic
  into a `T` slot, or needs `default<T>()`, does not instantiate with an
  index type, and the error names the instantiation.
* **No null.** Goose's optionals are references. A "no link" value is an ADT
  (`enum Link { None, To { n: NodeId } }`) or a sentinel in plain storage
  that is converted at use.

### 2.6 What may not hold or make one

* **Defaults.** An index type has no default value: `default<T>()`, a
  literal's `..`, a fixed array without an initializer and a field default
  all need one (`HasDefault`). The array may be empty, so not even 0 is
  valid.
* **Byte writers.** `format` and `to_bytes(a, out)` reject an output array of
  an index type (`(u8 in x)[>..]`). `bytes_of` views are read-only already.
* **Images.** `from_bytes` accepts element types holding index types, and
  its verifier checks each such value against the named array's length at
  verification time, rejecting the image otherwise. This differs from `in
  pool` links, which it rejects (`design/serialization.md` §4): an index does
  not depend on the element layout, so checking it once at load is
  meaningful. It is exactly where the check of data from outside belongs.
* **Threads.** Each thread program has its own copy of every global it uses
  (§11.2), and the copies of `a` grow apart after the spawn. `qput`, `qget`,
  `qpoll` and `thread_spawn` arguments reject types that hold index types.
* **C.** `extern fn` results and writable reference or slice parameters, and
  `export fn` parameters, may not hold index types, since C code is not
  checked. By-value parameters to C are fine.

### 2.7 The array never shrinks

An array that an index or bound type names is never shrunk. `pop`, `pop_n`,
`resize`, `clear` and a whole assignment of it are errors, anywhere in the
program, directly or through a reference parameter. The per-specialization
shrink summaries that §5.1 already keeps for globals find every such shrink.
The error names the index type that pins the array. Element writes,
`push`, `append` and a `reusable` pool's `free` (whose slot stays a valid
element, §5.4) are unaffected.

## 3. Why it is sound

The invariant is that every live value of `uN in a` is less than `a.len`
(`<=` for `upto`).

* **It is established** wherever a value is made: the conversion checks it, a
  loop's values lie between bounds that satisfy it, and a read gives what a
  store put there.
* **It is preserved** because:
  * `a.len` never decreases (§2.7). A grow-only global's element region also
    never moves.
  * every store into storage of the type needs a value of the type, which
    only §2.3 makes;
  * arithmetic yields plain integers (§2.4);
  * there is no default value and no byte-level write (§2.6);
  * images are verified, and values do not travel between threads or come
    from C.
* **Global initialization.** A conversion reads `a.len`, so the
  initialization order of globals (§11.1) treats it as a use of `a`.

Nothing here involves lifetimes. Rust needs generative lifetimes to keep a
branded index from outliving its container (the `indexing` crate), and Ada's
index subtypes (`array (Vertex) of T`) fix the bound when the type is
elaborated. Goose gets a bound that only grows from the grow-only/grow-shrink
split, which is the same monotonicity §10.5 already relies on.

The contents of `a` change freely. Only its length matters.

## 4. What bounds-check elimination gets from it

* **Facts from the type.** Any term whose expression has type `uN in a` gets
  `0 <= t <= len(a) - 1` at `a`'s *current* generation, and `upto` gets `t <=
  len(a)`. A current generation is always right, because `len(a)` never
  decreases, so no bridge facts are involved. This attaches to one-shot
  bases as well: a `for` range's end (`n.hi`) and a field read.
* **Turning a content fact into a length fact.** `dist[w]` with `w: u32 in
  nodes` reduces to `len(nodes) <= len(dist)`. That is one relation between
  two lengths, which the difference domain already states and keeps.
  * It breaks exactly where it should. If `nodes` grows after `dist` was
    sized, the generation of `len(nodes)` moves on and the check stays.
* **The conversion** is an index check of `a` and is elided the same way: in
  `for v in nodes.len { edges.push(v as NodeId); }` it costs nothing.
* **`index_of(r)` and `alloc_index(v)`** results get `0 <= t < len(recv)`,
  which they already satisfy, so `a.index_of(r) as (u32 in a)` is free.

## 5. Index types and relative references

Both are links that are checked once, when stored, and trusted when used.
Both rest on the same argument: a grow-only global target that nothing live
can see shrink. They differ in what the link names. A relative reference
names an *element*: following it is all it does, and it is a `T&` with a
root, constness, `.=` relinking and a free null. An index names a *position*
in a numbering: it is a number that reaches several arrays and can be
computed with, compared, sorted, hashed and sent out of the process. With an
index type, `&nodes[w]` turns an index into a reference without a check.

| | `Node&<u32 in pool>` | `u32 in nodes` |
|---|---|---|
| Reaches | the one array it points into, or a field inside an element | `a` and any array the analysis knows is at least as long |
| Load | `base + off - 1`, one addressing mode | `base + i * sizeof(T)`, free only for element sizes 1, 2, 4 and 8 |
| Null | the optional form, offset 0 | none: an ADT or a sentinel |
| Arithmetic, order, hashing | no (via `index_of`) | yes, as a plain number |
| `u16` covers | 64 KB of pool bytes | 65,535 elements of any size |
| Images | rejected by `from_bytes` | verified by `from_bytes` |
| Variable-size elements | yes (§3.3's index of links) | no: such an array cannot be indexed |
| Local or parameter arrays | self-relative form | no (v1) |

**Prefer relative references** where a link is only ever followed to one
element, and maybe relinked or null: linked lists and trees in a pool, map
slots pointing at nodes (`bench/goose/lru.goose`). **Prefer indices** where
the id is used as a number: to reach parallel arrays, to compute neighbours
or ranges (`i + W`, CSR offsets), to compare or sort, or to leave the
process.

A mesh is a case where both work and indices are the better choice. With
`verts: Vertex[>..]` of 32-byte vertices, `Vertex&<u32 in verts>` links in
`Tri` serve CPU code that reads positions. Indices still win, for four
reasons. The index buffer goes to the GPU as it is. It loads from file
formats as it is, with `from_bytes` doing the one check. `u16` indices, the
norm below 65,536 vertices, would reach only 2,048 vertices as `u16 in pool`.
And per-vertex attributes added later (normals, skinning weights, SoA columns
for SIMD) are parallel arrays the same index reaches.

## 6. `checkfree` functions

### 6.1 Meaning

```
fndecl := ("export" strlit? | "extern" strlit?)? "checkfree"? "inline"? "simd"? "recursive"?
          ("fn" | "thread_fn") ...
```

`checkfree fn f` is a compile error if a bounds check is left anywhere in
`f`'s body after bounds-check elimination. That covers every copy of the
body: each specialization, each `simd` version and each inlined copy. The
annotation changes nothing about what the program computes or how it is
compiled. `checkfree` is a keyword only directly before `inline`, `simd`,
`recursive`, `fn` or `thread_fn`, so it stays usable as a name.

*Bounds checks* are the index and slice checks of §9.3, conversions into
index and bound types (§2.3), and `free(i)`'s index check. The other aborts
of §9.3 are not:
* limited-array capacity;
* shrinking below empty;
* debug overflow and debug `as` checks;
* division by zero;
* relative-reference offset overflow;
* `assert` and `abort`.

`assert` in particular is how a `checkfree` function states its
preconditions once, outside its loops.

### 6.2 Calls

Every call in a `checkfree` body is to a `checkfree` function, a builtin or
an `extern`.
* **Indirect calls.** A call through a function value counts as a call to
  each function it may be. `print`, `str` and `format` count as calls to the
  user `format` overloads they reach.
* **Nested code.** Nested functions declared in a `checkfree` function are
  `checkfree` themselves. A trailing block is part of the body, and the
  function it is passed to must be `checkfree` too.
* **No inlining exception.** `inline` does not exempt a callee. Inlining is a
  request the implementation may not grant (§7.13, and never at `-O0`), and
  a call that stays a call runs the callee's own checks inside the loop.

So the guarantee is transitive: no bounds check runs while a `checkfree`
function is executing. Small helpers called from hot loops (`swap`, `min`,
`max`, vector math) are expected to be `checkfree` themselves.

### 6.3 Where its facts come from

A function's entry facts come from its call sites (§10.5). A `checkfree`
function relying on them can stop compiling when a new caller elsewhere
fails to establish them. In that case the error names that call site and the
fact it does not establish. The robust style needs no callers' facts:
* index types in the signature;
* entry `assert`s for the length relations the body needs, like
  `assert(dist.len >= nodes.len)`.

Each is one check per call, outside the loop, and reads as documentation of
the precondition.

### 6.4 What every implementation must prove

§10.5 says nothing about a program's meaning depends on how much the analysis
proves. `checkfree` makes whether a program compiles depend on it, so the
spec fixes a *core*: checks every conforming implementation must elide
inside a `checkfree` function. Accepting anything beyond the core is
implementation-defined. A program written to the core compiles under every
version of the analysis.

A *kill* of a fact about `x` is, between the fact and the check, a write to
`x`, a shrink of an array in the fact, a growth of the array an index type
names, or a call whose effect summary says it may do one of these. The core:

1. A constant index into a fixed array, in range, and an index whose type's
   whole range fits a fixed array (a `u8` into a `[256]`).
2. An index of an index type of `a`, into `a`.
3. An index of an index type of `a` into `b`, where `b.len >= a.len` (or
   `==`) was asserted or established by a counted fill, with no kill in
   between.
4. A `for` index into the array its count or range end is the length of
   (`for i in a.len`, `for x, i in a`, `for i in lo..a.len` with `lo >= 0`
   known), with no shrink of `a` in the body.
5. `a[i]` where a condition (`while`, `if`, `guard` or `assert`) established
   `i < a.len`, with no kill in between, for an `i` known to be non-negative:
   an unsigned type, an index type, or a local that starts non-negative and
   is written only by `++` and `+=` of a non-negative constant.
6. A check identical to one already passed on the same path, with no kill in
   between.

Everything else the analysis proves (products, reductions with `%` and `&`,
facts from callers, effect summaries, step counters) is best-effort.

### 6.5 Diagnostics

The error is per remaining check, at its index. It says which bound failed
(the lower, the upper, or both) and why, in the terms of
`docs/implementation.md` §9.1's "Kept" list:

* **A value read out of an array or field.** `w` is read out of `adj`, so
  the error suggests giving `adj`'s elements an index type.
* **A `u64` index variable.**
* **A length that was invalidated.** `dist`'s length was invalidated by the
  call to `f` at line N, or by `q.pop()`.
* **A fact that came from callers.** The call at file:line passes `src`
  without `src.len == W * W`.
* **A shape the domain cannot state:** a disjunctive loop exit, a counter
  stepped twice, a doubled child index.

Plain "check kept at line 61" is what `--bce-lines` gives today. The
explanation is where most of this feature's work is (§8).

### 6.6 Flags and combinations

* **Flags.**
  * Under `--no-bce`, `checkfree` is not verified. One warning says so, and
    every check is present as usual.
  * Debug and release builds run the same analysis and get the same verdict.
  * At `-O0` nothing is inlined. A function whose checks are settled by its
    own types and asserts gets the same verdict there.
* **Combinations.**
  * `checkfree` is an error with `extern`, which has no body.
  * It may be combined with `inline`, `simd`, `recursive`, `thread_fn` and
    `export`.
  * A thread entry and an export get no call-site facts, which the core
    never relies on anyway.

## 7. Worked example: CSR breadth-first search

`graph_csr.goose` written with index types. The graph is global and built
once. Per edge the traversal does no check, and per vertex none either.

```goose
struct Node { lo: u32 upto edges, hi: u32 upto edges }

var nodes: Node[>..] = [];
type NodeId = u32 in nodes;
var edges: NodeId[>..] = [];

// Builds the graph from an edge list nothing has validated: these checks are
// the only ones the traversal will ever need.
fn build(nv: i64, src: i32[:], dst: i32[:]) {
    let empty = 0 as (u32 upto edges);            // 0 <= edges.len always
    for v in nv { nodes.push(Node { lo: empty, hi: empty }); }
    var first: i64[>..] = [];                     // CSR offsets
    for v in nv + 1 { first.push(0); }
    for e in src.len { first[src[e] + 1]++; }
    for v in nv { first[v + 1] += first[v]; }
    var next: i64[>..] = [];
    for v in nv { next.push(first[v]); }
    let some = 0 as NodeId;                       // aborts for an empty graph
    for e in dst.len { edges.push(some); }
    for e in src.len {
        let s = src[e];
        edges[next[s]] = dst[e] as NodeId;        // one check per edge, here
        next[s]++;
    }
    for v in nv {
        nodes[v].lo = first[v] as (u32 upto edges);
        nodes[v].hi = first[v + 1] as (u32 upto edges);
    }
}

// The sum of distances from src; dist holds an entry per node.
checkfree fn bfs(dist: i32[>..]&, q: NodeId[>..<]&, src: NodeId) -> i64 {
    assert(dist.len >= nodes.len);
    var total = 0;
    q.clear();
    dist[src] = 0;                     // core 3
    q.push(src);
    var qh = 0;
    while qh < q.len {
        let u = q[qh];                 // core 5; u: NodeId
        qh++;
        let d = dist[u];               // core 3
        total += d;
        let n = nodes[u];              // core 2
        for k in n.lo..n.hi {          // k: u32 in edges (§2.3)
            let w = edges[k];          // core 2; w: NodeId
            if dist[w] < 0 {           // core 3
                dist[w] = d + 1;       // core 6
                q.push(w);
            }
        }
    }
    return total;
}
```

Notes on the example:
* **Core 3 holds through the loop** because nothing in it grows `nodes` or
  shrinks `dist`. `q` is a different array of a different type.
* **`build` keeps its checks,** on input data, at build time, once per edge
  and vertex.
* **The order in `build` matters.** The nodes exist before the edges that
  name them, and the offsets are set once the edges are all there.
* **The graph can't be rebuilt** in the same run. `edges` can never be
  cleared (§2.7), which suits a graph loaded once. A graph rebuilt per phase
  needs the grow-shrink extension of §10.

## 8. Implementation

### 8.1 Where the risk is

Every typed store already passes `TypeCheck::FitsAt`, which is also where
`in pool` checks roots. Making it reject an index-typed destination for
anything but a value of the same type covers almost every way an element can
be written. The rest is §2.6's short list.

The real risk is integer code that picks a result type by storage width, or
by copying an operand's `TypeExpr *`, and so would carry an index type along
silently:
* `MergeVals`' constant `adapt`, which would type `if c { 4000000 } else { w
  }` as `u32 in nodes`;
* `UnifyBranch`'s `ImplicitInt` cases;
* shifts, which take the left operand's type;
* `UnifyNumeric`;
* the constant and literal cases of `FitsAt`.

The typechecker has about 70 `intstorage`, `SameNum` and `IsU8` tests, and
each needs looking at.

Two choke points make that fail closed:
* **Strip the type in `TypeCheck::Operand`.** Every operator operand comes
  through it, so no arithmetic result can carry an index type. Index
  positions keep it on `exprtype` for the bounds-check pass before
  decaying.
* **Require `TypeEq`** of every value stored at, or joined into, an index
  type.

The alternative is a separate `TY_INDEX` kind, which every `kind == TY_INT`
test rejects. A site it misses becomes a spurious error rather than a hole,
at the price of about 100 such tests to visit, codegen included.

### 8.2 By area

* **`ast.h`.**
  * `TypeExpr` gains the named array (and the name the parser saw) outside
    the union, since `intstorage` is the `TY_INT` member. It also gains an
    `in`/`upto` bit.
  * Function declarations gain `checkfree`.
  * `AsCast` gains a `nobc` flag.
* **`parser.h`, `dump.h`, `TypeStr`.** The `indextype` production with its
  no-postfix rule, and the modifier. Small.
* **Typechecker.**
  * Resolving the name once, as `TypeRef::pool` is resolved, and §2.2's
    validity.
  * `TypeEq`, `FitsAt`, `Operand`, `MergeVals` and `UnifyBranch`.
  * `CompoundAssign` and `CheckIncDec`, `HasDefault`.
  * The cast rules: always checked, never redundant into a different type,
    no `as!`.
  * The `for` variable's type.
  * Queue, spawn, `extern`/`export`, `format` and `to_bytes` targets.
  * The shrink ban, through the global shrink summaries
    (`CheckGlobalShrinks`).
  * `checkfree`'s call rule, over the call graph `BuildCallGraph` already
    builds.
* **`bce.h`.**
  * §4's facts.
  * The cast as an index check.
  * `checkfree` verification. `lineout` already counts kept checks per
    source line across every specialization and inlined copy, so a check of
    zero kept over a function's lines is close to free.
  * The diagnostics of §6.5, which need the pass to record per kept check
    which bound failed, the base kind of the index term, the statement that
    last killed the length base, and which call site's meet dropped an entry
    fact.
* **Codegen.**
  * The conversion's check (`GS_IDX`, plus the width test of §2.3).
  * The `from_bytes` verifier's range check.
  * Making sure `Box<u32 in nodes>` and `Box<u32>` cannot collide in
    `Mangle`.
  * Nothing else. The C type comes from `intstorage`.
* **Optimizer.** Nothing for soundness. Its rewrites keep values, so an
  index type a rewrite keeps is still true, and one it drops only costs a
  check.

### 8.3 Size

For calibration, `in pool` landed in cae09614 as about 380 lines of compiler
source (typecheck +135, codegen +216, ast +21) plus spec and seven error
fixtures. About ten follow-ups over the next month fixed exactly the paths
§8.1 is about. Examples are "Encode references that literals, branches and
calls store in relative slots", "Keep relative references out of results and
default<T>() values" and "Give type-parameter locals and parameters the plain
reference for links".

Index types have no encoding half, since the C representation is the plain
integer, so codegen work is small. They are values that flow everywhere, so
the typechecker part is wider. Expect 400–600 lines for the types and the
`checkfree` check, plus about 20 error fixtures. Expect an open-ended amount
for §6.5's explanations, and a tail of the same kind as `in pool`'s.

## 9. Testing

* **`test/errors_tc` fixtures, one per rejection:**
  * a constant, an arithmetic result, compound assignment and `++` into an
    index type;
  * a mixed-branch join stored as one;
  * a `u32[:]` parameter given a `NodeId[:]`;
  * `default<NodeId>()`;
  * `format` into `(u8 in x)[>..]`;
  * `qput` of one, an `extern` result;
  * each shrink of a named array, directly and through a reference
    parameter;
  * `as!` into one;
  * an invalid named array (local, grow-shrink, sequential).
* **`// bce:elide` and `// bce:keep` fixtures** for §4. Among the keeps is
  `dist[w]` after `nodes` grows past where `dist` was sized.
* **Execution tests:** the conversion's abort, with its message, in release;
  `from_bytes` rejecting an out-of-range index; the width check of a `u8 in
  a` conversion.
* **`checkfree` fixtures:**
  * each core rule accepted;
  * a kept check rejected with each §6.5 reason;
  * a call to an unannotated function;
  * a new caller dropping an entry fact.
* **Fuzzing.** `bench/bce_fuzz.py` grows index-typed shapes: loads, joins,
  generic pass-through and growth between sizing and use.
* **Benchmarks.** Ports of `graph_csr.goose`, as in §7, and of a gather
  kernel (`out[i] = xf(verts[idx[i]])`). They measure the win, which is
  unmeasured so far. On clang a kept check is usually a well-predicted
  branch. On MSVC a kept check in a loop prevents vectorization
  (`docs/implementation.md` §9.1: `blur` was 1.75x slower with nine checks),
  and gather loops only vectorize without checks.

## 10. Open questions

* **Names.** `checkfree` overpromises slightly, since other aborts remain.
  `proven` and `boundsfree` are alternatives. Names that read as permission
  are out (Odin's `#no_bounds_check` and Julia's `@inbounds` disable checks
  unsafely). `upto` might instead be `in ..= a`.
* **`var` inference.** Should a `var` without a written type take the plain
  type, so that reassigning it works? `var u = q[qh]` would then lose the
  index type, and every loop that walks with a `var` would need it written.
* **Locals and parameters as `a`.** A local array could be named in local
  declarations, and a reference parameter's array settled per call site as
  pool parameters' are (§3.9). The obstacle is only a field's type, which
  cannot name a local.
* **Shrinkable arrays as `a`.** A grow-shrink array could shrink where no
  index value of it is live, as §5.2 does for references. That is what a
  graph rebuilt per phase needs.
* **Signed index types.** `i64 in a` would let `for i in a.len` and `for x, i
  in a` give index types without a cast. Giving existing loops new types
  changes which generic instantiations existing programs make, so v1 does
  not.
* **Read-only views.** A `const u32[:]` could accept a `NodeId[:]`, since
  nothing writes through it. That needs a subtyping rule `TypeEq` does not
  have.
* **An optional form** biased by one, as `in pool` is, would give a free
  null.
* **Thread spawn arguments** are probably safe, since the worker's copy of
  `a` is taken at the spawn, provided the worker uses `a`. v1 rejects them.
* **`index_of` and `alloc_index`** could return index types instead of
  `i64`. That would break code doing arithmetic on the result in place, so
  v1 only adds the fact (§4).
* **Fixed arrays as `a`** (`u8 in table` for a `T[256]`) are sound trivially
  and mostly cover what the type's range already gives.
