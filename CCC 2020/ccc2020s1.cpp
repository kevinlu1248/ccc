// ccc2020s1
// Tricky Dingo

/*
3
0 100
20 50
10 120
 */

#include <cstdio>
#include <algorithm>
// <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, arr[N][2];
double speed = 0.0;
pair<int, int> p[N];

//typedef struct State {
//    int t, x;
//    State (int t, int x): t(t),
//};

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d",  &a, &b);
        p[i] = make_pair(a, b);
    }
    sort(p, p + n, cmp);
    for (int i = 0; i < n - 1; i++) {
        double s =  ((double) p[i + 1].second - p[i].second) / ((double) p[i + 1].first - p[i].first);
//        printf("%f\n", s);
        speed = max(speed, abs(s));
    }
    printf("%f\n", speed);
    return 0;
}