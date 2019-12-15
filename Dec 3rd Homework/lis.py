# longest increasing subsequence

'''
Input:
7
1 7 3 5 9 4 8

Output:
4
'''

n, arr = int(input()), list(map(int, input().split()))
lis = [1]
for i, v in enumerate(arr[1:]):
    s = 1
    for x, y in zip(arr, lis):
        if v > x and y + 1 > s: 
            s = y + 1
    lis.append(s)
print(lis[-1])