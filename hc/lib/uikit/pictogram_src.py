# Authoring source for the named pictogram batches.
# Coordinates are a 64 grid, y down. The emitter fits each glyph into the cell.
import math
import os

ROOT = os.path.dirname(os.path.abspath(__file__))


def D(cx, cy, r):
    return [("disc", cx, cy, r)]


def B(x, y, w, h):
    return [("box", x, y, w, h)]


def T(x0, y0, x1, y1, x2, y2):
    return [("tri", x0, y0, x1, y1, x2, y2)]


def L(x0, y0, x1, y1, t):
    return [("bar", x0, y0, x1, y1, t)]


def O(cx, cy, r, t):
    return [("ring", cx, cy, r, t)]


def H(cx, cy, r):
    return [("punch", cx, cy, r)]


def N(x, y, w, h):
    return [("notch", x, y, w, h)]


def arc(cx, cy, r, a0, a1, t, steps=6):
    cmds = []
    for i in range(steps):
        u0 = a0 + (a1 - a0) * i / steps
        u1 = a0 + (a1 - a0) * (i + 1) / steps
        cmds.append(("bar", cx + r * math.cos(u0), cy + r * math.sin(u0), cx + r * math.cos(u1), cy + r * math.sin(u1), t))
    return cmds


def poly(pts):
    cx = sum(p[0] for p in pts) / len(pts)
    cy = sum(p[1] for p in pts) / len(pts)
    cmds = []
    for i in range(len(pts)):
        x0, y0 = pts[i]
        x1, y1 = pts[(i + 1) % len(pts)]
        cmds.append(("tri", cx, cy, x0, y0, x1, y1))
    return cmds


def ngon(cx, cy, r, n, rot=-math.pi / 2):
    pts = [(cx + r * math.cos(rot + i * 2 * math.pi / n), cy + r * math.sin(rot + i * 2 * math.pi / n)) for i in range(n)]
    return poly(pts)


def star(cx, cy, ro, ri, n=5, rot=-math.pi / 2):
    pts = []
    for i in range(n * 2):
        r = ro if i % 2 == 0 else ri
        a = rot + i * math.pi / n
        pts.append((cx + r * math.cos(a), cy + r * math.sin(a)))
    return poly(pts)


def rbox(x, y, w, h, r):
    return B(x + r, y, w - 2 * r, h) + B(x, y + r, w, h - 2 * r) + D(x + r, y + r, r) + D(x + w - r, y + r, r) + D(x + r, y + h - r, r) + D(x + w - r, y + h - r, r)


def burst(cx, cy, r0, r1, n, t):
    cmds = []
    for i in range(n):
        a = -math.pi / 2 + i * 2 * math.pi / n
        cmds += L(cx + r0 * math.cos(a), cy + r0 * math.sin(a), cx + r1 * math.cos(a), cy + r1 * math.sin(a), t)
    return cmds


ICONS = []


def add(name, *parts):
    cmds = []
    for p in parts:
        cmds.extend(p)
    ICONS.append((name, cmds))


