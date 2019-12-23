#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int n;
pair<int, int> a[N];
bool cmp(pair<int, int> x, pair<int, int> y){
    return x.second < y.second;
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d%d", &a[i].first, &a[i].second);
    sort(a, a+n, cmp); //sort(a, a+n);
    int time = 0, ans = 0;
    for(int i=0;i<n;i++)
        if(a[i].first >= time)
            ans++, time = a[i].second;
    printf("%d\n", ans);
    return 0;
}