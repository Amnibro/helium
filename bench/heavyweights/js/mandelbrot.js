const n = +(process.argv[2] ?? 200);
let count = 0;
for (let y = 0; y < n; y++) {
  const ci = (2.0 * y) / n - 1.0;
  for (let x = 0; x < n; x++) {
    const cr = (2.0 * x) / n - 1.5;
    let zr = 0, zi = 0, tr = 0, ti = 0, i = 0;
    while (i < 50 && tr + ti <= 4.0) { zi = 2.0 * zr * zi + ci; zr = tr - ti + cr; tr = zr * zr; ti = zi * zi; i++; }
    if (tr + ti <= 4.0) count++;
  }
}
console.log(count);
