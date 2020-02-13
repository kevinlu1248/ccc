// ccc11s4
// created on 2/8/2020 8:31 PM by Kevin Lu
// Blood Distribution

/*
5 5 3 1 2 11 5 12
2 4 9 2 3 9 7 3

33
 */

#include <cstdio>
#include <algorithm>
#include <w32api/mmcobj.h>
// <bits/stdc++.h>
using namespace std;
int ans;
Node arr; // donor/receiver, +/-, type

int main() {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 4; k++)
                scanf("%d", &arr[i][j][k]);
//    for (int i = 0; i < 4; i++) { // start with negative receivers
//        if (i == 0) {
//            if (arr[1][0][i] > arr[1][0][i])
//        }
//    }
    // negative receivers
    ans += min(arr[1][0][0], arr[0][0][0]);
    if (arr[1][0][0] > arr[0][0][0]) {arr[1][0][0] -= arr[0][0][0]; arr[0][0][0] = 0;} // O- receivers
    else arr[0][0][0] -= arr[1][0][0];
    for (int i = 0; i < 2 && arr[1][0][1]; i ++)  {
        ans += min(arr[1][0][1], arr[0][0][i]);
        if (arr[1][0][1] > arr[0][0][i]) {arr[1][0][1] -= arr[0][0][i]; arr[0][0][i] = 0;} // A- receivers
        else arr[0][0][1] -= arr[1][0][i];
    }
    for (int i = 0; i < 3 && arr[1][0][2]; i += 2)  {
        ans += min(arr[1][0][2], arr[0][0][i]);
        if (arr[1][0][2] > arr[0][0][i]) {arr[1][0][2] -= arr[0][0][i]; arr[0][0][i] = 0;} // B- receivers
        else arr[0][0][2] -= arr[1][0][i];
    }
    for (int i = 0; i < 4 && arr[1][0][3]; i++)  {
        ans += min(arr[1][0][3], arr[0][0][i]);
        if (arr[1][0][3] > arr[0][0][i]) {arr[1][0][3] -= arr[0][0][i]; arr[0][0][i] = 0;} // AB- receivers
        else arr[0][0][3] -= arr[1][0][i];
    }

    // positive receivers
    for (int i = 0; i < 2 && arr[1][1][0]; i++) {
        ans += min(arr[1][1][0], arr[0][i][0]);
        if (arr[1][1][0] > arr[0][i][0]) {arr[1][1][0] -= arr[0][i][0]; arr[0][i][0] = 0;} // AB- receivers
        else arr[0][1][0] -= arr[1][i][0];
    }
    for (int i = 0; i < 2 && arr[1][1][1]; i++)
        for (int j = 0; j < 2 && arr[1][1][1]; j++) {
            ans += min(arr[1][1][1], arr[0][j][i]);
            if (arr[1][1][1] > arr[0][j][i]) {arr[1][1][1] -= arr[0][j][i]; arr[0][j][i] = 0;} // AB- receivers
            else arr[0][1][1] -= arr[1][j][i];
        }
    for (int i = 0; i < 3 && arr[1][1][2]; i += 2)
        for (int j = 0; j < 2 && arr[1][1][2]; j++) {
            ans += min(arr[1][1][2], arr[0][j][i]);
            if (arr[1][1][2] > arr[0][j][i]) {arr[1][1][2] -= arr[0][j][i]; arr[0][j][i] = 0;} // AB- receivers
            else arr[0][1][2] -= arr[1][j][i];
        }
    for (int i = 0; i < 4 && arr[1][1][3]; i ++)
        for (int j = 0; j < 2 && arr[1][1][3]; j++) {
            ans += min(arr[1][1][3], arr[0][j][i]);
            if (arr[1][1][3] > arr[0][j][i]) {arr[1][1][3] -= arr[0][j][i]; arr[0][j][i] = 0;} // AB- receivers
            else arr[0][1][3] -= arr[1][j][i];
        }
//    for (int i = 0; i < 2; i++)
//        for (int j = 0; j < 2; j++)
//            for (int k = 0; k < 4; k++)
//                printf("%d, ", arr[i][j][k]);
    printf("%d\n", ans);
    return 0;
}