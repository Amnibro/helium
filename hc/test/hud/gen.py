import glob, json, os, random, re, subprocess, sys
OUT = sys.argv[1]
N = int(sys.argv[2]) if len(sys.argv) > 2 else 300
SEED = int(sys.argv[3]) if len(sys.argv) > 3 else 7
CH = sorted(glob.glob(os.path.expanduser("~/.cache/ms-playwright/chromium_headless_shell-*/*/chrome-headless-shell")))[-1]
J = ["flex-start", "flex-end", "center", "space-between", "space-around", "space-evenly"]
A = ["flex-start", "flex-end", "center", "stretch"]
def node(r, depth, root):
	n = {"dir": r.randint(0, 1), "jus": r.randint(0, 5), "ali": r.randint(0, 3), "gap": r.randint(0, 12), "pad": r.randint(0, 10), "mar": 0 if root else r.randint(0, 8)}
	def size():
		k = r.random()
		return (0, 0) if k < 0.4 else ((1, r.randint(10, 200)) if k < 0.8 else (2, r.randint(10, 100)))
	n["w"], n["h"] = ((1, 400), (1, 300)) if root else (size(), size())
	n["grow"] = 0 if root else r.choice([0, 0, 1, 2, 3])
	n["shrink"] = 1 if root else r.choice([0, 1, 1, 2])
	n["basis"] = -1 if root or r.random() < 0.6 else r.randint(0, 150)
	def lim():
		return -1 if r.random() < 0.8 else r.randint(10, 160)
	n["minw"], n["maxw"], n["minh"], n["maxh"] = (-1, -1, -1, -1) if root else (lim(), lim(), lim(), lim())
	if n["maxw"] >= 0 and n["minw"] > n["maxw"]: n["minw"], n["maxw"] = n["maxw"], n["minw"]
	if n["maxh"] >= 0 and n["minh"] > n["maxh"]: n["minh"], n["maxh"] = n["maxh"], n["minh"]
	n["abs"] = 0; n["l"] = n["t"] = n["rr"] = -1
	if not root and r.random() < 1 / 6:
		n["abs"] = 1; n["l"] = r.randint(0, 60); n["t"] = r.randint(0, 60); n["mar"] = 0
		if r.random() < 0.5: n["w"] = (1, r.randint(10, 120)); n["h"] = (1, r.randint(10, 120))
		else: n["rr"] = r.randint(0, 60); n["w"] = (0, 0); n["h"] = (1, r.randint(10, 120))
	n["kids"] = [] if depth >= 3 else [node(r, depth + 1, False) for _ in range(r.randint(0 if depth else 1, 5))]
	return n
def css(n, root):
	s = ["display:flex", "position:" + ("absolute" if n["abs"] else "relative"), "box-sizing:border-box", "flex-direction:" + ("row" if n["dir"] == 0 else "column"), "justify-content:" + J[n["jus"]], "align-items:" + A[n["ali"]], "gap:%dpx" % n["gap"], "padding:%dpx" % n["pad"], "margin:%dpx" % n["mar"], "flex-grow:%d" % n["grow"], "flex-shrink:%d" % n["shrink"], "flex-basis:" + ("auto" if n["basis"] < 0 else "%dpx" % n["basis"])]
	for k, v in (("width", n["w"]), ("height", n["h"])):
		if v[0] == 1: s.append("%s:%dpx" % (k, v[1]))
		elif v[0] == 2: s.append("%s:%d%%" % (k, v[1]))
	s.append("min-width:%s" % ("%dpx" % n["minw"] if n["minw"] >= 0 else "0"))
	s.append("min-height:%s" % ("%dpx" % n["minh"] if n["minh"] >= 0 else "0"))
	if n["maxw"] >= 0: s.append("max-width:%dpx" % n["maxw"])
	if n["maxh"] >= 0: s.append("max-height:%dpx" % n["maxh"])
	if n["abs"]:
		s.append("left:%dpx;top:%dpx" % (n["l"], n["t"]))
		if n["rr"] >= 0: s.append("right:%dpx" % n["rr"])
	return ";".join(s)
def html(n, root=True):
	return '<div class="n" style="%s">%s</div>' % (css(n, root), "".join(html(k, False) for k in n["kids"]))
def flat(n, parent, out):
	i = len(out)
	out.append((parent, n))
	for k in n["kids"]: flat(k, i, out)
r = random.Random(SEED)
trees = [node(r, 0, True) for _ in range(N)]
body = "".join('<div class="t" style="position:relative;width:400px;height:300px;margin-bottom:20px">%s</div>' % html(t) for t in trees)
page = '<html><body style="margin:0">%s<pre id="o"></pre><script>let r=[];for(const t of document.querySelectorAll(".t")){const o=t.getBoundingClientRect();const a=[];for(const e of t.querySelectorAll(".n")){const b=e.getBoundingClientRect();a.push([b.left-o.left,b.top-o.top,b.width,b.height].map(x=>x.toFixed(4)).join(","))}r.push(a.join(";"))}document.getElementById("o").textContent=r.join("|")</script></body></html>' % body
os.makedirs(OUT, exist_ok=True)
open(os.path.join(OUT, "trees.html"), "w").write(page)
dom = subprocess.run([CH, "--no-sandbox", "--disable-gpu", "--dump-dom", "file://" + os.path.join(OUT, "trees.html")], capture_output=True, text=True, timeout=120).stdout
res = re.search(r'<pre id="o">([^<]*)', dom).group(1).split("|")
with open(os.path.join(OUT, "trees.txt"), "w") as f:
	for t, line in zip(trees, res):
		nodes = []
		flat(t, -1, nodes)
		rects = line.split(";")
		f.write("tree %d\n" % len(nodes))
		for (p, n), rc in zip(nodes, rects):
			f.write(" ".join(str(x) for x in [p, n["dir"], n["jus"], n["ali"], n["gap"], n["pad"], n["mar"], n["w"][0], n["w"][1], n["h"][0], n["h"][1], n["grow"], n["shrink"], n["basis"], n["minw"], n["maxw"], n["minh"], n["maxh"], n["abs"], n["l"], n["t"], n["rr"]]) + " " + rc.replace(",", " ") + "\n")
print("trees", len(res))
