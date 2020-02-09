// ccc11s3
// created on 2/8/2020 7:51 PM by Kevin Lu
// Alice Through the Looking Glass 

#include <cstdio>
#include <algorithm>
//#include <math.h>
// <bits/stdc++.h>
using namespace std;
int t, a, b, c;
int isGlass[5][5] = {
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
};
int maybeGlass[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0},
};

int pow5(int k) {
    int i = 1;
    while (--k) i *= 5;
    return i;
}

bool glass(int m, int x, int y) {
//    printf("%d, %d\n", x, y);
    int nx = x / pow5(m), ny = y / pow5(m);
//    printf("%d, %d\n", nx, ny);
    if (isGlass[nx][ny]) return true;
    if (maybeGlass[nx][ny] && m > 1) {
        int x2 = x % pow5(m); int y2 = y % pow5(m);
        return glass(m - 1, x2, y2);
    }
    return false;
}

int main() {
    scanf("%d", &t);
//    printf("%d\n", isGlass[1][0]);
    for (int i = 0; i < t; i++) {
        scanf("%d%d%d", &a, &b, &c);
        printf("%s\n", glass(a, b, c) ? "crystal" : "empty");
    }
    return 0;
}