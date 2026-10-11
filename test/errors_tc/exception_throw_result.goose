// error: function value can fall off the end without returning value(s)
// A library function call has no bottom/never return type: an unconditional
// throw cannot stand in for the result of a value-returning function.
import exception;
fn value() -> i64 { exception::throw("no value"); }
fn work() { print(value()); }
fn main() { exception::try<u8[]>(work); }
