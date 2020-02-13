// nccc7s2
// created on 2/10/2020 1:54 PM by Kevin Lu
// Goats

/*
Sample Input
Copy

7 4 0 0 5 4

Sample Output
Copy

2.000

Sample Input
Copy

6 0 0 2 7 6

Sample Output
Copy

2.000

Sample Input
Copy

4 8 7 8 9 9

Sample Output
Copy

3.000
 */

#include <cstdio>
#include <algorithm>
#include <math.h>
// <bits/stdc++.h>
using namespace std;
long long xy[2][2], x, y;
long double ans = 0; // x1, y1, x2, y2

//double dis(int x1, int y1, int x2, int y2) {
//    return 0.0;
//}
//    // lines
//    ans = min(ans, dis(xy[0][0], xy[0][1], xy[1][0], xy[1][1]));
//    ans = min(ans, dis(xy[0][0], xy[0][1], xy[1][0], xy[1][1]));
//    ans = min(ans, dis(xy[0][0], xy[0][1], xy[1][0], xy[1][1]));
//    ans = min(ans, dis(xy[0][0], xy[0][1], xy[1][0], xy[1][1]));

int main() {
    scanf("%lld%lld%lld%lld%lld%lld", &x, &y, &xy[0][0], &xy[0][1], &xy[1][0], &xy[1][1]);
//    printf("%d, %d", x, y);
    xy[0][0] -= x; xy[1][0] -= x; xy[0][1] -= y; xy[1][1] -= y;
    ans = sqrt((xy[0][0]) * (xy[0][0]) + (xy[0][1]) * (xy[0][1]));
    ans = min(ans, (long double) sqrt((xy[1][0]) * (xy[1][0]) + (xy[0][1]) * (xy[0][1])));
    ans = min(ans, (long double) sqrt((xy[0][0]) * (xy[0][0]) + (xy[1][1]) * (xy[1][1])));
    ans = min(ans, (long double) sqrt((xy[1][0]) * (xy[1][0]) + (xy[1][1]) * (xy[1][1])));

    if ((xy[0][1] < 0 && xy[1][1] > 0)
        || (xy[0][1] > 0 && xy[1][1] < 0))
        ans = min(abs(xy[0][0]), abs(xy[1][0]));
    if ((xy[0][0] < 0 && xy[1][0] > 0)
        || (xy[0][0] > 0 && xy[1][0] < 0))
        ans = min(abs(xy[0][1]), abs(xy[1][1]));

    printf("%.3LF\n", ans);
    return 0;
}