#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

string s;
char c[300];
int happy, sad;
int main(){
    //gets(c); // 读取一整行到char[]中
    getline(cin, s); //iostream读取一整行到string中
    for(int i=0;i < s.length - 3;i++){
        string tmp = s.substr(i, 3);
        if(tmp == ":-)") happy++;
        if(tmp == ":-(") sad++;
    }
    return 0;
}