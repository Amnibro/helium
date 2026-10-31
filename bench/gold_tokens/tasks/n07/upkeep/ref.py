xs = [21, 23, 22, 30, 29, 18]
print("results: " + ",".join(str(b - a) for a, b in zip(xs, xs[1:]) if b > a))
