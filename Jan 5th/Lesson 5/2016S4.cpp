#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 411;

int n, a[N], ans, sum[N];
bool dp[N][N]; // dp[i][j]表示a[i]~a[j]是否可以合并为一个饭团

void solve(){
    for(int i=1;i<=n;i++)
        dp[i][i] = true;
    for(int i=1;i<=n;i++)
        sum[i] = a[i] + sum[i-1];
    for(int d=1;d<=n;d++){
        for(int i=1;i+d<=n;i++){
            int j = i + d;
            //calculate dp[i][j]
            int s=i, t=j;
            int sum_s=a[s], sum_t=a[t];
            while(s<t){
                while(sum_s != sum_t && s<t){
                    if(sum_s < sum_t){ // sum_s += a[++s];
                        s++;
                        sum_s += a[s];
                    }else{ // sum_t += a[--t];
                        t--;
                        sum_t += a[t];
                    }
                }
                if(s<t && dp[i][s] && dp[t][j]
                && (s+1 > t-1 || dp[s+1][t-1])){
                    dp[i][j] = true;
                    break;
                }
            }
            /*
            for(int s=i;s<j;s++){
                for(int t=s;t<=j;t++){
                    //[i,s], [s+1,t-1], [t,j]
                    if(sum[s] - sum[i-1] == sum[j] - sum[t-1]
                        && dp[i][s] && dp[t][j]
                        && (s+1>t-1 || dp[s+1][t-1]))
                        dp[i][j] = true;
                }
            }*/
        }
    }
    for(int i=1;i<=n;i++) for(int j=i;j<=n;j++)
        if(dp[i][j])
            ans = max(ans, sum[j] - sum[i-1]);
}

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        scanf("%d", &a[i]);
    solve();
    printf("%d\n", ans);
}