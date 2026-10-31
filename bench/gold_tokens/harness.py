#!/usr/bin/env python3
"""Gold token benchmark harness.

Verifies every task (Gold via goldc + hc, hand-written Helium/Rust/Go/Python
refs), re-checks all five implementations on a second input, counts tokens with
three tokenizers and writes results.json. Python here only drives builds,
compares outputs and counts tokens; it never produces a program's answer.

usage: harness.py --gold-root DIR --goldc BIN --hc BIN [--jobs N]
       (HC_LIB must point at helium/hc/lib)
"""
import argparse, concurrent.futures as cf, difflib, json, math, os, re, shutil
import subprocess, sys, tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
LANGS = ["amni", "rs", "go", "py"]
NAMES = {"gold": "Gold", "exp": "Expanded Helium (full)", "exp_prog": "Expanded Helium (program only)",
         "amni": "Helium (hand-written)", "rs": "Rust", "go": "Go", "py": "Python"}
PROG_MARK = "// ===== Gold bindings"


def run(cmd, cwd=None, timeout=300):
    p = subprocess.run(cmd, cwd=cwd, capture_output=True, timeout=timeout)
    return p.returncode, p.stdout.decode(errors="replace"), p.stderr.decode(errors="replace")


def visible(out):
    return "".join(l for l in out.splitlines(True) if not l.startswith("=> "))


class Tools:
    def __init__(self, a):
        self.gold_root, self.goldc, self.hc = a.gold_root, a.goldc, a.hc

    def gold(self, src, wd):
        g, am, b = (os.path.join(wd, x) for x in ("t.gold", "t.amni", "t.bin"))
        open(g, "w").write(src)
        rc, o, e = run([self.goldc, "compose", g, self.gold_root, am])
        if rc or not o.startswith("ok"):
            return None, None, "compose: " + o + e
        rc, o, e = run([self.hc, "build", am, "-o", b])
        if rc:
            return None, None, "hc build: " + o + e
        rc, o, e = run([b], cwd=wd, timeout=60)
        return open(am).read(), o, (None if rc == 0 else f"exit {rc}: {e}")

    def ref(self, lang, src, wd):
        f = os.path.join(wd, "ref." + lang)
        b = os.path.join(wd, "ref_" + lang + ".bin")
        open(f, "w").write(src)
        if lang == "py":
            rc, o, e = run([sys.executable, f], cwd=wd, timeout=60)
            return o, (None if rc == 0 else e)
        if lang == "amni":
            bc = [self.hc, "build", f, "-o", b]
        elif lang == "rs":
            bc = ["rustc", "--edition", "2021", "-O", "-o", b, f]
        else:
            bc = ["go", "build", "-o", b, f]
        rc, o, e = run(bc, cwd=wd)
        if rc:
            return None, f"build: {o}{e}"
        if lang == "rs" and e.strip():
            return None, f"rustc warnings: {e}"
        rc, o, e = run([b], cwd=wd, timeout=60)
        return o, (None if rc == 0 else e)


# ---- second-input substitution -------------------------------------------
BIND = re.compile(r"^(list|input|text) *= *(.*)$", re.M)


def alt_sources(gold, refs, alt):
    m = BIND.search(gold)
    orig = m.group(2).strip()
    new_gold = gold[:m.start(2)] + alt["value"] if alt["kind"] != "text" else None
    if alt["kind"] == "text":
        new_gold = gold[:m.start(2)] + '"' + alt["value"] + '"'
    new_gold += gold[m.end(2):]
    out = {}
    for lang, src in refs.items():
        if alt["kind"] == "text":
            pats = ['"' + orig.strip('"') + '"']
            rep = '"' + alt["value"] + '"'
        elif alt["kind"] == "list":
            pats = [", ".join(x.strip() for x in orig.split(","))]
            rep = alt["value"]
        else:  # single input value written as [N], {N} or vec![N]
            pats = ["[" + orig + "]", "{" + orig + "}"]
            rep = None
        hits = [(p, src.count(p)) for p in pats]
        total = sum(c for _, c in hits)
        if total != 1:
            raise ValueError(f"{lang}: input literal {pats} found {total} times")
        p = next(p for p, c in hits if c)
        r = rep if rep is not None else p[0] + alt["value"] + p[-1]
        out[lang] = src.replace(p, r)
    return new_gold, out


