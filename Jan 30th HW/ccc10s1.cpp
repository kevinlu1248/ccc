// ccc10s1
// Created on 2020-02-02 1:01 p.m. by Kevin Lu
// Computer Purchase 

/*
Sample Input
Copy

4
ABC 13 22 1
DEF 10 20 30
GHI 11 2 2
JKL 20 20 20

Output for Sample Input
Copy

JKL
DEF
*/

#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int n, r, s, d;
//string name;
char name[22];

typedef struct Comp {
	//string n;
	char n[22];
	int r, s, d, v;
	Comp(char n[22], int r = 0, int s = 0, int d = 0):
		n(n), r(r), s(s), d(d), v(2 * r + 3 * s + d){};
	bool operator<(const Comp& a) const{
		return v < a.v;
	}
}Comp;
Comp c[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s%d%d%d", name, &r, &s, &d);
		c[i] = Comp(name, r, s, d);
	}
	sort(c, c + n);
	for (Comp comp: c) {
		printf("%s/", comp.n);
		//comp.n >> cout;
	}
	return 0;
}