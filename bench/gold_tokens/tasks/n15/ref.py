xs = [9, 4, 9, 2]
i = len(xs) - 1 - xs[::-1].index(max(xs))
del xs[i]
print("results: " + ",".join(map(str, xs)))
