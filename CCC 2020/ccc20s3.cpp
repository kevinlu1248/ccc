// ccc20s3
// created on 2/12/2020 9:20 AM by Kevin Lu
// Strings

/*
aab
abacabaa

abca
abcacbabc

aba
abacabaaaab

abcdefghijklmnopqrstuvwxyz
abcdefghijklmnopqrstuvwxy

abab
aabaabbaaaab

abcde
abcdeabcdedcba

abd
abdabade

abab
abababababbbaaabbbaababba

cacc
aabacbacacacaaccbcccbbaaabacbaacccbcaaaa

bcca
bbabbbccabccbaccbaacbbaaaaaaabacaaccbcbc
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
// <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 20;
char nee[N], hay[N], a, b;
int cnt[30], cnt2[30], ans;
set<vector<char>> vis;

void print() {
    for (int i : cnt) printf("%d ", i);
    printf("\n");
    for (int i : cnt2) printf("%d ", i);
    printf("\n");
}

void size() {
    for (int i = 0; nee[i]; i++) a++;
    for (int i = 0; hay[i]; i++) b++;
    for (char c: nee) cnt[c - 'a']++;
    for (int i = 0; i < a; i++) cnt2[hay[i] - 'a']++;
}

bool check(int pos) {
    for (int i = 0; i < 30; i++)
        if (cnt[i] != cnt2[i]) return false;
//    for (int i = 0; i < a; i++) printf("%c", hay[i + pos]); puts("");
    vector<char> tmp;
    for (int i = pos; i < pos + a; i++) tmp.emplace_back(hay[i]);
    if (vis.find(tmp) != vis.end()) return false;
    vis.insert(tmp);
    return true;
}

int main() {
    scanf("%s%s", &nee, &hay);
//    for (int k = 0; k < 5; k++) {
//        for (int i = 0; i < 4; i++) nee[i] = rand() % 3 + 'a';
//        for (int j = 0; j < 40; j++) hay[j] = rand() % 3 + 'a';
//        printf("%s\n%s\n", nee, hay);
        size();
        for (int i = 0; i + a < b; i++) {
            if (check(i)) {
                ans++;
            }
            cnt2[hay[i] - 'a']--;
            cnt2[hay[i + a] - 'a']++;
        }

        if (check(b - a)) {
            ans++;
        }
        printf("%d", ans);
//    }
    return 0;
}