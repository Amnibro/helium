def square_digit_sum(n):
    return sum(int(d) ** 2 for d in str(abs(n)))

memo, hits, out = {}, 0, []
for x in [19, 7, 12, 23]:
    if x in memo:
        hits += 1
    else:
        memo[x] = square_digit_sum(square_digit_sum(x))
    out.append(memo[x])
print(f"subfunction ran on {len(out)} results, {hits} memo hits")
errors = []
if len(out) < 2:
    errors.append("not enough items to pair")
else:
    out = [out[i] + out[i + 1] for i in range(0, len(out) - 1, 2)]
if errors:
    print(f"error: {errors[-1]} ({len(errors)} total)")
else:
    print(f"no errors in {len(out)} results")
print("results: " + ",".join(map(str, out)))
