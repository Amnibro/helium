// regex: backtracking matcher for literals . * + ? ^ $ (Pike style, leftmost, any match),
// run over n generated lines for six patterns. Prints the match count of each pattern.
fn arg_n(d: i64) -> i64 { std::env::args().nth(1).and_then(|s| s.parse().ok()).unwrap_or(d) }
struct Rng(u32);
impl Rng { fn next(&mut self) -> u32 { let mut x = self.0; x ^= x << 13; x ^= x >> 17; x ^= x << 5; self.0 = x; x } }
struct M<'a> { re: &'a [u8], t: &'a [u8] }
impl<'a> M<'a> {
	fn one(&self, c: u8, t: usize) -> bool { t < self.t.len() && (c == b'.' || c == self.t[t]) }
	fn star(&self, c: u8, r: usize, mut t: usize) -> bool { loop { if self.here(r, t) { return true; } if !self.one(c, t) { return false; } t += 1; } }
	fn here(&self, r: usize, t: usize) -> bool {
		let re = self.re; let rl = re.len();
		if r == rl { return true; }
		if r + 1 < rl && re[r + 1] == b'*' { return self.star(re[r], r + 2, t); }
		if r + 1 < rl && re[r + 1] == b'+' { return self.one(re[r], t) && self.star(re[r], r + 2, t + 1); }
		if r + 1 < rl && re[r + 1] == b'?' { if self.one(re[r], t) && self.here(r + 2, t + 1) { return true; } return self.here(r + 2, t); }
		if re[r] == b'$' && r + 1 == rl { return t == self.t.len(); }
		if self.one(re[r], t) { return self.here(r + 1, t + 1); }
		false
	}
	fn matches(&self) -> bool {
		if !self.re.is_empty() && self.re[0] == b'^' { return self.here(1, 0); }
		for t in 0..=self.t.len() { if self.here(0, t) { return true; } }
		false
	}
}
fn main() {
	let n = arg_n(1000) as usize;
	let mut r = Rng(2463534242);
	let pats = ["ab*c", "^a.*f$", "c.d.e", "fa+b?c", "e.*e.*e.*a", "dd*ee*ff*a$"];
	let mut buf: Vec<u8> = Vec::new(); let mut off: Vec<usize> = Vec::new();
	for _ in 0..n { off.push(buf.len()); let k = 20 + r.next() % 40; for _ in 0..k { buf.push(b'a' + (r.next() % 6) as u8); } }
	off.push(buf.len());
	let mut out = Vec::new();
	for p in pats.iter() {
		let mut c = 0;
		for i in 0..n { let m = M { re: p.as_bytes(), t: &buf[off[i]..off[i + 1]] }; if m.matches() { c += 1; } }
		out.push(c.to_string());
	}
	println!("{}", out.join(" "));
}
