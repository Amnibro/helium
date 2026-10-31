struct Node { l: Option<Box<Node>>, r: Option<Box<Node>> }
fn make(d: i32) -> Box<Node> { if d > 0 { Box::new(Node { l: Some(make(d - 1)), r: Some(make(d - 1)) }) } else { Box::new(Node { l: None, r: None }) } }
fn check(n: &Node) -> i64 { match (&n.l, &n.r) { (Some(l), Some(r)) => 1 + check(l) + check(r), _ => 1 } }
fn main() {
    let n: i32 = std::env::args().nth(1).map(|s| s.parse().unwrap()).unwrap_or(10);
    let mind = 4; let maxd = if n < mind + 2 { mind + 2 } else { n };
    { let s = make(maxd + 1); println!("stretch tree of depth {}\t check: {}", maxd + 1, check(&s)); }
    let long = make(maxd);
    let mut d = mind;
    while d <= maxd {
        let it: i64 = 1 << (maxd - d + mind); let mut chk = 0;
        for _ in 0..it { let t = make(d); chk += check(&t); }
        println!("{}\t trees of depth {}\t check: {}", it, d, chk);
        d += 2;
    }
    println!("long lived tree of depth {}\t check: {}", maxd, check(&long));
}
