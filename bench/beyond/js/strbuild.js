// strbuild: write n numbers (xorshift32 % 1000000) comma separated into one string,
// then split it on commas and parse every field back. Prints length, count and sum.
const N = (d) => (process.argv.length > 2 ? parseInt(process.argv[2], 10) : d);
let rs = 2463534242;
function rnd() { rs ^= rs << 13; rs >>>= 0; rs ^= rs >>> 17; rs ^= rs << 5; rs >>>= 0; return rs; }
const n = N(1000);
const parts = [];
for (let i = 0; i < n; i++) parts.push(String(rnd() % 1000000));
const s = parts.join(",");
let count = 0, sum = 0;
for (const f of s.split(",")) { sum += parseInt(f, 10); count++; }
console.log(s.length + " " + count + " " + sum);
