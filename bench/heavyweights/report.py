#!/usr/bin/env python3
"""Turn results/*.json (written by run.py) into RESULTS.md, chart.png and summary.md."""
import json, math, statistics
from pathlib import Path

HERE = Path(__file__).resolve().parent
RES = HERE / "results"
ORDER = ["helium", "c-gcc", "c-clang", "c-gcc-arena", "rust", "zig", "go", "java", "node", "python"]
BENCHES = ["fib", "nbody", "spectral", "bintrees", "fannkuch", "mandelbrot", "strmap"]
REF = "c-gcc"


def load():
    d = {}
    for f in RES.glob("*__*.json"):
        r = json.loads(f.read_text())
        d[(r["lang"], r["bench"])] = r
    return d


def labels(d):
    return {k[0]: v["label"] for k, v in d.items()}


def fmt_t(s):
    return f"{s * 1000:.0f} ms" if s < 10 else f"{s:.1f} s"


def fmt_kb(kb):
    return f"{kb / 1024:.1f} MB"


def fmt_size(b):
    if b is None:
        return "–"
    return f"{b / 1024:.0f} KB" if b < 10 * 1048576 else f"{b / 1048576:.1f} MB"


def langs_present(d):
    return [l for l in ORDER if any((l, b) in d for b in BENCHES)]


def table(d, langs, cell, bench_label=lambda b: b):
    lab = labels(d)
    rows = ["| Program | " + " | ".join(lab[l] for l in langs) + " |",
            "|---|" + "---:|" * len(langs)]
    for b in BENCHES:
        cells = []
        for l in langs:
            r = d.get((l, b))
            cells.append(cell(r) if r else "–")
        rows.append(f"| {bench_label(b)} | " + " | ".join(cells) + " |")
    return "\n".join(rows)


def geomean_vs_ref(d, l, skip=()):
    xs = [d[(l, b)]["wall"]["median"] / d[(REF, b)]["wall"]["median"] for b in BENCHES
          if b not in skip and (l, b) in d and (REF, b) in d]
    return (math.exp(statistics.mean(math.log(x) for x in xs)), len(xs)) if xs else (None, 0)


def bold_best(d, langs, b, val):
    vals = {l: val(d[(l, b)]) for l in langs if (l, b) in d and val(d[(l, b)]) is not None}
    return min(vals, key=vals.get) if vals else None


def headline(d, langs):
    """Helium's geometric-mean wall time against each other language, all programs and without bintrees."""
    lab = labels(d)

    def rel(l, skip=()):
        h, x = geomean_vs_ref(d, "helium", skip)[0], geomean_vs_ref(d, l, skip)[0]
        r = x / h
        return f"{r:.2f}× faster" if r >= 1 else f"{1 / r:.2f}× slower"

    order = [l for l in ["rust", "go", "java", "node", "python", "zig", "c-clang", "c-gcc"] if l in langs]
    rows = ["| Helium (hcn) against | geomean wall time, all 7 programs | without bintrees |", "|---|---:|---:|"]
    for l in order:
        rows.append(f"| {lab[l]} | Helium {rel(l)} | Helium {rel(l, ('bintrees',))} |")
    return "\n".join(rows)


