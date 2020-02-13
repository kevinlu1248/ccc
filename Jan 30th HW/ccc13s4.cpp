// ccc13s4
// Created on 2020-02-01 8:18 p.m. by Kevin Lu
// Who is Taller?

/*
Sample Input 1
Copy

10 3
8 4
3 8
4 2
3 2

Output for Sample Input 1
Copy

yes

Sample Input 2
Copy

10 3
3 8
2 8
3 4
3 2

Output for Sample Input 2
Copy

unknown


*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <w32api/mmcobj.h>
//#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n, m, x, y, p, q;
Node arr;
bool vis[N];

bool bfs(int s, int t) {
	for (int i = 0; i < N; i++) vis[i] = false;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int node = q.front(); q.pop();
		if (vis[node]) continue;
		vis[node] = true;
		if (node == t) return true;
		for (int i: arr[node]) q.push(i);
	}
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		arr[x].push_back(y);
	}
	scanf("%d %d", &p, &q);
	if (bfs(p, q)) printf("yes\n");
	else if (bfs(q, p)) printf("no\n");
	else printf("unknown\n");
	return 0;
}