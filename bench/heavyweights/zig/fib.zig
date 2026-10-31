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
fn fib(n: i64) i64 { return if (n < 2) n else fib(n - 1) + fib(n - 2); }
pub fn main(init: std.process.Init.Minimal) void { out("{d}\n", .{fib(arg(init, 30))}); }
