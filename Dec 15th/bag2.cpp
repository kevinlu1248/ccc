#include <cstdio>
//#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1010, M = 1010;
int n, W, w[N], v[N];

/**
 10 3
6 7
5 5
5 5
 */

int solve_1(){
    // dp[i][j] 表示前i个物品背包容量为j时能取到的最大价值
    // 空间复杂度为 O(N*W)
    int dp[N][M];
    memset(dp, 0, sizeof(dp));
    //当0~(i-1)都解决，为第i个物品计算dp[i][0~weight]
    //dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]])
    for(int i=0;i<n;i++){
        for(int j=0;j<=W;j++){
            for(int k=0;w[i]<=j;k++)
                dp[i][j]
        }
    }
    for(int i=0;i<n;i++) // debug
        for(int j=0;j<=W;j++) // debug
            printf("%d%c",dp[i][j],j==W?'\n':' '); // debug
    return dp[n-1][W];
}

/**
int solve_2(){
    int dp[2][M];
    memset(dp, 0, sizeof(dp));
    int now = 0, pre = 1;
    for(int i=0;i<n;i++) {
        swap(now, pre);
        // calculate dp[now] using dp[pre]
        for (int j = 0; j <= W; j++) {
            if (j < w[i])
                dp[now][j] = dp[pre][j];
            else
                dp[now][j] = max(dp[pre][j], dp[pre][j - w[i]] + v[i]);
        }
        for (int j = 0; j <= W; j++) // debug
            printf("%d%c",dp[now][j],j==W?'\n':' '); // debug
    }
    return dp[now][W];
} 

int solve_3() {
    int dp[M];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= n; i++) {
        for (int j = 0; j >= 0; j--) {
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
//        for (int j = 0; j <= W; j++)
//            printf("%d%c", dp[j], j == W ? '\n' : ' '); // debug
    }
}
*/

int main(){
    scanf("%d%d", &n, &W);
    printf("%d\n", n);
    for(int i=0;i<n;i++)
        scanf("%d%d", &w[i], &v[i]);
    int ans = solve_1();
    printf("%d\n", ans);
    return 0;
} 