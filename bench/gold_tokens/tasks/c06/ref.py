def collatz(n):
    return n // 2 if n % 2 == 0 else 3 * n + 1

seq = [10]
while seq[-1] != 1:
    seq.append(collatz(seq[-1]))
i = 0
while i < len(seq) and seq[i] > 4:
    i += 1
print("results: " + ",".join(map(str, seq[i:])))
