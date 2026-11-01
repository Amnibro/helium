const n = +(process.argv[2] ?? 7);
const perm = new Int32Array(32), perm1 = new Int32Array(32), count = new Int32Array(32);
let maxFlips = 0, checksum = 0, permCount = 0, r = n;
for (let i = 0; i < n; i++) perm1[i] = i;
outer: for (;;) {
  while (r !== 1) { count[r - 1] = r; r--; }
  for (let i = 0; i < n; i++) perm[i] = perm1[i];
  let flips = 0, k;
  while ((k = perm[0]) !== 0) { const k2 = (k + 1) >> 1; for (let i = 0; i < k2; i++) { const t = perm[i]; perm[i] = perm[k - i]; perm[k - i] = t; } flips++; }
  if (flips > maxFlips) maxFlips = flips;
  checksum += permCount % 2 === 0 ? flips : -flips;
  for (;;) {
    if (r === n) break outer;
    const p0 = perm1[0];
    for (let i = 0; i < r; i++) perm1[i] = perm1[i + 1];
    perm1[r] = p0;
    if (--count[r] > 0) break;
    r++;
  }
  permCount++;
}
console.log(`${checksum}\nPfannkuchen(${n}) = ${maxFlips}`);
