# Helium

Helium compiles to native code and runs at C speed. A `.he` file reads like Python with static types: indentation blocks, `#` comments, no semicolons, `if/elif/else`, `and or not`, `in`, `range`, `//`, `**`, negative indexes and `a[i:j]` slices all work as in Python. Write it the way you would write Python, following the differences below.

```he
use dictionary
use math
struct Item { name const byte[:], qty int, price real }
value(it Item) real: real(it.qty) * it.price
divmod(a int, b int) int, int: return a // b, a % b
is_prime(n int) bool:
    if n < 2: return false
    i ~= 2
    while i * i <= n:
        if n % i == 0: return false
        i += 1
    true
main():
    stock Item[>..] ~= [Item { "bolt", 120, 0.25 }, Item { name: "gear", qty: 4, price: 12.5 }]
    stock.push(Item { "nut", 300, 0.1 })
    sort(stock) { a, b => value(a) > value(b) }
    total ~= 0.0
    for it in stock: total += value(it)
    print(fmt(total, 2), " ", stock[0].name, " ", stock[-1].name, " ", len(stock))
    words := split("the cat and the hat and the bat")
    counts ~= dictionary<const byte[:], int> {}
    for w in words: get_or_insert(counts, w, 0) += 1
    top := sorted(items(counts)) { a, b => a.val > b.val or a.val == b.val and a.key < b.key }
    for e in top[:2]: print(e.key, " ", e.val)
    print("the" in counts, " ", get(counts, "dog", 0), " ", counts.count)
    out byte[>..] ~= []
    for i in range(1, 20):
        if is_prime(i): out.append(str(i, ","))
    print(out[:-1])
    q, r := divmod(17, 5)
    a, b := 0, 1
    for _ in range(10): a, b = b, a + b
    print(q, " ", r, " ", a, " ", 2 ** 10, " ", sqrt(2.0), " ", int("42") + 1, " ", real(7) / 2.0)
    s := "Hello, World"
    up byte[>..] ~= []
    for c in s:
        if c.is_alpha(): up.push(c)
        elif c == ' ': up.append("_")
    print(upper(up), " ", s[::-1], " ", s[7:], " ", join(["a", "b", "c"], "-"), " ", replace(s, "World", "there"))
    grid ~= [[0; 3]; 2]
    grid[1][2] = 5
    print(grid, " ", if total > 100.0 { "big" } else { "small" })
```

Output:
```
110.00 gear nut 3
the 3
and 2
true 0 5
2,3,5,7,11,13,17,19
3 2 55 1024 1.4142135623730951 43 3.5
HELLO_WORLD dlroW ,olleH World a-b-c Hello, there
[[0, 0, 0], [0, 0, 5]] big
```

## Differences from Python

- Functions: `name(param type, ...) result:` (no `def`, no result for none). The last expression is the result, or use `return`. Several results: `return a, b` and `x, y := f()`. Recursion works. A nested function can read and change the enclosing function's locals. Program starts at `main():`.
- Variables: `x := e` declares a constant, `x ~= e` a variable, `x = e` assigns. `a, b := 1, 2` and `a, b = b, a` work.
- Types: `int` (64-bit, wraps on overflow: no big integers), `real` (64-bit float), `bool`, `byte`. No automatic int/real mixing: convert with `real(n)` or `int(x)` (truncates). `int(s)` and `real(s)` parse strings. `x as T` casts between number types.
- `/` on ints truncates toward zero; `//` floors like Python; `%` is never negative. `/` on reals is float division.
- Strings are bytes. A literal is a `const byte[:]` view: use that type for string fields, parameters, list elements and dictionary keys. Build new text in a growable `byte[>..]`: `out.append(t)`, `out.push(c)`, `str(a, b, 3)` formats and joins any values, `upper(s)`, `lower(s)`, `replace(s, a, b)`, `join(parts, sep)`, `repeat(s, n)`, `fmt(x, 2)` formats a real with 2 decimals. Compare strings with `==` and `<`.
- `s[i]` is a byte, a number (`'a'` is 97): `c - 'a'`, `c.is_digit()`, `out.push(c - 32)`. `print` shows a byte as a number; `chr(n)` makes a one-character string.
- Lists: `[]` starts an empty growable list. A list literal is fixed-size unless typed: `xs int[>..] ~= [1, 2]` can then `push`. `[v; n]` repeats `v` n times (fixed size). `xs.push(v)`, `xs.pop()`, `len(xs)` or `xs.len`, `xs[i:j]` is a view, `sorted(xs)` and `reversed(xs)` copy, `sort(xs)` and `reverse(xs)` work in place. `sort(xs) { a, b => ... }` takes "a comes before b". A parameter `xs int[:]` accepts any int list or array; `xs int[>..]&` lets a function push to the caller's list; `n int&` is an in-out parameter.
- `for x in xs`, `for i in range(n)`, `for i in range(a, b)`, `for x, i in xs` (value first, then index), `while c:`, `break`, `continue`. Inline conditional: `if c { a } else { b }`.
- Structs replace classes and tuples: `struct P { x int, y int }`, `P { 1, 2 }` or `P { x: 1, y: 2 }`, `p.x`, `==` compares. Methods are plain functions: `f(p)` or `p.f()`.
- Dictionaries (`use dictionary`): `d ~= dictionary<const byte[:], int> {}`, `insert(d, k, v)`, `get(d, k, default)`, `get_or_insert(d, k, 0) += 1`, `k in d`, `remove(d, k)`, `d.count`, `keys(d)`, `values(d)`, `items(d)` (elements have `.key` and `.val`). Their order is arbitrary, so sort before printing. A set is `dictionary<int, bool>`.
- `print(a, b)` writes its arguments with no separator and a newline: `print(a, " ", b)`. Bools print `true`/`false`, lists print `[1, 2]`.
- Not available: classes, exceptions, list comprehensions, lambdas in variables, f-strings, tuples, `None`, generators, big integers.
- Library without imports: `min max abs sum sorted reversed sort reverse contains find count gcd lcm pow swap split(s) split(s, sep) join trim upper lower replace repeat starts_with ends_with is_digit is_alpha is_alnum is_upper is_lower is_space ord chr str fmt heap_push heap_pop lower_bound insert_at remove_at`. `use math`: `sqrt exp log sin cos tan atan2 floor ceil round PI`.
