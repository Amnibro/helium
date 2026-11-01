import json, os, subprocess, sys, tempfile, time, statistics as st, shutil
from pathlib import Path
E = Path(__file__).parent; ROOT = E.parents[1]; HCN = os.environ.get("HC", str(ROOT/"build/hcn")); LIB = os.environ.get("HC_LIB", str(ROOT/"hc/lib"))
R = [json.loads(l) for l in open(E/"results.jsonl")]; T = {t["id"]: t for t in json.load(open(E/"tasks.json"))}
ext = {"helium": "amni", "python": "python", "rust": "rust"}
def build(lang, src, wd):
    if lang == "helium": shutil.copy(src, wd/"main.amni"); b = subprocess.run([HCN, "build", "main.amni", "-o", "prog"], cwd=wd, capture_output=True, env={**os.environ, "HC_LIB": LIB}); return ["./prog"] if b.returncode == 0 else None
    if lang == "rust": shutil.copy(src, wd/"main.rs"); b = subprocess.run(["rustc", "-O", "--edition", "2021", "main.rs", "-o", "prog"], cwd=wd, capture_output=True); return ["./prog"] if b.returncode == 0 else None
    shutil.copy(src, wd/"main.py"); return [sys.executable, "main.py"]
out = {}
for r in R:
    i = next((k for k, a in enumerate(r["attempts"]) if a.get("status") == "pass"), None)
    if i is None: continue
    src = E/"code"/f"{r['model'].replace(':', '_')}-{r['lang']}-{r['task']}-{i}.{ext[r['lang']]}"
    with tempfile.TemporaryDirectory(dir=E/"work") as wd:
        wd = Path(wd); exe = build(r["lang"], src, wd)
        if not exe: print("build fail", src.name); continue
        ts = []
        for _ in range(3):
            t0 = time.perf_counter(); p = subprocess.run(["nice", "-n", "10"] + exe, cwd=wd, capture_output=True, text=True, timeout=120); ts.append((time.perf_counter() - t0) * 1000)
            ok = "\n".join(l.rstrip() for l in p.stdout.strip("\n").splitlines()) == "\n".join(l.rstrip() for l in T[r["task"]]["expected"].strip("\n").splitlines())
        out.setdefault(r["task"], {}).setdefault(r["lang"], []).append(min(ts) if ok else None)
json.dump(out, open(E/"retime.json", "w"), indent=1)
