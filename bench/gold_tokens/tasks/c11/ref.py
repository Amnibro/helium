def digit_sum(n):
    return sum(int(d) for d in str(abs(n)))

xs = sorted(x for x in [25, 12, 8, 30, 15, 40] if x <= 25)
memo, hits, out = {}, 0, []
for x in xs:
    if x in memo:
        hits += 1
    else:
        memo[x] = digit_sum(x)
    out.append(memo[x])
print(f"subfunction ran on {len(out)} results, {hits} memo hits")
print("results: " + ",".join(map(str, out)))
