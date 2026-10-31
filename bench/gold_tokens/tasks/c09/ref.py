seq = [12]
while seq[-1] != 1:
    n = seq[-1]
    seq.append(n // 2 if n % 2 == 0 else 3 * n + 1)
print("results: " + ",".join(map(str, seq)))
