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
int t, n, x, i, c, s[100010], s_index;
//stack<int> s;

typedef struct Stack{
	int index;
	int arr[100010];
	Stack() {
		for (int j = 0; j < 100010; j++) arr[j];
	}
}Stack;

 //stack implementation
bool empty(int s[]) {
	return s[0] == 0;
}

int top(int s[]) {
	return s[s_index];
}

void pop(int s[]) {
	s[s_index--] = 0;
}

void push(int s[], int x) {
	s[++s_index] = x;
}

void empty_stack(int s[]) {
	for (int j ;s[j] != 0;) s[j++] = 0;
}

bool solve() {
	i = 1, c = 1; empty_stack(a);
	while (i <= n || !empty()) {
		//printf("%c %d %d", (c <= n) ? 'T' : 'F', c, n);
		if (c <= n) {
			scanf("%d", &x);
			printf("inputted %d\n", x);
			c++;
		}
		//printf("test");
		if (x == i) {
			i++;
			printf("direct %d\n", x);
			continue;
		}
		if (top() == i) {
			pop();
			i++;
			printf("indirect %d\n", x);
			continue;
		}
		if (!empty() && x > top()) return 0;
		//printf("into stack: %d\n", x);
		push(x);
	}
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