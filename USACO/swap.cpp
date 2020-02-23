/*
ID: kevinlu2
TASK: swap
LANG: C++
*/
// created on 2/23/2020 11:14 AM by Kevin Lu
// C:\Users\XPS\ccc\USACO

#include <cstdio>
#include <algorithm>
// <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, k, a[2], b[2], tmp[N], arr[N], ord = 0;
bool flag;

int main() {
    FILE *inp = fopen("swap.in", "r");
    FILE *outp = fopen("swap.out", "w");
    fscanf(inp, "%d%d%d%d%d%d", &n, &k, &a[0], &a[1], &b[0], &b[1]);
    for (int i = 1; i <= n; i++) arr[i] = i;
    while (!flag) {
        ord++;
        for (int i = 0; i <= (a[1] - a[0]) / 2; i++) swap(arr[a[0] + i], arr[a[1] - i]);
        for (int i = 0; i <= (b[1] - b[0]) / 2; i++) swap(arr[b[0] + i], arr[b[1] - i]);
        flag = true;
        for (int i = 0; i < n; i++) if (arr[i] != i) flag = false;
    }
    k %= ord;
    while (k--) {
        for (int &i: arr) if (i) printf("%d ", i); puts("");
        for (int i = 0; i <= (a[1] - a[0]) / 2; i++) swap(arr[a[0] + i], arr[a[1] - i]);
        for (int i = 0; i <= (b[1] - b[0]) / 2; i++) swap(arr[b[0] + i], arr[b[1] - i]);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", arr[i]);
        fprintf(outp, "%d\n", arr[i]);
    }
    return 0;
}

//#include <cstdio>
//#include <algorithm>
//// <bits/stdc++.h>
//using namespace std;
//const int N = 110;
//int n, k, a[2], b[2], tmp[N], arr[N];
//
//int main() {
//    FILE *inp = fopen("swap.in", "r");
//    FILE *outp = fopen("swap.out", "w");
//    fscanf(inp, "%d%d%d%d%d%d", &n, &k, &a[0], &a[1], &b[0], &b[1]);
//    for (int i = 1; i <= n; i++) arr[i] = i;
//    k %= 12;
//    int cop[32][N];
//    for (int i = 0; i <= (a[1] - a[0]) / 2; i++) swap(arr[a[0] + i], arr[a[1] - i]);
//    for (int i = 0; i <= (b[1] - b[0]) / 2; i++) swap(arr[b[0] + i], arr[b[1] - i]);
//    for(int i=1;i<=n;){
//        cop[0][i]= k[i];
//    }
//    for(int i=1;i<32;i++){
//        for(int j=1;j<n)
//            cop[i][j]=cop[i-1][cop[i-1][j]];
//    }
//    int current=
//    for(int i=0;;)
//        for (int i = 1; i <= n; i++) {
//            printf("%d\n", arr[i]);
//            fprintf(outp, "%d\n", arr[i]);
//        }
//    return 0;
//}