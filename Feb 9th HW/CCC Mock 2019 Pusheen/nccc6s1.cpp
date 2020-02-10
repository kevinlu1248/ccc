// nccc6s1
// created on 2/9/2020 2:40 PM by Kevin Lu
// Pusheen's Report Card

#include <cstdio>
#include <algorithm>
// <bits/stdc++.h>
using namespace std;
int sm, n, tmp;
double ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {scanf("%d", &tmp); sm += tmp;}
    ans = (double) sm / (double) n;
    printf("%2.1f\n", ans);

    return 0;
}