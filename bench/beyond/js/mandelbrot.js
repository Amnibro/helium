// mandelbrot: n x n grid over [-1.5,0.5]x[-1,1], 50 iterations, escape |z|^2 > 4.
// Prints the number of points inside and a hash of the row-packed bitmap.
const N = (d) => (process.argv.length > 2 ? parseInt(process.argv[2], 10) : d);
function run(n) {
	let inside = 0, h = 2166136261;
	for (let y = 0; y < n; y++) {
		const ci = 2.0 * y / n - 1.0;
		let bits = 0, nb = 0;
		for (let x = 0; x < n; x++) {
			const cr = 2.0 * x / n - 1.5;
			let zr = 0, zi = 0, inn = 1;
			for (let i = 0; i < 50; i++) {
				const tr = zr * zr - zi * zi + cr;
				const ti = 2.0 * zr * zi + ci;
				zr = tr; zi = ti;
				if (zr * zr + zi * zi > 4.0) { inn = 0; break; }
			}
			bits = ((bits << 1) | inn) >>> 0; nb++;
			inside += inn;
			if (nb === 8) { h = Math.imul(h ^ bits, 16777619) >>> 0; bits = 0; nb = 0; }
		}
		if (nb > 0) h = Math.imul(h ^ (bits << (8 - nb)), 16777619) >>> 0;
	}
	console.log(inside + " " + h);
}
run(N(200));
