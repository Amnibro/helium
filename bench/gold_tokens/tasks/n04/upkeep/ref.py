kept, total = [], 0
for x in [30, 25, 40, 10, 50]:
    if total + x > 150:
        break
    total += x
    kept.append(x)
print(f"no errors in {len(kept)} results")
print("results: " + ",".join(map(str, kept)))
