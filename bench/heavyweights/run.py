#!/usr/bin/env python3
"""Cross-language benchmark runner for Helium vs. C, Rust, Go, Zig, Java, Node, Python.

Usage:
  python3 run.py                 # build, verify and time everything (full sizes)
  python3 run.py --quick         # small sizes, 1 run each: smoke test of every program
  python3 run.py --lang zig      # restrict to some languages (repeatable)
  python3 run.py --bench nbody   # restrict to some programs (repeatable)

Measurements per (language, program):
  wall time   hyperfine, 1 warmup + RUNS timed runs, median reported
  peak RSS    hyperfine 2's per-run memory_peak_resident, median of the timed runs
  binary size size of the produced executable, and after `strip`
  compile     hyperfine, 3 runs, median; per-run caches are reset (see README.md)
  correctness stdout must equal the output of the C (gcc) build byte-for-byte

All timed processes run under `nice -n NICE taskset -c CPUS`.
Toolchain paths can be overridden with environment variables (see TOOLS).
"""
import argparse, json, os, platform, shutil, statistics, subprocess, sys, tempfile, time
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent.parent
BUILD = Path(os.environ.get("HW_BUILD", "/tmp/helium-heavyweights"))
RESULTS = HERE / "results"
HOME = Path.home()

TOOLS = {
    "hyperfine": os.environ.get("HYPERFINE", shutil.which("hyperfine") or str(HOME / ".local/opt/hyperfine-v2.0.0-x86_64-unknown-linux-musl/hyperfine")),
    "go": os.environ.get("GO", shutil.which("go") or str(HOME / ".local/opt/go1.27.3/bin/go")),
    "zig": os.environ.get("ZIG", shutil.which("zig") or str(HOME / ".local/opt/zig-x86_64-linux-0.17.0/zig")),
    "hcn": os.environ.get("HCN", str(ROOT / "build/hcn")),
}
NICE = os.environ.get("HW_NICE", "10")
CPUS = os.environ.get("HW_CPUS", "8-11")
RUNS = int(os.environ.get("HW_RUNS", "5"))

BENCHES = ["fib", "nbody", "spectral", "bintrees", "fannkuch", "mandelbrot", "strmap"]
FULL = {"fib": 40, "nbody": 10_000_000, "spectral": 3000, "bintrees": 18,
        "fannkuch": 11, "mandelbrot": 4000, "strmap": 5_000_000}
QUICK = {"fib": 30, "nbody": 1000, "spectral": 100, "bintrees": 10,
         "fannkuch": 7, "mandelbrot": 200, "strmap": 100_000}

# id, label, source dir, extension
LANGS = [
    ("c-gcc", "C (gcc -O2)", "c", ".c"),
    ("c-clang", "C (clang -O2)", "c", ".c"),
    ("helium", "Helium (hcn)", "helium", ".amni"),
    ("rust", "Rust (rustc -O3)", "rust", ".rs"),
    ("zig", "Zig (ReleaseFast)", "zig", ".zig"),
    ("go", "Go", "go", ".go"),
    ("java", "Java (OpenJDK)", "java", ".java"),
    ("node", "Node.js", "js", ".js"),
    ("python", "Python (CPython)", "python", ".py"),
]
# Extra variants that only exist for some programs: (id, label, base lang, file stem, program)
VARIANTS = [("c-gcc-arena", "C (gcc -O2, arena)", "c-gcc", "bintrees_arena", "bintrees")]

GO_ENV = {"GOPATH": str(BUILD / "gopath"), "GO111MODULE": "off", "CGO_ENABLED": "0"}


def sh(cmd, **kw):
    return subprocess.run(cmd, check=True, text=True, capture_output=True, **kw)


def warm_caches():
    """Pre-build toolchain runtime libraries once, so compile timings measure the program."""
    BUILD.mkdir(parents=True, exist_ok=True)
    gw = BUILD / "gocache-warm"
    if not gw.exists():
        (BUILD / "hello.go").write_text('package main\nimport ("fmt"; "math"; "os"; "strconv")\n'
            'func main() { n, _ := strconv.Atoi(os.Args[0]); fmt.Println(math.Sqrt(float64(n))) }\n')
        sh([TOOLS["go"], "build", "-o", str(BUILD / "hello-go"), str(BUILD / "hello.go")],
           env={**os.environ, **GO_ENV, "GOCACHE": str(gw)})
    zw = BUILD / "zigcache-warm"
    if not zw.exists():
        (BUILD / "hello.zig").write_text('const std = @import("std");\npub fn main() void { _ = std.os.linux.write(1, "hi\\n", 3); }\n')
        sh([TOOLS["zig"], "build-exe", "-O", "ReleaseFast", "-mcpu=baseline", "--global-cache-dir", str(zw),
            "--cache-dir", str(BUILD / "zc-hello"), f"-femit-bin={BUILD / 'hello-zig'}", str(BUILD / "hello.zig")])


