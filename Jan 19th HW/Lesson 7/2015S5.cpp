#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 3010;
const int M = 110;
int n, m, a[N], b[M];

void update(int &x, int y){
    if(y > x)
        x = y;
}

int dp[N][M][M][2];//时间复杂度为O(N*M*M)，转移是O(1)的
//dp[i][L][R][k=0/1]表示：a序列前i个派，b序列剩下中间(L,R)个派没有用(b序列从左侧[1,L]已经用作分隔、右侧[R,m]已经被吃了)，能吃到的最大价值，k表示我上一个派吃了还是没吃(接下来这个派可以吃还是不可以吃)

int solve(){
    sort(b+1, b+1+m);//b较小的作分割用，较大的要被吃
    //但是我不知道是不是都较小或者较大
    //但是我知道b靠中间的部分，不可能在左右两侧之前被拿走
    //也就是说，b只可能剩下中间的部分
    for(int i=0;i<=n;i++){//i=0是初始化的部分
        for(int d=m+1;d>0;d--)//[L,R]最大可能是[0,m+1]相当于b序列没有被使用
        //dp[i][1][m+1]就表示b[1]已经被用了（用作split）
        //dp[i][0][m]就表示b[m]已经被用了（被吃了）
        for(int L=0; ; L++){
            int R = L + d;
            if(R >= m+1) break;
            //calculate dp[i][L][R][0/1]
            if(i >= 1){
                //not to eat a[i]
                update(dp[i][L][R][0], dp[i-1][L][R][0]);
                update(dp[i][L][R][0], dp[i-1][L][R][1]);
                //eat a[i]
                update(dp[i][L][R][1], dp[i-1][L][R][0] + a[i]);
            }
            if(L >= 1){//insert b[L] to split (no eat)
                update(dp[i][L][R][0], dp[i][L-1][R][0]);
                update(dp[i][L][R][0], dp[i][L-1][R][1]);
            }
            if(R <= m){//insert b[R] to eat
                update(dp[i][L][R][1], dp[i][L][R+1][0] + b[R]);//eat b[R]
            }
        }
    }
    int res = 0;
    for(int i=1;i<=m;i++){
        //dp[n][i][i+1][0/1]表示a序列已经全部用光
        //b序列[1~i]的部分被用来分割，[i+1~m]的部分被吃了
        update(res, dp[n][i][i+1][0]);
        update(res, dp[n][i][i+1][1]);
    }
    return res;
}
int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for(int i=1;i<=m;i++)
        scanf("%d", &b[i]);
    int ans = solve();
    printf("%d\n", ans);
    return 0;
}