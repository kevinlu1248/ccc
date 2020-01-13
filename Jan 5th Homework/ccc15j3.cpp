// ccc15j3.cpp
// Created on 2020-01-12 2:44 p.m. by Kevin Lu
// Happy or Sad

#include <cstdio>
#include <algorithm>
#include <string>
// <bits/stdc++.h>
using namespace std;
string s;
int happy, sad;

int main() {
    scanf("%s", &s);
    printf("%s\n", s);
    for (int i = 0; s[i + 2]; i++) {
        if (string(s).substr(i, i + 3) == ":-)") happy++;
        else if (s.substr(i, i + 3) == ":-)") sad++;
    }
    printf("%d %d\n", happy, sad);
    return 0;
}