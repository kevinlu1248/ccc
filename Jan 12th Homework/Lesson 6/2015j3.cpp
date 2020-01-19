#include <cstdio>
#include <algorithm>
using namespace std;

char a[27] = "abcdefghijklmnopqrstuvwxyz";
char b[27] = "aaaeeeeiiiiioooooouuuuuuuu";
char c[27] = "-cdf-ghj-klmnp-qrstv-wxyzz";
char s[33];

int main(){
    char ans[111];
    scanf("%s", s);
    int j=0;
    for(int i=0;s[i];i++){
        if(c[s[i]-'a'] == '-') //元音
            ans[j++] = s[i];//元音不变
        else{//辅音
            ans[j++] = s[i];//先把辅音诺下来
            ans[j++] = b[s[i]-'a'];//加上最近的元音
            ans[j++] = c[s[i]-'a'];//加上紧跟着的辅音
        }
    }
    ans[j] = '\0';//终止符
    printf("%s\n", ans);
    return 0;
}