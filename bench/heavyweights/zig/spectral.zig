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
fn A(i: usize, j: usize) f64 { return 1.0 / @as(f64, @floatFromInt((i + j) * (i + j + 1) / 2 + i + 1)); }
fn mulAv(v: []const f64, av: []f64) void { for (0..v.len) |i| { var s: f64 = 0; for (0..v.len) |j| s += A(i, j) * v[j]; av[i] = s; } }
fn mulAtv(v: []const f64, atv: []f64) void { for (0..v.len) |i| { var s: f64 = 0; for (0..v.len) |j| s += A(j, i) * v[j]; atv[i] = s; } }
pub fn main(init: std.process.Init.Minimal) void {
    const n: usize = @intCast(arg(init, 100));
    const al = std.heap.smp_allocator;
    const u = al.alloc(f64, n) catch unreachable; const v = al.alloc(f64, n) catch unreachable; const t = al.alloc(f64, n) catch unreachable;
    @memset(u, 1.0); @memset(v, 0.0);
    for (0..10) |_| { mulAv(u, t); mulAtv(t, v); mulAv(v, t); mulAtv(t, u); }
    var vbv: f64 = 0; var vv: f64 = 0;
    for (0..n) |i| { vbv += u[i] * v[i]; vv += v[i] * v[i]; }
    out("{d:.9}\n", .{@sqrt(vbv / vv)});
}
