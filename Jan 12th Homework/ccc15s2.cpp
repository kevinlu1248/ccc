// ccc15s2
// Created on 2020-01-18 7:07 p.m. by Kevin Lu
// Jerseys

/*
4
3
M
S
S
L
L 3
S 3
L 1

1
*/

#include <cstdio>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int jer, ath, inp, ans = 0, j[N];
char c;

int size_to_int(char s) {
	return (s == 'L') ? 3 : (s == 'M') ? 2 : (s == 'S') ? 1 : 0;
}

int main() {
	scanf("%d%d", &jer, &ath);
	for (int i = 1; i <= jer; i++) {
		scanf("\n%c", &c);
		j[i] = size_to_int(c);
	}
	for (int i = 0; i < ath; i++) {
		scanf("\n%c%d", &c, &inp);
		if (j[inp] >= size_to_int(c)) {
			j[inp] = 0;
			ans++;
		}
	}
	//for (int i = 0; i < jer; i++) printf("%d;", j[i]);
	printf("%d\n", ans);
    return 0;
}