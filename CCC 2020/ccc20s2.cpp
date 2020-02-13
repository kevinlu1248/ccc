// ccc20s2
// created on 2/12/2020 8:45 AM by Kevin Lu
// Escape Room

/*
3
4
3 10  8 14
1 11 12 12
6  2  3  9
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
// <bits/stdc++.h>
using namespace std;
const int P = 1000010, N = 1010;
//const int P = 100;
int p[P], m, n, arr[N][N];
bool vis[N][N];

void init() {
    p[0] = 1;
    for (int i = 2; i < P; i++) {
//        printf("%d, %d\n", i, p[i]);
        if (!p[i]) p[p[0]++] = i;
        for (int j = 1; j < p[0] && p[j] * i < P; j++) {
            p[p[j] * i] = 1;
        }
    }
}

int pow(int a, int b) {
    int res = 1;
    while (b--) res *= a;
    return res;
}

vector<pair<int, int>> factorize(int x, vector<pair<int, int>> v) {
    printf("factoring %d\n", x);
    vector<pair<int, int>> res;
    if (v.empty()) {
        res.emplace_back(1, x);
        res.emplace_back(x, 1);
        return res;
    }
    pair<int, int> factor = v.back(); v.pop_back();
    for (int i = 0; i < factor.second; i++) {
        int r = pow(factor.first, i);
        for (auto j: factorize(x / r, v)) {
            res.emplace_back(make_pair(r, x / r));
            res.emplace_back(make_pair(x / r, r));
        }
    }
//    pair<int, int> f = ;
}

vector<pair<int, int>> factor(int x) {
//    printf("Factoring: %d\n", x);
//    vector<pair<int, int>> v;
//    int i = 0;
//    while (x > 1 && ++i < p[0] && p[i] <= x) {
//        printf("Now on factor %d\n", p[i]);
//        if (x % p[i] == 0) {
//            pair<int, int> f = make_pair(p[i], 0);
//            do {
//                x /= p[i];
//                f.first++;
//            } while(x %= p[i]);
//            v.emplace_back(f);
//        }
//    }
//    if (x > 1) v.emplace_back(make_pair(x, 1));
//
//    for (int i = 0; i < v.size(); i++) printf("(%d, %d); ", v[i].first, v[i].second);
//    return factorize(x, v);

    vector<pair<int, int>> v;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
//            printf("Found: %d %d (%d, %d);\n", i, x / i, n, m);
            if (i <= m && x / i <= n)
                v.emplace_back(make_pair(i, x / i));
            if (i <= n && x / i <= m)
                v.emplace_back(make_pair(x / i, i));
        }
    }
    return v;
}

bool solve() {
    queue<pair<int, int>> Q; Q.push(make_pair(1, 1));
    while(!Q.empty()) {
        pair<int, int> now = Q.front(); Q.pop();
        if (vis[now.first][now.second]) continue;
        vis[now.first][now.second] = true;
//        printf("%d, %d\n", now.first, now.second);
        if (now.first == m && now.second == n) return true;
        for (auto i: factor(arr[now.first][now.second])) {
            if (i.first == n && i.second == m) return true;
            Q.push(i);
        }
    }
    return false;
}

int main() {
//    init();
//    for (int i = 0; i < P; i++) printf("%d, ", p[i]);
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &arr[i][j]);
    printf("%s\n", solve() ? "yes" : "no");
    return 0;
}