def digit_records(n):
    count, best = 0, -1
    for d in str(abs(n)):
        if int(d) > best:
            best = int(d)
            count += 1
    return count

memo, hits, out = {}, 0, []
for x in [142, 365, 876]:
    if x in memo:
        hits += 1
    else:
        memo[x] = digit_records(x)
    out.append(memo[x])
print(f"subfunction ran on {len(out)} results, {hits} memo hits")
value, i = len(out), len(out)
while i > 0 and out[i - 1] > value:
    i -= 1
out.insert(i, value)
print("results: " + ",".join(map(str, out)))
