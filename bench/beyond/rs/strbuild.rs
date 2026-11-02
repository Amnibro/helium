// strbuild: write n numbers (xorshift32 % 1000000) comma separated into one string,
// then split it on commas and parse every field back. Prints length, count and sum.
use std::fmt::Write;
fn arg_n(d: i64) -> i64 { std::env::args().nth(1).and_then(|s| s.parse().ok()).unwrap_or(d) }
struct Rng(u32);
impl Rng { fn next(&mut self) -> u32 { let mut x = self.0; x ^= x << 13; x ^= x >> 17; x ^= x << 5; self.0 = x; x } }
fn main() {
	let n = arg_n(1000);
	let mut r = Rng(2463534242);
	let mut s = String::new();
	for i in 0..n { if i > 0 { s.push(','); } write!(s, "{}", r.next() % 1000000).unwrap(); }
	let (mut count, mut sum) = (0i64, 0i64);
	for f in s.split(',') { sum += f.parse::<i64>().unwrap(); count += 1; }
	println!("{} {} {}", s.len(), count, sum);
}