def chart(d, langs, path):
    """Speedup vs. C (gcc -O2) per program, plus geometric means; higher is faster."""
    import matplotlib
    matplotlib.use("Agg")
    import matplotlib.pyplot as plt
    lab = labels(d)
    langs = [l for l in langs if l != "c-gcc-arena"]
    colors = {"helium": "#7b2ff7", "c-gcc": "#555555", "c-clang": "#999999", "rust": "#ce422b", "zig": "#f7a41d",
              "go": "#00add8", "java": "#5382a1", "node": "#3c873a", "python": "#e0b800"}

    def sp(l, b):
        return d[(REF, b)]["wall"]["median"] / d[(l, b)]["wall"]["median"] if (l, b) in d and (REF, b) in d else None

    def lbl(x):
        return f"{x:.2f}" if x >= 0.1 else f"{x:.3f}"

    fig, (ax, gx) = plt.subplots(1, 2, figsize=(19, 8), dpi=130, gridspec_kw={"width_ratios": [2.8, 1]})
    w = 0.8 / len(langs)
    for i, l in enumerate(langs):
        hl = l == "helium"
        xs, ys = [], []
        for j, b in enumerate(BENCHES):
            s = sp(l, b)
            if s is None:
                continue
            xs.append(j + (i - len(langs) / 2 + 0.5) * w); ys.append(s)
        ax.bar(xs, ys, w, label=lab[l], color=colors.get(l), alpha=1.0 if hl else 0.55,
               edgecolor="black" if hl else "none", linewidth=1.2 if hl else 0, zorder=3 if hl else 2)
        for x, y in zip(xs, ys):
            ax.text(x, y * 1.06, lbl(y) + "×", ha="center", va="bottom", rotation=90,
                    fontsize=7.5 if hl else 6.5, fontweight="bold" if hl else "normal",
                    color="black" if hl else "#444444")
    ax.set_yscale("log")
    ax.axhline(1.0, color="black", linewidth=0.7)
    ax.set_xticks(range(len(BENCHES)), BENCHES)
    ax.set_ylim(0.005, 30)
    ax.set_ylabel("speedup vs. C (gcc -O2) = gcc time / language time\nlog scale; higher is faster")
    ax.set_title("Per program: median wall time, same algorithm, same output")
    ax.legend(ncol=len(langs), fontsize=8, loc="upper center", bbox_to_anchor=(0.5, -0.07), frameon=False)
    ax.grid(axis="y", which="both", alpha=0.25)

    rows = []
    for l in langs:
        g, _ = geomean_vs_ref(d, l)
        gnb, _ = geomean_vs_ref(d, l, ("bintrees",))
        rows.append((l, 1 / g, 1 / gnb, g, gnb))
    rows.sort(key=lambda r: r[1])
    h = 0.38
    for k, (l, s, snb, g, gnb) in enumerate(rows):
        hl = l == "helium"
        a = 1.0 if hl else 0.55
        gx.barh(k + h / 2, s, h, color=colors.get(l), alpha=a, edgecolor="black" if hl else "none", linewidth=1.2 if hl else 0)
        gx.barh(k - h / 2, snb, h, color=colors.get(l), alpha=a * 0.6, hatch="///", edgecolor="black" if hl else "#666666",
                linewidth=1.2 if hl else 0.3)
        fw = "bold" if hl else "normal"
        gx.text(s * 1.08, k + h / 2, f"{s:.2f}× (time {g:.2f}×)", va="center", fontsize=8, fontweight=fw)
        gx.text(snb * 1.08, k - h / 2, f"{snb:.2f}× (time {gnb:.2f}×)", va="center", fontsize=7, fontweight=fw, color="#444444")
    gx.set_yticks(range(len(rows)), [lab[r[0]] for r in rows])
    for t, r in zip(gx.get_yticklabels(), rows):
        if r[0] == "helium":
            t.set_fontweight("bold"); t.set_color(colors["helium"])
    gx.set_xscale("log")
    gx.set_xlim(0.015, 60)
    gx.axvline(1.0, color="black", linewidth=0.7)
    gx.set_xlabel("geomean speedup vs. C (gcc -O2), log scale; higher is faster")
    gx.set_title("Geometric mean, all 7 programs (solid)\nand without bintrees (hatched)")
    gx.grid(axis="x", which="both", alpha=0.25)
    fig.suptitle("Helium vs. C, Rust, Zig, Go, Java, Node and Python: speedup relative to C (gcc -O2)", fontsize=13)
    fig.tight_layout()
    fig.savefig(path)


