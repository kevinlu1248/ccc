// ccc19s3corrected
// created on 2/9/2020 10:21 AM by Kevin Lu
// Arithmetic Square

/*
8 9 10
16 X 20
24 X 30

8 9 10
16 18 20
24 27 30

X X X
X X X
X 17 15

14 X X
X 20 18
X 16 X

14 X X
X X X
X 16 X
 */


#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
// <bits/stdc++.h>
using namespace std;
const int U = (1e9) + 1;
int farr[3][3], xs;
char c, cs[8];
//vector<pair<int, int>> xpos;

typedef struct Node {
    int arr[3][3];
    vector<pair<int, int>> xpos;
    Node (int a[3][3]) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                arr[i][j] = a[i][j];
                if (a[i][j] == U)
                    xpos.emplace_back(pair<int, int> (i, j));
            }
    }
    void print(bool x = false) {
        for (int i = 0; i < 3; i++)
            printf("%d %d %d\n", arr[i][0], arr[i][1], arr[i][2]);
        if (x) {
            for (auto p: xpos)
                printf("(%d, %d),", p.first, p.second);
            printf("\n");
        }
    }
    bool sweep() {
        int tmp, xs = xpos.size();
        do {
//        print(); printf("%d\n", xs);
            tmp = xs;
            for (auto & i : arr) { // loop over rows
                if (i[0] != U && i[2] != U && i[1] == U
                    && (i[0] & 1) == (i[2] & 1)) // checking for parity
                {i[1] = (i[0] + i[2]) / 2; xs--;}
                if (i[0] != U && i[1] != U && i[2] == U)
                {i[2] = 2 * i[1] - i[0]; xs--;}
                if (i[1] != U && i[2] != U && i[0] == U)
                {i[0] = 2 * i[1] - i[2]; xs--;}
            }
            for (int i = 0; i < 3; i++) { // loop over columns
                if (arr[0][i] != U && arr[2][i] != U && arr[1][i] == U
                    && (arr[0][i] & 1) == (arr[2][i] & 1)) // checking for parity
                {arr[1][i] = (arr[0][i] + arr[2][i]) / 2; xs--;}
                if (arr[0][i] != U && arr[1][i] != U && arr[2][i] == U)
                {arr[2][i] = 2 * arr[1][i] - arr[0][i]; xs--;}
                if (arr[1][i] != U && arr[2][i] != U && arr[0][i] == U)
                {arr[0][i] = 2 * arr[1][i] - arr[2][i]; xs--;}
            }
        } while (tmp != xs);

        xpos.clear();
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (arr[i][j] == U)
                    xpos.emplace_back(pair<int, int> (i, j));

        return xpos.size() <= 0;
    }
    bool operator< (Node const n) const {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                if (arr[i][j] < n.arr[i][j]) return true;
                if (arr[i][j] > n.arr[i][j]) return false;
            }
        return false;
    }
} Node;

int pow10(int i) {
    int ans = 1;
    while (i--) ans *= 10;
    return ans;
}

void input() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            scanf("%c", &c);
            if (c == 'X') {
                scanf("%c", &c);
                farr[i][j] = U;
                xs++;
                continue;
            }
            bool neg = false;
            if (c == '-') {
                neg = true;
                scanf("%c", &c);
            }
            int k = 0;
            while (c != ' ' && c != '\n') {
                cs[k++] = c;
                scanf("%c", &c);
            }
//            for (int m = 0; m < k; m++) printf("%c, ", cs[m]); printf("\n");
            int l = 0, tmp = k;
            while (tmp--) {
                l += (cs[tmp] - '0') * pow10(k - tmp - 1);
            }
            farr[i][j] = neg ? -1 * l : l;
        }
}

Node solve() {
    Node n = Node(farr);
    if (n.sweep()) return n;

    queue<Node> Q; Q.push(n);
    set<Node> vis;
    while (!Q.empty()) {
        n = Q.front(); Q.pop();
//        n.print(true);
//        printf("%d\n", Q.size());
//        if (vis.find(n) != vis.end()) {printf("in set already\n"); continue;}
        vis.insert(n);
        if (!n.xpos.size()) return n;
//        printf("iterating through xpos\n");
        for (auto p: n.xpos) {
//            printf("iterating (%d, %d)\n", p.first, p.second);
            int tarr[3][3];
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    tarr[i][j] = n.arr[i][j];

            tarr[p.first][p.second] = 0;
            Node nn = Node(tarr);
            if (nn.sweep()) return nn;
//            nn.print(true);
//            nn.print(); printf("%d\n", nn.xpos.size());
//            if (vis.find(nn) != vis.end()) {printf("in set already\n"); continue;}
//            vis.insert(nn);
            Q.push(nn);
        }
    }
    return Node(farr);
}

int main() {
    input();
    solve().print();
    return 0;
}