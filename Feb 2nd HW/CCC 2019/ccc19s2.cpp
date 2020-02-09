// ccc19s2
// created on 2/9/2020 8:49 AM by Kevin Lu
// Pretty Average Primes

/*
4
8
4
7
21
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
// <bits/stdc++.h>
using namespace std;
const int N = (2e6) + 20;
int n, p;
bool isPrime[N];
vector<int> primes;

void sieve() {
    memset(isPrime, true, N);
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes.emplace_back(i);
            int j = i;
            while ((j += i) < N) {isPrime[j] = false;}
        }
    }
}

int main() {
    sieve();
//    for (auto &i: primes) printf("%d", i);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p);
        for (auto &j: primes) {
//            printf("%d", j);
            if (isPrime[2 * p - j]) {
                printf("%d %d\n", j, 2 * p - j);
                break;
            }
        }
    }
    return 0;
}