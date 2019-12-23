# ccc17s1

'''
Sample Input 1
Copy

3
1 3 3
2 2 6

Sample Output 1
Copy

2

Explanation for Sample Output 1

After 2 days, each team had scored a total of 4 runs.
Sample Input 2
Copy

3
1 2 3
4 5 6

Sample Output 2
Copy

0

Explanation for Sample Output 2

The only time when the Swifts and the Semaphores had scored the same number of runs was the beginning of the season.
Sample Input 3
Copy

4
1 2 3 4
1 3 2 4

Sample Output 3
Copy

4
'''

n, a, b, sum1, sum2, maxi = int(input()), tuple(map(int, input().split())), tuple(map(int, input().split())), 0, 0, -1
for i, x, y in zip(range(n), a, b):
    sum1 += x
    sum2 += y
    if sum1 == sum2:
        maxi = i
print(maxi + 1)