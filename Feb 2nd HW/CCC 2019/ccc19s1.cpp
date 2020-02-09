// ccc19s1
// created on 2/9/2020 8:35 AM by Kevin Lu
// Flipper

#include <cstdio>
#include <algorithm>
// <bits/stdc++.h>
using namespace std;
int c, v, h, arr[2][2] = {{1, 2}, {3, 4}};

int main() {
    while (true) {
        scanf("%c", &c);
        if (c == '\n') break;
        if (c == 'V') v++;
        else h++;
    }
    if (h & 1) {swap(arr[0][0],arr[1][0]); swap(arr[0][1],arr[1][1]);}
    if (v & 1) {swap(arr[0][0],arr[0][1]); swap(arr[1][0], arr[1][1]);}
    printf("%d %d\n%d %d\n", arr[0][0], arr[0][1], arr[1][0], arr[1][1]);

    return 0;
}