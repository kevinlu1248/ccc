// ccc15s4
// Created on 2020-01-18 8:13 p.m. by Kevin Lu
// Convex Hull

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
//#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
int k, n, m, a, b, t, h;

typedef struct Edge {
	int s, t, c, h;
	Edge(int a, int b, int c, int h): s(a), t(b), c(c), h(h) {}
} Edge;
vector<Edge> edges[N];

void addEdge(int a, int b, int t, int h) {
	edges[a].push_back(Edge(a, b, t, h));
	edges[b].push_back(Edge(b, a, t, h));
}

typedef struct Node {
	int u, dis;
	Node(int u, int dis) u(u), dis(dis) {}
	bool operator<(const Node &a) const{
		if (dis != a.dis) return dis < a.dis;
		return u < a.u;
	}
} Node;

int ans[N];
bool vis[N];
int dijkstra(int start, int end) {
	memset(ans, 0, sizeof(ans));
	memset(vis, -1, sizeof(vis));
	priority_queue<Node> Q;
	Q.push(Node(start, 0));
	while(!Q.empty()) {
		Node a = Q.top(); Q.pop();
		if (a.u == end) break;
		if (vis[a.u]) continue;
		vis[a.u] = true;
		for (Edge e: edges[a.u]) {
			if (ans[e.t] < 0 || ans[a.u] > e.c + a.dis) {
				ans[e.t] = e.c + a.dis;
				Q.push(Node(e.t, ans[e.t]));
			}
		}
	}
	return ans[end];
}

int main() {
	scanf("%d%d%d", k, n, m);
	for (int i = 0; i < n; i++) scanf("%d%d%d%d", &a, &b, &t, &h), addEdge(a, b, t, h);
	scanf("%d%d", &a, &b); // start and end
	return 0;
}