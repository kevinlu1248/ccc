// ccc10s3
// created on 2/8/2020 7:17 PM by Kevin Lu
// Firehose

/*
Sample Input
Copy

4
0
67000
68000
77000
2

Output for Sample Input
Copy

5000
 */

#include <cstdio>
#include <algorithm>
#include <functional>
// <bits/stdc++.h>
using namespace std;
const int K = 1010;
int n, arr[K], dis[K], k, ans = 1000000;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &k);
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) printf("%d, ", arr[i]); printf("\n");
    for (int i = 0; i < n; i++) {
        int d = arr[(i + 1) % n] - arr[i];
        if (d < 0) d += 1000000;
        dis[i] = d;
    }
    sort(dis, dis + n, greater<int>());
    for (int i = 0; i < n; i++) printf("%d, ", dis[i]); printf("\n");
    for (int i = 0; i < k; i++) ans -= dis[i];
    printf("%d\n", ans);
    return 0;
}