def plan(lang, stem):
    """Return (compile argv or None, prepare shell cmd or None, run argv, artifact path or None, env)."""
    src = HERE / dict((l[0], l[2]) for l in LANGS)[lang] / (stem + dict((l[0], l[3]) for l in LANGS)[lang])
    out = BUILD / lang / stem
    env = dict(os.environ)
    if lang == "c-gcc":
        return ["gcc", "-O2", "-o", str(out), str(src), "-lm"], None, [str(out)], out, env
    if lang == "c-clang":
        return ["clang", "-O2", "-o", str(out), str(src), "-lm"], None, [str(out)], out, env
    if lang == "helium":
        env["HC_LIB"] = str(ROOT / "hc/lib")
        return [TOOLS["hcn"], "build", str(src), "-o", str(out)], None, [str(out)], out, env
    if lang == "rust":
        return ["rustc", "-C", "opt-level=3", "-C", "codegen-units=1", "-o", str(out), str(src)], None, [str(out)], out, env
    if lang == "go":
        gc = BUILD / "gocache-run"
        env.update(GO_ENV, GOCACHE=str(gc))
        prep = f"rm -rf {gc} && cp -r {BUILD / 'gocache-warm'} {gc}"
        return [TOOLS["go"], "build", "-o", str(out), str(src)], prep, [str(out)], out, env
    if lang == "zig":
        gc, lc = BUILD / "zigcache-run", BUILD / "zigcache-local"
        prep = f"rm -rf {gc} {lc} && cp -r {BUILD / 'zigcache-warm'} {gc}"
        return [TOOLS["zig"], "build-exe", "-O", "ReleaseFast", "-mcpu=baseline", "--global-cache-dir", str(gc), "--cache-dir", str(lc),
                f"-femit-bin={out}", str(src)], prep, [str(out)], out, env
    if lang == "java":
        cls = BUILD / "java" / stem
        prep = f"rm -rf {cls}"
        return ["javac", "-d", str(cls), str(src)], prep, ["java", "-cp", str(cls), stem], cls, env
    if lang == "node":
        return None, None, ["node", str(src)], None, env
    if lang == "python":
        return None, None, ["python3", str(src)], None, env
    raise ValueError(lang)


def wrap(argv):
    return ["nice", "-n", NICE, "taskset", "-c", CPUS] + argv


def hyperfine(cmd_argv, runs, warmup, env, prepare=None, label="x"):
    js = BUILD / f"hf-{label}.json"
    hf = [TOOLS["hyperfine"], "-N", "--style", "none", "--runs", str(runs), "--warmup", str(warmup),
          "--export-json", str(js)]
    if prepare:
        hf += ["--prepare", prepare]
    hf.append(subprocess.list2cmdline(cmd_argv))
    sh(wrap(hf), env=env)
    r = json.loads(js.read_text())["results"][0]
    if "times" in r:  # hyperfine 1.x
        t = r["times"]
    else:  # hyperfine 2.x
        t = [m["time_wall_clock"]["value"] for m in r["measurements"]]
    out = {"median": statistics.median(t), "mean": statistics.mean(t),
           "stddev": statistics.stdev(t) if len(t) > 1 else 0.0, "min": min(t), "max": max(t), "times": t}
    if "measurements" in r:
        out["peak_rss_kb"] = statistics.median(m["memory_peak_resident"]["value"] for m in r["measurements"]) / 1024
    return out


def artifact_size(path):
    if path is None:
        return None, None
    if path.is_dir():
        n = sum(f.stat().st_size for f in path.rglob("*") if f.is_file())
        return n, n
    raw = path.stat().st_size
    tmp = BUILD / "stripped.bin"
    shutil.copy(path, tmp)
    subprocess.run(["strip", str(tmp)], capture_output=True)
    return raw, tmp.stat().st_size


