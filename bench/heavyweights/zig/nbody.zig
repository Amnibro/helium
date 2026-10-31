const std = @import("std");
fn out(comptime fmt: []const u8, args: anytype) void {
    var buf: [256]u8 = undefined;
    const s = std.fmt.bufPrint(&buf, fmt, args) catch unreachable;
    _ = std.os.linux.write(1, s.ptr, s.len);
}
fn arg(init: std.process.Init.Minimal, def: i64) i64 {
    const v = init.args.vector;
    if (v.len < 2) return def;
    return std.fmt.parseInt(i64, std.mem.span(v[1]), 10) catch def;
}
const PI = 3.141592653589793;
const SM = 4.0 * PI * PI;
const DPY = 365.24;
const Body = struct { x: f64, y: f64, z: f64, vx: f64, vy: f64, vz: f64, mass: f64 };
fn body(x: f64, y: f64, z: f64, vx: f64, vy: f64, vz: f64, m: f64) Body {
    return .{ .x = x, .y = y, .z = z, .vx = vx * DPY, .vy = vy * DPY, .vz = vz * DPY, .mass = m * SM };
}
fn energy(b: *[5]Body) f64 {
    var e: f64 = 0;
    for (0..5) |i| {
        e += 0.5 * b[i].mass * (b[i].vx * b[i].vx + b[i].vy * b[i].vy + b[i].vz * b[i].vz);
        for (i + 1..5) |j| {
            const dx = b[i].x - b[j].x; const dy = b[i].y - b[j].y; const dz = b[i].z - b[j].z;
            e -= b[i].mass * b[j].mass / @sqrt(dx * dx + dy * dy + dz * dz);
        }
    }
    return e;
}
fn advance(b: *[5]Body, dt: f64) void {
    for (0..5) |i| {
        for (i + 1..5) |j| {
            const dx = b[i].x - b[j].x; const dy = b[i].y - b[j].y; const dz = b[i].z - b[j].z;
            const d2 = dx * dx + dy * dy + dz * dz;
            const mag = dt / (d2 * @sqrt(d2));
            const mi = b[i].mass * mag; const mj = b[j].mass * mag;
            b[i].vx -= dx * mj; b[i].vy -= dy * mj; b[i].vz -= dz * mj;
            b[j].vx += dx * mi; b[j].vy += dy * mi; b[j].vz += dz * mi;
        }
    }
    for (b) |*p| { p.x += dt * p.vx; p.y += dt * p.vy; p.z += dt * p.vz; }
}
pub fn main(init: std.process.Init.Minimal) void {
    const n = arg(init, 1000);
    var b = [5]Body{
        body(0, 0, 0, 0, 0, 0, 1),
        body(4.84143144246472090e+00, -1.16032004402742839e+00, -1.03622044471123109e-01, 1.66007664274403694e-03, 7.69901118419740425e-03, -6.90460016972063023e-05, 9.54791938424326609e-04),
        body(8.34336671824457987e+00, 4.12479856412430479e+00, -4.03523417114321381e-01, -2.76742510726862411e-03, 4.99852801234917238e-03, 2.30417297573763929e-05, 2.85885980666130812e-04),
        body(1.28943695621391310e+01, -1.51111514016986312e+01, -2.23307578892655734e-01, 2.96460137564761618e-03, 2.37847173959480950e-03, -2.96589568540237556e-05, 4.36624404335156298e-05),
        body(1.53796971148509165e+01, -2.59193146099879641e+01, 1.79258772950371181e-01, 2.68067772490389322e-03, 1.62824170038242295e-03, -9.51592254519715870e-05, 5.15138902046611451e-05),
    };
    var px: f64 = 0; var py: f64 = 0; var pz: f64 = 0;
    for (b) |p| { px += p.vx * p.mass; py += p.vy * p.mass; pz += p.vz * p.mass; }
    b[0].vx = -px / SM; b[0].vy = -py / SM; b[0].vz = -pz / SM;
    out("{d:.9}\n", .{energy(&b)});
    var i: i64 = 0;
    while (i < n) : (i += 1) advance(&b, 0.01);
    out("{d:.9}\n", .{energy(&b)});
}
