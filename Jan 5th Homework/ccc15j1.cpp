// ccc15j1.cpp
// Created on 2020-01-12 2:44 p.m. by Kevin Lu
// Special Day$

#include <cstdio>
#include <algorithm>
// <bits/stdc++.h>
using namespace std;
int m, d;

int main() {
    scanf("%d%d", &m, &d);
    if (m > 2)
        printf("After\n");
    else if (m < 2)
        printf("Before\n");
    else
        if (d > 18)
            printf("After\n");
        else if (d < 18)
            printf("Before\n");
        else
            printf("Special\n");
    return 0;
}