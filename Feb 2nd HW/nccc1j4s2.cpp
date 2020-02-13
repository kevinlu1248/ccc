// nccc1j4s2
// Created on 2020-02-04 8:24 p.m. by Kevin Lu
// A Square Problem 

/*
Sample Input
Copy

3
012
120
201

Sample Output
Copy

Reduced

Sample Input
Copy

4
3210
0123
2301
1032

Sample Output
Copy

Latin

Sample Input
Copy

11
0123458372A
A9287346283
0285475A834
84738299A02
1947584037A
65848430002
038955873A8
947530200A8
93484721084
95539A92828
04553883568

Sample Output
Copy

No
*/

#include <cstdio>
#include <algorithm>
#include <w32api/mmcobj.h>
//#include <bits/stdc++.h>
using namespace std;
const int N = 40;
int n;
Node arr;

int map(int i, int j) {
	char c = arr[i][j];
	if ('0' <= c && c <= '9') return c - '0';
	return c - 'A' + 10;
}

void solve() {
	bool vis[N];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) vis[j] = 0;
		for (int j = 0; j < n; j++) {
			//printf("d: %d, c: %c\n", map(i, j), arr[i][j]);
			if (vis[map(i, j)]) {
				printf("No\n");
				return;
			}
			vis[map(i, j)] = true;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) vis[j] = 0;
		for (int j = 0; j < n; j++) {
			if (vis[map(j, i)]) {
				printf("No\n");
				return;
			}
			vis[map(j, i)] = true;
		}
	}
	for (int i = 0; i < n; i++)
		if (map(i, 0) != i || map(0, i) != i) {
			printf("Latin\n");
			return;
		}
	printf("Reduced\n");
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("\n");
		for (int j = 0; j < n; j++)
			scanf("%c", &arr[i][j]);
	}
	solve();
	return 0;
}