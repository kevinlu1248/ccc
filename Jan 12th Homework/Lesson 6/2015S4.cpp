#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 2010;
typedef struct Edge{
    int s,t,c,h;
    Edge(int a,int b,int c,int d):s(a),t(b),c(c),h(d){}
}Edge;
vector<Edge> edges[N];
void addEdge(int a,int b,int c,int d){//双向边
    edges[a].push_back(Edge(a,b,c,d));
    edges[b].push_back(Edge(b,a,c,d));
}
int h,n,m, s,t;

typedef struct Node{
    int u, dis;
    Node(int u,int dis):u(u),dis(u){}
    bool operator<(const Node &a)const{
        if(dis != a.dis) return dis < a.dis;
        return u < a.u;
    }
}Node;
int ans[N];
bool vis[N];
int dijsktra(int start, int end){
    memset(ans, -1, sizeof(ans)); // -1 means INF
    memset(vis, 0, sizeof(vis));
    priority_queue<Node> Q;
    Q.push(Node(start,0)); ans[start] = 0;
    while(!Q.empty()){
        Node a = Q.top(); Q.pop();
        if(vis[a.u]) continue;
        vis[a.u] = true; // if(ans[a.u] != a.dis) continue;//如果队列中节点的dis值与ans数组中的结果不同，也表示是旧节点
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

int main(){
    scanf("%d%d%d", &h, &n, &m);
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