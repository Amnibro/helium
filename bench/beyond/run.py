#!/usr/bin/env python3
"""Helium vs C, Rust, Go, Java, Node and Python on twelve compute programs.

  python3 run.py                       build, verify and time everything at full size
  python3 run.py --quick               small sizes, one run: smoke test
  python3 run.py --only he,gcc-O2      restrict to some variants (comma separated)
  python3 run.py --bench nbody,sort    restrict to some programs
  python3 run.py --hc path/to/hcn      Helium compiler to use (default build/hcn)

Every program implements the same algorithm in every language and takes its size as
argv[1]. Before timing, each variant's stdout must equal the gcc -O2 build's stdout
byte for byte; a mismatch is reported and the variant is not timed. Timing is
hyperfine (1 warmup, RUNS runs) under `taskset -c CPUS`; we report median, min and
max wall time (and, with hyperfine 2, peak RSS and instruction counts). Python gets a single run and a time limit.
"""
import argparse, json, os, shutil, subprocess, sys, time
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent.parent
HOME = Path.home()
HYPERFINE = os.environ.get("HYPERFINE", shutil.which("hyperfine") or str(HOME / ".local/opt/hyperfine-v2.0.0-x86_64-unknown-linux-musl/hyperfine"))
GO = os.environ.get("GO", shutil.which("go") or str(HOME / ".local/opt/go1.27.3/bin/go"))
BENCHES = ["fib", "nbody", "spectral", "fannkuch", "mandelbrot", "bintrees", "hashmap", "strbuild", "json", "regex", "matmul", "sort"]
FULL = {"fib": 45, "nbody": 30_000_000, "spectral": 5500, "fannkuch": 11, "mandelbrot": 6000, "bintrees": 21,
        "hashmap": 20_000_000, "strbuild": 30_000_000, "json": 3_000_000, "regex": 1_000_000, "matmul": 2000, "sort": 20_000_000}
QUICK = {"fib": 30, "nbody": 1000, "spectral": 100, "fannkuch": 7, "mandelbrot": 200, "bintrees": 10,
         "hashmap": 1000, "strbuild": 1000, "json": 1000, "regex": 1000, "matmul": 100, "sort": 1000}
CC = {"gcc-O2": ["gcc", "-O2"], "gcc-O3n": ["gcc", "-O3", "-march=native"], "clang-O2": ["clang", "-O2"], "clang-O3n": ["clang", "-O3", "-march=native"]}
VARIANTS = ["gcc-O2", "gcc-O3n", "clang-O2", "clang-O3n", "he", "he-v3", "he-v4", "rust", "rust-native", "go", "java", "node", "python"]

def sh(cmd, **kw):
    p = subprocess.run(cmd, capture_output=True, text=True, **kw)
    if p.returncode != 0: raise RuntimeError(f"{' '.join(map(str, cmd))}\n{p.stdout}{p.stderr}")
    return p.stdout

