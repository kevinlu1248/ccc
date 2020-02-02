// ccc14s3
// Created on 2020-01-30 12:56 p.m. by Kevin Lu
// The Geneva Confection

/*
* Sample Input
Copy

2
4
2
3
1
4
4
4
1
3
2

Output for Sample Input
Copy

Y
N
*/

//#include <cstdio>
////#include <algorithm>
//#include <stack>
#include <bits/stdc++.h>
using namespace std;
int t, n, x, i, c;
int a[100010], a_index, b[100010], b_index, truck;
//stack<int> s;

void empty_stack() {
	for (int j = 0; a[j];)  a[j++] = 0;
	for (int j = 0; b[j];)  b[j++] = 0;
}

bool solve() {
	truck = 1, a_index = n - 1, b_index = 0; empty_stack();
	//for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	//while (a_index || b_index) {
	//	if (a[a_index] == truck) {truck++, a_index = 0, b_index = 0; empty_stack();}
	//}

	//while ()
	//while (i <= n || !empty()) {
	//	//printf("%c %d %d", (c <= n) ? 'T' : 'F', c, n);
	//	if (c <= n) {
	//		scanf("%d", &x);
	//		printf("inputted %d\n", x);
	//		c++;
	//	}
	//	//printf("test");
	//	if (x == i) {
	//		i++;
	//		printf("direct %d\n", x);
	//		continue;
	//	}
	//	if (top() == i) {
	//		pop();
	//		i++;
	//		printf("indirect %d\n", x);
	//		continue;
	//	}
	//	if (!empty() && x > top()) return 0;
	//	//printf("into stack: %d\n", x);
	//	push(x);
	//}
	return true;
}

int main() {
	scanf("%d", &t);
	for (int _ = 0; _ < t; _++) {
		//printf("%d %d", _, t);
		scanf("%d", &n);
		printf("%c\n", solve() ? 'Y' : 'N');
	}
	return 0;
}