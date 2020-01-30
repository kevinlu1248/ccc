#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 2010;
const int K = 201;
typedef struct Edge{
    int s,t,c,k;
    Edge(int a,int b,int c,int d):s(a),t(b),c(c),k(d){}
}Edge;
vector<Edge> edges[N];
void addEdge(int a,int b,int c,int d){//双向边
    edges[a].push_back(Edge(a,b,c,d));
    edges[b].push_back(Edge(b,a,c,d));
}
int k,n,m, s,t;

typedef struct Node{
    int u, dis;
    Node(int u,int dis):u(u),dis(dis){}
    bool operator<(const Node &a)const{
        if(dis != a.dis) return dis < a.dis;
        return u < a.u;
    }
}Node;
int ans[N];
bool vis[N];
int dijsktra(int start, int end){//复杂度为O(m*log(n))
    //如果不用优先队列，改用循环，复杂度为O(n^2)
    memset(ans, -1, sizeof(ans)); // -1 means INF
    memset(vis, 0, sizeof(vis));
    priority_queue<Node> Q;
    Q.push(Node(start,0)); ans[start] = 0;
    while(!Q.empty()){
        Node a = Q.top(); Q.pop();
        if(vis[a.u]) continue;
        vis[a.u] = true; // if(ans[a.u] != a.dis) continue;//如果队列中节点的dis值与ans数组中的结果不同，也表示是旧节点（这样可以不使用vis）
        printf("Node %d(%d):\n", a.u, a.dis);
        if(a.u == end) break;
        for(Edge e : edges[a.u]){
            if(ans[e.t] < 0// ans[e.t] is INF
                || ans[e.t] > a.dis + e.c){//需要松弛
                //从边e走到e.t的距离 比原来记录的ans[e.t]答案要小，所以要更新ans[e.t]的记录，这个操作叫做：松弛操作
                printf("  >> %d(%d) > %d + Edge(%d)\n", e.t, ans[e.t], a.dis, e.c);
                ans[e.t] = a.dis + e.c;
                //优先队列priority_queue不支持直接修改内部节点的优先级
                //所以我们只能重新将该点与新dis值 插入队列
                //因为是优先队列，所以该点权值较小，会自然的优先出队
                //为了避免原来权值较大的旧节点重复出队，用vis数组避免
                Q.push(Node(e.t, ans[e.t]));
            }
        }
    }
    return ans[end];
}
int bellman_ford(int start, int end){//复杂度O(n*m)
    const int INF = 1000000000;//1e9
    for(int i=0;i<n;i++) ans[i] = INF;
    ans[start] = 0;
    for(int k=1;k<n;k++)//n-1次循环，表明最短路只经过至多n-1条边
        //对所有的边进行松弛（该操作会在循环中进行n-1次）
        for(int i=0;i<n;i++)//先遍历所有点
            for(Edge e : edges[i])//再遍历该点出去的所有边
                if(ans[e.s] < INF
                && ans[e.t] < ans[e.s] + e.c)//松弛操作：e.s->e.t(e.c)
                        ans[e.t] = ans[e.s] + e.c;
                    // ans[e.t] = min(ans[e.t], ans[e.s] + e.c);
    return ans[end];
}
int cnt[N];
int spfa(int start, int end){
    //复杂度在最坏情况下是O(n*m)的，但实际使用中复杂度会很低
    //可以检查图中是否存在负环（只能检查start能走到的负环）
                        //如果要检查全图中的负环，需要额外设置一个超级起点
    const int INF = 1000000000;//1e9
    for(int i=0;i<n;i++) ans[i] = INF;
    memset(vis, 0, sizeof(vis));//节点是否在队列中
    memset(cnt, 0, sizeof(cnt));//节点入队次数
    queue<int> Q;
    Q.push(start); ans[start] = 0; vis[start] = true;
    while(!Q.empty()){
        int u = Q.front(); Q.pop(); vis[u] = false;//vis标记该点是否在队列中
        for(Edge e : edges[u]){
            if(ans[e.s] < INF
            && ans[e.t] > ans[e.s] + e.c){//松弛操作：e.s->e.t(e.c)
                ans[e.t] = ans[e.s] + e.c;
                if(vis[e.t]) continue; // 如果已经在队列中，就不入队了
                Q.push(e.t); vis[e.t] = true;
                cnt[e.t]++; // cnt表示节点入队的次数
                if(cnt[e.t] > n) // 入队次数大于n，说明存在负环
                    return -INF;
            }
        }
    }
    return ans[end];
}
void floyd(int dis[N][N], int ans[N][N]){//复杂度是O(n^3)
    //全源最短路：所有节点到所有节点的最短路
    //不用调用n次dijkstra或spfa
    //dis是邻接矩阵，ans记录答案
    const int INF = 1000000000;//1e9
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) ans[i][j] = dis[i][j];
    //Floyd
    for(int k=0;k<n;k++)//先枚举所有中继节点k
        for(int i=0;i<n;i++)//再枚举所有起点i
            for(int j=0;j<n;j++)//以及终点j
                if(ans[i][k] < INF && ans[k][j] < INF)
                    if(ans[i][j] > ans[i][k] + ans[k][j])//松弛
                        ans[i][j] = ans[i][k] + ans[k][j];
    //compare (i->j) to (i->k->j)
}


typedef struct Point{
    int u, dis, k;
    Point(int u,int dis,int k):u(u),dis(dis),k(h){}
    bool operator<(const Point &a)const{
        if(dis != a.dis) return dis < a.dis;
        if(k != a.k) return k < a.k;
        return u < a.u;
    }
}Point;
int solve(int start, int end){
    //分层最短路
    int res = -1;
    const int K = 201;
    int ans[N][K];
    memset(ans, -1, sizeof(ans)); // -1 means INF
    ans[start][0] = 0;//当前磨损的甲板厚度为0
    priority_queue<Point> Q;
    Q.push(Point(start, 0, 0));
    while(!Q.empty()){//dijkstra
        Point now = Q.top(); Q.pop();
        if(now.dis != ans[now.u][now.k]) continue;
        if(now.u == end) break;
        for(Edge e : edges[now.u]){
            //走过边e之后的状态
            Point nxt(e.t, now.dis+e.c, now.k+e.k);
            if(nxt.k >= k) continue;//如果磨损厚度已经超过k，不需要考虑
            if(ans[nxt.u][nxt.k] < 0// nxt状态在ans中记录的为INF
                || ans[nxt.u][nxt.k] > nxt.dis){//需要松弛
                //从边e走到e.t的距离 比原来记录的ans答案要小，所以要更新ans的记录，这个操作叫做：松弛操作
                if(nxt.u == end)
                    if(res < 0 || res > nxt.dis)
                        res = nxt.dis;
                if(res >= 0 && res < nxt.dis)
                    continue;//剪枝
                ans[nxt.u][nxt.k] = nxt.dis;
                Q.push(nxt);
            }
        }
    }
    for(int i=0;i<k;i++){//磨损小于k的
        if(ans[end][i] < 0) continue;
        if(res < 0 ||  res > ans[end][i])
            res = ans[end][i];
    }
    return res;
}

int main(){
    scanf("%d%d%d", &k, &n, &m);
    for(int i=0;i<m;i++){
        int a,b,c,d;
        scanf("%d%d%d%d", &a,&b,&c,&d);
        addEdge(a,b,c,d);
    }
    scanf("%d%d", &s, &t);
    int ans = dijsktra(s, t);
    printf("%d\n", ans);
    return 0;
}