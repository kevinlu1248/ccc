// nccc5j4s2
// created on 2/7/2020 10:06 PM by Kevin Lu
// Reverse Sort

#include <cstdio>
#include <algorithm>
#include <w32api/mmcobj.h>
// <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, cnt;
Node arr;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < n - 1; j++)
            if (arr[j] < arr[j + 1]) {
                flag = false;
                swap(arr[j], arr[j + 1]);
                cnt++;
            }
        if (flag) break;
    }
    printf("%d\n", cnt);
    return 0;
}