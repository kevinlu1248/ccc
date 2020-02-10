// ccc19s5
// created on 2/9/2020 10:19 AM by Kevin Lu
// Triangle: The Data Structure

/*
4 2
3
1 2
4 2 1
6 1 4 2

 */

#include <cstdio>
#include <algorithm>
#include <queue>
// <bits/stdc++.h>
using namespace std;
const int N = 3010;
int n, k, tri[N][N], mx[N][N], c;

typedef struct Node {
    int x, y, c;
    Node (int x, int y, int c):
        x(x), y(y), c(c) {};
    bool operator< (Node const a) const {
        return c < a.c;
    }
} Node;
priority_queue<Node> Q;

void solve(){
    int cnt = (n - k + 2) * (n - k + 1) / 2;
    while (cnt && !Q.empty()) {
        Node nxt = Q.top(); Q.pop();
        int x = nxt.x, y = nxt.y;
        for (int i = 0; i < k && i <= x; i++)
            for (int j = 0; j <= i && j <= y; j++) {
                if (!mx[x - i][y - j]
                    && x - i >= y - j
                    && x - i <= n - k) { // other conditions too
                    mx[x - i][y - j] = nxt.c;
                    cnt--;
                }
            }
    }
    int ans = 0;
//    for (int i = 0; i <= n - k + 5; i++) {
//        for (int j = 0; j <= i; j++)
//            printf("%d, ", mx[i][j]);
//        printf("\n");
//    }
    for (int i = 0; i <= n - k; i++)
        for (int j = 0; j <= i; j++)
            ans += mx[i][j];
    printf("%d\n", ans);
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++) {
            scanf("%d", &c);
            Q.push(Node(i, j, c));
        }
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j <= i; j++)
//            printf("%d, ", tri[i][j]);
    solve();
    return 0;
}