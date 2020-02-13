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
10252
 */
#include <cstdio>
#include <algorithm>
#include <iostream>
// <bits/stdc++.h>
using namespace std;
const int N = (1e7) + 7;
int q, a, b, c, d, dp[N], v;

int f(int x) {
    if (x <= 0) return 1;
    if (x < N && dp[x]) return dp[x];
    if (x < N) return f(x / a - b) + f(x / c - d);
    return f(x / a - b) + f(x / c - d);
}

int main() {
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &q);
//    for (int i = 3e8; i < 4e8; i++) f(i);
    for (int i = 0; i < 200; i++) printf("%d: %d\n", i, f(i));
    printf("%d", f((1e8)));
    return 0;

}