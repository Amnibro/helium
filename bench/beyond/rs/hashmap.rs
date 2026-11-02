// hashmap: n inserts of xorshift32 keys mod n/2 (value += i), then n lookups of keys mod n.
// Prints entry count, sum of found values and miss count. Uses std HashMap (default hasher).
use std::collections::HashMap;
fn arg_n(d: i64) -> i64 { std::env::args().nth(1).and_then(|s| s.parse().ok()).unwrap_or(d) }
struct Rng(u32);
impl Rng { fn next(&mut self) -> u32 { let mut x = self.0; x ^= x << 13; x ^= x >> 17; x ^= x << 5; self.0 = x; x } }
fn main() {
	let n = arg_n(1000);
	let mut r = Rng(2463534242);
	let mut m: HashMap<u32, i64> = HashMap::new();
	let half = (n / 2) as u32;
	for i in 0..n { *m.entry(r.next() % half).or_insert(0) += i; }
	let (mut sum, mut miss) = (0i64, 0i64);
	for _ in 0..n { match m.get(&(r.next() % n as u32)) { Some(v) => sum += v, None => miss += 1 } }
	println!("{} {} {}", m.len(), sum, miss);
}
