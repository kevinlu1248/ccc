/**
背包问题：
有一个容量为 weight 的背包，现在有 n 类物品，每类物品分别具有 v[i] 的价值和 w[i] 的体积，每类物品有无穷多个，问能取走物品的最大价值？
0 <= n, weight, v[i], w[i] <= 10^3
Sample:
10 2
6 7
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
    //时间复杂度为 O(N*W * W)
// dp[i][j] 表示前i个物品背包容量为j时能取到的最大价值
    int dp[N][W]; memset(dp, 0, sizeof(dp));
//当0~(i-1)都解决，为第i个物品计算dp[i][0~weight]
//dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]])
    for(int i=0;i<n;i++){
        for(int j=0;j<=weight;j++){
            dp[i][j] = dp[i-1][j];
            for(int k=1;w[i]*k<=j;k++){
                dp[i][j] = max(dp[i][j],
                    dp[i-1][j-w[i]*k]+v[i]*k);
            }
        }
    }
    for(int i=0;i<n;i++) // debug
        for(int j=0;j<=weight;j++) // debug
            printf("%d%c",dp[i][j],j==weight?'\n':' '); // debug
    return dp[n-1][weight];
}
int solve_3(){
    int dp[W]; memset(dp, 0, sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=w[i];j<=weight;j--){
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
