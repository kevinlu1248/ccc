/*
ID: kevinlu2
TASK: triangles
LANG: C++
*/
// created on 2/23/2020 10:26 AM by Kevin Lu
/*
4
0 0
0 1
1 0
1 2

2
 */

#include <cstdio>
#include <algorithm>
// <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, x, y, ans;

typedef struct Point{
    int x, y;
    Point(): Point(0, 0) {};
    Point(int x, int y):
        x(x), y(y) {};
    Point operator- (Point const a) const {
        return Point(x - a.x, y - a.y);
    }
    int operator^ (Point const a) const {
        return abs(x * a.y - y * a.x);
    }
    bool operator< (Point const a) const {
        if (x != a.x) return x < a.x;
        return y < a.y;
    }
};

int area(Point a, Point b, Point c) {
//    printf("%d, %d, %d, %d, %d, %d;", a.x, a.y, b.x, b.y, c.x, c.y);
    if ((a.x == b.x && a.y == c.y)
        || (a.x == b.x && b.y == c.y)
        || (a.y == b.y && b.x == c.x)
        || (a.y == c.y && b.x == c.x)) {
//        printf("%d\n", ((b - a) ^ (c - a)));
//        return abs((c.x - a.x) * (b.y - a.y) / 2);
        return (b - a) ^ (c - a);
    }
    return 0;
}

Point p[N];

void solve() {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                ans = max(ans, area(p[i], p[j], p[k]));
}

int main() {
    FILE *inp = fopen("triangles.in", "r");
    FILE *outp = fopen("triangles.out", "w");
    fscanf(inp, "%d", &n);
    for (int i = 0; i < n; i++) {
        fscanf(inp, "%d%d", &x, &y);
        p[i] = Point(x, y);
    }
    sort(p, p + n);
    solve();
    fprintf(outp, "%d\n", ans);
    return 0;
}