def run_one(lang, label, stem, bench, sizes, quick):
    comp, prep, run, art, env = plan(lang, stem)
    (BUILD / lang).mkdir(parents=True, exist_ok=True)
    res = {"lang": lang, "label": label, "bench": bench, "file": stem, "n": sizes[bench]}
    if comp:
        if prep:
            subprocess.run(prep, shell=True, check=True)
        sh(comp, env=env)  # plain build first: surfaces compile errors
        res["compile_cmd"] = subprocess.list2cmdline(comp)
        if not quick:
            res["compile"] = hyperfine(comp, 3, 0, env, prep, f"c-{lang}-{stem}")
    res["run_cmd"] = subprocess.list2cmdline(run + [str(sizes[bench])])
    res["binary_bytes"], res["stripped_bytes"] = artifact_size(art)
    argv = run + [str(sizes[bench])]
    t0 = time.time()
    res["stdout"] = sh(wrap(argv), env=env).stdout
    res["single_run_s"] = time.time() - t0
    if not quick:
        res["wall"] = hyperfine(argv, RUNS, 1, env, None, f"r-{lang}-{stem}")
        res["peak_rss_kb"] = res["wall"].pop("peak_rss_kb")
    return res


def machine():
    cpu = next((l.split(":", 1)[1].strip() for l in open("/proc/cpuinfo") if l.startswith("model name")), "?")
    mem = next((int(l.split()[1]) for l in open("/proc/meminfo") if l.startswith("MemTotal")), 0)
    def ver(cmd):
        try:
            p = subprocess.run(cmd, capture_output=True, text=True)
            return (p.stdout or p.stderr).strip().splitlines()[0]
        except Exception as e:
            return f"unavailable ({e})"
    hc_rev = subprocess.run(["git", "-C", str(ROOT), "rev-parse", "--short", "HEAD"], capture_output=True, text=True).stdout.strip()
    return {
        "cpu": cpu, "threads": os.cpu_count(), "mem_gib": round(mem / 1048576, 1),
        "kernel": platform.release(), "os": ver(["sh", "-c", ". /etc/os-release; echo $PRETTY_NAME"]),
        "pinning": f"nice -n {NICE} taskset -c {CPUS}", "runs": RUNS,
        "versions": {
            "gcc": ver(["gcc", "--version"]), "clang": ver(["clang", "--version"]),
            "helium": f"hcn built from this repository at {hc_rev}",
            "rustc": ver(["rustc", "--version"]), "zig": ver([TOOLS["zig"], "version"]),
            "go": ver([TOOLS["go"], "version"]), "java": ver(["java", "-version"]),
            "node": ver(["node", "--version"]), "python": ver(["python3", "--version"]),
            "hyperfine": ver([TOOLS["hyperfine"], "--version"]),
        },
        "date": time.strftime("%Y-%m-%d %H:%M %z"),
    }


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--quick", action="store_true")
    ap.add_argument("--lang", action="append")
    ap.add_argument("--bench", action="append")
    a = ap.parse_args()
    sizes = QUICK if a.quick else FULL
    benches = a.bench or BENCHES
    jobs = [(l, lab, b, b) for l, lab, _, _ in LANGS for b in benches]
    jobs += [(v, lab, stem, b) for v, lab, base, stem, b in VARIANTS if b in benches]
    if a.lang:
        jobs = [j for j in jobs if j[0] in a.lang]
    warm_caches()
    RESULTS.mkdir(exist_ok=True)
    if not a.quick:
        (RESULTS / "machine.json").write_text(json.dumps(machine(), indent=2))
    ref = {}
    for b in benches:  # reference output: C (gcc)
        ref[b] = run_one("c-gcc", "C (gcc -O2)", b, b, sizes, True)["stdout"]
    failed = 0
    for lang, label, stem, bench in jobs:
        base = next((v[2] for v in VARIANTS if v[0] == lang), lang)
        try:
            r = run_one(base, label, stem, bench, sizes, a.quick)
            r["lang"] = lang
        except subprocess.CalledProcessError as e:
            print(f"FAIL {lang:12} {bench:10} {e.cmd}\n{e.stderr[-2000:]}", flush=True)
            failed += 1
            continue
        r["correct"] = r["stdout"] == ref[bench]
        failed += not r["correct"]
        w = r.get("wall", {}).get("median", r["single_run_s"])
        print(f"{'ok  ' if r['correct'] else 'BAD '} {lang:12} {bench:10} {w:8.3f}s  rss={r.get('peak_rss_kb', '-')}KB", flush=True)
        if not a.quick:
            (RESULTS / f"{lang}__{bench}.json").write_text(json.dumps(r, indent=2))
    sys.exit(1 if failed else 0)


if __name__ == "__main__":
    main()
