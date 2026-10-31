lengths = [len(w) for w in "a bb ccc dddd".split() if len(w) >= 2]
print("results: " + ",".join(map(str, lengths)))
