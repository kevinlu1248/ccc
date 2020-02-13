// nccc6s4
// created on 2/10/2020 10:18 AM by Kevin Lu
// Pusheen Plays Neko Atsume

/*
2 0 2 0 3
1
2
3

2
4
4

5 2 3 2 3
12345 123 12346 542 3
123 321 254 12 0
1 0 1 0 0
1000000000 1000000000 10000000000 1000000000 0
999999999 999999999 99999999 999999999 0
 */
#include <cstdio>
#include <cstring>
#include <stdlib.h>
// <bits/stdc++.h>
using namespace std;
const int N = (1e7) + 7;
int q, a, b, c, d, dp[N][3], v; // dp[i] is f(x), g(x), h(x)

void solve(int x) {
    // computing dp[x][0]
    if (!dp[x][1]) {
        if (x / a - b > 0) dp[x][1] = dp[x / a - b][0];
        else dp[x][1] = 1;
    }
    if (!dp[x][2]) {
        if (x / c - d > 0) dp[x][2] = dp[x / d - c][0];
        else dp[x][2] = 1;
    }
    dp[x][0] = dp[x][1] + dp[x][2];
    if (x + b < N / a)
        for (int i = a * (x + b); i < a * (x + b + 1); i++)
            dp[i][1] = dp[x][0];
    if (x + d < N / c)
        for (int i = c * (x + d); i < c * (x + d + 1); i++)
            dp[i][2] = dp[x][0];
//    printf("%d: g: [%d, %d), h: [%d, %d)\n", x, a * (x + b), a * (x + b + 1), c * (x + d), c * (x + d + 1));
}

int f(int x) {
//    printf("finding %d;\n", x);
    if (x <= 0) return 1;
    if (x < N) return dp[x][0];
//    if (x < N) return f(x / a - b) + f(x / c - d);
    return f(x / a - b) + f(x / c - d);
}

// brute force
int dp1[N];
int brute(int x) {
//    printf("finding: %d, %d\n", x, dp1[x]);
    if (x <= 0) return 1;
    if (x < N && dp1[x]) return dp1[x];
    if (x < N) return dp1[x] = f(x / a - b) + f(x / c - d);
    return f(x / a - b) + f(x / c - d);
}

int main() {
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &q);
    dp[0][0] = 1;
    for (int i = 1; i < N; i++) solve(i);
//    for (int i = 0; i < q; i++) {
//        scanf("%d", &v);
//        printf("%d\n", f(v));
//    }

    memset(dp1, 0, sizeof(dp1)); dp1[0] = 1;
    for (int i = 0; i < 1e7; i++) {
        int x = rand() % 1000000000;
//        printf("%d: %d, %d\n", x, brute(x), f(x));
        if (brute(x) != f(x)) {
            printf("Found error: %d, f(x) = %d, b(x) = %d\n", x, f(x), brute(x));
        }
        if (i == 1e7 - 1) puts("Done");
    }

//    for (int i = 0; i < 50; i++) printf("%d\n", brute(i));
//    for (int i = 1; i < 200; i++) printf("%d: %d, %d, %d\n", i, dp[i][0], dp[i][1], dp[i][2]);
//    for (int i = 3e8; i < 3e8 + 1e5; i++) f(i);
//    printf("%d", f((1e8)));
    return 0;
}