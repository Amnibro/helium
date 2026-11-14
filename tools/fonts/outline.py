import sys
from fontTools.ttLib import TTFont
from fontTools.pens.basePen import BasePen
p, idx, step = sys.argv[1], int(sys.argv[2]), int(sys.argv[3])
f = TTFont(p, fontNumber=idx) if p.endswith('.ttc') else TTFont(p)
gs = f.getGlyphSet(); order = f.getGlyphOrder(); out = sys.stdout.write
def w(v): v = int(v); return ((v + 32768) & 0xFFFF) - 32768
class Pen:
    def __init__(s): s.x = s.y = s.fx = s.fy = 0.0
    def cl(s):
        if s.fx != s.x or s.fy != s.y: out(f"2 {w(s.fx)} {w(s.fy)} 0 0 0 0\n")
    def moveTo(s, p): s.cl(); s.x, s.y = p; s.fx, s.fy = p; out(f"1 {w(s.x)} {w(s.y)} 0 0 0 0\n")
    def lineTo(s, p): s.x, s.y = p; out(f"2 {w(s.x)} {w(s.y)} 0 0 0 0\n")
    def curveTo(s, a, b, c): s.x, s.y = c; out(f"4 {w(c[0])} {w(c[1])} {w(a[0])} {w(a[1])} {w(b[0])} {w(b[1])}\n")
    def closePath(s): pass
    def endPath(s): pass
    def addComponent(s, *a): raise Exception('component')
for g in range(0, len(order), step):
    out(f"G {g}\n"); pen = Pen(); gs[order[g]].draw(pen); pen.cl()
