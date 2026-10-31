sums, total = [], 0
for x in [3, 8, 12, 5, 6]:
    if x % 2 == 0:
        total += x
        sums.append(total)
print("results: " + ",".join(map(str, sums)))
