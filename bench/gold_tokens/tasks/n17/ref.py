text = "retry loop".lower()
print("results: " + ",".join(str(text.count(v)) for v in "aeiou"))
