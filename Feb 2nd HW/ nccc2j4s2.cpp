//  nccc2j4s2
// created on 2/5/2020 10:16 PM by Kevin Lu
//  A Geometry Problem 

#include <cstdio>
#include <algorithm>
// <bits/stdc++.h>
using namespace std;
int a1, b1, a2, b2, a3, b3, s = 0;

bool solve() {
    int A = a1 * b1 + a2 * b2 + a3 * b3;
    while (s * s < A) s++;
    if (s * s != A) return false; // not perfect square
    if (a1 == s || b1 == s) {
        if (b1 == s) swap(&a1, &b1);
            // I give up this is too boring
    }
}

int main() {
//    for (int i = 0; i < 3; i++) scanf("%d%d", &arr[i][0], &arr[i][1]);
    scanf("%d%d%d%d%d%d", &a1, &b1, &a2, &b2, &a3, &b3);
    printf("%s\n", solve() ? "YES" : "NO");
    return 0;
}