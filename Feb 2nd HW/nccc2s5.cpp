// nccc2s5
// created on 2/5/2020 11:09 PM by Kevin Lu
// A Link/Cut Tree Problem

/*
Sample Input
Copy

3 4
1 2 3
2 3 3
2 1 1
1 2 1
6
2 1 2 4
2 2 3 2
1 1 4
2 1 2 4
1 2 1
2 2 3 2

Sample Output
Copy

0
1
1
0
 */

#include <cstdio>
#include <algorithm>
#include <vector>
// <bits/stdc++.h>
using namespace std;
const int N = 1010;
int weights[N], mst[N], nxt[N], n, m, q;

typedef struct Edge {
    int s, t, w, id; // t > s for edges
    Edge (int s = 0, int t = 0, int w = 0, int id = 0): s(s), t(t), w(w), id(id){};
    bool operator < (Edge const a) const { // highest weight to lowest
        return w > a.w;
    }
}Edge;
vector<Edge> graph[N];
vector<Edge> edges; // all edges s.t. t > s

void printGraph() {
    printf("graph:");
    for (int i = 1; i <= n; i++) {
        printf("    ");
        for (Edge edge: graph[i]) printf("%d", edge.t);
        printf("\n");
    }
}

void printArrs() {
    printf("Now printing nxt\n");
    for (int i = 1; i <= n; i++) printf("%d, ", nxt[i]);
    printf("\n");
    printf("Now printing mst\n");
    for (int i = 1; i <= n; i++) printf("%d, ", mst[i]);
    printf("\n");
    printf("Now printing weights\n");
    for (int i = 1; i <= n; i++) printf("%d, ", weights[i]);
    printf("\n");
}

bool query() {
    int ai, bi, wi;
    scanf("%d%d%d", &ai, &bi, &wi);
//    printf("Query: ai: %d, bi: %d, wi: %d\n", ai, bi, wi);
    if (ai > bi) swap(ai, bi);
    while (ai != bi) {
        if (ai == 1) swap(ai, bi);
        if (weights[ai] < wi) return false;
        ai = mst[ai];
    }
    return true;
}

int next(int i) {
    if (nxt[i] == i) return i;
    return (nxt[i] = next(nxt[i]));
}

void kruskal() { // minimum spanning tree using Kruskal
//    printf("Running kruskal\n");
//    printGraph();
    int cnt = 0;
    for (int i = 0; i <= n; i++) mst[i] = i;
    for (int i = 0; i <= n; i++) nxt[i] = i;
    for (Edge edge: edges) {
//        printf("Now checking Edge(%d, %d, %d, %d);\n", edge.s, edge.t, edge.w, edge.id);
//        printArrs();
        if (next(edge.s) == next(edge.t)) continue;
//        printf("Now connecting %d and %d;\n", edge.s, edge.t);
        mst[edge.t] = edge.s;
        weights[edge.t] = edge.w;
        nxt[next(edge.t)] = next(edge.s);
        if (++cnt == n - 1) break;
    }
//    printArrs();
}

void update() {
    int mi, wi, id;
    scanf("%d%d", &mi, &wi);
    for (int j = 0; j < m; j++)
        if (edges[j].id == mi) {
            edges[j].w = wi;
            id = j;
            break;
        }
    // printf("%d\n", id);
    // sorting again (O(n*log(n))) (could be O(n)
    sort(edges.begin(), edges.end());
    kruskal();
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back(Edge(a, b, c, i));
        graph[b].push_back(Edge(b, a, c, i));
        edges.push_back(Edge(min(a, b), max(a, b), c, i));
    }
    sort(edges.begin(), edges.end());
//    for (Edge edge: edges) printf("Edge(%d, %d, %d, %d);\n", edge.s, edge.t, edge.w, edge.id);
    kruskal();
    scanf("%d", &q);
    while (q--) {
        int a;
        scanf("%d", &a);
        if (a == 1) update();
        else printf("%d\n", query());
    }
    return 0;
}