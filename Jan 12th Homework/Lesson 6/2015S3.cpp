#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

const int N = 100010;
int n, m, g;

//并查集 Disjoint Set Union (DSU) / Union-find Sets
int fa[N];
void initFather(){
    for(int i=1;i<=n;i++)
        fa[i] = i;
}
int findFather(int x){
    if(fa[x] == x) return x;
    return fa[x] = findFather(fa[x]);
}
//总复杂度为O(M+N)
int main(){
    scanf("%d%d", &n, &m);
    initFather();
    int ans = 0;
    for(int i=0;i<m;i++){
        scanf("%d", &g);
        int x = findFather(g);
        if(x == 0) break;
        ans++;
        fa[x]--;//x登机口被占用，只能往前停
    }
    printf("%d\n", ans);
}


int pre[N],nxt[N];//pre数组和并查集中的fa数组很像，nxt数组可以省略
int use(int a){
    if(a <= 0) return -1; // break
    //将节点a从双向链表中删除
    pre[nxt[a]] = pre[a];
    nxt[pre[a]] = nxt[a];
    nxt[a] = N; // 该节点a已经被使用，标记为nxt[a]=N
    return pre[a];//节点a的前一个可用的节点pre[a]
}
int main_2(){
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++)
        pre[i] = i-1, nxt[i] = i+1;
    int ans = 0;
    for(int i=0;i<m;i++){
        scanf("%d", &g);
        int tmp = pre[g];
        if(nxt[g] >= N){//当前节点g已经被使用了，所以我们要往前找一个能用的节点，也就是pre[g]，也就是tmp
            if(pre[g] <= 0) break;//已经没有能用的了
            //否则有能用的，往前移一个，将当前g的pre置为前一个的pre
            pre[g] = pre[tmp];//把当前的pre置为前一个的pre(并查集)
            g = tmp;//往前移一个
        }
        pre[g] = use(g);//将节点g删掉
        if(pre[g] < 0) break;
        ans++;
    }
    printf("%d\n", ans)
    return 0;
}