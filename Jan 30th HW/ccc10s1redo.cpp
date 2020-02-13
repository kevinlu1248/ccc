// ccc10s1redo
// Created on 2020-02-02 4:32 p.m. by Kevin Lu
// Computer

#include <cstdio>
#include <algorithm>
#include <w32api/mmcobj.h>
//#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, r, s, d;
Node arr; // arr[i] is {id, value}
char name[N][22];

char lower(char c) {
	if ('A' < 'Z') return (c - ('A' - 'a'));
	return c;
}

typedef struct Comp {
	int v, id;
	Comp (int id, int r, int s, int d):
		id(id), v(2 * r + 3 * s + d) {};
	bool operator < (const Comp& a) const {
		if (v != a.v) return v < a.v;
		char name1[22] = name[id];
		char name2[22] = name[a.id];
		for (int i = 0; i < 20; i++) {
			if (lower(name1[i]) < lower(name2[i])) return true;
			if (lower(name1[i]) > lower(name2[i])) return false;
		}
		return true;
	}
}comps[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s%d%d%d", &name[i], &r, &s, &d);
		comps[i] = Comp(i, r, s, d);
	}
	return 0;
}