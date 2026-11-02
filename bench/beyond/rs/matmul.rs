// matmul: n x n f64 matrix product, i-k-j loop order. Prints the sum and one element.
fn arg_n(d: i64) -> i64 { std::env::args().nth(1).and_then(|s| s.parse().ok()).unwrap_or(d) }
fn main() {
	let n = arg_n(100) as usize;
	let mut a = vec![0.0f64; n * n]; let mut b = vec![0.0f64; n * n]; let mut c = vec![0.0f64; n * n];
	for i in 0..n { for j in 0..n {
		a[i * n + j] = ((i * 31 + j * 17) % 100) as f64 / 100.0;
		b[i * n + j] = ((i * 13 + j * 29) % 100) as f64 / 50.0 - 1.0;
	} }
	for i in 0..n { for k in 0..n {
		let aik = a[i * n + k];
		for j in 0..n { c[i * n + j] += aik * b[k * n + j]; }
	} }
	let mut s = 0.0; for v in c.iter() { s += v; }
	println!("{:.6} {:.9}", s, c[(n / 2) * n + n / 3]);
}
