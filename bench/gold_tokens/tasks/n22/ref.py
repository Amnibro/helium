from itertools import accumulate

xs = [20, 35, 15, 40, 10]
i = len(xs) - 1 - xs[::-1].index(max(xs))
del xs[i]
kept, total = [], 0
for x in xs:
    if total + x > 60:
        break
    total += x
    kept.append(x)
print("results: " + ",".join(map(str, accumulate(kept))))
