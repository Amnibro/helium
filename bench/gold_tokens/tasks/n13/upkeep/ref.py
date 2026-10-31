from itertools import accumulate

lengths = [len(w) for w in "parse the config file then retry".split()]
lengths = list(accumulate(lengths))
print("results: " + ",".join(map(str, lengths)))
