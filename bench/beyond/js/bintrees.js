// bintrees: arena binary trees. Nodes are index pairs in one array; each tree is built
// bottom-up into the arena after the long-lived tree and released by resetting the top.
const N = (d) => (process.argv.length > 2 ? parseInt(process.argv[2], 10) : d);
let L, R, top = 0;
function build(d) {
	const i = top++;
	if (d > 0) { const l = build(d - 1); const r = build(d - 1); L[i] = l; R[i] = r; }
	else { L[i] = -1; R[i] = -1; }
	return i;
}
function check(i) { return L[i] < 0 ? 1 : 1 + check(L[i]) + check(R[i]); }
let maxd = Math.max(6, N(10));
const cap = 2 * 2 ** (maxd + 1) + 2 * 2 ** maxd;
L = new Int32Array(cap); R = new Int32Array(cap);
const s = build(maxd + 1);
console.log("stretch tree of depth " + (maxd + 1) + "\t check: " + check(s));
top = 0;
const lived = build(maxd);
const mark = top;
for (let d = 4; d <= maxd; d += 2) {
	const iters = 2 ** (maxd - d + 4); let c = 0;
	for (let k = 0; k < iters; k++) { top = mark; c += check(build(d)); }
	console.log(iters + "\t trees of depth " + d + "\t check: " + c);
}
console.log("long lived tree of depth " + maxd + "\t check: " + check(lived));
