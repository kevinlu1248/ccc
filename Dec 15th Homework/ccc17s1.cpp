// ccc17s1
// Name of Problem

/*
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
 */

#include <cstdio>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
const int MAX = 100010;
int N, a[MAX], b[MAX], sa, sb, res = 0;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    for (int i = 0; i < N; i++) scanf("%d", &b[i]);
    for (int i = 0; i < N; i++) {
        sa += a[i], sb += b[i];
        if (sa == sb) res = i + 1;
    }
    printf("%d\n", res);
    return 0;
}