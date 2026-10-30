import json, os, re, subprocess, sys, tempfile, threading, time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
import tiktoken
EV = Path(__file__).parent; ROOT = EV.parents[1]; HC = Path(os.environ.get("HC", ROOT/"build/hcn")); LIB = os.environ.get("HC_LIB", str(ROOT/"hc/lib")); PRIMER = (ROOT/"HELIUM.md").read_text()
ENC = tiktoken.get_encoding("o200k_base"); TASKS = {t["id"]: t for t in json.load(open(EV/"tasks.json"))}
OUT = EV/"results.jsonl"; LOCK = threading.Lock(); SEM = {"claude": threading.Semaphore(4), "gemini": threading.Semaphore(3), "codex": threading.Semaphore(3), "grok": threading.Semaphore(3)}
SYS = "You are an expert programmer. Reply with only the requested code."
LANG = {"helium": ("amni", "Helium program (a single .amni file)", PRIMER + "\n\n---\n\n"), "python": ("python", "Python 3 program (standard library only)", ""), "rust": ("rust", "Rust program (a single main.rs, standard library only, built with rustc -O)", "")}
def ask(model, prompt, wd):
    prov = model.split(":")[0]; name = model.split(":", 1)[1] if ":" in model else ""
    with SEM[prov]:
        t0 = time.time()
        if prov == "claude":
            r = subprocess.run(["claude", "-p", "--setting-sources", "", "--strict-mcp-config", "--system-prompt", SYS, "--tools", "", "--model", name, "--output-format", "json"], input=prompt, capture_output=True, text=True, timeout=900, cwd=wd)
            d = json.loads(r.stdout); u = d.get("usage", {})
            return d.get("result", ""), {"in": u.get("input_tokens", 0) + u.get("cache_creation_input_tokens", 0) + u.get("cache_read_input_tokens", 0), "out": u.get("output_tokens", 0), "model": ",".join(d.get("modelUsage", {})), "s": time.time() - t0}
        if prov == "gemini":
            r = subprocess.run(["gemini", "-p", "Follow the instructions above exactly. Do not use any tools.", "-o", "json"] + (["-m", name] if name else []), input=prompt, capture_output=True, text=True, timeout=900, cwd=wd)
            d = json.loads(r.stdout[r.stdout.index("{"):]) if "{" in r.stdout else {}
            st = d.get("stats", {}).get("models", {}); toks = [v.get("tokens", {}) for v in st.values()]
            return d.get("response", r.stdout + r.stderr), {"in": sum(t.get("prompt", 0) for t in toks), "out": sum(t.get("candidates", 0) for t in toks), "model": ",".join(st), "s": time.time() - t0}
        if prov == "codex":
            lm = Path(wd)/"last.txt"
            r = subprocess.run(["codex", "exec", "--skip-git-repo-check", "--ephemeral", "-s", "read-only", "--json", "-o", str(lm)] + (["-m", name] if name else []) + ["-"], input=prompt, capture_output=True, text=True, timeout=900, cwd=wd)
            u = {}
            for line in r.stdout.splitlines():
                try: e = json.loads(line)
                except Exception: continue
                if e.get("type") == "turn.completed": u = e.get("usage", {})
            return (lm.read_text() if lm.exists() else r.stdout + r.stderr), {"in": u.get("input_tokens", 0), "out": u.get("output_tokens", 0), "model": name or "default", "s": time.time() - t0}
        if prov == "grok":
            pf = Path(wd)/"prompt.txt"; pf.write_text(prompt)
            r = subprocess.run(["grok", "--prompt-file", str(pf), "--output-format", "json", "--tools", "", "--max-turns", "1"] + (["-m", name] if name else []), capture_output=True, text=True, timeout=900, cwd=wd)
            try:
                d = json.loads(r.stdout); u = d.get("usage", {}) or {}
                return d.get("result", d.get("response", d.get("text", r.stdout))), {"in": u.get("input_tokens", 0), "out": u.get("output_tokens", 0), "model": d.get("model", name or "default"), "s": time.time() - t0}
            except Exception: return r.stdout + r.stderr, {"in": 0, "out": 0, "model": name or "default", "s": time.time() - t0}
def code_of(text, fence):
    m = re.findall(r"```[a-zA-Z0-9_+-]*\n(.*?)```", text, re.S)
    return max(m, key=len) if m else text.strip()
