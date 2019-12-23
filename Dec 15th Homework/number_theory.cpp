// Question 2.1

//#include <cstdio>
//#include <algorithm>
#include <iostream>
#include <cmath>

//#include <bits/stdc++.h>
using namespace std;
int n=1, N;

int solve(){
    if (n%3 == 0)
        printf("%d\n", (int) pow(n / 3, 3));
    else if (n%4 == 0)
        printf("%d\n", (int) pow(n / 2, 3) / 4);
    else
        printf("-1\n");
}

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d", &n);
        solve();
    }
    return 0;
} 