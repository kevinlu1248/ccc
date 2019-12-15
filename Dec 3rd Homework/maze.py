# maze problem using dynamic programming

'''
input:
4
..#T
#...
S.#.
....

output:
4

input:
2
TS
#.

output:
0
'''

from collections import deque

n = int(input())
arr = [["#"] + list(input()) + ["#"] for _ in range(n)]
arr = [["#" for _ in arr[0]]] + arr + [["#" for _ in arr[0]]]

# [print(line) for line in arr]

for i, string in enumerate(arr):
    for j, char in enumerate(string):
        if char == "T":
            end = (i, j)
        if char == "S":
            start = (i, j)
            arr[start[0]][start[1]] = -1

queue = deque()
queue.append((start[0], start[1]))
def maze(arr, coord = start):
    steps = -1
    while queue:
        coord = queue.popleft()
        # print(coord)
        steps = arr[coord[0]][coord[1]]
        for coord in ((coord[0] + 1, coord[1]), (coord[0] - 1, coord[1]), (coord[0], coord[1] + 1), (coord[0], coord[1] - 1)):
            if coord == end:
                return steps + 1
            elif arr[coord[0]][coord[1]] == ".":
                arr[coord[0]][coord[1]] = steps + 1
                queue.append(coord)
    return -1

print(maze(arr))
