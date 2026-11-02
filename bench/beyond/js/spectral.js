// spectral: power method on A(i,j) = 1/((i+j)(i+j+1)/2+i+1), 10 rounds of v = AtA u.
const N = (d) => (process.argv.length > 2 ? parseInt(process.argv[2], 10) : d);
function a(i, j) { return 1.0 / ((i + j) * (i + j + 1) / 2 + i + 1); }
function mulAv(v, out) { const n = v.length; for (let i = 0; i < n; i++) { let s = 0; for (let j = 0; j < n; j++) s += a(i, j) * v[j]; out[i] = s; } }
function mulAtv(v, out) { const n = v.length; for (let i = 0; i < n; i++) { let s = 0; for (let j = 0; j < n; j++) s += a(j, i) * v[j]; out[i] = s; } }
function mulAtAv(v, out, tmp) { mulAv(v, tmp); mulAtv(tmp, out); }
const n = N(100);
const u = new Float64Array(n).fill(1), v = new Float64Array(n), t = new Float64Array(n);
for (let k = 0; k < 10; k++) { mulAtAv(u, v, t); mulAtAv(v, u, t); }
let vbv = 0, vv = 0;
for (let i = 0; i < n; i++) { vbv += u[i] * v[i]; vv += v[i] * v[i]; }
console.log(Math.sqrt(vbv / vv).toFixed(9));
