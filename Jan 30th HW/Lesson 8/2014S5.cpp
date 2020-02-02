#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 2010;
int n, xs[N], ys[N], dis[N][N], d[N];

int sqr(int a){return a*a;}
void input(){
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d%d", &xs[i], &ys[i]);
}
vector<pair<int, int>> L;
bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    return dis[a.first][a.second] < dis[b.first][b.second];
}

int dp[2][N];
int solve(){
    for(int i=0;i<n;i++){
        d[i] = sqr(xs[i])+ sqr(ys[i]);
        for(int j=0;j<n;j++){
            dis[i][j] = sqr(xs[i]-xs[j]) + sqr(ys[i]-ys[j]);
            if(i != j)
                L.push_back(make_pair(i, j));
        }
    }
    sort(L.begin(), L.end(), cmp); // sort by dis
    int ans = 0, pre_distance=-1;
    vector<int> js;
    for(int i=0;i<L.size();i++){
        int distance = dis[L[i].first][L[i].second];
        if(pre_distance < distance){
            //update dp[0] by dp[1]
            for(int j : js)
                dp[0][j] = max(dp[0][j], dp[1][j]);
            js.clear();
        }
        js.push_back(L[i].first);
        dp[1][L[i].first] = max(dp[1][L[i].first], dp[0][L[i].second]+1);
        if(distance < d[L[i].first])
            ans = max(ans, dp[1][L[i].first]);
        //end
        pre_distance = distance;
    }
    return ans+1;
}

int main(){
    input();
    int ans = solve();
    printf("%d\n", ans);
    return 0;
}



/*

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;
//#define MANGO_DEBUG
#ifdef MANGO_DEBUG
#define debug(a...) printf(a);
#else
#define debug(a...)
#endif
#define update(a,op,b,s) do{if((a)op(b)){a=(b);s;}}while(false)
char c;
bool fastInput_flag;
void fastInput(int &a){
    a=0;fastInput_flag=false;
    do{
        c=getchar();
    }while(c!='-' && (c<'0'||c>'9'));
    if(fastInput_flag=(c=='-'))
        c=getchar();
    do{
        a=a*10+c-'0';
    }while((c=getchar())>='0' && c<='9');
    if(fastInput_flag) a=-a;
}


const int N=2010;
int n,dis[N][N],dp[3][N],ans;

inline int sqr(const int &a){return a*a;}
typedef struct Point{
    int x,y;
    Point(int x=0,int y=0):x(x),y(y){}
    int dis2(const Point &p=Point())const{return sqr(x-p.x)+sqr(y-p.y);}
}Point;
Point p[N];
Point l[N*N];

bool cmp(const Point &i,const Point &j){
    return dis[i.x][i.y]<dis[j.x][j.y];
}

void input(){
    fastInput(n);
    //p[0].x=p[0].y=0;
    for(int i=1;i<=n;i++){
        fastInput(p[i].x);
        fastInput(p[i].y);
    }
}

void solve(){
    if(n==0) return;
    int len=0;
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            dis[i][j]=p[i].dis2(p[j]);
            l[len].x=i;
            l[len++].y=j;
        }
    }
    sort(l,l+len,cmp);
    for(int i=0;i<len;i++){
        debug("cal: %d,%d,%d:\n",l[i].x,l[i].y,dis[l[i].x][l[i].y]);
        if(l[i].x)
            update(dp[0][l[i].x],<,dis[l[i].x][l[i].y],
                   dp[1][l[i].x]=dp[2][l[i].x]);
        update(dp[0][l[i].y],<,dis[l[i].x][l[i].y],
               dp[1][l[i].y]=dp[2][l[i].y]);
        if(l[i].x)
            update(dp[2][l[i].y],<,dp[1][l[i].x]+1,);
        update(dp[2][l[i].x],<,dp[1][l[i].y]+1,);
    }
    ans=dp[2][0];
}

void output(){
    printf("%d\n",ans);
}


int main() {
    int t=1;//scanf("%d",&t);
    while(t--) {
        input();
        solve();
        output();
    }
    return 0;
}


*/






