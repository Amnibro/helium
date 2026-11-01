// sort: bottom-up merge sort of n xorshift32 values. Prints a position-weighted checksum
// modulo 1e9+7 and whether the result is ordered.
const N = (d) => (process.argv.length > 2 ? parseInt(process.argv[2], 10) : d);
let rs = 2463534242;
function rnd() { rs ^= rs << 13; rs >>>= 0; rs ^= rs >>> 17; rs ^= rs << 5; rs >>>= 0; return rs; }
const n = N(1000);
let src = new Uint32Array(n), dst = new Uint32Array(n);
for (let i = 0; i < n; i++) src[i] = rnd();
for (let w = 1; w < n; w *= 2) {
	for (let lo = 0; lo < n; lo += 2 * w) {
		const mid = Math.min(lo + w, n), hi = Math.min(lo + 2 * w, n);
		let i = lo, j = mid, k = lo;
		while (i < mid && j < hi) dst[k++] = src[i] <= src[j] ? src[i++] : src[j++];
		while (i < mid) dst[k++] = src[i++];
		while (j < hi) dst[k++] = src[j++];
	}
	const t = src; src = dst; dst = t;
}
let h = 0, ok = 1;
for (let i = 0; i < n; i++) { h = (h + src[i] * (i % 1000 + 1)) % 1000000007; if (i > 0 && src[i - 1] > src[i]) ok = 0; }
console.log(h + " " + ok);
