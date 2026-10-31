def last_nonzero_digit(n):
    n = abs(n)
    while n and n % 10 == 0:
        n //= 10
    return n % 10

memo, hits, out = {}, 0, []
for x in [120, 4500, 70, 89, 105, 60]:
    if x in memo:
        hits += 1
    else:
        memo[x] = last_nonzero_digit(x)
    out.append(memo[x])
print(f"subfunction ran on {len(out)} results, {hits} memo hits")
print("results: " + ",".join(str(x) for x in sorted(out) if x >= 6))
