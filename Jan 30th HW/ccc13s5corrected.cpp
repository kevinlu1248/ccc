// ccc13s5(corrected)
// Created on 2020-02-01 11:03 p.m. by Kevin Lu
// Factor Solitaire

#include <cstdio>
#include <algorithm>
#include <vector>
//#include <bits/stdc++.h>
using namespace std;
const int N = 5000010;
int n, dp[N];
bool prime[N];
vector<int> primes;

// get all primes less than n
void sieve(int n) {
	for (int i = 2; i <= n; i++) prime[i] = true;
	for (int i = 2; i <= n; i++) {
		if (prime[i]) {
			primes.push_back(i);
			int tmp = i;
			while ((tmp += i) <= n) prime[tmp] = false;
		}
	}
}

int f(int n) {
	//printf("%d\n", n);
	if (n == 1) return 0;
	if (prime[n]) return f(n - 1) + n - 1;
	int m, ans = 0;
	for (int prime: primes) {
		m = 0;
		while (n % prime == 0) {
			n /= prime;
			m++;
		}
		//printf("(%d, %d)\n", prime, m);
		if (m) ans += m * (f(prime - 1) + prime - 1);
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	sieve(n);
	//for (int i: primes) printf("%d/", i);
	//for (int i = 0; i <= n; i++) printf("%d is a %s\n", i, prime[i] ? "prime" : "composite");
	printf("%d\n", f(n));
	return 0;
}