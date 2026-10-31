xs = [10, 14, 19, 31, 33]
if any(abs(b - a) > 10 for a, b in zip(xs, xs[1:])):
    print("error: gap exceeds limit (1 total)")
else:
    print(f"no errors in {len(xs)} results")
print("results: " + ",".join(map(str, xs)))
