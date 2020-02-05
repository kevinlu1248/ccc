// nccc1j5s3
// Created on 2020-02-04 8:48 p.m. by Kevin Lu
// A Simulation Problem

/*
Sample Input
Copy

4

Sample Output
Copy

1

Sample Input
Copy

7

Sample Output
Copy

2

Sample Input
Copy

10

Sample Output
Copy

3

Sample Input
Copy

1919

Sample Output
Copy

562

Sample Input
Copy

290976843

Sample Output
Copy

85225144
*/

#include <cstdio>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
long long int n;

int main() {
	scanf("%lld", &n);
	long long int t = n * (n - 1) / 2, k, L = 0, R = n, tmp;
	while (L < R - 1) {
		k = (L + R) / 2;
		tmp = k * (2 * n - k + 1);
		printf("calculating: %lld, L = %lld, R = %lld, tmp = %lld, t = %lld\n", k, L, R, tmp, t);
		if (tmp < t) L = k;
		else if (tmp > t) R = k;
		else {
			R = k;
			break;
		}
	}
	printf("k= %lld, L = %lld, R = %lld, tmp = %lld, t = %lld\n", k, L, R, tmp, t);
	printf("%lld\n", R);
	return 0;
}