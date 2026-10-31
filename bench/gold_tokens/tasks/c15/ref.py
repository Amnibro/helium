def last_even_digits_sum(n, count=2):
    total = found = 0
    n = abs(n)
    while n and found < count:
        d = n % 10
        if d % 2 == 0:
            total += d
            found += 1
        n //= 10
    return total

memo, hits, out = {}, 0, []
for x in [2468, 1357, 8642, 2048, 9876]:
    if x in memo:
        hits += 1
    else:
        memo[x] = last_even_digits_sum(x)
    out.append(memo[x])
print(f"subfunction ran on {len(out)} results, {hits} memo hits")
if len(out) >= 2:
    out = [(b - a) * 3 for a, b in zip(out, out[1:])]
print("results: " + ",".join(map(str, out)))
