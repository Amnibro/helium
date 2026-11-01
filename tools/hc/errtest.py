import sys, os, subprocess, concurrent.futures as cf, pathlib, tempfile
R = pathlib.Path(__file__).resolve().parents[2]
HC = str(pathlib.Path(sys.argv[1]).resolve()); B = R / "tools" / "hc" / "baseline" / "err.txt"; upd = "--update" in sys.argv
def run(f):
    exp = next((l.split("// error:", 1)[1].strip() for l in f.read_text(errors="replace").split("\n")[:5] if l.startswith("// error:")), "")
    with tempfile.TemporaryDirectory() as d:
        try: p = subprocess.run([HC, str(f), d + "/x.c"], capture_output=True, timeout=30, cwd=f.parent, env=dict(os.environ, HC_LIB=str(R / "hc" / "lib")))
        except subprocess.TimeoutExpired: return f.name, "crash"
    o = (p.stdout + p.stderr).decode(errors="replace")
    return f.name, ("accept" if p.returncode == 0 else "crash" if p.returncode < 0 or "runtime error" in o else "match" if exp and exp in o else "other")
with cf.ThreadPoolExecutor(7) as ex: res = dict(ex.map(run, sorted((R / "test" / "errors_tc").glob("*.amni"))))
n = {k: sum(1 for v in res.values() if v == k) for k in ("match", "other", "accept", "crash")}
print(" ".join(f"{k}={v}" for k, v in n.items()), f"total={len(res)}")
m = sorted(k for k, v in res.items() if v == "match"); base = set(B.read_text().split()) if B.exists() else set()
lost = sorted(base - set(m)); print("err lost:", " ".join(lost)); print("err crash:", " ".join(sorted(k for k, v in res.items() if v == "crash")))
if upd: B.write_text("\n".join(m) + "\n")
sys.exit(1 if lost else 0)
