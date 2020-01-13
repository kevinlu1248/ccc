// ccc15j5.cpp
// Created on 2020-01-12 2:44 p.m. by Kevin Lu
// Pi day

/*
8
4

5

6
2

3
 */

#include <cstdio>
// #include <algorithm>
// <bits/stdc++.h>
using namespace std;
int a, b;
int sols[250][250];

int part(int n, int k) {
//    printf("%d %d\n", n, k);
    if (k > n)
        return 0;
    else {
        if (sols[n][k]) return sols[n][k];
        sols[n][k] = part(n - k, k) + part(n - 1, k - 1);
        return sols[n][k];
    }
}

int main() {
    for (int i = 0; i < 250; i++) sols[i][1] = 1, sols[i][i] = 1;
    for (int i = 0; i < 250; i++) sols[i][2] = i / 2;
    scanf("%d %d", &a, &b);
    printf("%d\n", part(a, b));
//    for (int i = 0; i < 250; i++) {
//        for (int j = 0; j < 250; j++) printf("%d ", sols[i][j]);
//        printf("\n");
//    }
    return 0;
}