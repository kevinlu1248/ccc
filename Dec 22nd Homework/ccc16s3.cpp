// NOT DONE

// ccc16s3
// Name of Problem

/*
Sample Input 1
Copy

8 2
5 2
0 1
0 2
2 3
4 3
6 1
1 5
7 3

Output for Sample Input 1
Copy

3

Explanation for Output for Sample Input 1

The path between 5 5 and 2 2 goes through 5 → 1 → 0 → 2 5 \rightarrow 1 \rightarrow 0 \rightarrow 2 , which uses 3 roads.
Sample Input 2
Copy

8 5
0 6 4 3 7
0 1
0 2
2 3
4 3
6 1
1 5
7 3

Output for Sample Input 2
Copy

7
 */

#include <cstdio>
//#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int MAX = 100010
int N, M, a[MAX];

//typedef struct Edge {
//    int s, t;
//
//} edges[100100];

vector<int> edges[100010];
void add_edges(int s, int t){
    edges[s].push_back(t);
    edges[t].push_back(s);
}

pair<int, int> find_farest(int start) {
    // return <index, distance>
    int dis[100010], res = 0;
    for (int i = 0; i < N; i++) dis[i] = -1;
    dis[start] = 0;
    queue<int> Q;
    Q.push(start);
    while (!Q.empty()) {
        int node = Q.front(); Q.pop();
        dis[node] = res + 1;
        for (int to: edges[node]) if (dis[to] < 0) { // unvisited

        }
    }
}

int diameter(int start) {
    return find_farest(find_farest(0).first).second;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) scanf("")
    return 0;
}