
'''
4
0 0
1 0
2 0
1 1

5
0 0
0 1
3 0
3 2
9 8

5
0 0
0 1
0 2
1 3
1 4
'''

n = int(input())
lst = [list(map(int, input().split())) for _ in range(n)]

eps = 0.000000001

class Point:
    x, y = 0, 0
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def __mod__(self, other): # cross product
        return self.x * other.y - self.y * other.y
    def __sub__(self, other):
        return Point(self.x - other.x, self.y - other.y)

def nondeg(a, b, c):
    return abs((a - b) % (c - b)) > eps

if __name__ == '__main__':
    cnt = 0
    for i in range(n):
        for j in range(i + 1, n):
            for k in range(j + 1, n):
                a, b, c = Point(lst[i][0], lst[i][1]), Point(lst[j][0], lst[j][1]), Point(lst[k][0], lst[k][1])
                cnt += nondeg(a, b, c)
    print(cnt)
