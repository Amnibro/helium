// nbody: 5 bodies, symplectic Euler, dt 0.01. Prints energy before and after.
fn arg_n(d: i64) -> i64 { std::env::args().nth(1).and_then(|s| s.parse().ok()).unwrap_or(d) }
const NB: usize = 5;
struct Sys { x: [f64; NB], y: [f64; NB], z: [f64; NB], vx: [f64; NB], vy: [f64; NB], vz: [f64; NB], m: [f64; NB] }
fn init() -> Sys {
	let pi = 3.141592653589793f64; let dpy = 365.24; let s = 4.0 * pi * pi;
	let d: [[f64; 7]; NB] = [
		[0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0],
		[4.84143144246472090e+00, -1.16032004402742839e+00, -1.03622044471123109e-01, 1.66007664274403694e-03, 7.69901118419740425e-03, -6.90460016972063023e-05, 9.54791938424326609e-04],
		[8.34336671824457987e+00, 4.12479856412430479e+00, -4.03523417114321381e-01, -2.76742510726862411e-03, 4.99852801234917238e-03, 2.30417297573763929e-05, 2.85885980666130812e-04],
		[1.28943695621391310e+01, -1.51111514016986312e+01, -2.23307578892655734e-01, 2.96460137564761618e-03, 2.37847173959480950e-03, -2.96589568540237556e-05, 4.36624404335156298e-05],
		[1.53796971148509165e+01, -2.59193146099879641e+01, 1.79258772950371181e-01, 2.68067772490389322e-03, 1.62824170038242295e-03, -9.51592254519715870e-05, 5.15138902046611451e-05]];
	let mut b = Sys { x: [0.0; NB], y: [0.0; NB], z: [0.0; NB], vx: [0.0; NB], vy: [0.0; NB], vz: [0.0; NB], m: [0.0; NB] };
	for i in 0..NB {
		b.x[i] = d[i][0]; b.y[i] = d[i][1]; b.z[i] = d[i][2];
		b.vx[i] = d[i][3] * dpy; b.vy[i] = d[i][4] * dpy; b.vz[i] = d[i][5] * dpy; b.m[i] = d[i][6] * s;
	}
	let (mut px, mut py, mut pz) = (0.0, 0.0, 0.0);
	for i in 0..NB { px += b.vx[i] * b.m[i]; py += b.vy[i] * b.m[i]; pz += b.vz[i] * b.m[i]; }
	b.vx[0] = -px / s; b.vy[0] = -py / s; b.vz[0] = -pz / s;
	b
}
fn energy(b: &Sys) -> f64 {
	let mut e = 0.0;
	for i in 0..NB {
		e += 0.5 * b.m[i] * (b.vx[i] * b.vx[i] + b.vy[i] * b.vy[i] + b.vz[i] * b.vz[i]);
		for j in i + 1..NB {
			let dx = b.x[i] - b.x[j]; let dy = b.y[i] - b.y[j]; let dz = b.z[i] - b.z[j];
			e -= b.m[i] * b.m[j] / (dx * dx + dy * dy + dz * dz).sqrt();
		}
	}
	e
}
fn advance(b: &mut Sys, dt: f64) {
	for i in 0..NB {
		for j in i + 1..NB {
			let dx = b.x[i] - b.x[j]; let dy = b.y[i] - b.y[j]; let dz = b.z[i] - b.z[j];
			let d2 = dx * dx + dy * dy + dz * dz;
			let mag = dt / (d2 * d2.sqrt());
			let mj = b.m[j] * mag; let mi = b.m[i] * mag;
			b.vx[i] -= dx * mj; b.vy[i] -= dy * mj; b.vz[i] -= dz * mj;
			b.vx[j] += dx * mi; b.vy[j] += dy * mi; b.vz[j] += dz * mi;
		}
	}
	for i in 0..NB { b.x[i] += dt * b.vx[i]; b.y[i] += dt * b.vy[i]; b.z[i] += dt * b.vz[i]; }
}
fn main() {
	let n = arg_n(1000);
	let mut b = init();
	println!("{:.9}", energy(&b));
	for _ in 0..n { advance(&mut b, 0.01); }
	println!("{:.9}", energy(&b));
}
