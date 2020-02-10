// ccc11s5corrected
// created on 2/9/2020 6:02 PM by Kevin Lu
// Switch

/*
5
1
1
0
1
1

10
0
1
0
0
1
0
0
0
1
1

22
0
1
0
0
1
0
0
0
1
1
1
0
1
0
0
1
0
0
0
1
1
1

*/

#include <cstdio>
#include <algorithm>
#include <queue>
// <bits/stdc++.h>
using namespace std;
const int N = 27;
int n = 0, cnt1;
bool tmp;
int32_t s;

void printb(int32_t i) {
    do {printf("%d", i & 1);} while (i >>= 1);
    printf("\n");
}

bool getPos(int32_t u, int p) {
    return (u >> p) & 1;
}

int32_t setPos(int32_t u, int p, bool v) {
    int32_t t = u & (((1 << (n + 1)) - 1) ^ (1 << p));
//    printf("%d, ", t);
    return (t ^ (v << p));
}

int val(int i) {
    int cnt = 0;
    while (i &= i - 1) cnt++;
//    printf("%d\n", cnt);
    return cnt - cnt1;
}

bool check(int32_t i) {
    int cnt = -1;
    if (i == 1998735) printf("found!");
    for (int j = 0; j < n; j++) {
//        printf("%d", getPos(i, j));
        if (getPos(i, j)) {
            if (cnt == -1) cnt++;
            cnt++;
        }
        else {
            if (cnt < 4 && j != -1) return false;
            cnt = 0;
        }
    }
    return cnt >= 4;
}

bool vis[1 << N];

int bfs() {
    queue<int32_t> Q; Q.push(s);
    while (!Q.empty()) {
        int32_t now = Q.front(); Q.pop();
        if (vis[now]) continue; vis[now] = true;
        printf("now traversing "); printb(now);
        for (int i = 0; i < n; i++) {
            if (getPos(now, i)) continue;
            int nxt = setPos(now, i, true);
//            printf("now traversing "); printb(nxt);
            if (check(nxt)) return val(nxt);
            Q.push(nxt);
        }
    }
    return -1;
}

int main() {
    scanf("%d", &n);
    cnt1 = 0;
    for (int i = n; i--;) {
        scanf("%d", &tmp);
//        s |= (tmp << i);
        s = setPos(s, i, tmp);
//        printb(s);
    }
    cnt1 = val(s);
//    printf("%d\n", cnt1);
    printf("%d\n", bfs());
    return 0;
}