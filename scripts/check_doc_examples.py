#!/usr/bin/env python3
"""Compile every ```goose block of a markdown document with the compiler.

    python scripts/check_doc_examples.py docs/reference.md [--run] [--exe build/goose]

A block compiles as written or, failing that, wrapped: `import std;` in
front, the block inside `fn main() { }`, or an empty `fn main() {}` after
it, so a document can show the body of a main or a set of declarations
without the scaffolding. A block holding a live line (not a comment) that
ends in a `// error` note must fail to compile in every form; its
diagnostic is printed so the intended error can be checked by eye. An HTML
comment on the line before a fence marks the exceptions: `<!-- fragment -->`
skips a block that is not meant to compile on its own, and
`<!-- check-only -->` compiles a program without running it (one with
threads, which the in-process backend refuses).

With --run, each complete program is also run in-process, and its output
compared with a bare ``` block that directly follows it, as the reference
shows its examples' output; a program with no such block has its output
printed. The compiler is `--exe`, else the first of build/Release,
build/RelWithDebInfo, build and build/Debug that holds one, as the test
runners choose. Examples are written under build/doc_examples/.
"""
import argparse
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def find_compiler():
    exe = "goose.exe" if sys.platform == "win32" else "goose"
    for d in ("build/Release", "build/RelWithDebInfo", "build", "build/Debug"):
        p = os.path.join(ROOT, d, exe)
        if os.path.exists(p):
            return p
    raise SystemExit("no compiler found under build/; pass --exe")


def read_blocks(path):
    """The ```goose blocks: (first line number, lines, expected output, marker)."""
    lines = open(path, encoding="utf-8").read().split("\n")
    blocks = []
    i = 0
    while i < len(lines):
        m = re.match(r"^```(\w*)", lines[i])
        if not (m and m.group(1) == "goose"):
            i += 1
            continue
        marker = ""
        if i > 0:
            mm = re.match(r"^<!--\s*(fragment|check-only)\s*-->", lines[i - 1])
            if mm:
                marker = mm.group(1)
        start = i + 1
        body = []
        i += 1
        while i < len(lines) and not lines[i].startswith("```"):
            body.append(lines[i])
            i += 1
        i += 1
        # A bare ``` block right after the program is its expected output.
        expected = None
        j = i
        while j < len(lines) and lines[j].strip() == "":
            j += 1
        if j < len(lines) and lines[j].strip() == "```":
            expected = []
            j += 1
            while j < len(lines) and not lines[j].startswith("```"):
                expected.append(lines[j])
                j += 1
        blocks.append((start, body, expected, marker))
    return blocks


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("markdown")
    ap.add_argument("--exe", help="the compiler (default: the newest build under build/)")
    ap.add_argument("--run", action="store_true", help="also run complete programs and compare their output")
    ap.add_argument("--line", type=int, help="check only the block starting at this line")
    a = ap.parse_args()
    goose = os.path.abspath(a.exe) if a.exe else find_compiler()
    out_dir = os.path.join(ROOT, "build", "doc_examples")
    os.makedirs(out_dir, exist_ok=True)
    sys.stdout.reconfigure(encoding="utf-8", errors="replace")

    def compile_text(text, name):
        path = os.path.join(out_dir, name + ".goose")
        with open(path, "w", encoding="utf-8", newline="\n") as f:
            f.write(text)
        p = subprocess.run([goose, "check", path], capture_output=True, text=True,
                           encoding="utf-8", errors="replace")
        msg = "\n".join(l for l in (p.stdout + p.stderr).split("\n")
                        if not l.startswith(("parsed ok", "typechecked ok", "bce:")))
        return p.returncode, msg.strip(), path

    failures = 0
    checked = 0
    fragments = 0
    blocks = read_blocks(a.markdown)
    for start, body, expected, marker in blocks:
        if a.line is not None and start != a.line:
            continue
        if marker == "fragment":
            fragments += 1
            continue
        text = "\n".join(body) + "\n"
        expect_error = any(not l.lstrip().startswith("//") and re.search(r"//\s*error", l) for l in body)
        has_main = re.search(r"^\s*fn main\(", text, re.M) is not None
        forms = [("as-is", text), ("std", "import std;\n" + text)]
        if not has_main:
            forms += [("main-wrap", "import std;\nfn main() {\n" + text + "}\n"),
                      ("main-after", "import std;\n" + text + "\nfn main() {}\n")]
        results = []
        for label, t in forms:
            rc, msg, path = compile_text(t, "ex_%04d_%s" % (start, label))
            results.append((label, rc, msg, path))
            if rc == 0 and not expect_error:
                break
        checked += 1
        ok_forms = [r for r in results if r[1] == 0]
        if expect_error:
            if ok_forms:
                failures += 1
                print("FAIL line %d: expected an error, but compiled as %s" % (start, ok_forms[0][0]))
            else:
                best = next((r for r in results if "error" in r[2]), results[-1])
                first = [l for l in best[2].split("\n") if "error" in l or "warning" in l][:2]
                print("error-ok line %d (%s): %s" % (start, best[0], " | ".join(first)))
            continue
        if not ok_forms:
            failures += 1
            print("FAIL line %d: no form compiles" % start)
            for label, rc, msg, path in results:
                first = [l for l in msg.split("\n") if l.strip()][:3]
                print("   [%s] %s" % (label, " | ".join(first)))
            continue
        label, rc, msg, path = ok_forms[0]
        warn = [l for l in msg.split("\n") if "warning" in l]
        if warn:
            print("WARN line %d (%s): %s" % (start, label, " | ".join(warn[:2])))
        if a.run and label in ("as-is", "std") and has_main and marker != "check-only":
            p = subprocess.run([goose, path], capture_output=True, text=True, encoding="utf-8",
                               errors="replace", timeout=300)
            if p.returncode != 0:
                failures += 1
                tail = p.stderr.strip().split("\n")[-1] if p.stderr.strip() else p.stdout.strip()[-200:]
                print("FAIL line %d: run exited %d: %s" % (start, p.returncode, tail))
            elif expected is not None:
                got = p.stdout.replace("\r\n", "\n").rstrip("\n").split("\n")
                exp = "\n".join(expected).rstrip("\n").split("\n")
                if got != exp:
                    failures += 1
                    print("FAIL line %d: output differs" % start)
                    print("   expected: " + " / ".join(exp)[:400])
                    print("   got:      " + " / ".join(got)[:400])
            else:
                print("run line %d:\n%s" % (start, p.stdout.rstrip()))
    print("%d blocks, %d checked, %d fragments skipped, %d failures" % (len(blocks), checked, fragments, failures))
    sys.exit(1 if failures else 0)


if __name__ == "__main__":
    main()
