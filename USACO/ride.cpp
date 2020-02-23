/*
ID: kevinlu2
TASK: ride
LANG: C++
created on 2/23/2020 9:43 AM by Kevin Lu
*/

/*
COMETQ
HVNGAT
GO
ABSTAR
USACO
STAY
 */

#include <cstdio>
#include <algorithm>
// <bits/stdc++.h>
using namespace std;
const int N = 10;
int n, x = 1, y = 1;
char a[N], b[N];
//string a, b;

int main() {
    FILE* inp = fopen("ride.in", "r");
    FILE* out = fopen("ride.out", "w");
    fscanf(inp, "%s%s", a, b);
    for (char &c: a) {
        if (!c) break;
        x *= c - 'A' + 1;
        x %= 47;
    }
    for (char &c: b) {
        if (!c) break;
        y *= c - 'A' + 1;
        y %= 47;
    }
    printf("%d %d", x, y);
    fprintf(out, "%s\n", (x % 47 == y % 47) ? "GO" : "STAY");
    return 0;
}