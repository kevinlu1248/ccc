// Question 2.2

/**
Sample Input
1
1 2
2 3
3 5
Sample Output
123
*/

#include <cstdio>
//#include <algorithm>
#include <iostream>
using namespace std;
int N, x, y;
const int MAX=10010;

typedef struct Coord{
    int id;
    long int x, y;
}Coord;
Coord coords[MAX];
//Coord test[2] = {Coord(1, 2, 3), Coord(1, 3, 5)};

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%l%l", &coords[i].x, &coords[i].y);
    }
//    for (Coord& coord : coords)
//        printf("%d %d\n", coord.x, coord.y);
    printf("%l %l\n", coords[0].x, coords[0].y);
    cout << coords[0].x << '\n';
    return 0;
} 