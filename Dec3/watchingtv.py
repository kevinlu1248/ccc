# 2

'''
12 
1 3 
3 4 
0 7 
3 8 
15 19 
15 20 
10 15 
8 18 
6 12 
5 10 
4 14 
2 9
'''

arr = []
for _ in range(int(input())):
    arr.append(tuple(map(int, input().split())))
arr.sort(key=(lambda x: x[1] - x[0]))

chosen = [arr[0]]
for a, b in arr:
    for x, y in chosen:
        if a < x < b or x < a < y:
            chosen.append((x, y))
print(chosen)
