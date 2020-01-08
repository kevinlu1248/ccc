#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
//#undef MANGO_DEBUG
const int N=150010;
const int M=N;
const int NN=500;
int n,m,q,a[N],id[N],nn;

int ind[N],indnn[N],indnn1[N],sum[N/NN+1];
vector<int> line[M];
int line_len[M],pos[N];
vector<int> line_part[M];
int shift[M];

void input(){
    scanf("%d", &n);
    nn=NN;
    scanf("%d", &m);
    scanf("%d", &q);
    for(int i=0;i<n;i++) {
        ind[i]=i/nn;
        indnn[i]=ind[i]*nn;
        indnn1[i]=indnn[i]+nn;
        scanf("%d", &id[i]); id[i]--;
        pos[i]=line[id[i]].size();
        line[id[i]].push_back(i);
        //shift[id[i]]=0;
        line_len[id[i]]++;
    }
    for(int i=0;i<n;i++) {
        scanf("%d", &a[i]);
        sum[ind[i]]+=a[i];
    }
    for(int i=0;i<m;i++){
        int last=-1;
        for(int j:line[i]){
            if(last>=0 && ind[j]!=ind[last])
                line_part[i].push_back(last);
            last=j;
        }
        line_part[i].push_back(line[i][line_len[i]-1]);
    }
}
int tmp;
int shift_index(const int &id,const int &k){
    tmp=(pos[k]+shift[id]);
    if(tmp>=line_len[id]) return tmp-line_len[id];
    return tmp;
}
#define _query(k) (a[line[id[k]][shift_index(id[k],k)]])
int res,left,right;
int query(const int &l,const int &r){
    res=0;
    if(ind[l]==ind[r]){
        for(int i=l;i<=r;i++)
            res+=_query(i);
    }else{
        left=(l==indnn[l])?0:1;
        right=(r==indnn1[r])?0:1;
        if(left)
            for(int i=l,e=indnn1[l];i<e;i++)
                res+=_query(i);
        if(right)
            for(int i=indnn[r];i<=r;i++)
                res+=_query(i);
        right=ind[r]-right;
        for(int i=ind[l]+left;i<=right;i++)
            res+=sum[i];
    }
    return res;
}

int main() {
    input();
    int t,l,r,id,value,len;
    while(q--){
        scanf("%d", &t);
        if(t==1){
            scanf("%d", &l); l--;
            scanf("%d", &r); r--;
            printf("%d\n",query(l,r));
        }else{
            scanf("%d", &id);id--;
            len=line_part[id].size();
            if(len>0) {
                value = a[line[id][shift_index(id, line_part[id][len - 1])]];
                sum[ind[line_part[id][len - 1]]] -= value;
                sum[ind[line_part[id][0]]] += value;
            }
            for(int i=len-2,j=len-1;i>=0;j=i--) {
                value=a[line[id][shift_index(id,line_part[id][i])]];
                sum[ind[line_part[id][i]]] -= value;
                sum[ind[line_part[id][j]]] += value;
            }
            shift[id]--;
            if(shift[id]<0) shift[id]+=line_len[id];
        }
    }
    return 0;
}