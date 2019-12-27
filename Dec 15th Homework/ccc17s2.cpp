// ccc
// Name of Problem

/*
Sample Input
Copy

8
10 50 40 7 3 110 90 2

Sample Output
Copy

10 40 7 50 3 90 2 110
 */

#include <cstdio>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
int N, arr[110], res[110];

int main() {
    scanf("%d\n", &N);
    for (int i = 0; i < N; i++) {
        printf("%d\n", i);
        scanf("%d\n", &arr[i]);
    }
//    sort(arr, arr + N);
//    if (N % 2) {
//        for (int i = 1; i <= N; i++) {
//            if (i % 2)
//                res[i] = arr[N / 2 - i / 2];
//            else
//                res[i] = arr[N / 2 + i / 2];
//        }
//    } else {
//        for (int i = 1; i <= N; i++) {
//            if (i % 2)
//                res[i] = arr[N / 2 - i / 2];
//            else
//                res[i] = arr[N / 2 + i / 2];
//        }
//    }
//    for (int i = 0; i < N; i++) printf("%d\n", arr[i]);
//    for (int i = 0; i < N; i++) printf("%d\n", res[i]);
    return 0;
}