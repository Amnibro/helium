def small_divisors(n, limit=10):
    n = abs(n)
    return sum(1 for d in range(1, min(n, limit) + 1) if n % d == 0)

memo, hits, out = {}, 0, []
for x in [6, 12, 18]:
    if x in memo:
        hits += 1
    else:
        memo[x] = small_divisors(x)
    out.append(memo[x])
print(f"subfunction ran on {len(out)} results, {hits} memo hits")
unique = list(dict.fromkeys(out))
print("results: " + ",".join(map(str, unique * 2)))
