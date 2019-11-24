# ccc 2002 s2

'''
Sample Input 1
Copy

28
7

Sample Output 1
Copy

4

Sample Input 2
Copy

13
5

Sample Output 2
Copy

2 3/5

Sample Input 3
Copy

0
7

Sample Output 3
Copy

0

Sample Input 4
Copy

55
10

Sample Output 4
Copy

5 1/2
'''

n, d = int(input()), int(input())
if not n % d:
    print(n // d)
else:
    def gcd(x, y):
        x, y = max(x, y), min(x, y)
        if not x % y:
            return y
        else:
            return gcd(y, x % y)
    g = gcd(n, d)
    print('{} {}/{}'.format(n // d, (n % d) // g, d // g))