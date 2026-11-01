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
    const n = arg(init, 1000);
    const al = std.heap.smp_allocator;
    var m = std.StringHashMap(i64).init(al);
    var x: u64 = 1; var buf: [32]u8 = undefined;
    var i: i64 = 0;
    while (i < n) : (i += 1) {
        x = (x *% 1103515245 + 12345) & 0x7fffffff;
        const k = std.fmt.bufPrint(&buf, "key{d}", .{x % 200000}) catch unreachable;
        if (m.getPtr(k)) |v| { v.* += 1; } else { m.put(al.dupe(u8, k) catch unreachable, 1) catch unreachable; }
    }
    var maxc: i64 = 0;
    var it = m.valueIterator();
    while (it.next()) |v| if (v.* > maxc) { maxc = v.*; };
    var sum: i64 = 0;
    for (0..1000) |j| { const k = std.fmt.bufPrint(&buf, "key{d}", .{j}) catch unreachable; if (m.get(k)) |v| sum += v; }
    out("{d} {d} {d}\n", .{ m.count(), maxc, sum });
}
