#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
const int N = 100010;
int n, a[N];

class Stack{
public:
    int index, val[N];
    Stack():index(0){
        //no necessary to init `val`
        // memset(val, 0, sizeof(val));
    }
    int size(){
        return index;
    }
    bool empty(){
        return index <= 0;
    }
    void pop(){
        index--;
    }
    void push(int a){
        val[index++] = a;
    }
    int top(){
        return val[index-1];
    }
    void clear(){//not in STL stack
        index = 0;
    }
};
Stack s;


void solve(){
    // s.size()
    while(!s.empty()) s.pop();//保证栈是空的
    s.clear();//not in STL stack
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






class Queue{
public:
    int val[N];
    int L, R;
    Queue():L(0), R(0){}
    void push_back(int a){
        val[R++] = a;
    }
    void pop_front(){
        L++;
    }
    int front(){
        return val[L];
    }
    int size(){
        return R - L;
    }
    bool empty(){
        return size() <= 0;
    }
}