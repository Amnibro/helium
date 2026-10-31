seq = [14]
while seq[-1] != 1:
    n = seq[-1]
    seq.append(n // 2 if n % 2 == 0 else 3 * n + 1)
peaks = [seq[0]]
for x in seq[1:]:
    if x > peaks[-1]:
        peaks.append(x)
print("results: " + ",".join(map(str, peaks)))
