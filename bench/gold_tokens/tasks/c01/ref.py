def collatz(n):
    return n // 2 if n % 2 == 0 else 3 * n + 1

seq = [5]
while seq[-1] != 1:
    seq.append(collatz(seq[-1]))
print(f"no errors in {len(seq)} results")
print("results: " + ",".join(map(str, seq)))
