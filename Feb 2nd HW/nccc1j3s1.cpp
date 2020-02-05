// nccc1j3s1
// Created on 2020-02-04 8:08 p.m. by Kevin Lu
// Math Problem

/*
Sample Input
Copy

31 41 59

Sample Output
Copy

549.200

Sample Input
Copy

3 4 5

Sample Output
Copy

16.000
*/

#include <cstdio>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
int k, p, x, m;
double ans;

int main() {
	scanf("%d%d%d", &k, &p, &x);
	while (m * m < k * p / x) m++;
	double K=k, P=p, X=x, M=m;
	printf("%f %f %f %f\n", K, P, X, M);
	ans = max(M * X + K * P / M,
			(M + 1) * X + K * P / (M + 1));
	printf("%.3f\n", ans);
	return 0;
}