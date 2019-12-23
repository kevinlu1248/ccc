#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 8;

int n, a[N];


int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++) a[i] = i;
    do{
        for(int i=0;i<n;i++)
            printf("%d%c", a[i]+1, i<n-1?' ':'\n');
    }while(next_permutation(a, a + n));
    return 0;
}