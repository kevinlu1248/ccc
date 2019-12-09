// ccc template

#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, g, r, o, min, des, sum = 0;
    cin >> p >> g >> r >> o >> des;
    min = p;
    for (int i = 0; i <= p; i++) {
        for (int j = 0; j <= g; j++) {
            for (int l = 0; l <= r; l++) {
                for (int m = 0; m <= o; m++) {
                    int s = i * 1 + j * 2 + l * 3 + m * 4;
                    if (s < des) {
                        printf("# of PINK is %u # of GREEN is %u # of RED is %u # of ORANGE is %u\n", i, j, l, m);
                        min = s < (i + j + l + m) ? s : (i + j + l + m);
                        sum++;
                    }
                }
            }
        }
    }
    printf("Total combinations is %u.\n", sum);
    printf("Minimum number of tickets to print is %u.\n", min);
    return 0;
}
