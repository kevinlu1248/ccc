// ccc16s2
// Tandem Bike

/*
 * Sample Input 1
Copy

1
3
5 1 4
6 2 4

Output for Sample Input 1
Copy

12

Explanation for Output for Sample Input 1

There is a unique optimal solution:

    Pair the citizen from Dmojistan with speed 5 5 and the citizen from Pegland with speed 6 6 .
    Pair the citizen from Dmojistan with speed 1 1 and the citizen from Pegland with speed 2 2 .
    Pair the citizen from Dmojistan with speed 4 4 and the citizen from Pegland with speed 4 4 .

Sample Input 2
Copy

2
3
5 1 4
6 2 4

Output for Sample Input 2
Copy

15

Explanation for Output for Sample Input 2

There are multiple possible optimal solutions. Here is one optimal solution:

    Pair the citizen from Dmojistan with speed 5 5 and the citizen from Pegland with speed 2 2 .
    Pair the citizen from Dmojistan with speed 1 1 and the citizen from Pegland with speed 6 6 .
    Pair the citizen from Dmojistan with speed 4 4 and the citizen from Pegland with speed 4 4 .

Sample Input 3
Copy

2
5
202 177 189 589 102
17 78 1 496 540

Output for Sample Input 3
Copy

2016
 */

#include <cstdio>
//#include <iostream>
#include <algorithm>
#include <numeric>
#include <w32api/mmcobj.h>
//#include <bits/stdc++.h>
using namespace std;
int Q, N;
Node arr;

int main() {
    scanf("%d%d", &Q, &N);
    for (int i = 0; i < 2 * N; i++) scanf("%d", &arr[i]);
    sort(arr, arr + 2 * N, greater<int>());
    if (Q == 1) {
        int s = 0;
        for (int i = 0; i < 2 * N; i += 2) s += arr[i];
        printf("%d\n", s);
    }
    if (Q == 2) printf("%d\n", accumulate(arr, arr + N, 0));
//    for (int i = 0; i < 2 * N; i++) printf("%d\n", arr[i]);
    return 0;
}