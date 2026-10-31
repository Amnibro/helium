def digit_sum(n):
    return sum(int(d) for d in str(abs(n)))

xs = [digit_sum(digit_sum(x)) for x in [12, 25, 30, 45, 18]]
print("results: " + str(sum(set(xs))))
