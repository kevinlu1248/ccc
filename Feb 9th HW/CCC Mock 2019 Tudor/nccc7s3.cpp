// nccc7s3
// created on 2/10/2020 2:42 PM by Kevin Lu
// Tudor Tallies Triangular Totals

/*
Sample Input
Copy

4
0 0
1 0
2 0
1 1

4
100000000000000000 0
1 0
2 0
1 1

Sample Output
Copy

3

7
1 1
3 4
4 5
6 7
3 5
1 9
8 7
 */

#include <cstdio>
#include <algorithm>
#include <vector>
// <bits/stdc++.h>
using namespace std;
const int N = 3010;
int n;

typedef struct Point {
    long long x, y;
    Point (long long x, long long y):
        x(x), y(y) {};
    Point operator+ (Point const a) const {
        return Point(x + a.x, y + a.y);
    }
    Point operator- (Point const a) const {
        return Point(x - a.x, y - a.y);
    }
    int operator* (Point const a) const { // area
        return abs(x * a.y -y * a.x);
    }
    bool operator^ (Point const a) const { // has positive area
        // fix later
        long long nx = x >> 32, ny = y >> 32;
        long long anx = a.x >> 32, any = a.y >> 32;
        if (nx * any != ny * anx) return true;
        nx = x & ((1 << 32) - 1), ny = y & ((1 << 32) - 1);
        anx = a.x & ((1 << 32) - 1), any = a.y & ((1 << 32) - 1);
        return nx * any != ny * anx;
        return abs(x * a.y) != abs(y * a.x);
    }
};

vector<Point> points;

bool pos(Point a, Point b, Point c) {
//    printf("Points: %d, %d; %d, %d; %d, %d;\n", a.x, a.y, b.x, b.y, c.x, c.y);
//    printf("Area: %d\n", (a - b) * (c - b));
    return (a - b) ^ (c - b);
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        long long x, y;
        scanf("%lld%lld", &x, &y);
        points.emplace_back(Point(x, y));
    }
}

void solve() {
    long long cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++) {
                if (pos(points[i], points[j], points[k]))
                    cnt++;
            }
    printf("%lld\n", cnt);
}

int main() {
    input();
    solve();
    return 0;
}