i = int(input())

a, b = 1, 1
p = 10 ** 9 + 7
for _ in range(i):
    a, b = a + b % p, a % p