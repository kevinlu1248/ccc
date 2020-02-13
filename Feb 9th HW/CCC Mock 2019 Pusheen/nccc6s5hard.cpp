// nccc6s5hard
// created on 2/10/2020 1:35 PM by Kevin Lu
// Pusheen Eats Even More Tuna Sashimi and Tuna Nigiri
// using dijkstra

/*
 Sample Input
Copy

3 3
1 2 1
2 3 2
1 3 4
2
1 2
1 3

Sample Output
Copy

1
3
 */

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
// <bits/stdc++.h>
using namespace std;
const int N = 50010;
int n, m, q, s, t;
bool vis[N];

typedef struct Edge {
    int s, t, w;
    Edge(int s, int t, int w):
        s(s), t(t), w(w) {};
//    bool operator< (Edge const a) const {
//        return w > a.w;
//    }
    void print() {
        printf("Edge(%d, %d, %d)\n", s, t, w);
    }
} Edge;

vector<Edge> edges[N];

void input() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)  {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[a].emplace_back(Edge(a, b, c));
        edges[b].emplace_back(Edge(b, a, c));
    }
    scanf("%d", &q);
}

typedef struct Node {
    int t, cost;
    Node(int t, int cost):
        t(t), cost(cost) {};
    bool operator < (Node const a) const {
        return cost > a.cost;
    }
} Node;

int dijkstra(int s, int t) {
    memset(vis, 0, sizeof(vis));
    priority_queue<Node> Q; Q.push(Node(s, 0));
    while (!Q.empty()) {
        Node now = Q.top(); Q.pop();
//        now.print();
        if (t == now.t) return now.cost;
        if (vis[now.t]) continue;
        vis[now.t] = true;
        for (Edge &nxt: edges[now.t]) {
            Q.push(Node(nxt.t, now.cost + nxt.w));
        }
    }
    return -1;
}

int main() {
    input();
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &s, &t);
        printf("%d\n", dijkstra(s, t));
    }
    return 0;
}