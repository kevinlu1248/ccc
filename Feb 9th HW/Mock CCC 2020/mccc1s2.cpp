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
 */

// shortcut method
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
// <bits/stdc++.h>
using namespace std;
const int N = 2010;
int n;
pair<char, int> steps;
bool done, arr[N][N];

typedef struct Node {
    bool arr[N][N];
    vector<pair<char, int>> steps;
    Node (bool narr[N][N], vector<pair<char, int>> steps = vector<pair<char, int>>()):
        steps(steps) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                arr[i][j] = narr[i][j];
    };
    void print() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                printf("%d, ", arr[i][j]);
    }
    bool check() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (arr[i][j]) return false;
        return true;
    }
    void done() {
        printf("%d\n", steps.size());
        for (auto &p: steps) {
            printf("%c %d\n", p.first, p.second);
        }
    }
    Node col(int j) {
        Node nxt = Node(arr, steps);
        for (auto &step: steps) nxt.steps.emplace_back(step);
        for (int i = 0; i < n; i++) nxt.arr[i][j] = !arr[i][j];
        return nxt;
    }
    Node row(int i) {
        Node nxt = Node(arr, steps);
        for (auto &step: steps) nxt.steps.emplace_back(step);
        for (int j = 0; j < n; j++) nxt.arr[i][j] = !arr[i][j];
        return nxt;
    }
    vector<Node> getNext() {
        vector<Node> v;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (arr[i][j]) {
                    v.emplace_back(col(j));
                    v.emplace_back(row(i));
                    return v;
                }
            }
        return v;
    }
} Node;

void solve() {
    // checking
//    Node n = Node(arr, vector<pair<char, int>>());
    cout << "test" << endl;
    Node node = Node(arr);
//    queue<Node> Q; Q.push(node);
//    while (!Q.empty()) {
//        Node s = Q.front(); Q.pop();
//        if (s.check()) {s.done(); return;}
//        for (auto &nxt: s.getNext()) {
//            nxt.print();
//            Q.push(nxt);
//        }
//    }
//    printf("-1\n");
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    solve();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            printf("%d, ", arr[i][j]);
    return 0;
}