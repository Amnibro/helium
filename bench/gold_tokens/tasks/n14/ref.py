xs = [4, 9]
if len(xs) < 3:
    print("error: list shorter than minimum (1 total)")
else:
    print(f"no errors in {len(xs)} results")
print("results: " + ",".join(map(str, xs)))