# --- batch 0: core game and system metaphors ---
add("sword", T(32, 4, 24, 40, 40, 40), L(14, 40, 50, 40, 5), B(29, 42, 6, 12), D(32, 57, 4))
add("shield", B(14, 8, 36, 30), T(14, 34, 50, 34, 32, 58), H(32, 24, 5))
add("heart", D(22, 24, 11), D(42, 24, 11), T(10, 28, 54, 28, 32, 56))
add("skull", D(32, 24, 16), B(18, 28, 28, 16), H(24, 24, 4), H(40, 24, 4), N(28, 32, 8, 6), N(20, 40, 5, 8), N(30, 40, 4, 8), N(39, 40, 5, 8))
add("potion", B(24, 4, 16, 18), D(32, 6, 6), B(12, 16, 40, 38), H(32, 36, 5))
add("coin", L(12, 46, 52, 46, 12), L(12, 32, 52, 32, 12), L(16, 18, 48, 18, 10))
add("chest", B(8, 30, 48, 24), B(6, 10, 52, 16), N(6, 24, 52, 5), H(32, 40, 4))
add("bag", D(32, 40, 18), B(26, 18, 12, 12), L(20, 20, 14, 8, 4), L(44, 20, 50, 8, 4), H(32, 42, 4))
add("key", D(18, 32, 11), H(18, 32, 5), B(26, 29, 28, 6), B(44, 35, 6, 8), B(38, 35, 4, 6))
add("compass", O(32, 32, 20, 4), T(32, 10, 26, 34, 38, 34), T(32, 54, 28, 32, 36, 32), D(32, 32, 3))
add("gear", D(32, 32, 12), H(32, 32, 5), burst(32, 32, 10, 26, 8, 8))
add("user", D(32, 16, 9), D(32, 46, 18), N(8, 52, 48, 20))
add("home", T(32, 6, 6, 32, 58, 32), B(16, 30, 32, 26), N(26, 40, 12, 16))
add("star", star(32, 32, 26, 11))
add("book", B(4, 18, 26, 34), B(34, 18, 26, 34), N(10, 26, 14, 3), N(10, 34, 14, 3), N(40, 26, 14, 3), N(40, 34, 14, 3))
add("flame", D(38, 42, 12), T(36, 4, 18, 40, 52, 36), T(16, 28, 6, 46, 28, 44), H(26, 40, 7))
add("bolt", T(36, 4, 12, 34, 30, 32), T(24, 28, 52, 30, 26, 60))
add("bell", D(32, 28, 16), N(8, 40, 48, 20), L(16, 38, 48, 38, 5), D(32, 48, 4), B(29, 8, 6, 8))
add("search", O(26, 26, 14, 5), L(36, 36, 54, 54, 6))
add("filter", T(8, 10, 56, 10, 32, 34), B(28, 32, 8, 20))
add("folder", B(12, 12, 18, 10), rbox(8, 18, 48, 34, 4))
add("mail", B(8, 16, 48, 32), N(14, 28, 36, 14), L(10, 18, 32, 40, 5), L(54, 18, 32, 40, 5))
add("lock", arc(32, 24, 12, -math.pi, 0, 5, 6), rbox(16, 28, 32, 26, 4), H(32, 40, 3), N(30, 40, 4, 8))
add("unlock", arc(26, 22, 11, -math.pi, -0.2, 5, 6), rbox(16, 30, 32, 24, 4), H(32, 40, 3))
add("eye", L(6, 32, 58, 32, 22), H(32, 32, 8))
add("hide", L(8, 32, 56, 32, 14), H(32, 32, 5), L(10, 12, 54, 52, 5))
add("check", L(12, 34, 26, 50, 6), L(26, 50, 54, 14, 6))
add("close", L(14, 14, 50, 50, 6), L(50, 14, 14, 50, 6))
add("plus", L(32, 12, 32, 52, 6), L(12, 32, 52, 32, 6))
add("minus", L(12, 32, 52, 32, 6))
add("up", T(32, 8, 10, 32, 54, 32), B(26, 30, 12, 26))
add("down", T(32, 56, 10, 32, 54, 32), B(26, 8, 12, 26))
add("left", T(8, 32, 32, 10, 32, 54), B(30, 26, 26, 12))
add("right", T(56, 32, 32, 10, 32, 54), B(8, 26, 26, 12))
add("play", T(16, 10, 16, 54, 52, 32))
add("pause", B(16, 12, 10, 40), B(38, 12, 10, 40))
add("stop", rbox(14, 14, 36, 36, 4))
add("menu", L(12, 18, 52, 18, 5), L(12, 32, 52, 32, 5), L(12, 46, 52, 46, 5))
add("dots", D(14, 32, 5), D(32, 32, 5), D(50, 32, 5))
add("chat", rbox(8, 8, 48, 34, 6), T(18, 38, 34, 38, 22, 56))
add("pin", D(32, 22, 12), H(32, 22, 5), T(32, 58, 20, 30, 44, 30))
add("flag", B(14, 8, 4, 48), T(18, 10, 50, 18, 18, 28))
add("crown", B(10, 36, 44, 12), T(8, 36, 22, 36, 12, 14), T(24, 36, 40, 36, 32, 10), T(42, 36, 56, 36, 52, 14), D(12, 16, 3), D(32, 12, 3), D(52, 16, 3))
add("gem", T(32, 6, 8, 26, 56, 26), T(8, 26, 56, 26, 32, 58), N(10, 28, 44, 4))
add("bow", arc(24, 32, 22, -1.2, 1.2, 4, 7), L(40, 12, 40, 52, 3), L(40, 32, 56, 32, 3), T(56, 32, 48, 28, 48, 36))
add("axe", L(18, 50, 40, 14, 5), T(34, 8, 56, 18, 36, 28), T(36, 26, 54, 20, 48, 36))
add("hammer", L(20, 48, 36, 16, 5), B(28, 8, 26, 14))
add("staff", L(32, 18, 32, 58, 5), D(32, 12, 8), H(32, 12, 3))
add("wand", L(16, 50, 44, 16, 4), star(48, 12, 10, 4))
add("dagger", T(32, 4, 25, 36, 39, 36), L(16, 36, 48, 36, 5), B(28, 38, 8, 14), D(32, 56, 4))
add("helmet", D(32, 26, 16), B(6, 30, 52, 8), N(22, 24, 20, 8), B(29, 6, 6, 12))
add("armor", B(18, 22, 28, 34), D(16, 26, 10), D(48, 26, 10), N(26, 26, 12, 10))
add("boot", B(16, 8, 18, 30), B(12, 34, 40, 16), D(48, 46, 8))
add("glove", rbox(16, 22, 28, 30, 8), B(18, 8, 6, 18), B(26, 6, 6, 18), B(34, 10, 6, 16), B(40, 28, 10, 8))
add("ring", O(32, 36, 14, 5), D(32, 16, 6), T(32, 8, 26, 18, 38, 18))
add("amulet", arc(32, 16, 16, -math.pi + 0.4, -0.4, 3, 6), D(32, 42, 12), H(32, 42, 5))
add("scroll", D(14, 32, 12), D(50, 32, 12), B(14, 22, 36, 20), N(22, 30, 18, 4))
add("quill", L(18, 54, 42, 16, 4), T(40, 8, 34, 22, 50, 16), T(16, 52, 28, 30, 8, 36))
add("inkwell", B(16, 30, 32, 24), B(22, 16, 20, 16), D(32, 16, 10), H(32, 42, 5))
add("map", L(8, 46, 22, 30, 5), L(22, 30, 34, 42, 5), L(34, 42, 48, 24, 5), L(40, 12, 56, 28, 5), L(56, 12, 40, 28, 5))
add("anchor", O(32, 14, 6, 4), L(32, 18, 32, 48, 5), L(16, 28, 48, 28, 5), arc(32, 40, 16, 0.15, math.pi - 0.15, 5, 7))
add("ship", poly([(8, 40), (56, 40), (46, 52), (18, 52)]), L(32, 12, 32, 40, 4), T(34, 14, 50, 26, 34, 32))
add("wheel", O(32, 32, 20, 5), L(32, 14, 32, 50, 4), L(14, 32, 50, 32, 4), D(32, 32, 4))
add("anvil", B(4, 22, 36, 14), B(36, 28, 20, 8), B(16, 36, 16, 8), B(8, 44, 32, 10))
add("pick", L(18, 50, 42, 18, 5), L(28, 16, 52, 28, 6), T(24, 12, 36, 8, 34, 22))
add("shovel", L(28, 14, 28, 40, 5), rbox(16, 36, 24, 18, 4))
add("torch", B(28, 42, 8, 16), D(32, 28, 12), T(32, 6, 16, 34, 48, 32), T(18, 22, 8, 38, 26, 34))
add("lantern", arc(32, 12, 10, -math.pi, 0, 4, 5), B(26, 12, 12, 6), poly([(18, 20), (46, 20), (40, 48), (24, 48)]), H(32, 34, 6), B(20, 48, 24, 6))
add("camp", L(12, 50, 52, 40, 6), L(12, 40, 52, 50, 6), D(32, 26, 7), T(32, 10, 22, 30, 42, 30), D(16, 56, 4), D(48, 56, 4))
add("tent", T(32, 8, 6, 54, 58, 54), N(26, 32, 12, 22), L(32, 10, 32, 54, 2))
add("bed", B(8, 28, 48, 8), B(8, 36, 6, 16), B(50, 36, 6, 16), rbox(14, 18, 16, 12, 4), B(12, 40, 40, 6))
add("door", D(32, 16, 14), B(18, 16, 28, 40), N(24, 22, 8, 16), N(24, 42, 8, 8), D(40, 36, 3))
add("ladder", L(18, 8, 18, 56, 5), L(46, 8, 46, 56, 5), L(18, 18, 46, 18, 4), L(18, 32, 46, 32, 4), L(18, 46, 46, 46, 4))
add("rope", O(32, 36, 12, 5), arc(32, 20, 14, -math.pi, 0, 5, 6), L(44, 18, 44, 8, 4))
add("bomb", D(30, 36, 16), L(40, 22, 50, 10, 4), D(52, 8, 4))
add("target", D(32, 32, 22), H(32, 32, 16), D(32, 32, 10), H(32, 32, 5))
add("sight", O(32, 32, 12, 4), L(32, 6, 32, 18, 3), L(32, 46, 32, 58, 3), L(6, 32, 18, 32, 3), L(46, 32, 58, 32, 3), D(32, 32, 2))
add("bullet", B(24, 20, 16, 28), T(24, 20, 40, 20, 32, 6), B(28, 48, 8, 8))
add("scope", O(30, 32, 16, 4), L(30, 12, 30, 52, 3), L(14, 32, 46, 32, 3), B(44, 28, 12, 8))
add("grenade", D(32, 36, 16), B(24, 16, 16, 8), L(40, 16, 52, 8, 3), D(52, 8, 3))
add("trap", B(8, 14, 48, 10), B(8, 40, 48, 10), T(16, 24, 24, 32, 32, 24), T(32, 24, 40, 32, 48, 24), T(16, 40, 24, 32, 32, 40), T(32, 40, 40, 32, 48, 40))
add("web", O(32, 32, 8, 2), O(32, 32, 16, 2), O(32, 32, 24, 2), burst(32, 32, 0, 24, 8, 2))
add("paw", D(32, 40, 14), D(16, 22, 6), D(26, 14, 6), D(40, 14, 6), D(50, 24, 6))
add("fish", D(42, 34, 14), T(12, 34, 32, 20, 32, 48), T(40, 20, 50, 8, 48, 24), H(50, 32, 3))
add("leaf", T(30, 8, 8, 40, 30, 52), T(30, 8, 52, 26, 30, 52), L(30, 48, 18, 60, 4), L(30, 16, 30, 48, 3))
add("tree", B(28, 36, 8, 20), D(32, 28, 14), D(22, 34, 10), D(42, 34, 10))
add("peak", T(20, 20, 4, 56, 40, 56), T(44, 8, 26, 56, 60, 56))
add("drop", D(32, 38, 14), T(32, 8, 18, 40, 46, 40))
add("snow", burst(32, 32, 6, 26, 6, 4), D(32, 32, 4))
add("sun", D(32, 32, 10), burst(32, 32, 14, 26, 8, 4))
add("moon", D(36, 32, 16), H(24, 26, 14))
add("cloud", D(24, 36, 12), D(40, 34, 14), D(32, 28, 10), B(16, 36, 32, 12))
add("rain", D(24, 26, 10), D(40, 24, 12), B(16, 26, 30, 10), L(22, 42, 18, 54, 3), L(32, 44, 28, 56, 3), L(42, 42, 38, 54, 3))
add("music", D(22, 46, 8), L(30, 46, 30, 14, 4), L(30, 14, 50, 20, 4), D(46, 28, 6))
add("headset", arc(32, 28, 18, -math.pi, 0, 5, 7), rbox(8, 28, 10, 18, 3), rbox(46, 28, 10, 18, 3))
add("mic", rbox(24, 8, 16, 28, 8), L(32, 36, 32, 48, 4), L(20, 50, 44, 50, 4), arc(32, 28, 16, 0, math.pi, 3, 5))
add("camera", rbox(8, 18, 48, 32, 4), D(32, 34, 10), H(32, 34, 4), B(16, 12, 14, 8))
add("image", L(8, 12, 56, 12, 4), L(8, 52, 56, 52, 4), L(8, 12, 8, 52, 4), L(56, 12, 56, 52, 4), T(14, 48, 30, 30, 40, 48), T(32, 48, 50, 24, 56, 48), D(18, 22, 4))
add("film", B(6, 10, 52, 44), N(16, 16, 32, 32), H(10, 18, 3), H(10, 32, 3), H(10, 46, 3), H(54, 18, 3), H(54, 32, 3), H(54, 46, 3))
add("clock", O(32, 32, 20, 5), L(32, 32, 32, 16, 4), L(32, 32, 44, 36, 4), D(32, 32, 3))

