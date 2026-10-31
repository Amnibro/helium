xs = [10, 20, 30, 40, 5]
last = xs[-1]
xs = [x - last for x in xs]
for i in range(min(2, len(xs) // 2)):
    j = len(xs) - 1 - i
    xs[i], xs[j] = xs[j], xs[i]
print("results: " + ",".join(map(str, xs)))
