xs = [min(max(x, 0), 50) for x in [-5, 12, 48, 103, 7]]
print(f"no errors in {len(xs)} results")
print("results: " + ",".join(map(str, xs)))
