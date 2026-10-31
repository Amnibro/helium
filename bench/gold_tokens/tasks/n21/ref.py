seq = [27]
while seq[-1] <= 1000:
    n = seq[-1]
    seq.append(n // 2 if n % 2 == 0 else 3 * n + 1)
kept = [x for x in seq if abs(x) <= 50]
print(f"cached {len(kept)} results")
print("results: " + ",".join(map(str, kept)))
