# ccc17s3

'''
Sample Input 1
Copy

4
1 2 3 4

Sample Output 1
Copy

2 1

Sample Input 2
Copy

5
1 10 100 1000 2000

Sample Output 2
Copy

1 10
'''

# brute force
# from collections import Counter, defaultdict
# from itertools import combinations
# n, arr, c = int(input()), tuple(map(int, input().split())), defaultdict(list)
# for i, j in combinations(arr, 2):
#     if i != j:
#         c[i + j].append((i, j))
# print(c)

from collections import Counter, defaultdict
n, arr, dic, m, c = int(input()), Counter(map(int, input().split())), defaultdict(int), 0, 0
for i in range(2 * max(arr) + 1):
    r = i // 2 + 1 if i % 2 else i // 2
    for j in range(r):
        dic[i] += min(arr[j], arr[i - j])
for i in dic:
    v = dic[i]
    if v >= m:
        m = v
        c = 0
    if v == m:
        c += 1
print(m, c)