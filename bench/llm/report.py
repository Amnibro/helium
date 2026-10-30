import csv, json, statistics as st
from pathlib import Path
EV = Path(__file__).parent; R = [json.loads(l) for l in open(EV/"results.jsonl")]; RT = json.load(open(EV/"retime.json")); T = {t["id"]: t for t in json.load(open(EV/"tasks.json"))}
M = {"claude:haiku": ("Haiku 5.5", 0.10, 0.50, 0.01), "claude:sonnet": ("Sonnet 5.5", 2.0, 10.0, 0.20), "claude:opus": ("Opus 5.5", 4.0, 20.0, 0.20)}; L = ["helium", "python", "rust"]; PRIMER = 7000
rows = lambda m, l: [r for r in R if r["model"] == m and r["lang"] == l]
cost = lambda r, i, o, cr, cached: sum(((a["usage"]["in"] - (PRIMER if cached else 0)) * i + (PRIMER * cr if cached else 0) + a["usage"]["out"] * o) / 1e6 for a in r["attempts"])
def table(head, body): return "\n".join(["| " + " | ".join(head) + " |", "|" + "---|" * len(head)] + ["| " + " | ".join(map(str, b)) + " |" for b in body])
print("Correct programs, first try / after one repair\n")
print(table(["model"] + L, [[n] + [f"{sum(r['pass1'] for r in rows(m, l))}/{len(rows(m, l))} · {sum(r['pass2'] for r in rows(m, l))}/{len(rows(m, l))}" for l in L] for m, (n, *_) in M.items()]))
print("\nMedian tokens per program, first attempt: output (with thinking) · code (o200k)\n")
print(table(["model"] + L, [[n] + [f"{st.median(r['attempts'][0]['usage']['out'] for r in rows(m, l)):.0f} · {st.median(r['attempts'][0]['code_tokens'] for r in rows(m, l)):.0f}" for l in L] for m, (n, *_) in M.items()]))
print("\nMean cost per finished program in USD, repairs included (Helium: primer cache read · uncached)\n")
print(table(["model"] + L, [[n] + [f"{st.mean(cost(r, i, o, cr, True) for r in rows(m, 'helium')):.5f} · {st.mean(cost(r, i, o, cr, False) for r in rows(m, 'helium')):.5f}"] + [f"{st.mean(cost(r, i, o, cr, False) for r in rows(m, l)):.5f}" for l in L[1:]] for m, (n, i, o, cr) in M.items()]))
med = {t: {l: st.median(x for x in v[l] if x is not None) for l in L} for t, v in RT.items() if all(l in v for l in L)}
tot = lambda ts: {l: round(sum(med[t][l] for t in ts)) for l in L}
heavy = [t for t in med if med[t]["python"] > 50]
print("\nRuntime in ms, min of 3 runs, median over the three models' programs\n")
print(table(["tasks"] + L, [["all " + str(len(med))] + list(tot(med).values()), ["python > 50 ms (" + str(len(heavy)) + ")"] + list(tot(heavy).values()), ["all but collatz"] + list(tot([t for t in med if t != "collatz"]).values())]))
print("\n" + table(["task", "category"] + L + ["python/helium"], [[t, T[t]["cat"]] + [f"{med[t][l]:.1f}" for l in L] + [f"{med[t]['python'] / med[t]['helium']:.1f}x"] for t in sorted(heavy, key=lambda t: -med[t]["python"])]))
with open(EV/"runs.csv", "w", newline="") as f:
    w = csv.writer(f, lineterminator="\n"); w.writerow(["model", "language", "task", "category", "pass_first_try", "pass_after_one_repair", "attempts", "input_tokens", "output_tokens", "code_tokens_o200k", "runtime_ms"])
    for r in sorted(R, key=lambda r: (r["task"], r["model"], r["lang"])): a = r["attempts"]; w.writerow([M[r["model"]][0], r["lang"], r["task"], r["cat"], int(r["pass1"]), int(r["pass2"]), len(a), sum(x["usage"]["in"] for x in a), sum(x["usage"]["out"] for x in a), a[0]["code_tokens"], f"{med[r['task']][r['lang']]:.1f}" if r["task"] in med else ""])
