def is_prime(n):
    return n >= 2 and all(n % d for d in range(2, int(n ** 0.5) + 1))

def next_prime(n):
    n += 1
    while not is_prime(n):
        n += 1
    return n

text = "AbCdEfGh"
codes = [ord(c) for c in text[len(text) // 2:]]
codes = [next_prime(c) if is_prime(c) else c for c in codes]
print("results: " + ",".join(str(c) for c in sorted(codes) if c >= 65))
