// ncccs1
// created on 2/8/2020 8:29 AM by Kevin Lu
// The Sum Game

/*
3
 1 3 3
 2 2 6
 */

#include <cstdio>
#include <algorithm>
// <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, arr1[N], arr2[N], s1, s2, k;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &arr1[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &arr2[i]);
    for (int i = 1; i <= n; i++) {
        s1 += arr1[i]; s2 += arr2[i];
        if (s1 == s2) k = i;
    }
    printf("%d", k);
    return 0;
}