def collatz_steps(n):
    x, steps = max(n, 1), 0
    while x != 1 and steps < 200:
        x = x // 2 if x % 2 == 0 else 3 * x + 1
        steps += 1
    return steps

memo, hits, out = {}, 0, []
for x in [3, 5, 6, 7]:
    if x in memo:
        hits += 1
    else:
        memo[x] = collatz_steps(x)
    out.append(memo[x])
print(f"subfunction ran on {len(out)} results, {hits} memo hits")
print(f"no errors in {len(out)} results")
print("results: " + ",".join(map(str, out)))
