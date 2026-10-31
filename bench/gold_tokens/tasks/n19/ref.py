nums = []
for word in "code 500 retry 3 code 200 code 500 retry 1".split():
    try:
        nums.append(int(word))
    except ValueError:
        pass
top = sorted(set(nums), reverse=True)[:2]
print("results: " + ",".join(map(str, top)))
