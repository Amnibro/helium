xs = [1, 2, 3, 4, 5, 6, 7]
sums = [sum(xs[i:i + 3]) for i in range(0, len(xs), 3)]
print("results: " + ",".join(map(str, sums)))
