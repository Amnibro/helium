lengths = [len(w) for w in "parse the config file then retry".split()]
i = len(lengths) - 1 - lengths[::-1].index(max(lengths))
del lengths[i]
print("results: " + ",".join(map(str, lengths)))
