// ccc13s2real
// Created on 2020-02-02 12:19 p.m. by Kevin Lu
// Bridge Transport

/*
Sample Input 1
Copy

100
6
50
30
10
10
40
50

Output for Sample Input 1
Copy

5

Explanation of Output for Sample Input 1

The first four railway cars have total weight 50 + 30 + 10 + 10 = 100 50 + 30 + 10 + 10 = 100 , which is not greater than what the bridge can hold. When the first railway car leaves, and the next comes on, we have a total weight of 30 + 10 + 10 + 40 = 90 30 + 10 + 10 + 40 = 90 , which is not greater than what the bridge can hold. The last four cars would cause the bridge to break, since 10 + 10 + 40 + 50 = 110 10 + 10 + 40 + 50 = 110 which is greater than the bridge can hold. So, only the first 5 5 railway cars can be taken across the bridge.
Sample Input 2
Copy

100
3
150
1
1

Output for Sample Input 2
Copy

0
*/

#include <cstdio>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, w, arr[N];

int solve() {
	if (n <= 4) {
		for (int i = 0; i < n; i++) w -= arr[i];
		return w >= 0 ? n : 0;
	}
	if (w < arr[0] + arr[1] + arr[2] + arr[3]) {
		if (w < arr[0]) return 0;
		if (w < arr[0] + arr[1]) return 1;
		if (w < arr[0] + arr[1] + arr[2]) return 2;
		return 3;
	}
	else {
		int ans = 3;
		for (; ans < n; ans++) {
			if (w < arr[ans] + arr[ans - 1] + arr[ans - 2] + arr[ans - 3]) break;
		}
		return ans;
	}
}

int main() {
	scanf("%d%d", &w, &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	//for (int i = 0; arr[i]; i++) printf("%d/", arr[i]);
	printf("%d\n", solve());
	return 0;
}