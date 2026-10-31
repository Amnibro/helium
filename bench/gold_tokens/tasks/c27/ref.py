def digit_sum(n):
    return sum(int(d) for d in str(abs(n)))

memo, hits, out = {}, 0, []
for x in [19, 28, 37, 46]:
    if x in memo:
        hits += 1
    else:
        memo[x] = digit_sum(x)
    out.append(memo[x])
print(f"subfunction ran on {len(out)} results, {hits} memo hits")
print(f"cached {len(out)} results")
i = out.index(min(out))
out[i] *= 2 ** 3
print("results: " + ",".join(map(str, out)))
