import sys, os, re, subprocess, pathlib, shutil, tempfile
LOC = re.compile(r'"[^"\n]*\.(?:he|amni):\d+[^"\n]*"')
DEF = re.compile(r'^[A-Za-z].*? (f\d+_[A-Za-z_][A-Za-z0-9_]*)\((.*)\) \{$')
NUMID = re.compile(r'\b[A-Za-z_][A-Za-z0-9_]*\b')
def alpha(s, keep=()):
    m = {}; cnt = {}
    def r(x):
        w = x.group(0)
        if not any(ch.isdigit() for ch in w) or w in keep or w.startswith(('int', 'uint')) and w.endswith('_t'): return w
        st = re.sub(r'\d+', '', w)
        if w not in m: cnt[st] = cnt.get(st, -1) + 1; m[w] = f'{st}#{cnt[st]}'
        return m[w]
    return NUMID.sub(r, s)
def canon(c):
    c = LOC.sub('"L"', c)
    lines = c.split('\n'); fn = {}; cur = None; body = {}; order = []
    for l in lines:
        m = DEF.match(l)
        if m: cur = m.group(1); body[cur] = [l]; order.append(cur); continue
        if cur: body[cur].append(l)
        if l == '}': cur = None
    glob = '\n'.join(l for l in lines if not any(l is x for v in body.values() for x in v))
    names = {}
    for f in order:
        sig = body[f][0]; base = re.sub(r'^f\d+_', '', f)
        names[f] = base + '{' + alpha(DEF.match(sig).group(2)) + '|' + alpha(sig.split(f)[0]) + '}'
    def fren(s): return re.sub(r'\bf\d+_[A-Za-z_][A-Za-z0-9_]*\b', lambda x: names.get(x.group(0), x.group(0)), s)
    out = {}
    for f in order:
        k = names[f]; v = alpha(fren('\n'.join(body[f])))
        out[k] = out.get(k, '') + v
    return out
HC = sys.argv[1]; lib = sys.argv[2]; prog = pathlib.Path(sys.argv[3]); srcs = [pathlib.Path(p) for p in sys.argv[4:]]
S = pathlib.Path(tempfile.mkdtemp(prefix='slim')); W = pathlib.Path(os.environ.get('SLIM_OUT', S / 'out')); shutil.rmtree(W, ignore_errors=True); W.mkdir(parents=True)
env = dict(os.environ, HC_LIB=lib); oenv = env if os.environ.get('SLIM_NEW') == '1' else dict(env, HC_OLDLOC='1')
def norm(c): return re.sub(r'"[^"\n]*\.(?:he|amni):\d+[^"\n]*"', '"L"', c)
def fns(c):
    d = {}; cur = None
    for l in c.split('\n'):
        m = re.match(r'^[A-Za-z].*? (?:f\d+_)?([A-Za-z_][A-Za-z0-9_]*)\(.*\) \{$', l)
        if m: cur = m.group(1); d.setdefault(cur, []).append(l); continue
        if cur: d[cur].append(l)
        if l == '}': cur = None
    return {k: '\n'.join(v) for k, v in d.items()}
def build(root, out, e=None):
    p = subprocess.run([HC, str(root), str(out)], env=e or env, capture_output=True, text=True)
    return p.stdout + p.stderr if p.returncode else None
for f in prog.parent.glob('*.he'): shutil.copy(f, W / f.name)
err = build(prog, S / 'slim_base.c', oenv); assert not err, err
base = canon((S / 'slim_base.c').read_text())
keep = set(); kf = S / 'slim_keep.txt'
for it in range(60):
    kf.write_text(''.join(k + '\n' for k in sorted(keep)))
    for f in srcs:
        p = subprocess.run([HC, '--slim', str(prog), str(f), str(W / f.name), str(kf)], env=oenv, capture_output=True, text=True)
        if p.returncode: print('slim failed', f, p.stdout[:300]); sys.exit(1)
    err = build(W / prog.name, S / 'slim_new.c')
    if err:
        got = set()
        for m in re.finditer(r'([^\s:]+\.he):(\d+):', err):
            lines = (W / pathlib.Path(m.group(1)).name).read_text().split('\n'); i = int(m.group(2)) - 1
            while i >= 0 and not re.match(r'^(?:(?:recursive|inline|checkfree|simd|lut|export|thread_fn) )*[A-Za-z_][A-Za-z0-9_]*[<(]', lines[i]): i -= 1
            got.add(re.match(r'^(?:(?:recursive|inline|checkfree|simd|lut|export|thread_fn) )*([A-Za-z_][A-Za-z0-9_]*)', lines[i]).group(1))
        print('build errors, keep', sorted(got), err.strip().split(chr(10))[0][:150])
        if not got - keep: sys.exit(1)
        keep |= got; continue
    new = canon((S / 'slim_new.c').read_text())
    bad = {k for k in set(base) | set(new) if base.get(k) != new.get(k)}
    rest = False
    print(f'iter {it}: {len(bad)} functions differ' + (' (non-function diff)' if rest else ''))
    if not bad and not rest: break
    if rest: print('non-function C difference; giving up'); sys.exit(1)
    keep |= {b.split('{')[0] for b in bad}
print('kept', len(keep), 'functions; slimmed sources in', W)
