// json: generate a JSON array of n records, then parse it with a generic recursive-descent
// parser. Prints the sum of all numbers, total string bytes, trues, objects and arrays.
use std::fmt::Write;
fn arg_n(d: i64) -> i64 { std::env::args().nth(1).and_then(|s| s.parse().ok()).unwrap_or(d) }
struct Rng(u32);
impl Rng { fn next(&mut self) -> u32 { let mut x = self.0; x ^= x << 13; x ^= x >> 17; x ^= x << 5; self.0 = x; x } }
struct P<'a> { d: &'a [u8], p: usize, nums: i64, strs: i64, trues: i64, objs: i64, arrs: i64 }
impl<'a> P<'a> {
	fn ws(&mut self) { while self.p < self.d.len() && matches!(self.d[self.p], b' ' | b'\n' | b'\t' | b'\r') { self.p += 1; } }
	fn string(&mut self) { self.p += 1; let s = self.p; while self.d[self.p] != b'"' { if self.d[self.p] == b'\\' { self.p += 1; } self.p += 1; } self.strs += (self.p - s) as i64; self.p += 1; }
	fn value(&mut self) {
		self.ws();
		let c = self.d[self.p];
		if c == b'{' {
			self.objs += 1; self.p += 1; self.ws();
			if self.d[self.p] == b'}' { self.p += 1; return; }
			loop { self.ws(); self.string(); self.ws(); self.p += 1; self.value(); self.ws(); if self.d[self.p] == b',' { self.p += 1; continue; } self.p += 1; return; }
		} else if c == b'[' {
			self.arrs += 1; self.p += 1; self.ws();
			if self.d[self.p] == b']' { self.p += 1; return; }
			loop { self.value(); self.ws(); if self.d[self.p] == b',' { self.p += 1; continue; } self.p += 1; return; }
		} else if c == b'"' { self.string(); }
		else if c == b't' { self.trues += 1; self.p += 4; }
		else if c == b'f' { self.p += 5; }
		else if c == b'n' { self.p += 4; }
		else {
			let mut neg = false; if self.d[self.p] == b'-' { neg = true; self.p += 1; }
			let mut v = 0i64; while self.p < self.d.len() && self.d[self.p].is_ascii_digit() { v = v * 10 + (self.d[self.p] - b'0') as i64; self.p += 1; }
			self.nums += if neg { -v } else { v };
		}
	}
}
fn main() {
	let n = arg_n(1000);
	let mut r = Rng(2463534242);
	let mut s = String::from("[");
	for i in 0..n {
		if i > 0 { s.push_str(",\n"); }
		let (a, b, x, y, ok) = (r.next() % 100, r.next() % 100, r.next() % 10000, (r.next() % 10000) as i64 - 5000, r.next() & 1);
		write!(s, "{{\"id\":{},\"name\":\"item{}\",\"tags\":[\"t{}\",\"t{}\"],\"pos\":{{\"x\":{},\"y\":{}}},\"ok\":{}}}", i, i, a, b, x, y, if ok != 0 { "true" } else { "false" }).unwrap();
	}
	s.push(']');
	let mut p = P { d: s.as_bytes(), p: 0, nums: 0, strs: 0, trues: 0, objs: 0, arrs: 0 };
	p.value();
	println!("{} {} {} {} {} {}", s.len(), p.nums, p.strs, p.trues, p.objs, p.arrs);
}
