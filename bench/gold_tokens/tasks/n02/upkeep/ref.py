xs = sorted(set([72, 95, 60, 88, 95, 41]), reverse=True)[:2]
print(f"cached {len(xs)} results")
print("results: " + ",".join(map(str, xs)))
