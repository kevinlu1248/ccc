#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int N = 100010;

int n, m;
bool pho[N];
vector<int> edges[N];
bool activate[N];
void addEdge(int a,int b){
    //双向边
    edges[a].push_back(b);
    edges[b].push_back(a);
}

bool dfs(int u, int father = -1){
    //dfs(u)表示以u为根的子树是否可以被删除
    bool res = true;
    if(pho[u]) res = false;
    for(int to : edges[u]) if(to != father){
        if(!dfs(to, u))//以to为根的子树不能被删除
            res = false;
    }
    if(res)
        activate[u] = false; // delete this point
    return res;
}
void dealwith(){
    for(int i=0;i<n;i++)
        activate[i] = true;
    for(int i=0;i<n;i++) if(pho[i]){
        dfs(i);
        break;
    }
}


pair<int, int> findFarest(int start){
    // return <index, distance>
    int dis[N], res = 0;
    for(int i=0;i<n;i++) dis[i] = -1;
    //memset(dis, -1, sizeof(dis));
    queue<int> Q;
    Q.push(start); dis[start] = 0;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        res = max(res, dis[u]);
        for(int to : edges[u]) if(activate[to] && dis[to] < 0){
            dis[to] = dis[u] + 1;
            Q.push(to);
        }
    }
    return res;
}
pair<int, int> findFarest_bfs2(int start){
    int res = 0;
    queue<pair<int, pair<int, int>>> Q; // <index,<father,dis>>
    Q.push({start, {-1, 0}});
    while(!Q.empty()){
        pair<int, pair<int, int>> u = Q.front(); Q.pop();
        res = max(res, u.second.second);
        for(int to : edges[u.first]) if(activate[to] && to != u.second.first)
            Q.push({to, {u.first, u.second.second + 1}});
    }
    return res;
}
pair<int, int> findFarest_dfs(int start, int father = -1, int depth = 0){
    pair<int, int> res = {start, 0};
    for(int to : edges[start]) if(activate[to] && to != father){
        pair<int, int> tmp = findFarest_dfs(to, start, depth + 1);
        if(tmp.second > res.second)
            res = tmp;
    }
    return res;
}
int diameter(){
    // return findFarest(findFarest(0).first).second;
    int start = 0;
    for(int i=0;i<n;i++) if(activate[i])
        start = i;
    pair<int, int> a = findFarest(start);
    pair<int, int> b = findFarest(a.first);
    return b.second;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i=0;i<m;i++){
        int a;
        scanf("%d", a);
        pho[a] = true;
    }
    for(int i=1;i<n;i++){ //n-1 lines
        int a, b;
        scanf("%d%d", &a, &b);
        addEdge(a, b);
    }
    dealwith();
    int ans = 0;
    for(int i=0;i<n;i++) if(activate[i])
        ans++;
    ans = (ans - 1) * 2;
    ans -= diameter();
    printf("%d\n", ans)
    return 0;
}
