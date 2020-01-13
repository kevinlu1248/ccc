// ccc15j4.cpp
// Created on 2020-01-12 2:44 p.m. by Kevin Lu
// Happy or Sad

/*
5
R 2
R 3
W 5
S 2
S 3


14
R 12
W 2
R 23
W 3
R 45
S 45
R 45
S 23
R 23
W 2
S 23
R 34
S 12
S 34
 */

#include <cstdio>
#include <algorithm>
// <bits/stdc++.h>
using namespace std;
char c;
int m, x, t[110], w[110]; // t is when they sent they're last message and w is how long they've waited
int current=0;

int main() {
    for (int i=0;i<110;i++) t[i]=-1;

    scanf("%d", &m);
    for (int i=0;i<m;i++) {
        scanf(" %c %d", &c, &x);
//        printf("c = %c; x = %d;\n", c, x);

        if (c == 'R') {
            t[x] = current;
            current++;
        } else if (c == 'S') {
//            printf("current = %d; t = %d;\n", current, t[x]);
            w[x] += current - t[x];
            t[x] = -1;
            current++;
        } else if (c == 'W') {
            current += x - 1;
        }
//        for (int i=0;i<110;i++) if (t[i] != -1) printf("%d %d;", i, t[i]);
//        printf("current = %d\n", current);
    }

    for (int i=0;i<110;i++) {
        if (t[i] != -1) printf("%d %d\n", i, -1);
        else if (w[i] != 0) printf("%d %d\n", i, w[i]);
    }
    return 0;
}