class Node { constructor(l, r) { this.l = l; this.r = r; } }
function make(d) { return d > 0 ? new Node(make(d - 1), make(d - 1)) : new Node(null, null); }
function check(n) { return n.l === null ? 1 : 1 + check(n.l) + check(n.r); }
const n = +(process.argv[2] ?? 10), mind = 4, maxd = Math.max(mind + 2, n);
console.log(`stretch tree of depth ${maxd + 1}\t check: ${check(make(maxd + 1))}`);
const lng = make(maxd);
for (let d = mind; d <= maxd; d += 2) {
  const it = 2 ** (maxd - d + mind); let chk = 0;
  for (let i = 0; i < it; i++) chk += check(make(d));
  console.log(`${it}\t trees of depth ${d}\t check: ${chk}`);
}
console.log(`long lived tree of depth ${maxd}\t check: ${check(lng)}`);
