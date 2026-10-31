#!/usr/bin/env python3
"""results.json -> RESULTS.md and gold_tokens.png. No measurements happen here."""
import json, os
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt

HERE = os.path.dirname(os.path.abspath(__file__))
R = json.load(open(os.path.join(HERE, "results.json")))
N = R["names"]
TOKS = list(R["summary"])
MAIN = "o200k_base"
CMP = ["py", "amni", "rs", "go", "exp_prog", "exp"]
UCMP = ["py", "amni", "rs", "go", "exp"]
ok = [t for t in R["tasks"] if t["verified"]]
f2 = lambda x: f"{x:.2f}"


def chart(path):
    fig, axes = plt.subplots(1, 2, figsize=(13, 5.6), gridspec_kw={"width_ratios": [6, 5]})
    colors = {"o200k_base": "#c9a227", "cl100k_base": "#7a6a3a", "qwen2.5-coder": "#4f7cac"}
    for ax, keys, sk, title in (
            (axes[0], CMP, None, f"Writing a program ({len(ok)} tasks)"),
            (axes[1], UCMP, "upkeep", f"Making a change ({R['upkeep_verified']} tasks, diff tokens)")):
        w = 0.8 / len(TOKS)
        for i, tn in enumerate(TOKS):
            s = R["summary"][tn][sk] if sk else R["summary"][tn]
            vals = [s[k]["geomean"] for k in keys]
            xs = [j + (i - (len(TOKS) - 1) / 2) * w for j in range(len(keys))]
            bars = ax.bar(xs, vals, w, label=tn, color=colors.get(tn))
            for b, v in zip(bars, vals):
                ax.text(b.get_x() + b.get_width() / 2, v * 1.04, f"{v:.1f}×", ha="center", va="bottom",
                        fontsize=7, rotation=90)
        ax.set_yscale("log")
        ax.axhline(1, color="black", lw=1)
        ax.text(len(keys) - 0.5, 1.03, "1× = same tokens as Gold", ha="right", va="bottom", fontsize=8)
        ax.set_xticks(range(len(keys)))
        ax.set_xticklabels([N[k].replace(" (", "\n(") for k in keys], fontsize=8)
        ax.set_title(title, fontsize=11)
        ax.set_ylim(0.8, max(ax.get_ylim()[1], 10) * 2.2)
        ax.set_ylabel("tokens in that language ÷ tokens in Gold\n(geometric mean; higher = Gold saves more)")
        ax.grid(axis="y", which="both", alpha=0.25)
    axes[0].legend(title="tokenizer", fontsize=8, loc="upper left")
    fig.suptitle(f"Gold token savings: every program builds and prints identical output "
                 f"(Gold {R['gold_commit'][:7]})", fontsize=12)
    fig.text(0.5, 0.005, "Does not include the cost of knowing Gold's phrase library "
             f"({R['vocabulary']['phrasings']} phrasings, {R['vocabulary']['tokens'][MAIN]:,} o200k tokens); "
             "see RESULTS.md.", ha="center", fontsize=8, style="italic")
    fig.tight_layout(rect=(0, 0.03, 1, 0.95))
    fig.savefig(path, dpi=150)


def summary_table(tn, sk=None, keys=CMP):
    s = R["summary"][tn][sk] if sk else R["summary"][tn]
    tot = R["summary"][tn]["upkeep_totals" if sk else "totals"]
    rows = ["| compared with | median | geomean | min | max | total tokens (Gold total) |", "|---|---|---|---|---|---|"]
    for k in keys:
        v = s[k]
        rows.append(f"| {N[k]} | {f2(v['median'])}× | {f2(v['geomean'])}× | {f2(v['min'])}× | {f2(v['max'])}× "
                    f"| {tot[k]:,} ({tot['gold']:,}) |")
    return "\n".join(rows)


