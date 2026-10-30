# Helium

Helium compiles to native code and runs at C speed. A `.he` file reads like Python 3 with static types. Write it as you would write Python, applying the differences listed below.

```he
use dictionary
use math
struct Item { name const byte[:], qty int, price real }
struct Cell { r int, c int, d int }
value(it Item) real: real(it.qty) * it.price
is_prime(n int) bool:
    if n < 2: return false
    for d in range(2, int(sqrt(real(n))) + 1):
        if n % d == 0: return false
    true
shortest(grid const byte[:][:], start Cell) int:
    seen ~= [[false; 8]; 8]
    queue Cell[>..] ~= [start]
    head ~= 0
    while head < len(queue):
        cur := queue[head]
        head += 1
        if grid[cur.r][cur.c] == 'E': return cur.d
        for m in [Cell { 0, 1, 0 }, Cell { 1, 0, 0 }, Cell { 0, -1, 0 }, Cell { -1, 0, 0 }]:
            nr, nc := cur.r + m.r, cur.c + m.c
            if nr >= 0 and nr < len(grid) and nc >= 0 and nc < len(grid[0]) and grid[nr][nc] != '#' and not seen[nr][nc]:
                seen[nr][nc] = true
                queue.push(Cell { nr, nc, cur.d + 1 })
    -1
main():
    stock Item[>..] ~= [Item { "bolt", 120, 0.25 }, Item { name: "gear", qty: 4, price: 12.5 }]
    stock.push(Item { "nut", 300, 0.1 })
    sort(stock) { a, b => value(a) > value(b) }
    for i, it in enumerate(stock): print(f"{i + 1}. {it.name:<5}{value(it):>7.2f}")
    words := "the cat and the hat and the bat".split()
    counts ~= dictionary<const byte[:], int> {}
    for w in words: counts[w] += 1
    line ~= ""
    for w, n in sorted(counts.items()): line += f"{w}={n} "
    print(line)
    primes := [p for p in range(2, 30) if is_prime(p)]
    print(", ".join(str(p) for p in primes), " ", sum(p * p for p in primes), " ", primes[-1], " ", primes[:3])
    a, b := 0, 1
    for _ in range(10): a, b = b, a + b
    print(a, " ", 2 ** 10, " ", 17 // 5, " ", 17 % 5, " ", int("42") + 1, " ", real(7) / 2.0)
    s := "Hello, World"
    letters := [c for c in s if c.isalpha()]
    print(s.upper(), " ", s[::-1], " ", s[7:], " ", s.replace("World", "there"), " ", len(letters), " ", "lo" in s)
    grid := ["S..#", ".#..", "...E"]
    print(shortest(grid, Cell { 0, 0, 0 }))
```

Output:
```
1. gear   50.00
2. bolt   30.00
3. nut    30.00
and=2 bat=1 cat=1 hat=1 the=3 
2, 3, 5, 7, 11, 13, 17, 19, 23, 29 2397 29 [2, 3, 5]
55 1024 3 2 43 3.5
HELLO, WORLD dlroW ,olleH World Hello, there 10 true
5
```

## Differences from Python

- Functions: `name(param type, ...) result:` with no `def`; leave out the result type when there is none. The last expression is the result, or use `return`. Several results: `return a, b` and `x, y := f()`. The program starts at `main():`.
- `x := e` declares a constant, `x ~= e` a variable, `x = e` assigns. `a, b := 1, 2` and `a, b = b, a` work.
- Types: `int` (64-bit, wraps on overflow, no big integers), `real`, `bool`, `byte`. No implicit int/real mixing: `real(n)`, `int(x)` truncates, `int(s)` and `real(s)` parse strings.
- `/` on ints truncates toward zero, `//` floors, `%` is never negative.
- Strings are bytes. A literal is a `const byte[:]` view: use that type for string fields, parameters, list elements and dictionary keys. `s ~= ""` is a growable string (`s += t`, `s += 'c'`). `a + b`, f-strings and `str(x)` make new strings. String functions: `split() split(sep) strip() upper() lower() replace(a, b) startswith(p) endswith(p) find(t) count(t) isdigit() isalpha()`, `sep.join(parts)`, `ljust rjust zfill`.
- `s[i]` is a byte, a number: `'a'` is 97, `c - 'a'` works, `print(s[i])` prints the number, `chr(n)` makes a one-character string.
- Lists: `[]`, comprehensions and `xs int[>..] ~= [1, 2]` are growable (`push`, `pop`, `+=`). A plain literal like `[1, 2]` or `[v; n]` with a constant `n` has a fixed size. `[[0; w]; h]` makes a grid. `len(xs)`, `xs[-1]`, `xs[a:b]` (a view), `sorted(xs)`, `reversed(xs)`, `sort(xs)`, `sort(xs) { a, b => a.k < b.k }` (true when `a` goes first; there is no `key=`), `sum min max any all`.
- Parameters: `xs int[:]` accepts any int list or array (elements can be changed); `xs int[>..]&` lets a function push to the caller's list; `n int&` is an in-out parameter.
- Loops: `for x in xs`, `for i in range(...)`, `for i, x in enumerate(xs)`, `for k, v in d.items()`, `while`, `break`, `continue`. Inline conditional: `if c { a } else { b }`.
- Structs replace classes and tuples: `struct P { x int, y int }`, `P { 1, 2 }` or `P { x: 1, y: 2 }`, `p.x`. Methods are plain functions: `f(p)` or `p.f()`.
- Dictionaries (`use dictionary`): `d ~= dictionary<const byte[:], int> {}`. `d[k]` creates a missing key with a zero value (like `defaultdict`), so `d[k] += 1` counts. `k in d`, `get(d, k, default)`, `remove(d, k)`, `d.count`, `keys(d)`, `values(d)`, `d.items()` (elements have `.key` and `.val`). Their order is arbitrary; `sorted(d.items())` sorts by key. A set is `dictionary<int, bool>`.
- `print(a, b)` writes its arguments with no separator and then a newline, so prefer `print(f"{a} {b}")`. f-strings support `{x:.2f} {x:>8} {x:<8} {n:05d} {n:x}`. Bools print `true`/`false`.
- Not available: classes, exceptions, lambdas as values, tuples, `None`, keyword arguments, `print(end=)`, big integers, `import` (use `use math` for `sqrt sin cos exp log floor ceil round PI`).
- More built-ins: `gcd lcm pow abs ord chr fmt(x, decimals) heap_push heap_pop lower_bound insert_at remove_at swap`.
