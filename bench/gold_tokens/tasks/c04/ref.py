def digit_sum(n):
    return sum(int(d) for d in str(abs(n)))

xs = [19, 28, 37, 8, 40]
for i, x in enumerate(xs):
    if x < 10:
        break
    xs[i] = digit_sum(x)
print("results: " + ",".join(map(str, xs)))
