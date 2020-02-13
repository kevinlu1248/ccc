// CCC Mock 2019 Tudor
// created on 2/10/2020 1:37 PM by Kevin Lu
// Doors

#include <bits/stdc++.h>
using namespace std;
long long a, b;

int main() {
    scanf("%lld%lld", &a, &b);
    printf("%lld%s\n", a * b / 2, (a & 1LL && b & 1LL) ? ".5" : ".0");
    return 0;
}