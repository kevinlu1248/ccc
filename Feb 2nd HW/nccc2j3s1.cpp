// nccc2j3s1
// created on 2/5/2020 9:47 PM by Kevin Lu
// An Array Problem

/*
5
1
2
1
10
3

7
 */

#include <cstdio>
//#include <queue>
#include <algorithm>
#include <w32api/mmcobj.h>
// <bits/stdc++.h>
using namespace std;
int n, mx, sm, ans1, ans2;
Node arr;

void solve2() {
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (int i: arr) {
        sm += i;
        mx = max(mx, i);
    }
    ans1 = sm / 2;
    ans2 = sm - mx;
    printf("%d\n", min(ans1, ans2));
}

int main() {
//    priority_queue<int> Q;
    scanf("%d", &n);
    solve2();
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &inp);
//        Q.push(inp);
//    }
//    while (Q.size() >= 2) {
//        a = Q.top(); Q.pop();
//        b = Q.top(); Q.pop();
////        printf("Computing: %d and %d\n", a, b);
//        ans += b;
//        if (a - b > 0) Q.push(a - b);
////        printf("Difference: %d\n", a - b);
//    }
//    printf("%d\n", ans);
    return 0;
}