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
const Node = struct { l: ?*Node, r: ?*Node };
const al = std.heap.smp_allocator;
fn make(d: i64) *Node {
    const n = al.create(Node) catch unreachable;
    if (d > 0) { n.* = .{ .l = make(d - 1), .r = make(d - 1) }; } else { n.* = .{ .l = null, .r = null }; }
    return n;
}
fn check(n: *Node) i64 { return if (n.l) |l| 1 + check(l) + check(n.r.?) else 1; }
fn release(n: *Node) void { if (n.l) |l| { release(l); release(n.r.?); } al.destroy(n); }
pub fn main(init: std.process.Init.Minimal) void {
    const n = arg(init, 10);
    const mind: i64 = 4; const maxd = @max(mind + 2, n);
    const s = make(maxd + 1);
    out("stretch tree of depth {d}\t check: {d}\n", .{ maxd + 1, check(s) });
    release(s);
    const lng = make(maxd);
    var d = mind;
    while (d <= maxd) : (d += 2) {
        const it = @as(i64, 1) << @intCast(maxd - d + mind);
        var chk: i64 = 0; var i: i64 = 0;
        while (i < it) : (i += 1) { const t = make(d); chk += check(t); release(t); }
        out("{d}\t trees of depth {d}\t check: {d}\n", .{ it, d, chk });
    }
    out("long lived tree of depth {d}\t check: {d}\n", .{ maxd, check(lng) });
    release(lng);
}
