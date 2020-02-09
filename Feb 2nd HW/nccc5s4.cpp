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
// <bits/stdc++.h>
using namespace std;
const int N = 1000000010, K = 1000010;
int n, k, cnt, t, nxt;
vector<int> v;

int main() {
    scanf("%d%d", &n, &k);
    if (k < 3) {printf("0\n"); return 0;}

    scanf("%d", &t); v.emplace_back(t);
    scanf("%d", &t); v.emplace_back(t);
    for (int i = 2; i < k; i++) {
        scanf("%d", &t);
        v.emplace_back(t);
        cnt += (v[v.size() - 3] + 1 == v[v.size() - 2] && v[v.size() - 2] + 1 == v[v.size() - 1]);
    }
    printf("%d", cnt);
//    for (int i = 0; i < n; i++) {
//        char c;
//        scanf("%c", &c);
//        arr[i] = (c == '1');
//    }
//    cnt -= arr[0]; cnt -= arr[1];
//    for (int i = 0; i < n - 3; i++) {
//        cnt += (arr[i] && arr[i + 1] && arr[i + 2]);
//        if ((k -= arr[i + 2]) <= 0) break;
//    }
    return 0;
}