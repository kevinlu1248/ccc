// ccc16s1
// Name of Problem

/*
Sample Input 1
Copy

abba
baaa

Output for Sample Input 1
Copy

N

Sample Input 2
Copy

cccrocks
socc*rk*

Output for Sample Input 2
Copy

A
 */

#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
int AST=42, mmapa[200], mmapb[200], ast_a, ast_b, ma, mb;
//char a[101], b[101];
string a, b;
using namespace std;

int abs_dif(int x, int y) {
    if (x > y) return x - y;
    else return y - x;
}

int main() {
//    cin >> a >> b;
    scanf("%s%s", &a, &b);
    for (char &c: a) mmapa[c]++;
    for (char &c: b) mmapb[c]++;
    ast_a = mmapa[AST], ast_b = mmapb[AST];
//    printf("%s%s", &a, &b);
//    printf("%d\n", '*');
    for (int i = 0; i < 200; i++) {
        if (i == 42) continue; // i == '*'
        ma = mmapa[i], mb = mmapb[i];
        if (ma > mb) {
            if (ma - mb > ast_b) {
                cout << 'N';
                return 0;
            }
            ast_b -= ma - mb;
        } else if (mb > ma) {
            if (mb - ma > ast_a) {
                cout << 'N';
                return 0;
            }
            ast_a -= mb - ma;
        }
    }
    cout << 'A';
    return 0;
}