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

typedef struct Line {
    int id, v = 0;
    char type;
    Line (int id, char type): id(id), type(type) {
        for (int i = 0; i < n; i++) {
                if (type == 'C') {
                    v += arr[i][id];
                } else {
                    v += arr[id][i];
                }
        }
    }
    bool operator < (Line const a) const {
        return v < a.v;
    }
    void print() {
        printf("Line(%d, %c, %d)\n", id, type, v);
    }
};

vector<Line> lines;

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d, ", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}

void init() {
    for (int i = 0; i < n; i++) {
        lines.emplace_back(Line(i, 'R'));
        lines.emplace_back(Line(i, 'C'));
    }
}

bool check() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j]) return false;
    return true;
}

void col(int j) {
    int tmp[N];
    for (int i = 0; i < n; i++) {
        if (arr[j][i])
            tmp[i] = -1;
        else tmp[i] = 1;
        arr[i][j] = !arr[i][j];
    }
    for (Line &line: lines)
        if (line.type == 'R')
            line.v += tmp[line.id];
    steps.emplace_back(pair<char, int> ('C', j));
    cols[j] = true;
}

void row(int i) {
    int tmp[N];
    for (int j = 0; j < n; j++) {
        if (arr[i][j])
            tmp[j] = -1;
        else tmp[j] = 1;
        arr[i][j] = !arr[i][j];
    }
    for (Line &line: lines)
        if (line.type == 'C')
            line.v += tmp[line.id];
    steps.emplace_back(pair<char, int> ('R', i));
    rows[i] = true;
}

void printSteps() {
    printf("%d\n", steps.size());
    for (auto &p: steps) printf("%c %d\n", p.first, p.second + 1);
}

void solve() {
    init();
    while (cnt++ <  2 * n) {
//        print();
        if (check()) {printSteps(); return;}
        sort(lines.begin(), lines.end());
        Line l = lines.back(); lines.pop_back();
//        l.print();
        if (l.type == 'R') row(l.id);
        else col(l.id);
    }
    puts("-1");
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    solve();
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < n; j++)
//            printf("%d, ", arr[i][j]);
    return 0;
}