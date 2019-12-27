# quick fibonacci sequence


import time
p = 1000000007


# quick exponentiation (mod 1000000007) (with integers)
# outputs x ^ n
def exp(x, n):
    res = 1
    x %= p
    while n:
        if res % 2:
            res *= x
            res %= p
        x *= x
        x %= p
        n >>= 1
    return res % p
    # i, res = 1, x
    # while 2 * i < n:
    #     i *= 2
    #     res = res ** 2 % p
    # while i < n:
    #     i += 1
    #     res = res * x % p
    # return res

# quick exponentiation
start = time.time()
base, exponent = 2, 1000000000
print(exp(base, exponent))
print(time.time() - start)

# regular exponentiation
start = time.time()
print(base ** exponent % p)
print(time.time() - start)


'''
from itertools import product
p = 1000000007

class Matrix:

    def __init__(self, array): 
        # assume its rectangular
        self.array = array
        self.width = len(array[0])
        self.height = len(array)

    def __mul__(self, other):
        if self.width is not other.height:
            raise Exception("Length and width not equal")
        res = [[0 for _ in range(other.width)] for __ in range(self.height)]
        for x, y in product(range(self.height), range(other.width)):
            val = 0
            for i in range(self.width):
                val = (val + (self.array[i][x] * other.array[y][i] % p) ) % p
            # print(x, y, val)
            res[x][y] = val
        return Matrix(res)

    def __pow__(self, n):
        multiplier = Matrix(self.array)
        res = Matrix(self.array)
        while n:
            if n % 2 == 1: res *= multiplier
            multiplier *= multiplier
            n >>= 1
        return res

        # if n == 2:
        #     return self * self
        # i, res = 1, self
        # while i * 2 < n:
        #     i *= 2
        #     res **= 2
        # while i < n:
        #     i += 1
        #     res *= self
        # return res

    def __repr__(self):
        return "\n".join(map(str, self.array))

# eg.
# print(Matrix([[1, 1], [1, 0]]) ** 1234)

start = time.time()
n = int(input())
if n <= 2:
    print(1)
else:
    arr = Matrix([[1, 1], [1, 0]]) ** (n - 2)
    print(arr.array[0][0] + arr.array[0][1])

'''