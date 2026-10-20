enum Item<T> { Some { value: T }, None }
type Payload = Item<i64>.Some;

fn filled<T>(value: T) {
    let payload = Item<T>.Some {
        const for <N, A> in fields<Item<T>.Some> { A: value, }
    };
    let fixed: Item<T> = Item<T>.Some {
        const for <N, A> in fields<Item<T>.Some> { A: value, }
    };
    var variable: Item<T>.. = Item<T>.Some {
        const for <N, A> in fields<Item<T>.Some> { A: value, }
    };
    print(payload.value);
    match fixed { Some p => print(p.value), None => {} }
    match variable { Some &p => print(p.value), None => {} }
}

fn main() {
    filled(7);
    filled(3.5);
    let payload: Payload = Payload {
        const for <N, A> in fields<const Payload> { A: 9, }
    };
    print(payload.value);
}