def main():
    chart(os.path.join(HERE, "gold_tokens.png"))
    S = R["summary"][MAIN]
    V = R["vocabulary"]
    tot = S["totals"]
    per_task_saving = {k: (tot[k] - tot["gold"]) / len(ok) for k in ("py", "amni", "rs", "go")}
    breakeven = {k: V["tokens"][MAIN] / v for k, v in per_task_saving.items()}
    losses = []
    for t in ok:
        for tn in TOKS:
            tk = t["tokens"][tn]
            for k in ("py", "amni", "rs", "go"):
                if tk[k] <= tk["gold"]:
                    losses.append(f"{t['id']} writing, {N[k]}, {tn}: {tk[k]} vs Gold {tk['gold']}")
            if "upkeep" in t:
                u = t["upkeep"]["diff_tokens"][tn]
                for k in ("py", "amni", "rs", "go"):
                    if u[k] <= u["gold"]:
                        losses.append(f"{t['id']} upkeep, {N[k]}, {tn}: {u[k]} vs Gold {u['gold']}")
    exp_vs_hand = sorted(t["tokens"][MAIN]["exp_prog"] / t["tokens"][MAIN]["amni"] for t in ok)
    L = []
    w = L.append
    w("# Gold token benchmark\n")
    w(f"How many tokens a Gold script takes compared with the same program written in Helium, Rust, Go and "
      f"Python, and with the Helium that Gold expands into. Gold is pinned at `{R['gold_commit']}`.\n")
    w("![Gold token savings](gold_tokens.png)\n")
    w("## Headline (o200k_base, geometric mean of per-task ratios)\n")
    w(f"Over {len(ok)} tasks, all verified, the same program needs:\n")
    for k in ("py", "amni", "rs", "go"):
        w(f"* **{N[k]}**: {f2(S[k]['geomean'])}× the tokens of the Gold script (median {f2(S[k]['median'])}×, "
          f"range {f2(S[k]['min'])}–{f2(S[k]['max'])}×)")
    w(f"* **Expanded Helium**: {f2(S['exp_prog']['geomean'])}× without the shared prelude, "
      f"{f2(S['exp']['geomean'])}× with it\n")
    U = S["upkeep"]
    w(f"For a change to an existing program ({R['upkeep_verified']} tasks), the diff is "
      + ", ".join(f"{f2(U[k]['geomean'])}× in {N[k]}" for k in ("py", "amni", "rs", "go"))
      + " the size of the Gold diff (geomean of diff tokens).\n")
    spread = max(abs(R["summary"][tn][k]["geomean"] / S[k]["geomean"] - 1) for tn in TOKS for k in CMP)
    w(f"The other two tokenizers put every writing geomean within {spread*100:.0f}% of these numbers "
      "(tables below).\n")
    w("## What it does not show\n")
    w(f"* **The phrase library is not free.** Writing Gold means knowing which sentences exist. The library "
      f"index at `{R['gold_commit'][:7]}` has {V['phrasings']:,} phrasings, which comes to "
      + ", ".join(f"{V['tokens'][tn]:,} {tn}" for tn in TOKS)
      + " tokens as a plain list. If a model had to hold the whole list in context, the "
      f"per-program savings measured here (o200k, on average {per_task_saving['py']:.0f} tokens against Python and "
      f"{per_task_saving['rs']:.0f} against Rust) would only repay it after about {breakeven['py']:.0f} programs "
      f"against Python or {breakeven['rs']:.0f} against Rust. These counts measure the program text only.")
    w(f"* **The Helium that ships is bigger, not smaller.** Without the prelude, the expanded program is "
      f"{exp_vs_hand[len(exp_vs_hand)//2]:.1f}× the tokens of a hand-written Helium program with the same output "
      f"(median; range {exp_vs_hand[0]:.1f}–{exp_vs_hand[-1]:.1f}×). With the prelude it is larger still. Gold "
      f"saves on what a person or model writes and edits, not on the size of the generated code.")
    w("* **Python is the closest competitor.** Gold's lead is smallest against Python, and on c21 Python ties "
      "or wins (see below).")
    w("* **Selection bias.** Every task here is one Gold can express. The 28 corpus scripts were produced by "
      "Gold's own generator, and the 22 new tasks were written with the library at hand. Programs that need "
      "constructs outside the library are not represented at all. The existing `bench/llm` tasks (anagrams, "
      "brackets, caesar_crack, ...) could not be expressed with the phrasings available at this commit, so they "
      "were not reused.")
    rng = lambda k: f"{min(t['lines'][k] for t in ok)}–{max(t['lines'][k] for t in ok)}"
    w(f"* **Small programs.** Gold scripts here are {rng('gold')} lines. The references are {rng('py')} lines in "
      f"Python, {rng('amni')} in Helium, {rng('rs')} in Rust and {rng('go')} in Go. The ratios say nothing about "
      "large programs.\n")
    w("### Cases where Gold does not win\n")
    w("Every task/tokenizer/language combination where the other language needed no more tokens than Gold "
      "(a tie or a loss for Gold):\n")
    for x in losses or ["none"]:
        w(f"* {x}")
    w("")
    w("## Method\n")
    w("Each task directory under `tasks/<id>/` contains:\n")
    w("* `task.gold`: the Gold script (comment lines removed; e01/e02 come from `examples/demo.gold` and "
      "`examples/nested.gold`, where the only change was dropping one comment line)")
    w("* `expanded.amni`: the output of `goldc compose`, committed so that changes in expansion are caught")
    w("* `expected.txt`: the full stdout of the compiled Gold program")
    w("* `ref.amni`, `ref.rs`, `ref.go`, `ref.py`: hand-written programs with no comments. Go is gofmt-clean, "
      "Rust is rustfmt-clean and builds with no warnings, and Python uses ordinary idioms such as "
      "comprehensions and `sorted`.\n")
    w("`harness.py` does the following for each task:\n")
    w("1. Composes `task.gold` with `goldc`, checks that the result is byte-identical to `expanded.amni`, builds "
      "it with `hc` and runs it. Stdout must equal `expected.txt` byte for byte.")
    w("2. Builds and runs the four references (`hc build`, `rustc --edition 2021 -O`, `go build`, `python3`). "
      "Each one's stdout must equal Gold's stdout with the `=> ...` debug state line removed. That line is "
      "Gold's internal state dump and is not program output.")
    w("3. **Second-input check.** It replaces the input literal (list, start value or text) in the Gold script "
      "and in all four references with the values listed in `tasks.json`, rebuilds everything and requires all "
      "five outputs to agree again. It also requires that the new output differs from the original, so a "
      "program that prints a fixed answer fails.")
    w("4. For tasks with an `upkeep/` directory, it verifies the changed version the same way (the change is "
      "described in `upkeep/change.txt`).")
    w("5. Counts tokens with tiktoken `o200k_base` and `cl100k_base`, and with the Hugging Face tokenizer of "
      "Qwen2.5-Coder-7B-Instruct (an open tokenizer). Whole files are counted. "
      "\"Expanded Helium (program only)\" starts at the `// ===== Gold bindings` marker, which drops the shared "
      "prelude.")
    w("6. Ratio = tokens(other) ÷ tokens(Gold) for each task. Summaries are the median and the geometric mean "
      "across tasks.")
    w("7. Upkeep cost = tokens on the lines a line diff (`difflib`) adds or removes between the base and changed "
      "file. A changed line counts twice, once removed and once added.\n")
    w("Python runs only the build/compare/count steps and the Python reference. No Helium or Gold output is "
      "produced by Python.\n")
    w("### Fairness notes\n")
    w("* The references print exactly what Gold prints (for example `no errors in 6 results` and "
      "`subfunction ran on N results, H memo hits`), so they carry Gold's output format. A program written "
      "from scratch might print less.")
    inv = [t for t in ok if t["invisible_sentences"]]
    w(f"* {len(inv)} tasks contain a sentence whose only effect is on Gold's internal state (the `=>` line), "
      "with nothing visible in stdout. The references leave those steps out, which favours the references. "
      "The tasks: " + "; ".join(f"{t['id']} (\"{'; '.join(t['invisible_sentences'])}\")" for t in inv) + ".")
    w("* Excluded: " + "; ".join(f"{e['id']} ({e['source']}): {e['reason']}" for e in R["excluded"]) + ".")
    w("* The references assume non-empty input. They do include the data-dependent error branches that Gold "
      "prints (pair checks, gap checks, minimum length).")
    for t in ok:
        if t.get("note"):
            w(f"* {t['id']}: {t['note']}")
    w("* The upkeep edits are minimal, hand-made edits to each reference (helpers that are no longer needed "
      "are deleted), followed by rustfmt/gofmt. The expanded "
      "Helium diff is shown for information: nobody edits it, since it is regenerated.\n")
    w("## Summary by tokenizer\n")
    for tn in TOKS:
        w(f"### {tn}: writing\n")
        w(summary_table(tn) + "\n")
        w(f"### {tn}: upkeep (diff tokens)\n")
        w(summary_table(tn, "upkeep", UCMP) + "\n")
    w(f"## Per task ({MAIN} tokens)\n")
    w("| task | title | Gold | Expanded (program) | Helium | Rust | Go | Python | Python÷Gold | Rust÷Gold |")
    w("|---|---|---|---|---|---|---|---|---|---|")
    for t in ok:
        k = t["tokens"][MAIN]
        w(f"| {t['id']} | {t['title']} | {k['gold']} | {k['exp_prog']} | {k['amni']} | {k['rs']} | {k['go']} "
          f"| {k['py']} | {f2(k['py']/k['gold'])} | {f2(k['rs']/k['gold'])} |")
    w("")
    w(f"## Upkeep per task ({MAIN} diff tokens)\n")
    w("| task | change | Gold | Expanded Helium | Helium | Rust | Go | Python |")
    w("|---|---|---|---|---|---|---|---|")
    for t in ok:
        if "upkeep" in t:
            u = t["upkeep"]["diff_tokens"][MAIN]
            w(f"| {t['id']} | {t['upkeep']['change']} | {u['gold']} | {u['exp']} | {u['amni']} | {u['rs']} "
              f"| {u['go']} | {u['py']} |")
    w("")
    w("## Reproducing\n")
    w("```sh\n# Helium: hc/bootstrap.sh produces build/hcn\n"
      f"git clone <gold repo> gold && git -C gold checkout {R['gold_commit'][:7]}\n"
      "build/hcn build gold/goldc.amni -o goldc\n"
      "python3 -m venv venv && venv/bin/pip install tiktoken tokenizers matplotlib\n"
      "# tokenizer.json from Qwen/Qwen2.5-Coder-7B-Instruct on Hugging Face\n"
      "HC_LIB=$PWD/hc/lib venv/bin/python bench/gold_tokens/harness.py \\\n"
      "    --gold-root gold --goldc ./goldc --hc build/hcn --qwen-tokenizer tokenizer.json\n"
      "venv/bin/python bench/gold_tokens/report.py\n```\n")
    w(f"Last run: {R['tasks_verified']}/{R['tasks_total']} tasks verified, "
      f"{R['upkeep_verified']}/{R['upkeep_total']} upkeep variants verified. Tools: rustc, go and python3 "
      "versions: " + ", ".join(R["tool_versions"].values()) + " (python).")
    open(os.path.join(HERE, "RESULTS.md"), "w").write("\n".join(L) + "\n")


if __name__ == "__main__":
    main()
