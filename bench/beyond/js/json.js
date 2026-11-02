// json: generate a JSON array of n records, then parse it with a generic recursive-descent
// parser. Prints the sum of all numbers, total string bytes, trues, objects and arrays.
const N = (d) => (process.argv.length > 2 ? parseInt(process.argv[2], 10) : d);
let rs = 2463534242;
function rnd() { rs ^= rs << 13; rs >>>= 0; rs ^= rs >>> 17; rs ^= rs << 5; rs >>>= 0; return rs; }
const n = N(1000);
const parts = ["["];
for (let i = 0; i < n; i++) {
	if (i > 0) parts.push(",\n");
	const a = rnd() % 100, b = rnd() % 100, x = rnd() % 10000, y = (rnd() % 10000) - 5000, ok = rnd() & 1;
	parts.push('{"id":' + i + ',"name":"item' + i + '","tags":["t' + a + '","t' + b + '"],"pos":{"x":' + x + ',"y":' + y + '},"ok":' + (ok ? "true" : "false") + "}");
}
parts.push("]");
const D = Buffer.from(parts.join(""), "latin1");
let P = 0, nums = 0, strs = 0, trues = 0, objs = 0, arrs = 0;
function ws() { while (P < D.length && (D[P] === 32 || D[P] === 10 || D[P] === 9 || D[P] === 13)) P++; }
function str() { P++; const s = P; while (D[P] !== 34) { if (D[P] === 92) P++; P++; } strs += P - s; P++; }
function value() {
	ws();
	const c = D[P];
	if (c === 123) {
		objs++; P++; ws();
		if (D[P] === 125) { P++; return; }
		for (;;) { ws(); str(); ws(); P++; value(); ws(); if (D[P] === 44) { P++; continue; } P++; return; }
	} else if (c === 91) {
		arrs++; P++; ws();
		if (D[P] === 93) { P++; return; }
		for (;;) { value(); ws(); if (D[P] === 44) { P++; continue; } P++; return; }
	} else if (c === 34) str();
	else if (c === 116) { trues++; P += 4; }
	else if (c === 102) P += 5;
	else if (c === 110) P += 4;
	else {
		let neg = false; if (D[P] === 45) { neg = true; P++; }
		let v = 0; while (P < D.length && D[P] >= 48 && D[P] <= 57) { v = v * 10 + (D[P] - 48); P++; }
		nums += neg ? -v : v;
	}
}
value();
console.log([D.length, nums, strs, trues, objs, arrs].join(" "));