# ---- tokenizers ------------------------------------------------------------
def load_tokenizers(qwen_path):
    import tiktoken
    from tokenizers import Tokenizer
    o2, cl = tiktoken.get_encoding("o200k_base"), tiktoken.get_encoding("cl100k_base")
    qw = Tokenizer.from_file(qwen_path)
    return {"o200k_base": lambda s: len(o2.encode(s, disallowed_special=())),
            "cl100k_base": lambda s: len(cl.encode(s, disallowed_special=())),
            "qwen2.5-coder": lambda s: len(qw.encode(s, add_special_tokens=False).ids)}


def program_part(amni):
    i = amni.find(PROG_MARK)
    if i < 0:
        raise ValueError("expanded Helium has no program marker")
    return amni[i:]


def diff_text(a, b):
    """Lines added or removed by a unified line diff, as one string."""
    lines = [l[1:] for l in difflib.unified_diff(a.splitlines(True), b.splitlines(True), n=0)
             if l[:1] in "+-" and not l.startswith(("+++", "---"))]
    return "".join(l if l.endswith("\n") else l + "\n" for l in lines)


# ---- per-task work --------------------------------------------------------
def task_dir_files(d):
    rd = lambda n: open(os.path.join(d, n)).read()
    return rd("task.gold"), rd("expanded.amni"), rd("expected.txt"), {l: rd("ref." + l) for l in LANGS}


def verify_set(tools, gold, refs, wd, expected=None, expanded=None):
    """Build and run Gold and the four refs. Returns (gold_amni, gold_out, check dict)."""
    chk = {}
    amni, out, err = tools.gold(gold, wd)
    if err:
        chk["gold"] = {"ok": False, "error": err[:2000]}
        return amni, out, chk
    g_ok = True
    if expected is not None:
        g_ok = out == expected
    if expanded is not None and amni != expanded:
        chk["gold_expansion_matches_committed"] = False
        g_ok = False
    chk["gold"] = {"ok": g_ok} if g_ok else {"ok": False, "got": out, "want": expected}
    want = visible(out)
    for l, src in refs.items():
        o, e = tools.ref(l, src, wd)
        if e:
            chk[l] = {"ok": False, "error": e[:2000]}
        else:
            chk[l] = {"ok": o == want} if o == want else {"ok": False, "got": o, "want": want}
    return amni, out, chk


def do_task(tools, meta):
    tid = meta["id"]
    d = os.path.join(HERE, "tasks", tid)
    gold, expanded, expected, refs = task_dir_files(d)
    res = {"id": tid}
    with tempfile.TemporaryDirectory() as wd:
        _, out, res["base"] = verify_set(tools, gold, refs, wd, expected, expanded)
    try:
        ag, ar = alt_sources(gold, refs, meta["alt"])
        with tempfile.TemporaryDirectory() as wd:
            _, aout, res["alt"] = verify_set(tools, ag, ar, wd)
        res["alt_output"] = aout
        res["alt_differs"] = aout is not None and visible(aout) != visible(expected)
    except ValueError as e:
        res["alt"] = {"setup": {"ok": False, "error": str(e)}}
    up = os.path.join(d, "upkeep")
    if os.path.isdir(up):
        ug, uexp, uexpect, urefs = task_dir_files(up)
        with tempfile.TemporaryDirectory() as wd:
            _, _, res["upkeep"] = verify_set(tools, ug, urefs, wd, uexpect, uexp)
        res["upkeep_change"] = open(os.path.join(up, "change.txt")).read().strip()
    res["ok"] = all(all(v["ok"] if isinstance(v, dict) else v for v in res[k].values())
                    for k in ("base", "alt", "upkeep") if k in res) and res.get("alt_differs", False)
    return res


def texts(d):
    gold, expanded, _, refs = task_dir_files(d)
    t = {"gold": gold, "exp": expanded, "exp_prog": program_part(expanded)}
    t.update(refs)
    return t


