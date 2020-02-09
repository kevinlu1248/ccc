// mcccs4
// created on 2/8/2020 9:29 AM by Kevin Lu
// Animal Farm

/*
4
3 1 2 3 7 4 6
4 1 2 4 5 7 7 2 6
4 4 7 6 5 4 8 9 2
5 3 2 4 7 8 4 7 4 7 7

4
3 1 2 3 7 4 1
4 1 2 4 5 7 7 2 6
4 4 7 6 5 4 8 9 2
5 3 2 4 7 8 4 7 4 7 1

10
3 4 1 5 4 4 16
3 5 1 10 4 12 26
3 2 3 5 10 3 3
3 3 4 5 5 16 3
3 9 6 11 10 11 25
3 1 2 10 12 6 12
3 2 5 10 3 26 6
3 6 7 11 13 17 11
3 7 8 11 17 2 17
3 8 9 11 2 25 2
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
// <bits/stdc++.h>
using namespace std;
const int N = 110, M = 820;
int n, corns[N], e, c, nxt[N];

typedef struct Edge {
    int corn1, corn2, s, t, c;
    Edge (int s = 0, int t = 0, int c = 0, int corn1 = 0, int corn2 = 0):
        s(s), t(t), c(c), corn1(corn1), corn2(corn2) {};
    explicit operator bool() {return c;}
    void print() {printf("Edge(%d, %d, %d, %d, %d); ", s, t, c, corn1, corn2);}
    bool operator< (Edge const& a) const {
        return c < a.c;
    }
} Edge;
Edge fences[M][M]; // fences[i][j] is the fence with corner i, j
vector<Edge> edges[N]; // p is 1 indexed, 0 is outside
vector<Edge> aedges; // all edges t > s

void printGraph(bool w_fences = false, bool graph = true) {
    printf("\n");
    if (w_fences) {
        printf("fences: \n");
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                if (fences[i][j].c > 0) {printf("(%d, %d): ", i, j); fences[i][j].print();}
            }
        }
        printf("\n");
    }
    for (int i = 0; i < M && edges[i].size(); i++) {
        printf("Polygon: %d\n", i);
        vector<Edge> v = edges[i];
        for (Edge e: v) {
            e.print();
        }
        printf("\n");
    }
    printf("\n");
}

void addEdge(int corn1, int corn2, int p, int c) { // p is 1 indexed
//    printf("Adding fence: %d, %d, %d, %d, %d\n", corn1, corn2, p, c, fences[corn1][corn2].c);
    if (fences[corn1][corn2].c > 0) {
        Edge fence = fences[corn1][corn2];
        edges[p].emplace_back(Edge(p, fence.s, c, corn1, corn2));
        edges[fence.s].emplace_back(Edge(fence.s, p, c, corn1, corn2));
        int s = min(fence.s, p), t = max(fence.s, p);
        aedges.emplace_back(Edge(s, t, c, corn1, corn2));
        fences[corn1][corn2] = Edge();
        fences[corn2][corn1] = Edge();
    } else {
        fences[corn1][corn2] = Edge(p, 0, c, corn1, corn2);
        fences[corn2][corn1] = Edge(p, 0, c, corn1, corn2);
    }
//    printGraph(true, false);
}

int next(int i) {
//    printf("next: %d\n", i);
    for (int i = 0; i <= n; i++) printf("%d, ", nxt[i]);
    printf("\n");
    if (nxt[i] == i) return i;
    return (nxt[i] = next(nxt[i]));
}

int kruskal(bool include_outside = false) {
    int c = 0, cnt = 0;
    for (int i = 0; i <= n; i++) nxt[i] = i;
//    memset(nxt, -1, n + 1);
    sort(aedges.begin(), aedges.end());
    for (Edge edge: aedges) edge.print();
    printf("Starting traverse");
    for (Edge edge: aedges) {
        printf("traversing edge: "); edge.print(); printf("\n");
        int s = edge.s, t = edge.t;
        if (!include_outside && s == 0) continue; // ignore all edges with outside
//        printf("%d, %d\n", next(s), next(t));
        if (next(s) == next(t)) continue;
        printf("Adding edge: "); edge.print(); printf("\n");
        c += edge.c; nxt[t] = s;
//        printf("cnt = %d, n = %d;", cnt, n);
        if (++cnt >= n - 1 && !include_outside) return c;
        if (cnt >= n && include_outside) return c;
    }
    return c;
}

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &e);
        for (int j = 0; j < e; j++) scanf("%d", &corns[j]);
        for (int j = 0; j < e; j++) {
            scanf("%d", &c);
            addEdge(corns[j], corns[(j + 1) % e], i, c);
        }
//        printf("just finished: %d\n", i);
    }
//    printGraph(true);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
//            fences[i][j].print();
//            if (fences[i][j]) printf("(%d, %d): %d; ", i, j, fences[i][j].c);
            if (fences[i][j].c > 0) {
                Edge fence = fences[i][j];
                edges[0].emplace_back(Edge(0, fence.s, fence.c, i, j));
                edges[fence.s].emplace_back(Edge(fence.s, 0, fence.c, i, j));
                aedges.emplace_back(Edge(0, fence.s, fence.c, i, j));
                fences[i][j] = Edge();
                fences[j][i] = Edge();
            }
        }
    }
}

int main() {
    input();
//    printGraph(true);
    int ans1 = kruskal();
    int ans2 = kruskal(true);
//    printf("%d\n", min(ans1, ans2));
    printf("%d, %d\n", ans1, ans2);
//    printGraph();
    return 0;
}