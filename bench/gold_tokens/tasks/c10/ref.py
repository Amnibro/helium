xs = [10, 25, 18, 40, 32]
gaps = [b - a for a, b in zip(xs, xs[1:])]
ranks = [1 + sum(g < x for g in gaps) for x in gaps]
print("results: " + ",".join(map(str, ranks)))
