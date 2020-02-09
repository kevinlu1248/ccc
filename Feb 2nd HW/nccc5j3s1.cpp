// nccc5j3s1
// created on 2/7/2020 7:03 PM by Kevin Lu
// Median Triplets

#include <cstdio>
#include <algorithm>
// <bits/stdc++.h>
using namespace std;
int const N = 120;
int n, x, arr[N], ans;

int main() {
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            int a = 0, b = 0;
            for (int j = 0; j < i; j++) if (arr[j] <= arr[i]) a++;
            for (int j = i + 1; j < n; j++) if (arr[j] >= arr[i]) b++;
            ans += a * b;
        }
    }
    printf("%d\n", ans);
    return 0;
}