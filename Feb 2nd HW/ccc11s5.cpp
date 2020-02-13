// ccc11s5
// created on 2/8/2020 9:06 PM by Kevin Lu
// Switch

/*
5
1
1
0
1
1

10
0
1
0
0
1
0
0
0
1
1

3

22
0
1
0
0
1
0
0
0
1
1
1
0
1
0
0
1
0
0
0
1
1


23
0
1
0
0
1
0
0
0
1
1
1
0
1
0
0
1
0
0
0
1
1
1
 */

#include <cstdio>
#include <algorithm>
#include <queue>
#include <string.h>
#include <w32api/mmcobj.h>
// <bits/stdc++.h>
using namespace std;
const int K = 30, N = 40000000;
int k;
bool vis[N];
Node arr;

typedef struct Bstr {
    bool arr[K];
    int steps;
    Bstr (bool a[K], int steps = 0): steps(steps) {
        for (int i = 0; i < k; i++) arr[i] = a[i];
    }
    explicit operator int() {
        int sm;
        for (int i = 0; i < k; i++) if (arr[i]) sm += 1 << i;
        return sm;
    }
    void print() {
//        for (int i = 0; i < k; i++) printf("%d", arr[i]);
        int sm;
        for (int i = 0; i < k; i++) if (arr[i]) sm += 1 << i;
        printf("%d, %d\n", sm, steps);
    }
};

bool check(Bstr s) {

    int cnt = 0;
    for (int j = 0; j < k; j++) {
        bool i = s.arr[j];
        if (i) cnt++;
        else {
            if (cnt < 4) return false;
            cnt = 0;
        }

    }
    return !(s.arr[k - 1] && cnt < 4);
}

int bfs() {
    if (check(Bstr(arr))) return 0;
    queue<Bstr> Q; Q.push(Bstr(arr));
    memset(vis, 0, N);
    bool tmp[K];
    int hash;
//    printf("%d, ", (int) Bstr(arr));
    while (!Q.empty()) {
        Bstr nxt = Q.front(); Q.pop();

//        for (int i = 0; i < N / 16; i++) if (vis[i]) printf("%d, ", i); printf("\n");

        hash = (int) nxt;
        if (vis[hash]) continue;
        vis[hash] = true;
//        printf("Traversing: "); nxt.print();
        for (int i = 0; i < k; i++) tmp[i] = nxt.arr[i];
        for (int i = 0; i < k; i++) {
            if (tmp[i]) continue;
            tmp[i] = true;
            Bstr after = Bstr(tmp, nxt.steps + 1);
            if (check(after)) return after.steps;
            if (!vis[(int) after]) {Q.push(after); vis[(int) after] = true;}
            tmp[i] = false;
        }
    }
    return 0;
}

int main() {
    scanf("%d", &k);
    for (int i = 0; i < k; i++) scanf("%d", &arr[i]);
//    Bstr a = Bstr(arr);
    printf("%d\n", bfs());
    return 0;
}