// fannkuch: pancake flips over all permutations (permutation index order), checksum and max flips.
fn arg_n(d: i64) -> i64 { std::env::args().nth(1).and_then(|s| s.parse().ok()).unwrap_or(d) }
fn main() {
	let n = arg_n(7) as usize;
	let mut perm = [0usize; 16]; let mut perm1 = [0usize; 16]; let mut count = [0usize; 16];
	for i in 0..n { perm1[i] = i; }
	let (mut r, mut maxf, mut pc, mut checksum) = (n, 0i64, 0i64, 0i64);
	loop {
		while r != 1 { count[r - 1] = r; r -= 1; }
		perm[..n].copy_from_slice(&perm1[..n]);
		let mut flips = 0i64; let mut k = perm[0];
		while k != 0 {
			let (mut i, mut j) = (0, k);
			while i < j { perm.swap(i, j); i += 1; j -= 1; }
			flips += 1;
			k = perm[0];
		}
		if flips > maxf { maxf = flips; }
		checksum += if pc % 2 == 0 { flips } else { -flips };
		loop {
			if r == n { println!("{}\nPfannkuchen({}) = {}", checksum, n, maxf); return; }
			let p0 = perm1[0];
			for i in 0..r { perm1[i] = perm1[i + 1]; }
			perm1[r] = p0;
			count[r] -= 1;
			if count[r] > 0 { break; }
			r += 1;
		}
		pc += 1;
	}
}
