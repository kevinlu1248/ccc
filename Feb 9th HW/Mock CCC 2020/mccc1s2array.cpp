// mccc1s2
// created on 2/11/2020 5:30 PM by Kevin Lu
// Flipper Redux

/*
Sample Input 1
Copy

3
1 0 0
1 0 0
0 1 1

Sample Output 1
Copy

2
R 3
C 1

Note that the rows count from top to bottom and columns count from left to right
Sample Input 2
Copy

3
0 0 0
1 0 0
0 0 0

Sample Output 2
Copy

-1

4
1 0 0 1
0 1 1 0
0 1 1 0
0 1 1 0
 */

// shortcut method
#include <cstdio>
#include <algorithm>
#include <vector>
// <bits/stdc++.h>
using namespace std;
const int N = 2010;
int n, cnt;
vector<pair<char, int>> steps;
bool done = false, arr[N][N], rows[N], cols[N];

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d, ", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}

bool check() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j]) return false;
    return true;
}

void col(int j) {
    for (int i = 0; i < n; i++) {
        arr[i][j] = !arr[i][j];
    }
    steps.emplace_back(pair<char, int> ('C', j));
    cols[j] = true;
}

void row(int i) {
    for (int j = 0; j < n; j++) {
        arr[i][j] = !arr[i][j];
    }
    steps.emplace_back(pair<char, int> ('R', i));
    rows[i] = true;
}

void printSteps() {
    printf("%d\n", steps.size());
    for (auto &p: steps) printf("%c %d\n", p.first, p.second + 1);
}

bool solve() {
    for (int i = 0; i < n; i++)
        if (arr[0][i]) col(i);
    for (int j = 0; j < n; j++)
        if (arr[j][0]) row(j);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j]) return false;
    printSteps();
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    if (!solve()) puts("-1");
    return 0;
}