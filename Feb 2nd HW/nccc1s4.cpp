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
#include <vector>
//#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = 5010;
int arr[M][4], n, m, k, S, T;

typedef struct T_Edge {
	int pos, from, to; // s and t are start and end
	bool v;
	T_Edge (int pos, int from, int to, bool v):
		pos(pos), from(from), to(to), v(v) {};
}T_Edge;
vector<T_Edge> edges;

int main() {
	scanf("%d%d%d%d%d", &n, &m, &k, &S, &T);
	for (int i = 0; i < m; i++)
		scanf("%d%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3]);
	int i = -1;
	while (arr[++i][0]) {
		int *row = arr[i];
		printf("%d %d %d %d\n", row[0], row[1], row[2], row[3]);
		edges.push_back(T_Edge(row[0], row[2], row[3], true));
		edges.push_back(T_Edge(row[1], row[2], row[3], true));
	}

	return 0;
}