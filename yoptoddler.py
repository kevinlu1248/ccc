# ccc04s2

'''
Sample Input
Copy

5 2
99 97 100 85 -4
95 97 100 62 1000

Sample Output
Copy

Yodeller 5 is the TopYodeller: score 996, worst rank 5

Explanation of Sample Output
After Round 1

Yodeller 3 has score 100, and is ranked 1.
Yodeller 1 has score 99, and is ranked 2.
Yodeller 2 has score 97, and is ranked 3.
Yodeller 4 has score 85, and is ranked 4.
Yodeller 5 has score -4, and is ranked 5.
After Round 2

Yodeller 5 has score 996, and is ranked 1.
Yodeller 3 has score 200, and is ranked 2.
Yodeller 1 has score 194, and is ranked 3.
Yodeller 2 has score 194, and is ranked 3.
Yodeller 4 has score 147, and is ranked 5.
'''

n, k = map(int, input().split())
scores = [list(map(int, input().split())) for _ in range(k)]

scoreboard = list(enumerate(map(sum, zip(*scores))))
top = 0
for i, v in scoreboard[1:]:
    if v > scoreboard[i - 1][1]:
        top = i
top += 1

# hw 
# 2004 - 2005 S1-S3
# 2005 S4
