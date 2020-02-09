// nccc5j5s3
// created on 2/7/2020 10:13 PM by Kevin Lu
// Directed Graph Connectivity

/*
3 3
1 2
2 1
2 3
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
// <bits/stdc++.h>
using namespace std;
const int N = 60, M = 3000;
int n, m;

typedef struct Edge {
    int s, t, id;
    Edge (int s, int t, int id): s(s), t(t), id(id) {};
}Edge;
vector<Edge> edges[N];

bool bfs(int i) {
    queue<int> Q; Q.push(1);
    bool vis[N]; memset(vis, 0, N);
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        if (vis[v]) continue;
        vis[v] = true;
        if (v == n) return true;
        for (Edge edge: edges[v])
            if (edge.id != i && !vis[edge.t]) Q.push(edge.t);
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int s, t;
        scanf("%d%d", &s, &t);
        edges[s].emplace_back(Edge(s, t, i));
    }
    for (int i = 1; i <= m; i++) {
        printf("%s\n", bfs(i) ? "YES" : "NO");
    }
    return 0;
}