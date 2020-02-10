// nccc6s2
// created on 2/10/2020 8:07 AM by Kevin Lu
// Pusheen's Puzzle Present

/*
3
1 2 3
4 8 5
7 9 6

2

4
1
5
9
13 14 15 16
 */

#include <cstdio>
#include <algorithm>
// <bits/stdc++.h>
using namespace std;
int n, l = -1, r = -1, t, p;

int main() {
    scanf("%d", &n);
    for (int j = 0; j < n; j++) {
        if (l != -1) break;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &t);
            p = n * j + i;
            if (t == p) {
                if (r != -1) break;
                continue;
            }
            if (l == -1) l = p;
            else r = p;
        }
    }
    printf("%d\n", r - l + 1);
    return 0;
}