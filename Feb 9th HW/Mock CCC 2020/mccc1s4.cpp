// mccc1s4
// created on 2/11/2020 7:25 PM by Kevin Lu
// Square Root Decomposition

/*
8 6 4
3 2 3 3 3 1 1 99
Q 1 3
U 2 1
Q 1 3
Q 4 6
Q 1 7
Q 1 8

8 6 4
3 2 3 3 3 1 1 99
Q 1 3
Q 1 2
Q 1 3
Q 4 6
Q 1 7
Q 1 8

3
2
2
5
-1
 */

#include <cstdio>
#include <algorithm>
// <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, S = 3;//330;
int n, q, b, arr[N], segs[N], nxt[N];
char type;

pair<int, int> comp(int s, int t) { // returns (value, index)
    int cnt = 0, iter = s, w = 0;
    for (int i = s; i < t; i++) {
//        printf("%d, %d, %d\n", i, arr[i], b);
        if (arr[i] > b) return make_pair(-1, i - 1);
        if (w + arr[i] > b) {
            w = arr[i];
            cnt++;
            iter = i;
        } else w += arr[i];
    }
    return make_pair(cnt, iter);
}

void init() {
    for (int i = 1; i <= n; i++) {
        pair<int, int> p = comp(i, min(n + 1, i + S));
        segs[i] = p.first;
        nxt[i] = p.second;
    }
    for (int i = 1; i <= n; i++) printf("%d, %d, %d\n", arr[i], segs[i], nxt[i]);
}

void query() {
    int l, r, ans = 0;
    scanf("%d%d", &l, &r);
//    printf("%d %d\n", l, r);
    int i = l;
    while (nxt[i] < r + 1 && nxt[i] != i) {
//        printf("%d", i);
        ans += segs[i];
        i = nxt[i];
    }
//    printf("%d, %d\n", ans, i);
    ans += comp(i, r).first;
    printf("%d\n", ans);
}

void mutate() {
    int x, v;
    scanf("%d%d", &x, &v);
    arr[x] = v;
    for (int i = max(x - S, 1); i < x; i++) {
        pair<int, int> p = comp(i, min(n + 1, i + S));
        segs[i] = p.first;
        nxt[i] = p.second;
    }
}

int main() {
    scanf("%d%d%d", &n, &q, &b);
    for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
    init();
    while (q--) {
//        printf("%d\n", q);
        getchar();
        scanf("%c", &type);
        if (type == 'Q') query();
//        else mutate();
    }
    return 0;
}