def norm(s): return "\n".join(l.rstrip() for l in s.strip("\n").splitlines())
def execute(lang, code, wd):
    wd = Path(wd)
    try:
        if lang == "helium":
            (wd/"main.amni").write_text(code); b = subprocess.run([str(HC), "build", "main.amni", "-o", "prog"], cwd=wd, capture_output=True, text=True, timeout=300, env={**os.environ, "HC_LIB": LIB}); exe = ["./prog"]
        elif lang == "rust":
            (wd/"main.rs").write_text(code); b = subprocess.run(["rustc", "-O", "--edition", "2021", "main.rs", "-o", "prog"], cwd=wd, capture_output=True, text=True, timeout=300); exe = ["./prog"]
        else:
            (wd/"main.py").write_text(code); b = subprocess.run([sys.executable, "-m", "py_compile", "main.py"], cwd=wd, capture_output=True, text=True, timeout=60); exe = [sys.executable, "main.py"]
        if b.returncode != 0: return "compile", (b.stderr + b.stdout)[-2500:], None, ""
        t0 = time.time(); r = subprocess.run(["nice", "-n", "10"] + exe, cwd=wd, capture_output=True, text=True, timeout=120); ms = (time.time() - t0) * 1000
        if r.returncode != 0: return "runtime", (r.stderr + r.stdout)[-2500:], ms, r.stdout
        return "ok", "", ms, r.stdout
    except subprocess.TimeoutExpired: return "timeout", "the program did not finish within the time limit", None, ""
def one(model, lang, tid):
    t = TASKS[tid]; fence, what, pre = LANG[lang]
    base = f"{pre}Write a complete {what} for this task.\n\nTask: {t['prompt']}\n\nThe program takes no input and prints exactly the requested output, nothing else. Reply with only the code in one ```{fence} fenced block."
    rec = {"model": model, "lang": lang, "task": tid, "cat": t["cat"], "attempts": []}
    with tempfile.TemporaryDirectory(dir=EV/"work") as wd:
        prompt = base
        for att in range(2):
            try: text, u = ask(model, prompt, wd)
            except Exception as e: rec["attempts"].append({"error": f"ask: {e!r}"[:300]}); break
            code = code_of(text, fence); st, err, ms, out = execute(lang, code, wd)
            passed = st == "ok" and norm(out) == norm(t["expected"])
            rec["attempts"].append({"status": st if st != "ok" else ("pass" if passed else "wrong"), "code_tokens": len(ENC.encode(code)), "usage": u, "ms": ms, "err": err[:400], "out": out[:300] if not passed else ""})
            (EV/"code"/f"{model.replace(':', '_')}-{lang}-{tid}-{att}.{fence}").write_text(code)
            if passed: break
            why = err if st != "ok" else f"It printed:\n{out[:1500]}\nbut the expected output is:\n{t['expected']}"
            prompt = f"{base}\n\nYour previous program:\n```{fence}\n{code}\n```\nIt failed ({st if st != 'ok' else 'wrong output'}):\n{why}\n\nReply with the corrected complete program only, in one ```{fence} fenced block."
    rec["pass1"] = bool(rec["attempts"]) and rec["attempts"][0].get("status") == "pass"; rec["pass2"] = any(a.get("status") == "pass" for a in rec["attempts"])
    with LOCK:
        with open(OUT, "a") as f: f.write(json.dumps(rec) + "\n")
    print(f"{model:24} {lang:7} {tid:20} {'PASS' if rec['pass1'] else 'pass2' if rec['pass2'] else 'FAIL'} {[a.get('status') for a in rec['attempts']]}", flush=True)
if __name__ == "__main__":
    (EV/"work").mkdir(exist_ok=True); (EV/"code").mkdir(exist_ok=True)
    models = sys.argv[1].split(","); langs = sys.argv[2].split(","); ids = sys.argv[3].split(",") if len(sys.argv) > 3 and sys.argv[3] != "all" else list(TASKS)
    done = set()
    if OUT.exists():
        for l in open(OUT): r = json.loads(l); done.add((r["model"], r["lang"], r["task"]))
    jobs = [(m, l, i) for i in ids for m in models for l in langs if (m, l, i) not in done]
    with ThreadPoolExecutor(12) as ex: list(ex.map(lambda j: one(*j), jobs))