# --- batch 1: status, items, tools ---
add("medkit", B(8, 16, 48, 32), N(18, 24, 28, 16), L(32, 26, 32, 38, 5), L(22, 32, 42, 32, 5))
add("mana", T(32, 4, 16, 28, 48, 28), T(16, 26, 48, 26, 32, 60))
add("sprint", T(50, 32, 28, 14, 28, 50), L(6, 20, 24, 20, 4), L(4, 32, 24, 32, 4), L(8, 44, 24, 44, 4))
add("buff", T(32, 6, 10, 28, 54, 28), T(32, 24, 14, 46, 50, 46))
add("debuff", T(32, 58, 10, 36, 54, 36), T(32, 40, 14, 18, 50, 18))
add("poison", D(32, 40, 16), B(26, 8, 12, 18), H(24, 36, 3), H(40, 36, 3), N(26, 44, 12, 4))
add("ice", ngon(32, 32, 22, 6), N(28, 18, 8, 28))
add("ember", D(20, 40, 8), T(20, 22, 12, 40, 28, 40), D(40, 36, 7), T(40, 18, 32, 36, 48, 36), D(30, 22, 5))
add("heal", B(24, 6, 16, 52), B(6, 24, 52, 16))
add("fence", B(6, 10, 8, 44), B(50, 10, 8, 44), B(6, 18, 52, 8), B(6, 36, 52, 8))
add("crit", D(32, 32, 7), burst(32, 32, 8, 28, 12, 3))
add("dodge", arc(34, 34, 16, -2.4, 0.8, 5, 7), T(48, 18, 36, 16, 40, 30))
add("cloak", D(32, 18, 12), T(32, 14, 8, 56, 56, 56), H(32, 20, 5))
add("quest", B(28, 6, 8, 32), D(32, 50, 6))
add("warn", T(32, 6, 6, 56, 58, 56), N(29, 22, 6, 16), H(32, 46, 3))
add("info", D(32, 32, 22), H(32, 18, 3), N(29, 26, 6, 16))
add("bone", L(14, 50, 50, 14, 8), D(12, 52, 7), D(52, 12, 7), D(20, 42, 5), D(44, 22, 5))
add("ghost", D(32, 26, 16), B(16, 26, 32, 22), N(16, 42, 8, 12), N(28, 44, 8, 12), N(40, 42, 8, 12), H(24, 26, 3), H(40, 26, 3))
add("wing", T(4, 52, 58, 10, 16, 30), T(18, 46, 60, 24, 28, 26))
add("claw", T(8, 16, 22, 56, 26, 14), T(22, 8, 38, 56, 40, 10), T(40, 16, 54, 56, 58, 12))
add("fang", T(32, 6, 16, 36, 48, 36), B(20, 32, 24, 16))
add("horn", T(8, 52, 24, 28, 40, 48), T(20, 32, 36, 8, 48, 28))
add("scales", L(32, 10, 32, 54, 4), L(10, 16, 54, 16, 4), T(6, 18, 26, 18, 16, 40), T(38, 18, 58, 18, 48, 40), D(32, 16, 4))
add("elixir", B(27, 6, 10, 10), B(20, 16, 24, 28), D(32, 46, 14), N(24, 30, 16, 3))
add("meat", D(20, 42, 14), L(28, 34, 54, 12, 8), D(54, 10, 5))
add("bread", L(12, 36, 52, 36, 20), N(22, 26, 3, 18), N(32, 24, 3, 20), N(42, 26, 3, 18))
add("apple", D(32, 36, 16), B(30, 8, 5, 12), D(42, 16, 5))
add("cheese", T(8, 14, 56, 24, 8, 52), H(24, 30, 4), H(20, 40, 3))
add("egg", L(32, 18, 32, 48, 24), N(22, 22, 14, 3))
add("shroom", D(32, 22, 16), B(28, 26, 8, 26), H(22, 18, 3), H(40, 22, 3))
add("carrot", T(36, 8, 14, 52, 48, 46), D(20, 12, 6), D(30, 6, 5))
add("hook", arc(34, 30, 16, -2.8, 1.1, 5, 7), L(34, 14, 34, 6, 5), T(46, 40, 40, 32, 52, 28))
add("net", L(12, 16, 52, 16, 3), L(12, 32, 52, 32, 3), L(12, 48, 52, 48, 3), L(16, 10, 16, 54, 3), L(32, 10, 32, 54, 3), L(48, 10, 48, 54, 3))
add("barrel", B(18, 10, 28, 44), D(18, 18, 8), D(46, 18, 8), D(18, 46, 8), D(46, 46, 8), L(10, 32, 54, 32, 4))
add("crate", L(8, 8, 56, 8, 4), L(8, 56, 56, 56, 4), L(8, 8, 8, 56, 4), L(56, 8, 56, 56, 4), L(8, 8, 56, 56, 4), L(56, 8, 8, 56, 4))
add("ingot", B(14, 28, 36, 18), T(14, 28, 6, 46, 14, 46), T(50, 28, 58, 46, 50, 46))
add("ore", D(26, 34, 14), D(42, 30, 12), D(36, 46, 10))
add("log", L(10, 32, 54, 32, 18), H(16, 32, 6))
add("stone", D(28, 36, 14), D(44, 34, 10), B(22, 30, 18, 16))
add("brick", B(6, 10, 24, 16), B(34, 10, 24, 16), B(6, 32, 48, 18))
add("nail", T(32, 6, 22, 20, 42, 20), L(32, 16, 32, 58, 5))
add("screw", L(32, 18, 32, 56, 6), D(32, 12, 8), L(18, 28, 46, 24, 4), L(18, 40, 46, 36, 4))
add("wrench", L(12, 50, 36, 22, 6), O(48, 16, 10, 5), N(46, 6, 14, 12))
add("nut", ngon(32, 32, 22, 6), H(32, 32, 8))
add("needle", L(14, 52, 46, 14, 3), O(48, 12, 6, 3))
add("spool", B(24, 16, 16, 32), D(20, 18, 10), D(44, 18, 10), D(20, 46, 10), D(44, 46, 10))
add("cloth", B(10, 14, 44, 26), T(10, 40, 28, 32, 10, 56), T(54, 40, 36, 32, 54, 56))
add("pelt", D(32, 38, 16), T(16, 28, 6, 8, 26, 30), T(48, 28, 58, 8, 38, 30))
add("feather", T(34, 6, 12, 46, 34, 58), T(34, 6, 54, 36, 34, 58))
add("arrow", L(8, 32, 36, 32, 4), T(52, 32, 32, 18, 32, 46), T(8, 32, 18, 24, 18, 40))
add("quiver", B(26, 14, 14, 40), T(22, 8, 48, 12, 30, 20), T(20, 10, 28, 4, 30, 14), L(16, 24, 12, 52, 3))
add("spear", L(32, 16, 32, 58, 4), T(32, 4, 22, 22, 42, 22))
add("mace", L(32, 28, 32, 58, 5), D(32, 18, 12), D(32, 6, 4), D(18, 14, 4), D(46, 14, 4), D(16, 24, 4), D(48, 24, 4))
add("flail", B(28, 46, 8, 12), O(32, 36, 4, 3), O(32, 26, 4, 3), D(32, 14, 8))
add("whip", B(12, 44, 8, 14), arc(30, 36, 18, -2.6, 0.6, 4, 8))
add("sickle", L(18, 28, 18, 58, 5), arc(34, 28, 16, -1.2, 2.2, 5, 7))
add("scythe", L(14, 54, 46, 10, 4), arc(40, 22, 16, 0.4, 2.6, 5, 6))
add("hoe", L(36, 8, 36, 44, 5), B(8, 40, 36, 8))
add("rake", L(28, 20, 28, 58, 4), B(8, 12, 44, 6), L(12, 12, 12, 24, 3), L(24, 12, 24, 24, 3), L(36, 12, 36, 24, 3), L(48, 12, 48, 24, 3))
add("can", B(12, 22, 28, 28), L(40, 28, 56, 12, 5), arc(20, 30, 12, -math.pi, -0.4, 4, 5), D(46, 40, 3), D(54, 50, 3))
add("seed", D(34, 38, 10), T(34, 16, 24, 36, 40, 32), L(34, 44, 28, 56, 3))
add("flower", D(32, 32, 6), D(32, 14, 8), D(32, 50, 8), D(14, 32, 8), D(50, 32, 8))
add("clover", D(32, 20, 10), D(18, 36, 10), D(46, 36, 10), L(32, 40, 32, 58, 3))
add("cactus", B(28, 12, 8, 40), B(14, 22, 16, 6), B(14, 14, 6, 14), B(42, 28, 12, 6), B(48, 20, 6, 14))
add("herb", L(32, 16, 32, 58, 3), D(22, 26, 7), D(44, 34, 7), D(24, 44, 6))
add("vial", B(28, 4, 8, 12), B(22, 14, 20, 30), D(32, 46, 12))
add("kettle", D(32, 40, 16), N(10, 48, 44, 16), B(18, 18, 28, 8), arc(32, 22, 16, -math.pi, -0.2, 4, 5))
add("mortar", arc(32, 36, 16, 0.2, math.pi - 0.2, 6, 7), L(36, 28, 54, 10, 5))
add("rune", B(16, 8, 32, 48), N(28, 16, 8, 10), N(22, 30, 18, 6), N(30, 42, 8, 8))
add("shard", T(22, 6, 8, 36, 34, 58), T(42, 4, 30, 40, 56, 54))
add("orb", D(32, 32, 18), H(32, 32, 10), D(32, 32, 4))
add("totem", B(22, 4, 20, 56), H(28, 14, 3), H(36, 14, 3), H(28, 32, 3), H(36, 32, 3), N(26, 44, 12, 4))
add("idol", D(32, 14, 8), T(32, 22, 12, 56, 52, 56))
add("grave", B(26, 2, 12, 16), B(18, 6, 28, 6), B(16, 26, 32, 32))
add("coffin", B(18, 18, 28, 28), T(18, 18, 46, 18, 32, 4), T(18, 46, 46, 46, 32, 60))
add("candle", B(28, 24, 8, 26), T(32, 6, 24, 26, 40, 26), B(20, 48, 24, 8))
add("hour", T(10, 6, 54, 6, 32, 32), T(10, 58, 54, 58, 32, 32))
add("timer", O(32, 36, 16, 4), B(28, 6, 8, 8), L(32, 36, 32, 24, 3), L(32, 36, 42, 40, 3))
add("alarm", D(18, 16, 7), D(46, 16, 7), O(32, 38, 14, 4), L(32, 38, 32, 28, 3), L(18, 50, 12, 58, 4), L(46, 50, 52, 58, 4))
add("cal", B(10, 14, 44, 40), B(10, 14, 44, 12), D(20, 12, 4), D(44, 12, 4), N(18, 34, 8, 8), N(30, 34, 8, 8), N(42, 34, 8, 8))
add("ribbon", B(22, 6, 20, 40), T(22, 46, 32, 34, 22, 58), T(42, 46, 32, 34, 42, 58))
add("link", O(22, 32, 12, 5), O(44, 32, 12, 5))
add("split", O(16, 32, 12, 5), O(48, 32, 12, 5))
add("share", D(14, 42, 6), D(50, 16, 6), D(50, 48, 6), L(18, 40, 46, 20, 3), L(18, 44, 46, 46, 3))
add("fetch", T(32, 8, 16, 28, 48, 28), B(26, 24, 12, 14), L(8, 50, 56, 50, 5), L(8, 40, 8, 50, 4), L(56, 40, 56, 50, 4))
add("send", T(32, 56, 16, 36, 48, 36), B(26, 16, 12, 22), L(8, 14, 56, 14, 5), L(8, 14, 8, 24, 4), L(56, 14, 56, 24, 4))
add("disk", rbox(10, 6, 44, 52, 4), N(16, 8, 32, 14), B(18, 36, 20, 16))
add("trash", T(12, 16, 52, 16, 32, 8), L(10, 14, 54, 14, 4), B(16, 20, 32, 34), N(24, 28, 4, 18), N(36, 28, 4, 18))
add("pencil", L(14, 50, 44, 16, 6), T(46, 8, 36, 22, 54, 18), D(12, 54, 5))
add("copy", L(16, 16, 48, 16, 4), L(16, 48, 48, 48, 4), L(16, 16, 16, 48, 4), L(48, 16, 48, 48, 4), L(8, 8, 40, 8, 3), L(8, 40, 40, 40, 3), L(8, 8, 8, 40, 3), L(40, 8, 40, 40, 3))
add("paste", B(14, 14, 36, 42), B(22, 6, 20, 12), N(20, 24, 24, 4), N(20, 34, 20, 4), N(20, 44, 16, 4))
add("scissors", O(18, 46, 8, 4), O(40, 46, 8, 4), L(22, 40, 50, 8, 4), L(36, 40, 10, 8, 4))
add("undo", arc(36, 30, 14, -0.4, 2.8, 5, 7), T(16, 18, 8, 32, 26, 30))
add("redo", arc(28, 30, 14, 0.3, 3.5, 5, 7), T(48, 18, 38, 30, 56, 32))
add("crop", L(8, 8, 8, 26, 4), L(8, 8, 26, 8, 4), L(56, 8, 38, 8, 4), L(56, 8, 56, 26, 4), L(8, 56, 8, 38, 4), L(8, 56, 26, 56, 4), L(56, 56, 56, 38, 4), L(56, 56, 38, 56, 4))
add("magnet", B(10, 12, 14, 22), B(40, 12, 14, 22), arc(32, 34, 18, 0, math.pi, 8, 7))
add("battery", rbox(8, 18, 40, 28, 4), B(48, 26, 8, 12), N(14, 24, 8, 16), N(26, 24, 8, 16))
add("plug", B(12, 28, 22, 16), L(34, 32, 52, 20, 5), L(34, 40, 52, 48, 5), D(54, 18, 4), D(54, 50, 4))
add("wifi", arc(32, 40, 8, -math.pi, 0, 4, 4), arc(32, 40, 16, -math.pi + 0.2, -0.2, 4, 5), arc(32, 40, 24, -math.pi + 0.3, -0.3, 4, 6), D(32, 46, 4))
add("bug", D(32, 36, 12), D(32, 16, 7), L(14, 20, 6, 12, 3), L(50, 20, 58, 12, 3), L(16, 32, 6, 36, 3), L(48, 32, 58, 36, 3), L(16, 44, 6, 54, 3), L(48, 44, 58, 54, 3))


