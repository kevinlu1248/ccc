#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 8;
int n, a[N];
bool vis[N];
void dfs(int pos){
    if(pos >= n){ // full
        for(int i=0;i<n;i++)
            printf("%d%c", a[i]+1, i<n-1?' ':'\n');
    }else{
        for(int i=0;i<n;i++) if(!vis[i]) {
            a[pos] = i;
            vis[i] = true;
            dfs(pos + 1);
            // a[pos] = -1;
            vis[i] = false;
        }
    }
}
int main(){
    scanf("%d", &n);
    dfs(0);
    return 0;
}