// sort: bottom-up merge sort of n xorshift32 values. Prints a position-weighted checksum
// modulo 1e9+7 and whether the result is ordered.
fn arg_n(d: i64) -> i64 { std::env::args().nth(1).and_then(|s| s.parse().ok()).unwrap_or(d) }
struct Rng(u32);
impl Rng { fn next(&mut self) -> u32 { let mut x = self.0; x ^= x << 13; x ^= x >> 17; x ^= x << 5; self.0 = x; x } }
fn main() {
	let n = arg_n(1000) as usize;
	let mut r = Rng(2463534242);
	let mut src: Vec<u32> = (0..n).map(|_| r.next()).collect();
	let mut dst = vec![0u32; n];
	let mut w = 1;
	while w < n {
		let mut lo = 0;
		while lo < n {
			let mid = (lo + w).min(n); let hi = (lo + 2 * w).min(n);
			let (mut i, mut j, mut k) = (lo, mid, lo);
			while i < mid && j < hi { if src[i] <= src[j] { dst[k] = src[i]; i += 1; } else { dst[k] = src[j]; j += 1; } k += 1; }
			while i < mid { dst[k] = src[i]; i += 1; k += 1; }
			while j < hi { dst[k] = src[j]; j += 1; k += 1; }
			lo += 2 * w;
		}
		std::mem::swap(&mut src, &mut dst);
		w *= 2;
	}
	let (mut h, mut ok) = (0i64, 1);
	for i in 0..n { h = (h + src[i] as i64 * (i as i64 % 1000 + 1)) % 1000000007; if i > 0 && src[i - 1] > src[i] { ok = 0; } }
	println!("{} {}", h, ok);
}
