xs = [x for x in [40, 15, 70, 25, 90] if abs(x) <= 30]
print(f"cached {len(xs)} results")
print("results: " + ",".join(map(str, xs)))
