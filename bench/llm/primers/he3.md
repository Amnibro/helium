# Helium

Helium is Python 3 with static types, compiled to native code that runs at C speed. Write the Python you would normally write, give functions typed signatures, and apply the differences below. Write the program directly: the compiler explains any mistake.

```he
use dictionary
use math
struct Item { name const byte[:], qty int, price real }
struct Cell { r int, c int, d int }
value(it Item) real: real(it.qty) * it.price
digit_sum(n int) int: sum(int(d) for d in str(n))
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
    print(a, " ", 2 ** 10, " ", digit_sum(2026), " ", 17 // 5, " ", 17 % 5, " ", int("42") + 1, " ", real(7) / 2.0)
    s := "Hello, World"
    letters := [c for c in s if 'a' <= c <= 'z' or c.isupper()]
    print(s.upper(), " ", "the end".title(), " ", s[::-1], " ", s[7:], " ", s.replace("World", "there"), " ", len(letters), " ", "lo" in s)
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
55 1024 10 3 2 43 3.5
HELLO, WORLD The End dlroW ,olleH World Hello, there 10 true
5
```

## Same as Python

Indentation blocks, `#` comments, `if/elif/else`, `while`, `for x in xs`, `range`, `break`, `continue`, `and or not`, `in`, `not in`, chained comparisons, `//`, `%`, `**`, `xs[-1]`, `xs[a:b]`, `s[::-1]`, f-strings with format specs (`{x:.2f} {x:>8} {n:05d} {n:x} {n:b} {p:.1%}`), list comprehensions, generators as arguments (`sum(x * x for x in xs)`), `for i, x in enumerate(xs)`, `for k, v in d.items()`, `a, b = b, a`, `int(s)`, `int(digit_char)`, `str(x)`, `ord chr len sum min max abs any all sorted reversed bin oct hex`, string methods `split strip lstrip rstrip upper lower title capitalize replace startswith endswith find count isdigit isalpha isupper islower ljust rjust center zfill` and `sep.join(parts)`, `gcd lcm isqrt factorial comb perm prod median mean`.

## Differences

- Functions: `name(param type, ...) result:` with no `def`; leave out the result type when there is none. The last expression is the result, or use `return`. Several results: `return a, b` and `x, y := f()`. The program starts at `main():`.
- `x := e` declares a constant, `x ~= e` a variable, `x = e` assigns. `a, b := 1, 2` works.
- Types: `int` (64-bit, no big integers), `real`, `bool`, `byte`. No implicit int/real mixing: `real(n)`, `int(x)` truncates.
- `/` on ints truncates toward zero.
- Strings are bytes. A literal is a `const byte[:]`: use that type for string fields, parameters, list elements and dictionary keys. `s ~= ""` is a growable string (`s += t`, `s += 'c'`). `s[i]` and `for c in s` give a byte, a number: `'a'` is 97, `c - 'a'` works, `print(c)` prints the number, `chr(c)` makes a one-character string.
- Lists: `[]`, comprehensions and `xs int[>..] ~= [1, 2]` are growable (`push`, `pop`, `+=`). A plain literal like `[1, 2]` or `[v; n]` has a fixed size. `[[0; w]; h]` makes a grid. `sort(xs)` sorts in place, `sort(xs) { a, b => a.k < b.k }` takes a "goes first" test (there is no `key=`).
- Parameters: `xs int[:]` accepts any int list (elements can be changed); `xs int[>..]&` lets a function push to the caller's list; `n int&` is an in-out parameter.
- Structs replace classes and tuples: `struct P { x int, y int }`, `P { 1, 2 }` or `P { x: 1, y: 2 }`, `p.x`. Methods are plain functions: `f(p)` or `p.f()`.
- Dictionaries (`use dictionary`): `d ~= dictionary<const byte[:], int> {}`. `d[k]` creates a missing key with a zero value (like `defaultdict`), so `d[k] += 1` counts. `k in d`, `get(d, k, default)`, `remove(d, k)`, `d.count`, `keys(d)`, `values(d)`, `d.items()` (elements have `.key` and `.val`). Order is arbitrary; `sorted(d.items())` sorts by key. A set is `dictionary<int, bool>`.
- `print(a, b)` writes its arguments with no separator, so prefer `print(f"{a} {b}")`. Bools print `true`/`false`.
- Not available: classes, exceptions, lambdas as values, tuples, `None`, keyword arguments, big integers, `import` (`use math` gives `sqrt sin cos exp log floor ceil round PI`).