def bounds(cmds):
    xs = []
    ys = []

    def push(x, y):
        xs.append(x)
        ys.append(y)

    for c in cmds:
        op = c[0]
        if op in ("disc", "punch"):
            _, cx, cy, r = c
            push(cx - r, cy - r)
            push(cx + r, cy + r)
        elif op in ("box", "notch"):
            _, x, y, w, h = c
            push(x, y)
            push(x + w, y + h)
        elif op == "tri":
            _, x0, y0, x1, y1, x2, y2 = c
            push(x0, y0)
            push(x1, y1)
            push(x2, y2)
        elif op == "bar":
            _, x0, y0, x1, y1, t = c
            rad = t * 0.5
            push(x0 - rad, y0 - rad)
            push(x0 + rad, y0 + rad)
            push(x1 - rad, y1 - rad)
            push(x1 + rad, y1 + rad)
        elif op == "ring":
            _, cx, cy, r, t = c
            rad = r + t * 0.5
            push(cx - rad, cy - rad)
            push(cx + rad, cy + rad)
    return min(xs), min(ys), max(xs), max(ys)


def fit(cmds, margin=4):
    x0, y0, x1, y1 = bounds(cmds)
    bw = max(1.0, x1 - x0)
    bh = max(1.0, y1 - y0)
    s = min((64 - 2 * margin) / bw, (64 - 2 * margin) / bh)
    dx = (64 - bw * s) / 2 - x0 * s
    dy = (64 - bh * s) / 2 - y0 * s

    def xy(x, y):
        return x * s + dx, y * s + dy

    out = []
    for c in cmds:
        op = c[0]
        if op in ("disc", "punch"):
            _, cx, cy, r = c
            nx, ny = xy(cx, cy)
            out.append((op, nx, ny, r * s))
        elif op in ("box", "notch"):
            _, x, y, w, h = c
            nx, ny = xy(x, y)
            out.append((op, nx, ny, w * s, h * s))
        elif op == "tri":
            _, a, b, c1, d, e, f = c
            a, b = xy(a, b)
            c1, d = xy(c1, d)
            e, f = xy(e, f)
            out.append((op, a, b, c1, d, e, f))
        elif op == "bar":
            _, a, b, c1, d, t = c
            a, b = xy(a, b)
            c1, d = xy(c1, d)
            out.append((op, a, b, c1, d, max(4.0, t * s)))
        elif op == "ring":
            _, cx, cy, r, t = c
            nx, ny = xy(cx, cy)
            out.append((op, nx, ny, r * s, max(3.0, t * s)))
    return out


