// mccc1s3
// created on 2/11/2020 5:56 PM by Kevin Lu
// SAM I am

#include <cstdio>
#include <algorithm>
#include <cstring>
// <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, cnt = 1, q;
char A[N][N], a[N];

int main() {
    scanf("%s%d", &A[0], &q);
    for (int i = 0; i < q; i++) {
        char o;
        scanf("%c", &o);
        if (o == 'C') {
            int s, j = 0;
            char t;
            scanf("%d%c", &s, &t);
            while (A[s][j++]) A[cnt][i] = A[s][j];
            A[cnt][j] = t;
            cnt++;
        } else {

        }
    }
    return 0;
}