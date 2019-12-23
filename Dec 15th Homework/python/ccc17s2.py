# ccc17s2
'''
Sample Input
Copy

8
10 50 40 7 3 110 90 2

Sample Output
Copy

10 40 7 50 3 90 2 110

7
10 50 40 7 3 110 90
'''
n, arr, res = int(input()), list(map(int, input().split())), []
arr.sort()
if n % 2:
    first, second = arr[:n // 2 + 1], arr[n // 2 + 1:]
    for i in range(n // 2):
        res.append(first[-i-1])
        res.append(second[i])
    print(" ".join(map(str, res)))
else:
    first, second = arr[:n // 2], arr[n // 2:]
    for i in range(n // 2):
        res.append(first[-i-1])
        res.append(second[i])
    print(" ".join(map(str, res)))