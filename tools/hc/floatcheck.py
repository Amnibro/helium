import sys, subprocess, pathlib, struct, tempfile, random
from decimal import Decimal
R = pathlib.Path(__file__).resolve().parents[2]
N = int(sys.argv[1]) if len(sys.argv) > 1 else 1000000
C = r'''#include "hrt.h"
static void hr_init_globals(void) {}
static void hr_main(void) { uint64_t b; int k; while (fread(&k, 4, 1, stdin) == 1 && fread(&b, 8, 1, stdin) == 1) { if (k) { uint32_t u = (uint32_t)b; float f; memcpy(&f, &u, 4); hr_ff(&hr_ob, f); } else { double d; memcpy(&d, &b, 8); hr_fd(&hr_ob, d); } hr_fb(&hr_ob, '\n'); if (hr_ob.n > 65536) hr_flush(); } }
'''
def f32(x):
    try: return struct.unpack('f', struct.pack('f', x))[0]
    except OverflowError: return float('inf') if x > 0 else float('-inf')
def fbits(x): return struct.unpack('I', struct.pack('f', x))[0]
def fnear(v):
    f = f32(float(v))
    if f in (float('inf'), float('-inf')): return f
    c = [struct.unpack('f', struct.pack('I', fbits(f) + d))[0] for d in (-1, 0, 1) if 0 <= fbits(f) + d < 0x7F800000 or fbits(f) >= 0x80000000]
    return min(c, key=lambda y: (abs(Decimal(y) - v), fbits(y) & 1))
def best32(x):
    for p in range(1, 10):
        c = [Decimal('%.*e' % (p - 1, x))]
        c += [c[0] + d * Decimal(1).scaleb(c[0].adjusted() - p + 1) for d in (-1, 1)]
        ok = [v for v in c if fnear(v) == x]
        if ok: return min(ok, key=lambda v: (abs(v - Decimal(x)), int(v.as_tuple().digits[-1]) % 2)).normalize()
with tempfile.TemporaryDirectory() as d:
    src = pathlib.Path(d, 'f.c'); src.write_text(C); exe = pathlib.Path(d, 'f')
    subprocess.run(['cc', '-O2', '-w', '-I', str(R / 'hc'), str(src), '-o', str(exe), '-lm'], check=True)
    rng = random.Random(7); cases = []
    for i in range(N):
        k = i % 2; b = rng.getrandbits(64)
        if i % 7 == 3: b = (b & 0x800FFFFFFFFFFFFF) | ((1023 + rng.randrange(-40, 40)) << 52) if not k else (b & 0x807FFFFF) | ((127 + rng.randrange(-20, 20)) << 23)
        b = b & 0xFFFFFFFF if k else b
        x = f32(struct.unpack('f', struct.pack('I', b))[0]) if k else struct.unpack('d', struct.pack('Q', b))[0]
        if x != x or x in (float('inf'), float('-inf')): continue
        cases.append((k, b, x))
    out = subprocess.run([str(exe)], input=b''.join(struct.pack('<iQ', k, b) for k, b, x in cases), capture_output=True, check=True).stdout.decode().split('\n')
bad = 0
for (k, b, x), s in zip(cases, out):
    want = best32(x) if k else Decimal(repr(x)).normalize()
    if x == 0 or Decimal(s).normalize() == want: continue
    bad += 1
    if bad <= 10: print('f32' if k else 'f64', hex(b), 'got', s, 'want', want)
print(f'{len(cases)} values, {bad} wrong')
sys.exit(1 if bad else 0)
