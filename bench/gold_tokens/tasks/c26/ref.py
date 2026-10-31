xs = [25, 20, 15, 4, 2]
avg = sum(xs) // len(xs)
kept = []
for x in xs:
    if x < avg:
        break
    kept.append(x)
for i, x in enumerate(kept):
    while 0 < x < 40:
        x *= 2
    kept[i] = x
print("results: " + ",".join(map(str, kept)))
