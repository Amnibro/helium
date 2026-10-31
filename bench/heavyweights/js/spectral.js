function A(i, j) { return 1 / (((i + j) * (i + j + 1)) / 2 + i + 1); }
function mulAv(v, av) { const n = v.length; for (let i = 0; i < n; i++) { let s = 0; for (let j = 0; j < n; j++) s += A(i, j) * v[j]; av[i] = s; } }
function mulAtv(v, atv) { const n = v.length; for (let i = 0; i < n; i++) { let s = 0; for (let j = 0; j < n; j++) s += A(j, i) * v[j]; atv[i] = s; } }
const n = +(process.argv[2] ?? 100);
const u = new Float64Array(n).fill(1), v = new Float64Array(n), t = new Float64Array(n);
for (let k = 0; k < 10; k++) { mulAv(u, t); mulAtv(t, v); mulAv(v, t); mulAtv(t, u); }
let vbv = 0, vv = 0;
for (let i = 0; i < n; i++) { vbv += u[i] * v[i]; vv += v[i] * v[i]; }
console.log(Math.sqrt(vbv / vv).toFixed(9));
