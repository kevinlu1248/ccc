/*
ID: kevinlu2
TASK: swap
LANG: C++
*/
// created on 2/23/2020 11:14 AM by Kevin Lu
// C:\Users\XPS\ccc\USACO

/*
8 5 1003
2 5
3 7
5 6
2 9
1 5
 */

#include <cstdio>
#include <algorithm>
// <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m, k, perm[N][2], tmp[N], arr[N], ord = 0;
bool flag;

int main() {
    FILE *inp = fopen("swap.in", "r");
    FILE *outp = fopen("swap.out", "w");
    fscanf(inp, "%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) fscanf(inp, "%d%d", &perm[i][0], &perm[i][1]);
    for (int i = 1; i <= n; i++) arr[i] = i;
    while (!flag) {
        ord++;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j <= (perm[i][1] - perm[i][0]) / 2; j++)
                swap(arr[perm[i][0] + j], arr[perm[i][1] - j]);
        }
        for (int &i: arr) if (i) printf("%d ", i); puts("");
        flag = true;
        for (int i = 0; i < n; i++) if (arr[i] != i) flag = false;
    }
    k %= ord;
    printf("%d\n", ord);
    while (k--) {
        for (int &i: arr) if (i) printf("%d ", i); puts("");
        for (int i = 0; i < m; i++)
            for (int j = 0; j <= (perm[i][1] - perm[i][0]) / 2; j++) swap(arr[perm[i][0] + j], arr[perm[i][1] - j]);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", arr[i]);
        fprintf(outp, "%d\n", arr[i]);
    }
    return 0;
}