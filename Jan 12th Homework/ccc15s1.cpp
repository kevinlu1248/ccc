// ccc15s1
// Created on 2020-01-18 6:59 p.m. by Kevin Lu
// Zero that Out

/*
4
3
0
4
0

0

10
1
3
5
4
0
0
7
0
0
6

7
 */

#include <cstdio>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
int j, k, arr[100010], ind = 0, ans = 0;

int main() {
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &j);
        if (j == 0) arr[--ind] = 0;
        else arr[ind++] = j;
    }
    for (int i = 0; arr[i]; i++) ans += arr[i];
    printf("%d", ans);
    return 0;
}