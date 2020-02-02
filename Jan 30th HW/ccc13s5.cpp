// ccc13s5
// Created on 2020-02-01 8:41 p.m. by Kevin Lu
// Factor Solitaire

/*
Sample Input 1
Copy

15

Output for Sample Input 1
Copy

9

Sample Input 2
Copy

2013

Output for Sample Input 2
Copy

91
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <chrono>
//#include <bits/stdc++.h>
using namespace std;
const int N = 5000010;
int n, dp[N], elapsed;

//int[] sieve(int n) {
//	return {0};
//}

// slow method for now
vector<int> factor(int x) {
	auto start = chrono::system_clock::now();
	vector<int> ans = {1};
	for (int i = 1; i < x; i++) {
		if (x % i == 0) {
			//printf("factor of %d: %d\n", x, i);
			ans.push_back(i);
		}
	}
	auto end = std::chrono::system_clock::now();
	elapsed += chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	return ans;
}

int solve(int n) {
	//printf("now solving: %d, dp[%d] = %d\n", n, n, dp[n]);
	if (n == 1) return 0;
	if (dp[n]) return dp[n];
	int ans = -1;
	for (int f: factor(n)) {
		//printf("considering factor: %d\n", f);
		if (ans == -1)
			ans = solve(n - f) + n / f - 1; // ans if f was picked
		else
			ans = min(ans, solve(n - f) + n / f - 1);
	}
	return dp[n] = ans;
}

int main() {
	//for (int i = 1; i < n + 1; i++) printf("%d => %d\n", i, dp[i]);
	scanf("%d", &n);
	auto tstart = chrono::system_clock::now();
	printf("%d", solve(n));
	auto tend = std::chrono::system_clock::now();
	printf("total time for factorizing: %d\n", elapsed);
	printf("total ns for entire algorithm %lld\n", chrono::duration_cast<chrono::nanoseconds>(tend - tstart).count());
	for (int i = 1; i < n + 1; i++) printf("%d => %d\n", i, dp[i]);
	return 0;
}