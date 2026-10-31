xs = [1]
xs += [n for n in range(2, 31) if all(n % d for d in range(2, int(n ** 0.5) + 1))]
print("results: " + ",".join(map(str, xs)))
