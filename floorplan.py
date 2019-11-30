# ccc03s3
# ccc04s2

'''
Sample Input 1
Copy

105
14
16
IIIIIIIIIIIIIIII
I......I.......I
I......III.....I
I........I.....I
I........IIIIIII
IIIIIIIIII.....I
I.I......I.....I
III..III.I.....I
I....I.IIIII...I
I....I.....III.I
I....I.......I.I
I....I.....III.I
I....I.....I...I
IIIIIIIIIIIIIIII

Output for Sample Input 1
Copy

4 rooms, 1 square metre(s) left over

Sample Input 2
Copy

13
2
3
.I.
.I.

Output for Sample Input 2
Copy

2 rooms, 9 square metre(s) left over
'''

from itertools import product

s, length, width = (int(input()) for _ in range(3))
plan = [input() for _ in range(length)]
rooms = []
visited = set()

def fplan(tup):
    return plan(tup[0], tup[1])

def size(x, y):
    # print(visited, x, y)
    out = 1
    for (i, j) in ((x, y + 1), (x, y - 1), (x + 1, y), (x - 1, y)):
        if length > i >= 0 and width > j >= 0:
            if plan[i][j] == "." and (i, j) not in visited:
                visited.add((i, j))
                out += size(i, j)
            
    return out

for (x, y) in product(range(length), range(width)):
    if plan[x][y] == '.' and (x, y) not in visited:
        visited.add((x, y))
        rooms.append(size(x, y))

rooms.sort(reverse=True)        

rooms_tiled = 0
for room in rooms:
    if s > room:
        s -= room
        rooms_tiled += 1
# while s >= rooms[-1]:
#     rooms_tiled += 1
#     s -= rooms.pop()

print("{} rooms, {} square metre(s) left over".format(rooms_tiled, s))
# print(plan)