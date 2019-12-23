#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int n;
typedef struct Pair{
    int s, t;
    bool operator<(Pair x){
        return s < x.s;
    }
}Pair;
Pair a[N];
bool cmp(Pair x, Pair y){
    return x.t < y.t;
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d%d", &a[i].s, &a[i].t);
    sort(a, a+n, cmp); //sort(a, a+n);
    int time = 0, ans = 0;
    for(int i=0;i<n;i++)
        if(a[i].s >= time)
            ans++, time = a[i].t;
    printf("%d\n", ans);
    return 0;
}