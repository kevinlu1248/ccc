// ccc15j2.cpp
// Created on 2020-01-12 2:44 p.m. by Kevin Lu
// Happy or Sad

// How are you :-) doing :-( today :-)?
// :)
// This :-(is str :-(:-a(nge te:-)xt.

#include <cstdio>
#include <algorithm>
//#include <string>
#include <bits/stdc++.h>
using namespace std;
char s[300], inp;
int happy, sad;

int main() {
    int i = 0;
    do {
        scanf("%c", &s[i]);
    } while (s[i++] != '\n');
//    printf("%s\n", s);
    for (int i = 0; s[i + 2]; i++) {
        if (s[i] == ':' && s[i + 1] == '-')
            if (s[i + 2] == ')')
                happy++;
            else if (s[i + 2] == '(')
                sad++;
    }
    if (happy > sad)
        printf("happy\n");
    else if (happy < sad)
        printf("sad\n");
    else if (happy == 0 && sad == 0)
        printf("none\n");
    else if (happy == sad)
        printf("unsure\n");
//    printf("%d %d\n", happy, sad);
    return 0;
}