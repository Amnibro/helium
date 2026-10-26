// A `let` table of string literals holds only views of static data, so a
// string read out of it, here or in a callee, keeps no grow-only array from
// shrinking (§5.1).
let KEYS = ["alpha", "beta"];
var counts: i64[>..] = [];
struct Pick { name: const u8[:], n: i64 }
fn pick(i: i64) -> Pick { return Pick { name: KEYS[i], n: i }; }
fn main() {
    counts.push(1);
    let x = KEYS[counts.len];
    let p = pick(0);
    counts.pop();
    counts.push(2);
    print(x, " ", p.name, " ", counts[0]);
}
