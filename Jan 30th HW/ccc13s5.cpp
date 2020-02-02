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
//#include <bits/stdc++.h>
using namespace std;
const int N = 5000010;
int n;
int dp[N];

//int[] sieve(int n) {
//	return {0};
//}

// slow method for now
vector<int> factor(int x) {
	vector<int> ans;
	for (int i = 0; i < x; i++)
		if (x % i == 0)
			ans.push_back(i);
	return ans;
}

int solve(int n) {
	printf("now solving: %d", n);
	if (dp[n]) return dp[N];
	int ans = -1;
	for (int f: factor(n)) {
		if (ans == -1)
			ans = solve(n - f) + n / f - 1; // ans if f was picked
		else
			ans = min(ans, solve(n - f) + n / f - 1);
	}
	return dp[n] = ans;
}

int main() {
	dp[1] = 1;
	scanf("%d", &n);
	printf("%d", solve(n));
	return 0;
}