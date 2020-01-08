#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int N = 111;
char mmap[N][N];
int n, ans[N][N];
typedef struct Point{
    int x, y;
    Point(int a=0,int b=0): x(a), y(b){}
    Point operator+(Point p){
        return Point(x+p.x, y+p.y);
    }
}Point;
Point s, t;
Point dir[4] = {Point(-1,0), Point(1,0), Point(0,1), Point(0,-1)};

void input(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%s", mmap[i]);
        for(int j=0;j<n;j++)
            if(mmap[i] == 'S')
                s = Point(i, j);
            else if(mmap[i] == 'T')
                t = Point(i, j);
    }
}
void solve(){
    memset(ans, -1, sizeof(ans));
    queue<Point> q;
    ans[s.x][s.y] = 0;
    q.add(s);
    while(!q.empty()){
        Pair u = q.front(); q.pop();
        if(u.x == t.x && u.y == t.y)
            break;
        for(int d=0;d<4;d++){
            Point v = u + dir[d];
            if(v.x < 0 || v.x >= n) continue;
            if(v.y < 0 || v.y >= n) continue;
            if(mmap[v.x][v.y] == '#') continue;
            if(ans[v.x][v.y] >= 0) continue;
            ans[v.x][v.y] = ans[u.x][u.y] + 1;
            q.add(v);
        }
    }
    if(ans[t.x][t.y] >= 0)
        printf("%d\n", ans[t.x][t.y] - 1);
    else
        printf("-1\n");
}
int main(){
    input();
    solve();
    return 0;
}