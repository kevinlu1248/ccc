#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
using namespace std;

const int N = 1001;
int n;
long long t, ans;
struct Rect{
    long long x,y,xr,yr,g;
    Rect(long long x=0, long long y=0, long long xr=0, long long yr=0, long long g=0):x(x), y(y), xr(xr), yr(yr), g(g){}
}rects[N];
void input(){
    scanf("%d%lld", &n, &t);
    for(int i=0;i<n;i++){
        scanf("%lld%lld%lld%lld%lld", &rects[i].x, &rects[i].y, &rects[i].xr, &rects[i].yr, &rects[i].g);
        //xr > x, yr > y
    }
}

vector<long long> ys;//ys至多包含2*n个数
map<long long, int> ymap;
void discretization_y(){//离散化y轴
    set<long long> tmp;
    for(int i=0;i<n;i++){
        tmp.insert(rects[i].y);
        tmp.insert(rects[i].yr);
    }//去重
    for(long long y : tmp)//已经按从小到大顺序
        ys.push_back(y);
    for(int i=0;i<ys.size();i++)
        ymap[ys[i]] = i;
}
vector<long long> xs;//xs至多包含2*n个数
map<long long, int> xmap;
void discretization_x(){//离散化x轴
    set<long long> tmp;
    for(int i=0;i<n;i++){
        tmp.insert(rects[i].x);
        tmp.insert(rects[i].xr);
    }//去重
    for(long long x : tmp)//已经按从小到大顺序
        xs.push_back(x);
    for(int i=0;i<xs.size();i++)
        xmap[xs[i]] = i;
}

int main(){
    input();
    discretization_x();
    discretization_y();
    printf("xs: ");
    for(long long x : xs)
        printf("%lld ", x);
    printf("\n");
    printf("ys: ");
    for(long long y : ys)
        printf("%lld ", y);
    printf("\n");
    for(int i=1;i<xs.size();i++)
        for(int j=1;j<ys.size();j++){
            //cell (xs[i-1],xs[i])-(ys[i-1],ys[i])
            // printf("(%lld,%lld)-(%lld,%lld)\n",xs[i-1],xs[i],ys[j-1],ys[j]);
            long long g = 0;
            for(int k=0;k<n;k++){
                if(rects[k].x<=xs[i-1] && rects[k].xr>=xs[i])
                    if(rects[k].y<=ys[j-1] && rects[k].yr>=ys[j])
                        g += rects[k].g;
            }
            // printf("=%lld\n",g);
            if(g >= t)
                ans += (xs[i]-xs[i-1]) * (ys[j]-ys[j-1]);
        }
    printf("%lld\n", ans);
}