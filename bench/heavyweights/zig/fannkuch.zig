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
    const n: usize = @intCast(arg(init, 7));
    var perm: [32]i64 = undefined; var perm1: [32]i64 = undefined; var count: [32]usize = undefined;
    var max_flips: i64 = 0; var checksum: i64 = 0; var perm_count: i64 = 0; var r: usize = n;
    for (0..n) |i| perm1[i] = @intCast(i);
    while (true) {
        while (r != 1) : (r -= 1) count[r - 1] = r;
        @memcpy(perm[0..n], perm1[0..n]);
        var flips: i64 = 0;
        while (perm[0] != 0) {
            const k: usize = @intCast(perm[0]);
            std.mem.reverse(i64, perm[0 .. k + 1]);
            flips += 1;
        }
        if (flips > max_flips) max_flips = flips;
        checksum += if (@mod(perm_count, 2) == 0) flips else -flips;
        while (true) {
            if (r == n) { out("{d}\nPfannkuchen({d}) = {d}\n", .{ checksum, n, max_flips }); return; }
            const p0 = perm1[0];
            for (0..r) |i| perm1[i] = perm1[i + 1];
            perm1[r] = p0;
            count[r] -= 1;
            if (count[r] > 0) break;
            r += 1;
        }
        perm_count += 1;
    }
}
