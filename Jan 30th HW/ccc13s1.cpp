// 2013s3
// Created on 2020-02-01 6:15 p.m. by Kevin Lu
// Distinct Digits

#include <cstdio>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;

/*
Sample Input 1
Copy

1987

Output for Sample Input 1
Copy

2013

Sample Input 2
Copy

999

Output for Sample Input 2
Copy

1023


*/

int main() {
	int d;
	scanf("%d", &d);
	while (++d) {
		bool digs[10], res = true;
		for (int i = 0; i < 10; i++) digs[i] = 0;
		int t = d;
		//printf("%d: ", t);
		do {
			//printf("%d/", t % 10);
			if (digs[t % 10]) {
				res = false;
				break;
			}
			digs[t % 10] = true;
		} while(t /= 10);
		//printf("\n");
		if (res) break;
	}
	printf("%d", d);
	return 0;
}