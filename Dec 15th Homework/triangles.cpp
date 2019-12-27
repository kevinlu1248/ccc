// Question 2.2

/**
Sample Input
1
1 2
2 3
3 5
Sample Output
1 2 3

1
2 3
3 5
1 2
*/

#include <cstdio>
//#include <algorithm>
#include <iostream>
using namespace std;
int N, x, y;
const int MAX=10010;

typedef struct Coord{
    int id, x, y;
    bool operator<(const Coord& other) const{
//        printf("%d %d", x, other.x);
        return x < other.x;
    }
}Coord;
Coord coords[MAX];
//Coord test[2] = {Coord(1, 2, 3), Coord(1, 3, 5)};

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N * 3; i++) {
        coords[i].id = i;
        scanf("%d%d", &coords[i].x, &coords[i].y);
    }
    sort(coords, coords + 3 * N );
//    for (Coord& coord : coords)
//        printf("%d %d\n", coord.x, coord.y);
//    for (Coord& coord: coords) {
//        if (coord.x == 0) break;
//        printf("%d %d %d\n", coord.id, coord.x, coord.y);
//    }
    for (int i = 0; i < N; i++) {
//        if (coords.x == 0) break;
        printf("%d %d %d\n", coords[3 * i].id + 1, coords[3 * i + 1].id + 1, coords[3 * i + 2].id + 1);
    }
    return 0;
} 