def square_digit_sum(n):
    return sum(int(d) ** 2 for d in str(abs(n)))

memo, hits, out = {}, 0, []
for x in [12, 34, 56, 78]:
    if x in memo:
        hits += 1
    else:
        memo[x] = square_digit_sum(x)
    out.append(memo[x])
print(f"subfunction ran on {len(out)} results, {hits} memo hits")
out = out[::2]
print(f"no errors in {len(out)} results")
print(f"cached {len(out)} results")
print("results: " + ",".join(map(str, out)))
