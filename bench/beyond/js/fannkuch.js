// fannkuch: pancake flips over all permutations (permutation index order), checksum and max flips.
const N = (d) => (process.argv.length > 2 ? parseInt(process.argv[2], 10) : d);
function run(n) {
	const perm = new Int32Array(16), perm1 = new Int32Array(16), count = new Int32Array(16);
	for (let i = 0; i < n; i++) perm1[i] = i;
	let r = n, maxf = 0, pc = 0, checksum = 0;
	for (;;) {
		while (r !== 1) { count[r - 1] = r; r--; }
		for (let i = 0; i < n; i++) perm[i] = perm1[i];
		let flips = 0, k = perm[0];
		while (k !== 0) {
			let i = 0, j = k;
			while (i < j) { const t = perm[i]; perm[i] = perm[j]; perm[j] = t; i++; j--; }
			flips++;
			k = perm[0];
		}
		if (flips > maxf) maxf = flips;
		checksum += pc % 2 === 0 ? flips : -flips;
		for (;;) {
			if (r === n) { console.log(checksum + "\nPfannkuchen(" + n + ") = " + maxf); return; }
			const p0 = perm1[0];
			for (let i = 0; i < r; i++) perm1[i] = perm1[i + 1];
			perm1[r] = p0;
			count[r]--;
			if (count[r] > 0) break;
			r++;
		}
		pc++;
	}
}
run(N(7));
