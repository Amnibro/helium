// hashmap: n inserts of xorshift32 keys mod n/2 (value += i), then n lookups of keys mod n.
// Prints entry count, sum of found values and miss count. Uses the built-in Map.
const N = (d) => (process.argv.length > 2 ? parseInt(process.argv[2], 10) : d);
let rs = 2463534242;
function rnd() { rs ^= rs << 13; rs >>>= 0; rs ^= rs >>> 17; rs ^= rs << 5; rs >>>= 0; return rs; }
const n = N(1000);
const m = new Map();
const half = Math.floor(n / 2);
for (let i = 0; i < n; i++) { const k = rnd() % half; m.set(k, (m.get(k) ?? 0) + i); }
let sum = 0, miss = 0;
for (let i = 0; i < n; i++) { const v = m.get(rnd() % n); if (v !== undefined) sum += v; else miss++; }
console.log(m.size + " " + sum + " " + miss);
