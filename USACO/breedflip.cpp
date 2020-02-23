/*
ID: kevinlu2
TASK: breedflip
LANG: C++
*/
// created on 2/23/2020 11:02 AM by Kevin Lu
// C:\Users\XPS\ccc\USACO

#include <cstdio>
#include <algorithm>
// <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, ans;
char a[N], b[N];
bool arr[N], flag;

int main() {
    FILE *inp = fopen("breedflip.in", "r");
    FILE *outp = fopen("breedflip.out", "w");
    fscanf(inp, "%d%s%s", &n, a, b);
    for (int i = 0; i < n; i++) arr[i] = (a[i] != b[i]); // xor
    for (bool &bo: arr) {
        if (!flag && bo) {
            flag = true;
            ans++;
        }
        if (flag && !bo) flag = false;
    }
    ans += flag;
    fprintf(outp, "%d\n", ans);
    printf("%d\n", ans);
    return 0;
}