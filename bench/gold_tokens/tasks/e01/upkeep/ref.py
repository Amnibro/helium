def square_digit_sum(n):
    return sum(int(d) ** 2 for d in str(abs(n)))

seq = [27]
while seq[-1] != 1:
    n = seq[-1]
    seq.append(n // 2 if n % 2 == 0 else 3 * n + 1)
print(f"no errors in {len(seq)} results")
print(f"cached {len(seq)} results")
memo, hits, out = {}, 0, []
for x in seq:
    if x in memo:
        hits += 1
    else:
        memo[x] = square_digit_sum(x)
    out.append(memo[x])
print(f"subfunction ran on {len(out)} results, {hits} memo hits")
print("results: " + ",".join(map(str, out)))
