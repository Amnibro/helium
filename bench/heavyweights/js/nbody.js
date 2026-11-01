const PI = Math.PI, SM = 4 * PI * PI, DPY = 365.24;
const B = [
  [0, 0, 0, 0, 0, 0, 1],
  [4.84143144246472090e+00, -1.16032004402742839e+00, -1.03622044471123109e-01, 1.66007664274403694e-03, 7.69901118419740425e-03, -6.90460016972063023e-05, 9.54791938424326609e-04],
  [8.34336671824457987e+00, 4.12479856412430479e+00, -4.03523417114321381e-01, -2.76742510726862411e-03, 4.99852801234917238e-03, 2.30417297573763929e-05, 2.85885980666130812e-04],
  [1.28943695621391310e+01, -1.51111514016986312e+01, -2.23307578892655734e-01, 2.96460137564761618e-03, 2.37847173959480950e-03, -2.96589568540237556e-05, 4.36624404335156298e-05],
  [1.53796971148509165e+01, -2.59193146099879641e+01, 1.79258772950371181e-01, 2.68067772490389322e-03, 1.62824170038242295e-03, -9.51592254519715870e-05, 5.15138902046611451e-05]];
const b = B.map(r => ({ x: r[0], y: r[1], z: r[2], vx: r[3] * DPY, vy: r[4] * DPY, vz: r[5] * DPY, mass: r[6] * SM }));
function energy() {
  let e = 0;
  for (let i = 0; i < 5; i++) {
    const p = b[i];
    e += 0.5 * p.mass * (p.vx * p.vx + p.vy * p.vy + p.vz * p.vz);
    for (let j = i + 1; j < 5; j++) { const q = b[j]; const dx = p.x - q.x, dy = p.y - q.y, dz = p.z - q.z; e -= p.mass * q.mass / Math.sqrt(dx * dx + dy * dy + dz * dz); }
  }
  return e;
}
function advance(dt) {
  for (let i = 0; i < 5; i++) {
    const p = b[i];
    for (let j = i + 1; j < 5; j++) {
      const q = b[j];
      const dx = p.x - q.x, dy = p.y - q.y, dz = p.z - q.z, d2 = dx * dx + dy * dy + dz * dz, mag = dt / (d2 * Math.sqrt(d2));
      const mi = p.mass * mag, mj = q.mass * mag;
      p.vx -= dx * mj; p.vy -= dy * mj; p.vz -= dz * mj;
      q.vx += dx * mi; q.vy += dy * mi; q.vz += dz * mi;
    }
  }
  for (const p of b) { p.x += dt * p.vx; p.y += dt * p.vy; p.z += dt * p.vz; }
}
let px = 0, py = 0, pz = 0;
for (const p of b) { px += p.vx * p.mass; py += p.vy * p.mass; pz += p.vz * p.mass; }
b[0].vx = -px / SM; b[0].vy = -py / SM; b[0].vz = -pz / SM;
const n = +(process.argv[2] ?? 1000);
console.log(energy().toFixed(9));
for (let i = 0; i < n; i++) advance(0.01);
console.log(energy().toFixed(9));