OPS = {"disc": 1, "box": 2, "tri": 3, "bar": 4, "ring": 5, "punch": 6, "notch": 7}
WIDTH = {"disc": 4, "punch": 4, "box": 5, "notch": 5, "tri": 7, "bar": 6, "ring": 5}


def encode(cmds):
    raw = []
    for c in fit(cmds):
        op = c[0]
        nums = []
        for a in c[1:]:
            v = int(round(a))
            if v < 0:
                v = 0
            if v > 64:
                v = 64
            nums.append(v)
        raw.append(OPS[op])
        raw.extend(nums)
        need = WIDTH[op] - 1
        if len(nums) != need:
            raise SystemExit(f"bad arity {op} {nums}")
    return raw


def emit_batch(batch, icons):
    blobs = [encode(cmds) for _, cmds in icons]
    seen = {}
    for (name, _), blob in zip(icons, blobs):
        key = tuple(blob)
        if key in seen:
            raise SystemExit(f"duplicate geometry {name} == {seen[key]}")
        seen[key] = name
    names = [n for n, _ in icons]
    if len(names) != len(set(names)):
        raise SystemExit("duplicate name")
    ops = []
    at = [0]
    for blob in blobs:
        ops.extend(blob)
        at.append(len(ops))
    lines = []
    lines.append(f"// Named pictograms, batch {batch}. Generated from pictogram_src.py.")
    lines.append("namespace uikit;")
    lines.append("")
    lines.append(f"let ICON_N{batch} = {len(icons)};")
    def chunks(vals, n):
        rows = []
        for i in range(0, len(vals), n):
            rows.append(", ".join(str(v) for v in vals[i:i + n]))
        return rows

    lines.append(f"let ICON_OPS{batch} byte[{len(ops)}] = [")
    op_rows = chunks(ops, 24)
    for i, row in enumerate(op_rows):
        lines.append(f"\t{row}{',' if i + 1 < len(op_rows) else ''}")
    lines.append("];")
    lines.append(f"let ICON_AT{batch} int[{len(at)}] = [")
    at_rows = chunks(at, 16)
    for i, row in enumerate(at_rows):
        lines.append(f"\t{row}{',' if i + 1 < len(at_rows) else ''}")
    lines.append("];")
    lines.append("")
    lines.append(f"fn icon_name_{batch}(i int) const byte[:] {{")
    for i, name in enumerate(names):
        lines.append(f'\tif i == {i} {{ return "{name}"; }}')
    lines.append(f'\t"{names[0]}"')
    lines.append("}")
    lines.append("")
    path = os.path.join(ROOT, f"icons_b{batch}.amni")
    with open(path, "w", encoding="utf-8") as f:
        f.write("\n".join(lines))
    print(f"wrote {path} icons={len(icons)} bytes={len(ops)}")


def main():
    if len(ICONS) % 100 != 0:
        raise SystemExit(f"need multiples of 100, have {len(ICONS)}")
    for b in range(len(ICONS) // 100):
        emit_batch(b, ICONS[b * 100:(b + 1) * 100])


if __name__ == "__main__":
    main()
