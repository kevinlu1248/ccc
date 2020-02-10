// nccc6s3
// created on 2/10/2020 8:23 AM by Kevin Lu
// Pusheen Eats Tuna Sashimi and Tuna Nigiri 

/*
Sample Input 1
Copy

1 0 0
0 0
1 0

Sample Output 1
Copy

2

Sample Input 2
Copy

4 0 0
0 0
4 0

Sample Output 2
Copy

4

Sample Input 3
Copy

1 1 0
0 0
1 1

Sample Output 3
Copy

4

Sample Input 4
Copy

2 0 1
0 0
2 0
1 0

Sample Output 4
Copy

-1
 */

#include <cstdio>
#include <algorithm>
#include <queue>
// <bits/stdc++.h>
using namespace std;
const int N = 110;
int gx, gy, n, sx, sy, tx, ty;
bool wind[N][N];

typedef struct State {
    int x, y, vx, vy, t;
    State(): State(0, 0, 0, 0, 0) {};
    State (int x, int y, int vx, int vy, int t):
        x(x), y(y), vx(vx), vy(vy), t(t) {};
    vector<State> getNext() {
//        printf("In getNext() with %d %d %d %d %d!\n", x, y, vx, vy, wind[x][y]);
        vector<State> v;
        x += vx; y += vy;
        if (x > gx || y > gy || x < 0 || y < 0
            || wind[x][y]) {
//            puts("OBO");
            return v; // out of bounds
        }
        if (abs(vx * (vx - 1) / 2) > gx - x
            || abs(vy * (vy - 1) / 2) > gy - y){
//            printf("OBO with %d %d %d %d", x, y, vx, vy);
            return v;
        }
        for (int i = -1; i < 3; i += 2) {
            State n = State(x, y, vx + i, vy, t + 1);
//            printf("%d\n", n.okay());
//            if (n.okay())
            v.emplace_back(n);
        }
        for (int i = -1; i < 3; i += 2) {
            State n = State(x, y, vx, vy + i, t + 1);
//            printf("%d\n", n.okay());
//            if (n.okay())
            v.emplace_back(n);
        }
        return v;
    }
    bool check() {
        return x == tx && y == ty
            && ((abs(vy) <= 1 && vx == 0)
            || (vy == 0 && vx <= 1));
    }
    int val() {
        if (abs(vx) == 1 || abs(vy) == 1) return t + 1;
        return t;
    }
    bool okay() {
//        printf("State(%d, %d, %d, %d, %d)\n", x, y, vx, vy, t);
//        printf("%d, %d, %d, %d\n", (abs(vx) - 1) * abs(vx)/ 2, (abs(vy) - 1) * abs(vy) / 2, gx, gy);
        return (abs(vx) - 1) * abs(vx) / 2 <= gx - x
            && (abs(vy) - 1) * abs(vy) / 2 <= gy - y;
    }
    void print() {
        printf("State(%d, %d, %d, %d, %d)\n", x, y, vx, vy, t);
    }
} State;

void input() {
    scanf("%d%d%d", &gx, &gy, &n);
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    sx = a, sy = b, tx = c, ty = b;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        wind[a][b] = true;
    }
}

const int M = 110;
bool vis[M][M][M][M];

int solve() {
    queue<State> Q; Q.push(State(sx, sy, 0, 0, 0));
    while (!Q.empty()) {
        State now = Q.front(); Q.pop();
//        now.print();
//        if (vis[now.x][now.y][now.x + now.vx][now.y + now.vy]) continue;
//        vis[now.x][now.y][now.x + now.vx][now.y + now.vy] = true;
        for (auto &nxt: now.getNext()) {
//            nxt.print();
            if (nxt.check()) return nxt.val();
            Q.push(nxt);
        }
    }
    return -1;
}

int main() {
    input();
    printf("%d\n", solve());
    return 0;
}