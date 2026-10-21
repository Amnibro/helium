"""The runtime's standard input at its edges (stdlib/os.goose), built by
`goose build` and, where the JIT runs, run by `goose run`: stdin read as the
bytes piped in, a carriage return before a line break and a Ctrl-Z among
them, which Windows' text mode would translate and stop at."""
import os
from pathlib import Path
import subprocess
import tempfile

import toolchain as tc

PROGRAM = """\
import std;
import os;

// Standard input as the program reads it: with `all`, read_stdin's bytes.
fn main() {
    let argv = args();
    var got: u8[>..] = [];
    if argv[1] == "all" {
        read_stdin(got);
    }
    print(got.len);
    for b in got { print(b); }
}
"""


def check_runtime_io(exe, base, *, jit):
    """Raises RuntimeError on a failure."""
    base = Path(base).resolve()
    base.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix="runtime-io-", dir=base) as tmp:
        root = Path(tmp)
        env = dict(os.environ, GOOSE_HOME=str(root / "home"))
        source = root / "runtime_io.goose"
        tc.write_text(source, PROGRAM)
        app = root / ("runtime_io" + tc.EXE_SUFFIX)

        def run(argv, stdin=b""):
            r = subprocess.run([str(a) for a in argv], cwd=root, env=env, input=stdin,
                               capture_output=True, timeout=300)
            return r.returncode, tc.decode(r.stdout), tc.decode(r.stderr)

        code, out, err = run([exe, "build", "-o", app, source])
        if code != 0:
            raise RuntimeError(f"runtime io: goose build:\n{out}{err}")
        runners = [("built", [app])] + ([("JIT", [exe, "run", source, "--"])] if jit else [])
        cases = [("all", b"a\r\nb\x1ac", [6, 97, 13, 10, 98, 26, 99])]
        for how, argv in runners:
            for mode, data, want in cases:
                code, out, err = run(argv + [mode], data)
                if code != 0 or out.split() != [str(n) for n in want]:
                    raise RuntimeError(f"runtime io: the {how} program reading {data!r} with "
                                       f"{mode}: wanted {want}, got exit {code}:\n{out}{err}")
