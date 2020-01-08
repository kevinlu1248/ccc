#include <cstdio>
#include <cstring>
using namespace std;
const int N = 26;
int cnt[N], n, ans;
char s[111];
/*
"Hello"
'H' 'e' 'l' 'l' 'o' '\0'
*/
int main(){
    scanf("%s", s);
    //n = strlen(s); // this is in <cstring>
    for(;s[n];n++) //for(;s[n] != 0;n++) //for(;s[n] != '\0';n++)
        ;
    for(int i=0;i<n;i++) // 计数
        cnt[s[i]-'a']++;
    
    scanf("%s", s);
    for(int i=0;i<n;i++){
        if(s[i] == '*')
            ans++; // number of *
        else
            cnt[s[i]-'a']--;
    }
    for(int i=0;i<N;i++){
        if(cnt[i] < 0){ // 第二个字符串中i字符数量多了
            ans = -1;
            break;
        }else // 第二个字符串中i字符数量少了，用*补
            ans -= cnt[i];
    }
    if(ans == 0) printf("A\n");
    else printf("N\n");
}