#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 111;

int t, n, a[N], b[N];

int main(){
    scanf("%d%d", &t, &n);
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    for(int i=0;i<n;i++)
        scanf("%d", &b[i]);
    sort(a, a+n);
    sort(b, b+n);
    int ans = 0;
    if(t == 1){
        for(int i=0;i<n;i++)
            ans += max(a[i], b[i]);
    }else{
        for(int i=0;i<n;i++)
            ans += max(a[i], b[n-1 - i]);
    }
    printf("%d\n", ans);
    return 0;
}

int main_2(){
    scanf("%d%d", &t, &n);
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    for(int i=0;i<n;i++)
        scanf("%d", &b[i]);
    sort(a, a+n);
    sort(b, b+n);
    if(t == 2)
        // reverse b[:]
        for(int i=0;i*2<n;i++)
            swap(b[i], b[n-1-i])
    int ans = 0;
    for(int i=0;i<n;i++)
        ans += max(a[i], b[i]);
    printf("%d\n", ans);
    return 0;
}

bool cmp_1(int a,int b){
    return a < b;
}
bool cmp_2(int a,int b){
    return a > b;
}
int main_3(){
    scanf("%d%d", &t, &n);
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    for(int i=0;i<n;i++)
        scanf("%d", &b[i]);
    sort(a, a+n, cmp_1);
    sort(b, b+n, (t==1 ? cmp_1 : cmp_2));
    int ans = 0;
    for(int i=0;i<n;i++)
        ans += max(a[i], b[i]);
    printf("%d\n", ans);
    return 0;
}