def doubling_sum(n, limit=50):
    cur, total = max(n, 1), 0
    while cur <= limit:
        total += cur
        cur *= 2
    return total

memo, hits, out = {}, 0, []
for x in [3, 5, 7]:
    if x in memo:
        hits += 1
    else:
        memo[x] = doubling_sum(x)
    out.append(memo[x])
print(f"subfunction ran on {len(out)} results, {hits} memo hits")
print(f"cached {len(out)} results")
print("results: " + ",".join(map(str, out)))
