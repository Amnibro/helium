import os, shutil, subprocess, sys, tempfile
from pathlib import Path
exe = str(Path(sys.argv[1]).resolve()); base = Path(sys.argv[2] if len(sys.argv) > 2 else tempfile.mkdtemp(prefix="hcpkg")).resolve(); shutil.rmtree(base, ignore_errors=True)
home = base / "home"; work = base / "work"; work.mkdir(parents=True)
def g(*a, cwd=work):
    r = subprocess.run(["git", "-c", "user.name=t", "-c", "user.email=t@e", "-c", "commit.gpgsign=false", "-c", "tag.gpgsign=false", *a], cwd=cwd, capture_output=True, text=True)
    assert r.returncode == 0, r.stderr; return r.stdout.strip()
def entry(code): (work / "gitpkg.amni").write_text(f"namespace gitpkg;\nimport .sub.helper;\nfn code() i64 {{ return helper() + {code}; }}\n")
sub = base / "subrepo"; sub.mkdir(); (sub / "helper.amni").write_text("namespace gitpkg;\nfn helper() i64 { return 0; }\n")
g("init", "-q", "-b", "main", ".", cwd=sub); g("add", ".", cwd=sub); g("commit", "-q", "-m", "s", cwd=sub)
entry(5); g("init", "-q", "-b", "main", "."); g("-c", "protocol.file.allow=always", "submodule", "add", "-q", sub.as_uri(), "sub"); g("add", "."); g("commit", "-q", "-m", "one"); g("tag", "v1")
entry(6); g("commit", "-q", "-am", "two"); g("tag", "v2"); second = g("rev-parse", "HEAD")
bare = base / "gitpkg.git"; g("clone", "-q", "--bare", str(work), str(bare)); g("config", "uploadpack.allowAnySHA1InWant", "true", cwd=bare)
url = "file:///" + bare.as_posix().lstrip("/")
def prog(name, lines): p = base / f"{name}.amni"; p.write_text("\n".join(lines) + "\n"); return p
use_tag = prog("use_tag", [f'import gitpkg from "{url}@v1";', "fn main() { print(gitpkg::code()); }"])
use_hash = prog("use_hash", [f'import gitpkg from "{url}@{second}";', "fn main() { print(gitpkg::code()); }"])
lib = base / "lib"; lib.mkdir(); (lib / "lib.amni").write_text(f'namespace lib;\nimport gitpkg from "{url}@v2";\nfn code() i64 {{ return gitpkg::code(); }}\n')
use_lib = prog("use_lib", ['import lib from "./lib";', f'import gitpkg from "{url}@v1";', "fn main() { print(lib::code()); }"])
env = dict(os.environ, GIT_ALLOW_PROTOCOL="file", GOOSE_HOME=str(home), XDG_CACHE_HOME=str(base / "cache"), HC_LIB=str(Path(os.environ.get("HC_LIB", Path(__file__).resolve().parents[2] / "hc" / "lib")).resolve()))
def hc(*a, ok=True):
    r = subprocess.run([exe, *map(str, a)], cwd=base, env=env, capture_output=True, text=True, timeout=120)
    if ok and r.returncode != 0: raise SystemExit(f"FAIL hc {a}: {r.returncode}\n{r.stdout}{r.stderr}")
    return r
def conc(p):
    ws = [subprocess.Popen([exe, "fetch", str(p)], cwd=base, env=env, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True) for _ in range(8)]
    outs = [w.communicate(timeout=120)[0] for w in ws]
    bad = [o for w, o in zip(ws, outs) if w.returncode != 0]; assert not bad, bad[0]
    n = sum(o.count("fetching the package gitpkg") for o in outs); assert n == 1, f"fetched {n} times: {outs}"
def expect(p, want, warn=None):
    r = hc("run", p); assert r.stdout.strip() == want, (p.name, r.stdout, r.stderr)
    if warn: assert warn in r.stderr, ("no warning", r.stderr)
    else: assert "warning:" not in r.stderr, r.stderr
r = hc("check", "--offline", use_tag, ok=False)
assert r.returncode == 1 and "is not fetched" in r.stdout + r.stderr and "hc fetch" in r.stdout + r.stderr, r
assert not list((home / "pkg").glob("gitpkg-*")), "offline fetched"
print("offline ok"); conc(use_tag); print("concurrent ok"); expect(use_tag, "5"); hc("check", "--offline", use_tag)
caches = list((home / "pkg").glob("gitpkg-*/v1")); assert len(caches) == 1, caches
stale = caches[0].parent / f"{second[:12]}.tmp"; stale.mkdir(); (stale / "unfinished").write_text("x")
conc(use_hash); assert not stale.exists(), "stale tmp left"; expect(use_hash, "6"); print("commit ok")
expect(use_lib, "5", warn="declares at v1"); print("lib warning ok")
use_retry = prog("use_retry", [f'import gitpkg from "{url}@retry";', "fn main() { print(gitpkg::code()); }"])
r = hc("fetch", use_retry, ok=False); assert r.returncode == 1 and "cannot fetch the package gitpkg" in r.stdout + r.stderr, r
assert not any((caches[0].parent / n).exists() for n in ("retry", "retry.tmp")), "failed fetch left checkout"
g("tag", "retry", "HEAD", cwd=bare); conc(use_retry); expect(use_retry, "6"); print("retry ok")
g("tag", "-f", "v1", "HEAD"); g("fetch", "-q", "--tags", "--force", str(work), cwd=bare); expect(use_tag, "5")
r = hc("fetch", "--update", use_tag); assert "updating the package gitpkg" in r.stderr, r; expect(use_tag, "6"); print("update ok")
print("pkgtest: 7 pass, 0 fail"); shutil.rmtree(base, ignore_errors=True)
