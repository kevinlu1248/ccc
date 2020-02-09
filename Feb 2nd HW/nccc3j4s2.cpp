// nccc3j4s2
// created on 2/7/2020 6:21 PM by Kevin Lu
// A Median Problem 

/*
3
1 2 3
4 5 6
7 8 9
 */

#include <cstdio>
#include <algorithm>
// <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, med, arr[N], arr2[N];

int main() {
    scanf("%d", &n); med = (n + 1) / 2 - 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) scanf("%d", &arr[j]);
        sort(arr, arr + n);
        arr2[i] = arr[med];
//        printf("%d\n", arr[med]);
    }
    sort(arr2, arr2 + n);
    printf("%d\n", arr2[med]);
    return 0;
}