/**
背包问题：
有一个容量为 weight 的背包，现在有 n 个物品，分别具有 v[i] 的价值和 w[i] 的体积，问能取走物品的最大价值？
0 <= n, weight, v[i], w[i] <= 10^3
Sample:
10 3
6 7
5 5
5 5
时间复杂度为 O(N*W)
空间复杂度为 O(W)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 111, W = 111;
int n, weight, w[N], v[N];
int solve_1(){
// dp[i][j] 表示前i个物品背包容量为j时能取到的最大价值
    int dp[N][W];
    memset(dp, 0, sizeof(dp));
//当0~(i-1)都解决，为第i个物品计算dp[i][0~weight]
//dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]])
    for(int i=0;i<n;i++){
        for(int j=0;j<=weight;j++){
            if(j < w[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
        }
    }
    for(int i=0;i<n;i++) // debug
        for(int j=0;j<=weight;j++) // debug
            printf("%d%c",dp[i][j],j==weight?'\n':' '); // debug
    return dp[n-1][weight];
}
int solve_2(){
    int dp[2][W]; memset(dp, 0, sizeof(dp));
    int now = 0, pre = 1;
    for(int i=0;i<n;i++){
        swap(now, pre);
        // calculate dp[now] using dp[pre]
        for(int j=0;j<=weight;j++){
            if(j < w[i])
                dp[now][j] = dp[pre][j];
            else
                dp[now][j] = max(dp[pre][j], dp[pre][j-w[i]] + v[i]);
        }
        for(int j=0;j<=weight;j++) // debug
            printf("%d%c",dp[now][j],j==weight?'\n':' '); // debug
    }
    return dp[now][weight];
}
int solve_3(){
    int dp[W]; memset(dp, 0, sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=weight;j>=w[i];j--){
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
        for(int j=0;j<=weight;j++) // debug
            printf("%d%c",dp[j],j==weight?'\n':' '); // debug
    }
    return dp[weight];
}
int main(){
    scanf("%d%d", &weight, &n);
    for(int i=0;i<n;i++)
        scanf("%d%d", &w[i], &v[i]);
    int ans = solve_1();
    printf("%d\n", ans);
    return 0;
}
