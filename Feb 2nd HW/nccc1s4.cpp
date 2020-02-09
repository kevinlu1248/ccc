// nccc3s4
// Created on 2020-02-05 10:54 a.m. by Kevin Lu
// A Graph Problem

/*
Sample Input
Copy

4 5 10
3 2
1 2 4 7
3 1 1 6
3 4 7 10
2 4 3 5
4 2 8 9

Sample Output
Copy

5

Sample Input
Copy

4 5 9
1 4
1 2 3 5
1 3 6 7
1 4 2 3
2 4 4 6
3 4 7 9

Sample Output
Copy

5
*/

#include <cstdio>
#include <algorithm>
#include <vector> // for edges
#include <queue> // for bfs
#include <cstring> // for memset
//#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = 5010;
int arr[M][4], lengths[M], n, m, k, S, T, ans;

typedef struct T_Edge {
	int pos, from, to; // s and t are start and end
	bool v;
	T_Edge (int pos, int from, int to, bool v):
		pos(pos), from(from), to(to), v(v) {};
	bool operator < (T_Edge const a) const {
	    return pos < a.pos;
	}
}T_Edge;
vector<T_Edge> t_edges;
vector<int> edges[N];

bool bfs() {
    bool vis[N];
    memset(vis, 0, N);
    queue<int> Q; Q.push(S);
    while (!Q.empty()) {
        int nxt = Q.front(); Q.pop();
        if (vis[nxt]) continue; vis[nxt] = true;
        if (nxt == T) return true;
        for (int i: edges[nxt]) Q.push(i);
    }
    return false;
}

void solve() {
    for (int i = 0; i < 2 * m; i++) {
        T_Edge t_edge = t_edges[i];
//        printf("T_Edge(%d, %d, %d, %d), i = %d\n", t_edge.pos, t_edge.from, t_edge.to, t_edge.v, i);

        if (t_edge.v) edges[t_edge.from].push_back(t_edge.to);
        else for (int j = 0; j < edges[t_edge.from].size(); j++) // deleting connection to t_edge.to
            if (edges[t_edge.from][j] == t_edge.to)
                edges[t_edge.from].erase(edges[t_edge.from].begin() + j);

        // printing graph
//        for (int j = 1; j <= n; j++) {
//            printf("    :");
//            for (int l: edges[j])
//                printf("%d ", l);
//            printf("\n");
//        }

        if (!lengths[i]) continue;
        if (bfs()) {
            ans += lengths[i]; // some value
        }
//        printf("finished i = %d, ans = %d, lengths = %d, bfs = %d\n", i, ans, lengths[i], bfs());
    }
    printf("%d\n", ans);
}

void input() {
    scanf("%d%d%d%d%d", &n, &m, &k, &S, &T);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3]);
        t_edges.push_back(T_Edge(arr[i][2], arr[i][0], arr[i][1], true));
        t_edges.push_back(T_Edge(arr[i][3] + 1, arr[i][0], arr[i][1], false));
    }
    sort(t_edges.begin(), t_edges.end());
    for (int i = 0; i < 2 * m; i++) {
        lengths[i] = t_edges[i + 1].pos - t_edges[i].pos;
//        printf("i: %d, lengths: %d\n", i, lengths[i]);
    }
    lengths[2 * m - 1] = k - t_edges[2 * m - 1].pos + 1;
//    printf("i: %d, lengths: %d\n", 2 * m - 1, lengths[2 * m - 1]);
}

int main() {
	input();
//	for (T_Edge edge: t_edges) printf("%d %d %d %d\n", edge.pos, edge.from, edge.to, edge.v);
	solve();
	return 0;
}