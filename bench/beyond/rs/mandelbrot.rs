// mandelbrot: n x n grid over [-1.5,0.5]x[-1,1], 50 iterations, escape |z|^2 > 4.
// Prints the number of points inside and a hash of the row-packed bitmap.
fn arg_n(d: i64) -> i64 { std::env::args().nth(1).and_then(|s| s.parse().ok()).unwrap_or(d) }
fn main() {
	let n = arg_n(200);
	let mut inside = 0i64; let mut h: u32 = 2166136261;
	for y in 0..n {
		let ci = 2.0 * y as f64 / n as f64 - 1.0;
		let mut bits: u32 = 0; let mut nb = 0;
		for x in 0..n {
			let cr = 2.0 * x as f64 / n as f64 - 1.5;
			let (mut zr, mut zi) = (0.0f64, 0.0f64);
			let mut inn = 1u32;
			for _ in 0..50 {
				let tr = zr * zr - zi * zi + cr;
				let ti = 2.0 * zr * zi + ci;
				zr = tr; zi = ti;
				if zr * zr + zi * zi > 4.0 { inn = 0; break; }
			}
			bits = (bits << 1) | inn; nb += 1;
			inside += inn as i64;
			if nb == 8 { h = (h ^ bits).wrapping_mul(16777619); bits = 0; nb = 0; }
		}
		if nb > 0 { h = (h ^ (bits << (8 - nb))).wrapping_mul(16777619); }
	}
	println!("{} {}", inside, h);
}
