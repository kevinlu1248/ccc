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

//扫描线
typedef struct Seg{
    long long x, g, y, yr;
    int id;
    Seg(long long x=0, long long g=0, long long y=0, long long yr=0, int id=0):x(x),g(g),y(y),yr(yr), id(id){}
    bool operator<(const Seg &seg)const{
        if(x!=seg.x) return x < seg.x;
        if(y!=seg.y) return y < seg.y;
        if(yr!=seg.yr) return yr < seg.yr;
        // if(g!=seg.g) return g < seg.g;
        return id < seg.id;
    }
}Seg;
vector<Seg> segs;

long long y_g[N*2];

long long solve(){
    long long ans = 0;
    for(int i=0;i<ys.size();i++)
        y_g[i] = 0;
    //segments
    for(int i=0;i<n;i++){
        segs.push_back(Seg(rects[i].x, rects[i].g, rects[i].y, rects[i].yr, i));//open
        segs.push_back(Seg(rects[i].xr, -rects[i].g, rects[i].y, rects[i].yr, i));//close
    }
    sort(segs.begin(), segs.end());
    //扫描
    long long pre_x = -1;
    for(Seg seg : segs){
        // printf("> x = %lld, y:(%lld,%lld), g=%lld id=%d\n", seg.x, seg.y,seg.yr, seg.g, seg.id);
        //计算答案 (pre_x -> seg.x)
        if(pre_x >= 0){
            long long w = seg.x - pre_x;//x轴跨度
            long long sum = 0;
            for(int i=1;i<ys.size();i++)
                if(y_g[i] >= t)
                    sum += ys[i]-ys[i-1];
            ans += w * sum;
        }
        //更新扫描线上的灰度值
        //y_g[seg.y -> seg.yr] += seg.g
        int L = ymap[seg.y];
        int R = ymap[seg.yr];
        for(int i=L+1;i<=R;i++)
            y_g[i] += seg.g;
        // for(int i=0;i<ys.size();i++){
        //     if(i>0) printf(" -[%lld]- ", y_g[i]);
        //     printf("%lld", ys[i]);
        // }printf("\n");
        //end
        pre_x = seg.x;
    }
    return ans;
}
/*
> x = 11, y:(11,15), g=1 id=0
8 -[0]- 11 -[1]- 12 -[1]- 13 -[1]- 15 -[0]- 17
> x = 12, y:(12,13), g=1 id=3
8 -[0]- 11 -[1]- 12 -[2]- 13 -[1]- 15 -[0]- 17
> x = 13, y:(8,17), g=2 id=1
8 -[2]- 11 -[3]- 12 -[4]- 13 -[3]- 15 -[2]- 17
> x = 14, y:(8,17), g=-2 id=1
8 -[0]- 11 -[1]- 12 -[2]- 13 -[1]- 15 -[0]- 17
> x = 17, y:(8,17), g=1 id=2
8 -[1]- 11 -[2]- 12 -[3]- 13 -[2]- 15 -[1]- 17
> x = 18, y:(8,17), g=-1 id=2
8 -[0]- 11 -[1]- 12 -[2]- 13 -[1]- 15 -[0]- 17
> x = 19, y:(12,13), g=-1 id=3
8 -[0]- 11 -[1]- 12 -[1]- 13 -[1]- 15 -[0]- 17
> x = 20, y:(11,15), g=-1 id=0
8 -[0]- 11 -[0]- 12 -[0]- 13 -[0]- 15 -[0]- 17
*/



int main(){
    input();
    discretization_y();
    long long ans = solve();
    printf("%lld\n", ans);
}