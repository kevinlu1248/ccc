
'''
5
44,62
34,69
24,78
42,44
64,10
'''

n = int(input())
lst = []
for i in range(n):
    inp = input().split(',')
    x = int(inp[0])
    y = int(inp[1])
    lst.append((x, y))

xmin, xmax, ymin, ymax = lst[0][0], lst[0][0], lst[0][1], lst[0][1]

for x, y in lst:
    # print("{} {}".format(x, y))
    if x > xmax: xmax = x
    if x < xmin: xmin = x
    if y > ymax: ymax = y
    if y < ymin: ymin = y

print("{},{}\n{},{}\n".format(xmin - 1, ymin - 1, xmax + 1, ymax + 1))
