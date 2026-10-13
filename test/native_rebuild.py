"""When a native part is built again: a program's own C edited after a build
is compiled again for both `goose build` and `goose run`, and an extern fn
added to the program without touching its C rebuilds the JIT library, whose
symbol table names every extern fn."""
import os
import shutil
import subprocess
import tempfile
from pathlib import Path

import toolchain as tc


def check_native_rebuild(exe, base, *, jit):
    """Returns why a part was skipped, or None when every check ran; raises
    RuntimeError on a failure."""
    base = Path(base).resolve()
    base.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix="rebuild-", dir=base) as tmp:
        root = Path(tmp)
        env = dict(os.environ)
        env["GOOSE_HOME"] = str(root / "home")

        def run(argv):
            r = subprocess.run([str(a) for a in argv], cwd=root, env=env, capture_output=True,
                               text=True, errors="replace", timeout=600)
            return r.returncode, r.stdout, r.stderr

        def require(good, message):
            if not good:
                raise RuntimeError(f"native rebuild: {message}")

        def expect(argv, want, what):
            code, out, err = run(argv)
            require(code == 0 and (want is None or out.split() == want),
                    f"{what}: wanted {' '.join(want or ['success'])}, got exit {code}:\n"
                    f"{out}{err}")

        def program(*externs):
            tc.write_text(root / "rebuild.goose",
                          "import std;\n" +
                          "".join(f"extern fn {e}() -> i64;\n" for e in externs) +
                          "fn main() {\n" + "".join(f"    print({e}());\n" for e in externs) +
                          "}\n")

        def impl(a):
            tc.write_text(root / "rebuild_impl.c",
                          "#include <stdint.h>\n"
                          f"int64_t rebuild_a(void) {{ return {a}; }}\n"
                          "int64_t rebuild_b(void) { return 2; }\n")

        tc.write_text(root / "rebuild.build", 'c_sources = ["rebuild_impl.c"];\n')
        program("rebuild_a")
        impl(1)
        source = root / "rebuild.goose"
        app = root / ("rebuild" + tc.EXE_SUFFIX)
        expect([exe, "build", "-o", app, source], None, "goose build")
        expect([app], ["1"], "the built program")
        impl(11)
        expect([exe, "build", "-o", app, source], None, "goose build after editing the C")
        expect([app], ["11"], "the program built after editing the C")
        if jit:
            expect([exe, "run", source], ["11"], "goose run")
            impl(111)
            expect([exe, "run", source], ["111"], "goose run after editing the C")
            program("rebuild_a", "rebuild_b")
            expect([exe, "run", source], ["111", "2"], "goose run after adding an extern fn")
    return None
