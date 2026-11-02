// bintrees: arena binary trees. Nodes are index pairs in one array; each tree is built
// bottom-up into the arena after the long-lived tree and released by resetting the top.
fn arg_n(d: i64) -> i64 { std::env::args().nth(1).and_then(|s| s.parse().ok()).unwrap_or(d) }
struct Arena { l: Vec<i32>, r: Vec<i32>, top: i32 }
fn build(a: &mut Arena, d: i32) -> i32 {
	let i = a.top; a.top += 1;
	if d > 0 { let l = build(a, d - 1); let r = build(a, d - 1); a.l[i as usize] = l; a.r[i as usize] = r; }
	else { a.l[i as usize] = -1; a.r[i as usize] = -1; }
	i
}
fn check(a: &Arena, i: i32) -> i64 { let l = a.l[i as usize]; if l < 0 { 1 } else { 1 + check(a, l) + check(a, a.r[i as usize]) } }
fn main() {
	let maxd = arg_n(10).max(6) as i32;
	let cap = ((2i64 << (maxd + 1)) + (2i64 << maxd)) as usize;
	let mut a = Arena { l: vec![0; cap], r: vec![0; cap], top: 0 };
	let s = build(&mut a, maxd + 1);
	println!("stretch tree of depth {}\t check: {}", maxd + 1, check(&a, s));
	a.top = 0;
	let lived = build(&mut a, maxd);
	let mark = a.top;
	let mut d = 4;
	while d <= maxd {
		let iters = 1i64 << (maxd - d + 4); let mut c = 0;
		for _ in 0..iters { a.top = mark; let t = build(&mut a, d); c += check(&a, t); }
		println!("{}\t trees of depth {}\t check: {}", iters, d, c);
		d += 2;
	}
	println!("long lived tree of depth {}\t check: {}", maxd, check(&a, lived));
}