def stats(xs):
    xs = sorted(xs)
    n = len(xs)
    med = xs[n // 2] if n % 2 else (xs[n // 2 - 1] + xs[n // 2]) / 2
    return {"n": n, "median": med, "geomean": math.exp(sum(math.log(x) for x in xs) / n),
            "min": xs[0], "max": xs[-1]}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--gold-root", required=True)
    ap.add_argument("--goldc", required=True)
    ap.add_argument("--hc", required=True)
    ap.add_argument("--qwen-tokenizer", required=True, help="path to Qwen2.5-Coder tokenizer.json")
    ap.add_argument("--jobs", type=int, default=os.cpu_count())
    a = ap.parse_args()
    if not os.environ.get("HC_LIB"):
        sys.exit("HC_LIB must be set to helium/hc/lib")
    for t in ("rustc", "go"):
        if not shutil.which(t):
            sys.exit(f"{t} not found")
    tools = Tools(a)
    spec = json.load(open(os.path.join(HERE, "tasks.json")))
    metas = spec["tasks"]
    with cf.ThreadPoolExecutor(a.jobs) as ex:
        checks = list(ex.map(lambda m: do_task(tools, m), metas))
    tok = load_tokenizers(a.qwen_tokenizer)
    per = []
    for m, c in zip(metas, checks):
        d = os.path.join(HERE, "tasks", m["id"])
        t = texts(d)
        row = {**m, "verified": c["ok"], "checks": c,
               "lines": {k: len(v.splitlines()) for k, v in t.items()},
               "tokens": {tn: {k: f(v) for k, v in t.items()} for tn, f in tok.items()}}
        up = os.path.join(d, "upkeep")
        if os.path.isdir(up):
            u = texts(up)
            row["upkeep"] = {"change": c.get("upkeep_change"),
                             "diff_lines": {k: len(diff_text(t[k], u[k]).splitlines()) for k in t},
                             "diff_tokens": {tn: {k: f(diff_text(t[k], u[k])) for k in t}
                                             for tn, f in tok.items()}}
        per.append(row)
    ok = [r for r in per if r["verified"]]
    summary = {}
    for tn in tok:
        s = {}
        for k in NAMES:
            if k == "gold":
                continue
            s[k] = stats([r["tokens"][tn][k] / r["tokens"][tn]["gold"] for r in ok])
        s["totals"] = {k: sum(r["tokens"][tn][k] for r in ok) for k in NAMES}
        ups = [r for r in ok if "upkeep" in r]
        s["upkeep"] = {k: stats([r["upkeep"]["diff_tokens"][tn][k] / r["upkeep"]["diff_tokens"][tn]["gold"]
                                 for r in ups]) for k in NAMES if k not in ("gold", "exp_prog")}
        s["upkeep_totals"] = {k: sum(r["upkeep"]["diff_tokens"][tn][k] for r in ups) for k in NAMES}
        summary[tn] = s
    # The phrase book a writer (or model) has to know to write Gold at all:
    # every phrasing in the library index, one per line.
    idx = [l.split("\t")[0] for l in open(os.path.join(a.gold_root, "lib", "index.tsv")) if l.strip()]
    book = "\n".join(idx) + "\n"
    vocab = {"phrasings": len(idx), "tokens": {tn: f(book) for tn, f in tok.items()}}
    ver = lambda c: run(c)[1].strip().splitlines()[0]
    toolv = {"rustc": ver(["rustc", "--version"]), "go": ver(["go", "version"]), "python": sys.version.split()[0]}
    out = {"tool_versions": toolv, "gold_commit": spec["gold_commit"], "excluded": spec["excluded"], "names": NAMES,
           "tasks_total": len(per), "tasks_verified": len(ok),
           "upkeep_total": sum("upkeep" in r for r in per),
           "upkeep_verified": sum("upkeep" in r for r in ok),
           "summary": summary, "vocabulary": vocab, "tasks": per}
    json.dump(out, open(os.path.join(HERE, "results.json"), "w"), indent=1)
    bad = [r["id"] for r in per if not r["verified"]]
    print(f"verified {len(ok)}/{len(per)} tasks; failing: {bad or 'none'}")
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
