const n = +(process.argv[2] ?? 1000);
const m = new Map();
let xs = 1;
for (let i = 0; i < n; i++) {
  // (x * 1103515245 + 12345) mod 2^31, exact in doubles via 16-bit split
  const hi = Math.floor(xs / 65536), lo = xs % 65536;
  xs = (((hi * 1103515245) % 2147483648) * 65536 + lo * 1103515245 + 12345) % 2147483648;
  const k = "key" + (xs % 200000);
  m.set(k, (m.get(k) ?? 0) + 1);
}
let maxc = 0; for (const v of m.values()) if (v > maxc) maxc = v;
let sum = 0; for (let j = 0; j < 1000; j++) sum += m.get("key" + j) ?? 0;
console.log(`${m.size} ${maxc} ${sum}`);
