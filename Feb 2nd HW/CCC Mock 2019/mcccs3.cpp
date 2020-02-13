// mcccs3
// created on 2/8/2020 8:35 AM by Kevin Lu
// Absolutely Acidic

/*
5
1
1
1
4
3

3

4
10
6
1
8

9

10
5
5
5
2
2
7
7
1
9
3

3
 */

#include <cstdio>
#include <algorithm>
#include <w32api/mmcobj.h>
//#include <vector>
// <bits/stdc++.h>
using namespace std;
const int R = 1010;
int n, t, mx = 0, mx2 = 0;
Node arr; // id, c

int absd(int a, int b) {return (a > b) ? (a - b) : (b - a);}
bool cmp(pair<int, int> a, pair<int, int> b) {return a.second > b.second;}
//bool cmp2(int a, int b) {return a > b;}
//bool cmp3(pair<int, int> a, pair<int, int> b) {return absd(a.first, mx) > absd(b.first, mx);}

int solve() {
    sort(arr, arr + R - 1, cmp);
//    for (int i = 0; i < R; i++) printf("(%d, %d); ", arr[i].first, arr[i].second);
    if (arr[0].second > arr[1].second) mx = arr[0].first;
    else {
        int max2 = arr[0].first, min2 = arr[0].first;
        for (int i = 1; i < R && arr[i].second == arr[0].second; i++) {
            max2 = max(max2, arr[i].first);
            min2 = min(min2, arr[i].first);
        }
        return max2 - min2;
    }
    if (arr[1].second > arr[2].second) mx2 = arr[1].first;
    else {
//        vector<pair<int, int>> v;
//        for (int i = 1; i < R && arr[i].second == arr[2].second; i++)
//            v.emplace_back(arr[i]);
//        sort(v.begin(), v.end(), cmp3);
//        return absd(v[0].first, mx);
        int res = 0;
        for (int i = 1; i < R && arr[i].second == arr[1].second; i++)
            res = max(res, absd(arr[i].first, arr[0].first));
        return res;
    }
    return mx - mx2;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < R; i++) arr[i] = pair<int, int> (i, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        pair<int, int> p = arr[t];
        arr[t] = pair<int, int> (p.first, p.second + 1);
    }
    printf("%d\n", solve());
    return 0;
}