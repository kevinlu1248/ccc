// ccc19s5again
// created on 2/9/2020 4:42 PM by Kevin Lu
// Triangles

/*
4 2
3
1 2
4 2 1
6 1 4 2

 */

#include <cstdio>
#include <algorithm>
// <bits/stdc++.h>
using namespace std;
const int N = 3020;
int n, k, dp[14][N][N];

//void fill(int layer, int size) {
//    dp[layer];
//}

void solve() {
    int s = 0;
    while ((1 << ++s) < k) {
        dp[s];
//        int tsize = (n >> (s - 1)) - (n >> s);
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            scanf("%d", dp[0][i][j]);
    solve();
    return 0;
}