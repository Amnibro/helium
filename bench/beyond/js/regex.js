// regex: backtracking matcher for literals . * + ? ^ $ (Pike style, leftmost, any match),
// run over n generated lines for six patterns. Prints the match count of each pattern.
const N = (d) => (process.argv.length > 2 ? parseInt(process.argv[2], 10) : d);
let rs = 2463534242;
function rnd() { rs ^= rs << 13; rs >>>= 0; rs ^= rs >>> 17; rs ^= rs << 5; rs >>>= 0; return rs; }
let re, B, T0 = 0, TL = 0;
function one(c, t) { return t < TL && (c === 46 || c === B[T0 + t]); }
function star(c, r, t) { for (;;) { if (here(r, t)) return true; if (!one(c, t)) return false; t++; } }
function here(r, t) {
	const rl = re.length;
	if (r === rl) return true;
	if (r + 1 < rl && re[r + 1] === 42) return star(re[r], r + 2, t);
	if (r + 1 < rl && re[r + 1] === 43) return one(re[r], t) && star(re[r], r + 2, t + 1);
	if (r + 1 < rl && re[r + 1] === 63) { if (one(re[r], t) && here(r + 2, t + 1)) return true; return here(r + 2, t); }
	if (re[r] === 36 && r + 1 === rl) return t === TL;
	if (one(re[r], t)) return here(r + 1, t + 1);
	return false;
}
function match() {
	if (re.length > 0 && re[0] === 94) return here(1, 0);
	for (let t = 0; t <= TL; t++) if (here(0, t)) return true;
	return false;
}
const n = N(1000);
const pats = ["ab*c", "^a.*f$", "c.d.e", "fa+b?c", "e.*e.*e.*a", "dd*ee*ff*a$"];
B = new Uint8Array(n * 60); const off = new Int32Array(n + 1);
let pos = 0;
for (let i = 0; i < n; i++) { off[i] = pos; const k = 20 + rnd() % 40; for (let j = 0; j < k; j++) B[pos++] = 97 + rnd() % 6; }
off[n] = pos;
const out = [];
for (const p of pats) {
	re = Buffer.from(p, "latin1"); let c = 0;
	for (let i = 0; i < n; i++) { T0 = off[i]; TL = off[i + 1] - off[i]; if (match()) c++; }
	out.push(c);
}
console.log(out.join(" "));
