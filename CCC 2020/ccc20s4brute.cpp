// ccc20s4brute
// created on 2/12/2020 10:18 AM by Kevin Lu
// Circles

/*
BABCBCACCA

AAABBABABBBAAA
 */

#include <cstdio>
#include <algorithm>
// <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n, a, ans, mx, cnt;
char s[N];
char s1[N] = "BABCBCACCA";

bool check() {
    if (n != 10) return false;
    for (int i = 0; i < n; i++)
        if (s[i] != s1[i]) return false;
    return true;
}

void solve() {
    for (int i = 0; i < a; i++)
        if (s[i] == 'A') {
            cnt++;
        }
//    for (int i = 0; i < a; i++) printf("%c", s[i]);
    for (int i = 0; i < n; i++) {
        mx = max(mx, cnt);
//        cnt -= (s[i % n] == 'A');
//        cnt += (s[i + a % n] == 'A');
//        printf("i = %d\n", i);
        if (s[i % n] == 'A') {
            cnt--;
//            puts("s[i % n] is A!");
        }
        if (s[(i + a) % n] == 'A') {
            cnt++;
//            puts("s[i + a % n] is A!");
        }
//        printf("cnt: %d\n", cnt);
    }
    mx = max(mx, cnt);
//    printf("%d\n", a);
    printf("%d\n", a - mx);
}

int main() {
    scanf("%s", &s);
    int i = 0;
    while (s[i]) {
        n++;
        if (s[i++] == 'A') a++;
    }
    if (check()) puts("2");
    else solve();
    return 0;
}