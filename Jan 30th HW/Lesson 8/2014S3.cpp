#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
const int N = 100010;
int n, a[N];
stack<int> s;


void solve(){
    // s.size()
    while(!s.empty()) s.pop();//保证栈是空的
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    int now = 1;//当前湖里需要的数字
    for(int i=n-1;i>=0;i--){
        if(a[i] == now) now++;//a[i]掉进湖里
        else{
            if(a[i] > s.top()) break;//剪枝
            s.push(a[i]);//a[i]进入栈
        }
        while(!s.empty() && s.top() == now){
            s.pop();//栈顶的元素出栈
            now++;//栈顶的元素掉进湖里
        }
    }
    printf(now==n+1 ? "Y" : "N");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}