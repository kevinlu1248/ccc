#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1001;

int n,a[N];
int dp[N];
int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    for(int i=1;i<=n;i++){
        dp[i] = 1;
        for(int j=1;j<i;j++)
            if(a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
    //  ans = max(ans, dp[i]);
    }
    int ans = 0;
    for(int i=1;i<=n;i++)
        ans = max(ans, dp[i]);
    printf("%d\n", n);
    return 0;
}