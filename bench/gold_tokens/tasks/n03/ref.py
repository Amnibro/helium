from itertools import accumulate

print("results: " + ",".join(map(str, accumulate([5, 10, 15, 20]))))
