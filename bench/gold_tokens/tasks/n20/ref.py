xs = [min(max(x, 0), 100) for x in [12, 18, -3, 25, 140, 33]]
deltas = [b - a for a, b in zip(xs, xs[1:])]
if any(abs(b - a) > 50 for a, b in zip(deltas, deltas[1:])):
    print("error: gap exceeds limit (1 total)")
else:
    print(f"no errors in {len(deltas)} results")
print("results: " + ",".join(map(str, deltas)))
