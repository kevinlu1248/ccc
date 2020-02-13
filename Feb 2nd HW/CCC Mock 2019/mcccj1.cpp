// mcccj1
// created on 2/8/2020 8:20 AM by Kevin Lu
// What is n, daddy?

#include <cstdio>
#include <algorithm>
#include <w32api/mmcobj.h>
// <bits/stdc++.h>
using namespace std;
Node arr = {0, 1, 2, 2, 3, 3, 3, 2, 2, 1, 1};
int n;

int main() {
    scanf("%d", &n);
    printf("%d\n", arr[n]);
    return 0;
}