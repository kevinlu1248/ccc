// ccc18s5
// created on 2/9/2020 9:42 PM by Kevin Lu
// Maximum Strategic Savings

/*
2 3 4 1
2 3 5
3 2 7
1 2 6
1 1 8
2 1 5
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
// <bits/stdc++.h>
using namespace std;
const int N = 100010;
int nm[2], pq[2];
long long tc;

typedef struct Edge {
    int s, t, c, typ, id;
    Edge (): Edge(0,0,0,0,0) {};
    Edge (int s, int t, int c, int typ, int id):
        s(s), t(t), c(c), typ(typ), id(id) {};
    bool operator < (Edge a) {
        return c < a.c;
    }
    void print() {
        printf("Edge(%d, %d, %d, %d, %d);\n", s, t, c, typ, id);
    }
}Edge;
vector<Edge> edges;

void input() {
    scanf("%d%d%d%d", &nm[0], &nm[1], &pq[0], &pq[1]);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < pq[i]; j++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            edges.emplace_back(Edge(a - 1, b - 1, c, i, j));
            tc += 1LL * c * nm[i];
        }
}

int fa[2][N], fas[2];
void init() {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < nm[!i]; j++)
            fa[i][j] = j;
//    for (int i = 0; i < 2; i++)
//        for (int j = 0; j < nm[!i]; j++)
//            printf("%d\n", fa[i][j]);
    fas[0] = nm[0]; fas[1] = nm[1];
}

int father(int i, int j) {
//    printf("%d\n", fa[i][j]);
    if (fa[i][j] == j) return j;
    return fa[i][j] = father(i, fa[i][j]);
}

bool unionf(int i, int a, int b) {
    int na = father(i, a);
    int nb = father(i, b);
//    printf("%d, %d\n", na, nb);
    if (na == nb) return false;
    fa[i][na] = fa[i][nb];
    return true;
}

int main() {
    input();
    init();
    sort(edges.begin(), edges.end());
    for (Edge edge: edges) {
//        printf("%d %d\n", fas[0], fas[1]);
//        edge.print();
        if (fas[0] <= 1 && fas[1] <= 1) break;
        if (unionf(edge.typ, edge.s, edge.t)) {
//            printf("Connected %d, %d of %d\n", edge.s, edge.t, edge.typ);
            tc -= 1LL * edge.c * nm[edge.typ]; nm[!edge.typ]--;
//            printf("edges %d * ", nm[!edge.typ] + 1); edge.print();
        }
    }
    printf("%lld\n", tc);
    return 0;
}