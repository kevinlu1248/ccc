// ccc19s5
// created on 2/9/2020 10:19 AM by Kevin Lu
// Triangle: The Data Structure

/*
4 2
3
1 2
4 2 1
6 1 4 2

7 3
3
1 2
4 2 1
6 1 4 2
4 2 1 4 5
2 1 6 1 4 7
8 2 1 6 1 4 7

 */

#include <cstdio>
#include <algorithm>
// <bits/stdc++.h>
using namespace std;
const int N = 3010;
int n, k, tri[N][N], sm[N][N];

void solve(){
    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= i; j++)
            sm[0][0] += tri[i][j];
    }
    for (int i = 1; i <= n - k; i++) {
        sm[i][0] = sm[i - 1][0];
        for (int j = 0; j < k; j++) {
            printf("sub: (%d, %d)\n", j + i - 1, j);
            sm[i][0] -= tri[j + i - 1][j];
            printf("add: (%d, %d)\n", i + k - 1, j);
            sm[i][0] += tri[i + k - 1][j];
        }
    }
    for (int l = 1; l < n - k; l++) {
        sm[0][l] = sm[l - 1][l - 1];


//        for (int i = 0; i < k; i++) {
//            for (int j = 0; j <= i; j++)
//                sm[0][0] += tri[i][j];
//        }
//        for (int i = 1; i <= n - k; i++) {
//            sm[0][i] = sm[0][i - 1];
//            for (int j = 0; j < k; j++) {
//                printf("sub: (%d, %d)\n", j + i - k + 1, j);
//                sm[0][i] -= tri[j + i - k + 1][j];
//                printf("add: (%d, %d)\n", i + k - 1, j);
//                sm[0][i] += tri[i + k - 1][j];
//            }
//        }
    }
    for (int i = 0; i < n - k + 1; i++) {
        for (int j = 0; j <= i; j++)
            printf("%d, ", sm[i][j]);
        printf("\n");
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            scanf("%d", &tri[i][j]);
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j <= i; j++)
//            printf("%d, ", tri[i][j]);
    solve();
    return 0;
}