kept, total = [], 0
for x in [30, 25, 40, 10, 50]:
    if total + x > 100:
        break
    total += x
    kept.append(x)
print("results: " + ",".join(map(str, kept)))
