// ccc19s3
// created on 2/9/2020 9:09 AM by Kevin Lu
// Arithmetic Square

/*
8 9 10
16 X 20
24 X 30

8 9 10
16 18 20
24 27 30

X -17 X
X X X
X 17 X

14 X X
X 20 18
X 16 X

14 X X
X X 18
X 16 22
 */

#include <cstdio>
#include <algorithm>
#include <vector>
// <bits/stdc++.h>
using namespace std;
const int U = (1e9) + 1;
int arr[3][3], xs;
char c, cs[8];
vector<pair<int, int>> xpos;

void print() {
    for (int i = 0; i < 3; i++)
        printf("%d %d %d\n", arr[i][0], arr[i][1], arr[i][2]);
}

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
                arr[i][j] = U;
                xs++; xpos.emplace_back(pair<int, int> (i, j));
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
            arr[i][j] = neg ? -1 * l : l;
        }
}

void sweep() {
    int tmp;
    do {
//        print(); printf("%d\n", xs);
        tmp = xs;
        for (auto & i : arr) { // loop over rows
            if (i[0] != U && i[2] != U && i[1] == U
                && (i[0] % 2) == (i[2] % 2)) // checking for parity
            {i[1] = (i[0] + i[2]) / 2; xs--;}
            if (i[0] != U && i[1] != U && i[2] == U)
            {i[2] = 2 * i[1] - i[0]; xs--;}
            if (i[1] != U && i[2] != U && i[0] == U)
            {i[0] = 2 * i[1] - i[2]; xs--;}
        }
        for (int i = 0; i < 3; i++) { // loop over columns
            if (arr[0][i] != U && arr[2][i] != U && arr[1][i] == U
                && (arr[0][i] % 2) == (arr[2][i] % 2)) // checking for parity
            {arr[1][i] = (arr[0][i] + arr[2][i]) / 2; xs--;}
            if (arr[0][i] != U && arr[1][i] != U && arr[2][i] == U)
            {arr[2][i] = 2 * arr[1][i] - arr[0][i]; xs--;}
            if (arr[1][i] != U && arr[2][i] != U && arr[0][i] == U)
            {arr[0][i] = 2 * arr[1][i] - arr[2][i]; xs--;}
        }
    } while (tmp != xs);
}

void solve() {
    sweep();

//    int tmp[3][3], txs = xs;
//    for (int i = 0; i < 3; i++)
//        for (int j = 0; j < 3; j++)
//            tmp[i][j] = arr[i][j];
//
//    while (txs == xs) {
//        for (int i = 0; i < 3; i++)
//            for (int j = 0; j < 3; j++)
//                arr[i][j] = tmp[i][j];
//
//        // modify the numbers
//        bool flag = false;
//        for (int i = 0; i < 3; i++) {
//            for (int j = 0; j < 3; j++) {
//                if (arr[i][j] == U) {
//                    arr[i][j] = 0;
//                    flag = true;
//                    break;
//                }
//            }
//            if (flag) break;
//        }
//        sweep();
//    }

    int tmp[3][3], txs = xs;
    for (int l = 0; l < xs; l++) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                tmp[i][j] = arr[i][j];
        if (arr[xpos[l].first][xpos[l].second] != U) continue;
        arr[xpos[l].first][xpos[l].second] = 0;
        xs--;
        sweep();
//        print(); printf("%d\n", xs);
        if (!xs) break;
        if (xs < txs) continue;
        xs = txs;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                arr[i][j] = tmp[i][j];
    }
}

int main() {
    input();
    solve();
    print();
    return 0;
}