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
pub fn main(init: std.process.Init.Minimal) void {
    const n = arg(init, 200);
    const nf: f64 = @floatFromInt(n);
    var count: i64 = 0;
    var y: i64 = 0;
    while (y < n) : (y += 1) {
        const ci = 2.0 * @as(f64, @floatFromInt(y)) / nf - 1.0;
        var x: i64 = 0;
        while (x < n) : (x += 1) {
            const cr = 2.0 * @as(f64, @floatFromInt(x)) / nf - 1.5;
            var zr: f64 = 0; var zi: f64 = 0; var tr: f64 = 0; var ti: f64 = 0; var i: i32 = 0;
            while (i < 50 and tr + ti <= 4.0) : (i += 1) { zi = 2.0 * zr * zi + ci; zr = tr - ti + cr; tr = zr * zr; ti = zi * zi; }
            if (tr + ti <= 4.0) count += 1;
        }
    }
    out("{d}\n", .{count});
}
