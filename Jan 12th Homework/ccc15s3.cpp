// ccc15s3
// Created on 2020-01-15 9:57 p.m. by Kevin Lu
// Gates

/*
4
3
4
1
1

2

4
6
2
2
3
3
4
4

3
 */

#include <cstdio>
#include <algorithm>
//#include <bits/stdc++.h>
//using namespace std;
int next[10100], g, p, pi;

int get_next(int n) {
    if (next[n] == n) return n;
    return next[n] = get_next(next[n]);
}

int main() {
    scanf("%d%d",&g, &p);
    for (int i = 0; i <= g; i++) next[i] = i;
    for (int i = 0; i < p; i++) {
        scanf("%d", &pi);
        int gate = get_next(pi);
        if (gate != 0) {
            next[gate] = gate - 1;
        } else {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("%d\n", p);
    return 0;
}