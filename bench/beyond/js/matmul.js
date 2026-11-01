// matmul: n x n f64 matrix product, i-k-j loop order. Prints the sum and one element.
const N = (d) => (process.argv.length > 2 ? parseInt(process.argv[2], 10) : d);
const n = N(100);
const a = new Float64Array(n * n), b = new Float64Array(n * n), c = new Float64Array(n * n);
for (let i = 0; i < n; i++) for (let j = 0; j < n; j++) {
	a[i * n + j] = ((i * 31 + j * 17) % 100) / 100.0;
	b[i * n + j] = ((i * 13 + j * 29) % 100) / 50.0 - 1.0;
}
for (let i = 0; i < n; i++) for (let k = 0; k < n; k++) {
	const aik = a[i * n + k];
	for (let j = 0; j < n; j++) c[i * n + j] += aik * b[k * n + j];
}
let s = 0; for (let i = 0; i < n * n; i++) s += c[i];
console.log(s.toFixed(6) + " " + c[Math.floor(n / 2) * n + Math.floor(n / 3)].toFixed(9));
