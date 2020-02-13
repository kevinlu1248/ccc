// mccc1
// created on 2/11/2020 4:53 PM by Kevin Lu
// War

/*
5
1 1 2 4 3
1 2 2 4 1

5
1 3 2 4 3
2 2 2 4 1

7
1 3 2 4 3 4 5
1 2 2 5 1 1 5

1
1
1

5
1 2 3 4 4
1 2 3 4 4
 */

#include <cstdio>
#include <algorithm>
// <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, cnt;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++) 
            scanf("%d", &arr[i][j]);
    int i = -1;
    bool isWar = false;
    while (++i < n) {
//        printf("%d, %d\n", arr[0][i], arr[1][i]);
        if (arr[0][i] == arr[1][i])
            isWar = true;
        else if (arr[0][i] != arr[1][i] && isWar) {
            cnt++;
            isWar = false;
        }
    }
    if (isWar) cnt++;
    printf("%d", cnt);
    return 0;
}