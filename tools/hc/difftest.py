import sys, os, subprocess, concurrent.futures as cf, pathlib, collections, re, json
R = pathlib.Path(__file__).resolve().parents[2]
S = pathlib.Path(sys.argv[1]); HC = sys.argv[2]; W = pathlib.Path(sys.argv[3]); W.mkdir(parents=True, exist_ok=True)
flt = sys.argv[4] if len(sys.argv) > 4 else ""
def exp_for(f):
    if f.parent.name == "samples": d = R / "samples" / "expected"; i = R / "samples" / "data" / (f.stem + ".stdin")
    else: d = R / "test" / "expected"; i = None
    o = d / (f.stem + ".out")
    return (o if o.exists() else None), (i if i and i.exists() else None), (d / (f.stem + ".aborts")).exists()
def norm(b): return b.replace(b"\r\n", b"\n")
def run(f):
    exp, sin, ab = exp_for(f)
    if not exp: return None
    c = W / (f.stem + ".c"); x = W / f.stem
    env = dict(os.environ, HC_LIB=str(R / "hc" / "lib"))
    try: p = subprocess.run([HC, str(f), str(c)], capture_output=True, timeout=30, env=env)
    except subprocess.TimeoutExpired: return f, "check", "timeout"
    if p.returncode != 0: return f, "check", (p.stdout + p.stderr).decode(errors="replace").strip().split("\n")[0][:220]
    p = subprocess.run(["nice", "-n", "10", "clang", "-O1", "-fwrapv", "-w", "-ferror-limit=1", "-I", str(R / "hc"), str(c), "-o", str(x), "-lm", "-lpthread"], capture_output=True)
    if p.returncode != 0:
        m = [l for l in p.stderr.decode(errors="replace").split("\n") if "error" in l]
        return f, "cc", (m[0] if m else p.stderr.decode()[:200])[:220]
    try: p = subprocess.run([str(x)], capture_output=True, timeout=20, stdin=open(sin, "rb") if sin else subprocess.DEVNULL, cwd=str(R / ("samples" if f.parent.name == "samples" else "test")))
    except subprocess.TimeoutExpired: return f, "run", "timeout"
    want = norm(exp.read_bytes()); got = norm(p.stdout)
    if got != want:
        gl = got.split(b"\n"); wl = want.split(b"\n")
        i = next((k for k in range(min(len(gl), len(wl))) if gl[k] != wl[k]), min(len(gl), len(wl)))
        return f, "out", f"line {i+1}: got {gl[i][:80] if i < len(gl) else b'<eof>'} want {wl[i][:80] if i < len(wl) else b'<eof>'} {p.stderr.decode(errors='replace').strip()[:100]}"
    if ab != (p.returncode != 0): return f, "exit", f"exit {p.returncode} {p.stderr.decode(errors='replace')[:120]}"
    x.unlink(); c.unlink()
    return f, "pass", ""
files = sorted(f for f in S.rglob("*.amni") if flt in str(f))
res = collections.defaultdict(list)
with cf.ThreadPoolExecutor(16) as ex:
    for r in ex.map(run, files):
        if r: res[r[1]].append((r[0], r[2]))
tot = sum(len(v) for v in res.values())
print(" ".join(f"{k}={len(v)}" for k, v in sorted(res.items())), f"total={tot}")
with open(W / "report.txt", "w") as o:
    for k in ("check", "cc", "out", "exit", "run"):
        for f, m in res.get(k, []): o.write(f"{k}\t{f.relative_to(S)}\t{m}\n")
msgs = collections.Counter(re.sub(r"^\S+:\d+: ", "", m)[:70] for k in ("check",) for f, m in res.get(k, []))
for m, c in msgs.most_common(25): print(c, m)