def build(v, b, out, hc):
    """Returns the command (list) that runs variant v of program b."""
    exe = out / v / b; exe.parent.mkdir(parents=True, exist_ok=True)
    if v in CC: sh(CC[v] + [str(HERE / "c" / f"{b}.c"), "-o", str(exe), "-lm"])
    elif v.startswith("he"): sh([hc, "build", str(HERE / "he" / f"{b}.amni"), "-o", str(exe)] + ({"he-v3": ["--v3"], "he-v4": ["--v4"]}.get(v, [])), env=dict(os.environ, HC_LIB=str(ROOT / "hc" / "lib")))
    elif v.startswith("rust"): sh(["rustc", "-C", "opt-level=3", "-C", "codegen-units=1", "--edition", "2021"] + (["-C", "target-cpu=native"] if v == "rust-native" else []) + [str(HERE / "rs" / f"{b}.rs"), "-o", str(exe)])
    elif v == "go": sh([GO, "build", "-o", str(exe), str(HERE / "go" / f"{b}.go")], env=dict(os.environ, GO111MODULE="off", CGO_ENABLED="0", GOPATH=str(out / "gopath"), GOCACHE=str(out / "gocache")))
    elif v == "java":
        sh(["javac", "-d", str(exe.parent), str(HERE / "java" / f"{b}.java")]); return ["java", "-cp", str(exe.parent), b]
    elif v == "node": return ["node", str(HERE / "js" / f"{b}.js")]
    elif v == "python": return ["python3", str(HERE / "py" / f"{b}.py")]
    return [str(exe)]

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--quick", action="store_true"); ap.add_argument("--only", default=""); ap.add_argument("--bench", default="")
    ap.add_argument("--hc", default=str(ROOT / "build" / "hcn")); ap.add_argument("--cpus", default=os.environ.get("BEYOND_CPUS", "3,19"))
    ap.add_argument("--runs", type=int, default=int(os.environ.get("BEYOND_RUNS", "7"))); ap.add_argument("--py-limit", type=float, default=150)
    ap.add_argument("--out", default=str(ROOT / "build" / "beyond")); ap.add_argument("--json", default="")
    a = ap.parse_args()
    sizes = QUICK if a.quick else FULL
    vs = [v for v in VARIANTS if not a.only or v in a.only.split(",")]
    if "gcc-O2" not in vs: vs.insert(0, "gcc-O2")
    bs = [b for b in BENCHES if not a.bench or b in a.bench.split(",")]
    out = Path(a.out); out.mkdir(parents=True, exist_ok=True)
    res = {"cpus": a.cpus, "runs": a.runs, "sizes": {b: sizes[b] for b in bs}, "hc": a.hc, "results": {}}
    pin = ["taskset", "-c", a.cpus]
    for b in bs:
        n = str(sizes[b]); ref = None; res["results"][b] = {}
        for v in vs:
            r = res["results"][b][v] = {}
            try: cmd = build(v, b, out, a.hc)
            except RuntimeError as e: r["error"] = "build: " + str(e)[:400]; print(f"{b:10} {v:12} BUILD FAILED"); continue
            t0 = time.time()
            try: got = subprocess.run(pin + cmd + [n], capture_output=True, text=True, timeout=a.py_limit if v == "python" else 600).stdout
            except subprocess.TimeoutExpired: r["timeout"] = a.py_limit; print(f"{b:10} {v:12} > {a.py_limit:.0f} s"); continue
            first = time.time() - t0
            if ref is None: ref = got; res["results"][b]["_ref"] = got
            if got != ref: r["error"] = "output differs: " + got[:200]; print(f"{b:10} {v:12} OUTPUT DIFFERS: {got.strip()[:80]!r}"); continue
            if v == "python" or a.quick: r.update(median=first, min=first, max=first, runs=1)
            else:
                jf = out / f"{b}-{v}.json"
                sh([HYPERFINE, "-N", "--warmup", "1", "--runs", str(a.runs), "--export-json", str(jf), " ".join(pin + cmd + [n])])
                hr = json.loads(jf.read_text())["results"][0]
                if "times" in hr: t = sorted(hr["times"]); r.update(median=t[len(t) // 2], min=t[0], max=t[-1], runs=len(t))
                else:
                    sm = hr["summary"]; w = sm["time_wall_clock"]; r.update(median=w["median"], min=w["min"], max=w["max"], runs=w["count"])
                    for k in ("memory_peak_resident", "instructions", "cpu_cycles"):
                        if k in sm: r[k] = sm[k]["median"]
            print(f"{b:10} {v:12} {r['median']:8.3f} s  [{r['min']:.3f} .. {r['max']:.3f}]", flush=True)
    jp = Path(a.json) if a.json else out / ("quick.json" if a.quick else "full.json")
    jp.write_text(json.dumps(res, indent=1)); print("wrote", jp)

if __name__ == "__main__": main()
