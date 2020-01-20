// ccc15s5
// Created on 2020-01-18 7:50 p.m. by Kevin Lu
// Greedy for Pies

/*
5
10
12
6
14
7
3
1
8
2

44
*/

#include <cstdio>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
int n, m, a[3010], b[100], ans[3010];

void input() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]);
}

void solve() {
	ans[0] = a[0], ans[1] = max(a[0], a[1]);
	for (int i = 2; i < n; i++) {
		ans[i] = max(ans[i - 1], ans[i - 2] + a[i]);
		//printf("%d\n", ans[i]);
	}
	printf("%d\n", ans[n - 1]);
}

int main() {
	input();
	solve();
	return 0;
}