#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N = 100010;
int n, a[N];
vector<int> s;
//vector<T>::pop_back 把最后一个元素删除
//vector<T>::push_back 把新元素加入到数组末尾
//因为上述两种操作都是针对数组末尾的元素的，所以时间复杂度为O(1)
void solve(){
    // s.size()
    while(!s.empty()) s.pop_back();//保证栈是空的
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    int now = 1;//当前湖里需要的数字
    for(int i=n-1;i>=0;i--){
        if(a[i] == now) now++;//a[i]掉进湖里
        else{
            if(a[i] > s[s.size()-1]) break;//剪枝
            s.push_back(a[i]);//a[i]进入栈
        }
        while(!s.empty() && s[s.size()-1] == now){
            s.pop_back();//栈顶的元素出栈
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