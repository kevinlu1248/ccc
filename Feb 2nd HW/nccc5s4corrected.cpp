// nccc5s4
// created on 2/7/2020 10:33 PM by Kevin Lu
// Sparse Binary String Counting 

/*
5 4
1
2
4
5
 */

#include <cstdio>
#include <algorithm>
#include <queue>
#include <w32api/mmcobj.h>
// <bits/stdc++.h>
using namespace std;
const int N = 1000000010, K = 1000010;
int n, k, cnt = 0, inp;
Node arr;
vector<int> v;

int main() {
    scanf("%d%d", &n, &k);
    arr[0] = 0;
    for (int i = 1; i <= k; i++) scanf("%d", &arr[i]);
    for (int i = 1; i < k - 1; i++) {
        cnt += (arr[i] - arr[i - 1]) * (n - arr[i + 2] + 1);
    }
    printf("%d\n", cnt);
    return 0;
}