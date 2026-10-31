nums = []
for word in "order 12 qty 7 price 30 tax 3".split():
    try:
        nums.append(int(word))
    except ValueError:
        pass
print(f"no errors in {len(nums)} results")
print("results: " + ",".join(map(str, nums)))
