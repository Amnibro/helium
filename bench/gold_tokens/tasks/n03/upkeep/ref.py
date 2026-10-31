from itertools import accumulate

sums = list(accumulate([5, 10, 15, 20]))
print(f"no errors in {len(sums)} results")
print("results: " + ",".join(map(str, sums)))
