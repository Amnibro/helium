fn main() {
    let n: usize = std::env::args().nth(1).map(|s| s.parse().unwrap()).unwrap_or(7);
    let (mut perm, mut perm1, mut count) = ([0usize; 32], [0usize; 32], [0usize; 32]);
    let (mut max_flips, mut checksum, mut perm_count, mut r) = (0i64, 0i64, 0i64, n);
    for i in 0..n { perm1[i] = i; }
    loop {
        while r != 1 { count[r - 1] = r; r -= 1; }
        perm[..n].copy_from_slice(&perm1[..n]);
        let mut flips = 0i64;
        loop { let k = perm[0]; if k == 0 { break; } perm[..=k].reverse(); flips += 1; }
        if flips > max_flips { max_flips = flips; }
        checksum += if perm_count % 2 == 0 { flips } else { -flips };
        loop {
            if r == n { println!("{}\nPfannkuchen({}) = {}", checksum, n, max_flips); return; }
            let p0 = perm1[0];
            for i in 0..r { perm1[i] = perm1[i + 1]; }
            perm1[r] = p0;
            count[r] -= 1;
            if count[r] > 0 { break; }
            r += 1;
        }
        perm_count += 1;
    }
}