def main():
    d = load()
    m = json.loads((RES / "machine.json").read_text())
    langs = langs_present(d)
    lab = labels(d)
    n = {b: next(r["n"] for (l, bb), r in d.items() if bb == b) for b in BENCHES if any(bb == b for (_, bb) in d)}

    def tcell(b_val):
        return lambda r: fmt_t(r["wall"]["median"])

    def wall_table():
        out = ["| Program | " + " | ".join(lab[l] for l in langs) + " |", "|---|" + "---:|" * len(langs)]
        for b in BENCHES:
            best = bold_best(d, [l for l in langs if l != "c-gcc-arena"], b, lambda r: r["wall"]["median"])
            cells = []
            for l in langs:
                r = d.get((l, b))
                if not r:
                    cells.append("–"); continue
                c = fmt_t(r["wall"]["median"]) + ("" if r["correct"] else " ✗")
                cells.append(f"**{c}**" if l == best else c)
            out.append(f"| {b} ({n[b]:,}) | " + " | ".join(cells) + " |")
        gm = []
        for l in langs:
            g, k = geomean_vs_ref(d, l)
            gm.append(f"{g:.2f}×" + ("" if k == len(BENCHES) else f" ({k} prog.)") if g else "–")
        out.append("| **geomean vs C (gcc)** | " + " | ".join(gm) + " |")
        gx = []
        for l in langs:
            g, k = geomean_vs_ref(d, l, ("bintrees",))
            gx.append(f"{g:.2f}×" if g else "–")
        out.append("| geomean without bintrees | " + " | ".join(gx) + " |")
        return "\n".join(out)

    rss = table(d, langs, lambda r: fmt_kb(r["peak_rss_kb"]))
    size = table(d, langs, lambda r: fmt_size(r.get("stripped_bytes")))
    comp = table(d, langs, lambda r: fmt_t(r["compile"]["median"]) if r.get("compile") else "–")
    cmds = []
    for l in langs:
        r = next(r for (ll, b), r in sorted(d.items()) if ll == l)
        def rel(c):
            c = c.replace(str(HERE.parent.parent), "$REPO").replace("/tmp/helium-heavyweights", "$BUILD")
            c = c.replace(str(Path.home()), "~").replace(f" {r['n']}", " N")
            if r["file"] != r["bench"]:  # a variant that exists for one program only
                return c
            return c.replace(f"/{r['file']}", "/PROG").replace(f" {r['file']} ", " PROG ")
        envp = {"helium": "HC_LIB=$REPO/hc/lib ", "go": "GO111MODULE=off CGO_ENABLED=0 GOCACHE=… "}.get(l, "")
        cmds.append(f"| {lab[l]} | `{envp}{rel(r.get('compile_cmd', '–'))}` | `{rel(r['run_cmd'])}` |")
    allok = all(r["correct"] for r in d.values())
    v = m["versions"]
    import datetime
    mt = sorted(f.stat().st_mtime for f in RES.glob("*__*.json"))
    tz = datetime.datetime.now().astimezone().tzinfo
    span = " to ".join(dict.fromkeys(datetime.datetime.fromtimestamp(t, tz).strftime("%Y-%m-%d %H:%M %z") for t in (mt[0], mt[-1])))
    chart(d, langs, HERE / "chart.png")

    md = f"""# Helium vs. the heavyweights

Seven small programs, each written once per language with the same algorithm and the
same output. Every build's stdout is compared byte-for-byte with the C (gcc) build at
the benchmark size before it is timed; {"all " + str(len(d)) + " builds matched" if allok else "builds marked ✗ did not match"}.
Numbers are measured, not estimated; regenerate them with `python3 run.py` (about 30
minutes, most of it CPython) and `python3 report.py`.

## Headline

Ratio of geometric-mean wall times over the programs below (each language's times are first
divided by C (gcc)'s; the ratio of two such geomeans is the same whichever language is the
reference). bintrees favours Helium because its program uses a per-function pool where the
others allocate every node (see below), so the right-hand column leaves it out.

{headline(d, langs)}

Helium is slower on fib, where gcc inlines the recursion into itself (see below).

![speedup relative to C (gcc -O2), higher is faster](chart.png)

The chart shows speedup, C (gcc)'s time divided by each language's (higher is faster), on a
log scale; the right panel is the geometric mean over all 7 programs (solid) and without
bintrees (hatched), with the corresponding time ratio in brackets.

## Wall time

Median of {m['runs']} timed runs after 1 warmup run (hyperfine), process start-up included.
Fastest per row in bold (the arena variant of C is excluded from that).
The last rows are the geometric mean of each language's time divided by C (gcc)'s, with
and without bintrees (where the allocation strategies differ, see below).

{wall_table()}

## Peak resident memory

Median over the timed runs (hyperfine's `memory_peak_resident`).

{rss}

## Executable size

Size after `strip`. Java: the `.class` files (the JVM itself is not counted). Node and
Python: no build artifact.

{size}

## Compile time

Median of 3 builds (hyperfine). Before each Go and Zig build the toolchain cache is
reset to a copy that holds only the prebuilt standard runtime (made by compiling a
hello-world), so the timing covers compiling the program, not a cache hit. gcc, clang,
rustc, javac and hcn keep no cache between runs.

{comp}

## What each program does

| Program | Work (argument N) | Output |
|---|---|---|
| fib | naive doubly recursive `fib(N)` on 64-bit ints | the number |
| nbody | Benchmarks Game n-body, 5 bodies, N steps of dt = 0.01 | energy before and after, `%.9f` |
| spectral | Benchmarks Game spectral-norm, N×N, 10 power iterations | the norm, `%.9f` |
| bintrees | Benchmarks Game binary-trees, depth N, min depth 4 | the standard check lines |
| fannkuch | Benchmarks Game fannkuch-redux (single-threaded), N | checksum and max flips |
| mandelbrot | N×N grid over [-1.5, 0.5]×[-1, 1], 50 iterations, count of points in the set | the count |
| strmap | N inserts/increments of string keys `"key" + (x mod 200000)` from an LCG into a string→int hash map | distinct keys, max count, sum of counts of key0…key999 |

All programs are single-threaded.

## Differences between implementations that affect the numbers

- **bintrees.** Helium has no per-object heap; its program builds each tree in a
  pool local to the function that builds it, freed in one step when that function
  returns. The C, Rust, Zig, Go, Java, Node and Python programs allocate and free
  every node individually (malloc/free, `Box`, the smp allocator, the GC). Because
  that is a different allocation strategy, `c/bintrees_arena.c` ("C (gcc -O2, arena)")
  is the same program with one bump arena per tree: compare Helium with that column
  for the code generator, and with the others for the language as idiomatically used.
- **strmap.** Each language uses its standard string-keyed hash map: Helium
  `dictionary<const byte[:], int>` (keys copied into one growing byte array),
  Rust `HashMap<String, i64>` (SipHash), Zig `std.StringHashMap` (Wyhash), Go
  `map[string]int`, Java `HashMap<String, Integer>`, JS `Map`, Python `dict`. C has no
  standard map, so `c/strmap.c` is a 35-line FNV-1a open-addressing table.
- **fib.** gcc -O2 inlines `fib` into itself several levels deep (its `fib` is about
  250 instructions with one remaining recursive call; clang's is about 30), which is
  why gcc is twice as fast as everything else here. fib measures call overhead and
  how far a compiler unrolls recursion.
- **Instruction set.** Every ahead-of-time build targets baseline x86-64 (SSE2, no
  AVX): the gcc, clang, rustc and Go defaults, Zig with `-mcpu=baseline` (its default
  is the host CPU), Helium without `--v3`/`--v4`. The JVM and V8 JITs use whatever the
  host CPU supports.
- **Start-up.** Times include process start-up and, for Java and Node, JIT warm-up
  inside the single run: the programs are measured as a user runs them.
- **Not included.** Kotlin (no `kotlinc` on the machine; a system install was out of
  scope), PyPy (not installed). Rust is built with `rustc` directly using the flags
  `cargo --release` would use, plus `codegen-units=1`.

## Machine and versions

- CPU: {m['cpu']} ({m['threads']} hardware threads), {m['mem_gib']} GiB RAM
- OS: {m['os']}, Linux {m['kernel']}
- Every build and run: `{m['pinning']}` (4 cores of the CCD without the stacked L3 cache, low priority; the desktop
  was in normal use, so expect a few percent of noise)
- Measured {span}. During the published run another job (an LLM evaluation
  harness that calls model APIs and compiles and runs the programs they write) was
  pinned to CPUs 24-31, which include the SMT siblings of the cores used here
- gcc: {v['gcc']}
- clang: {v['clang']}
- Helium: {v['helium']}
- rustc: {v['rustc']}
- Zig: {v['zig']}
- Go: {v['go']}
- Java: {v['java']}
- Node: {v['node']}
- Python: {v['python']}
- hyperfine: {v['hyperfine']}

## Exact commands

`$REPO` is the repository root, `$BUILD` is `/tmp/helium-heavyweights` (`HW_BUILD`),
`PROG` is the program name and `N` the argument from the wall-time table. Per-run
raw data (every timing, the exact command lines, outputs) is in `results/*.json`.

| Language | Build | Run |
|---|---|---|
{chr(10).join(cmds)}

Reproduce:

```bash
hc/bootstrap.sh                     # builds build/hcn
cd bench/heavyweights
python3 run.py --quick              # small sizes: checks every program builds and agrees
python3 run.py                      # full run, writes results/*.json
python3 report.py                   # writes RESULTS.md and chart.png
```

`run.py` finds hyperfine, go and zig on `PATH` or under `~/.local/opt`; override with
`HYPERFINE=`, `GO=`, `ZIG=`, `HCN=`, and the pinning with `HW_CPUS=` / `HW_NICE=` /
`HW_RUNS=`.
"""
    (HERE / "RESULTS.md").write_text(md)

    # Short table for the top-level README.
    main_langs = [l for l in ["helium", "c-gcc", "c-clang", "rust", "zig", "go", "java", "node", "python"] if l in langs]
    s = ["| Program | " + " | ".join(lab[l] for l in main_langs) + " |", "|---|" + "---:|" * len(main_langs)]
    for b in BENCHES:
        s.append(f"| {b} | " + " | ".join(fmt_t(d[(l, b)]["wall"]["median"]) if (l, b) in d else "–" for l in main_langs) + " |")
    s.append("| geomean vs C (gcc) | " + " | ".join(f"{geomean_vs_ref(d, l)[0]:.2f}×" for l in main_langs) + " |")
    s.append("| geomean without bintrees | " + " | ".join(f"{geomean_vs_ref(d, l, ('bintrees',))[0]:.2f}×" for l in main_langs) + " |")
    (HERE / "summary.md").write_text("\n".join(s) + "\n")
    print("\n".join(s))


if __name__ == "__main__":
    main()
