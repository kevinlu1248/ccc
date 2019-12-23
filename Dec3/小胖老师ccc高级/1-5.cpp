#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2;
const int p = 1000000007;
typedef struct Matrix{
    int a[N][N];
    Matrix(){
        for(int i=0;i<N;i++) for(int j=0;j<N;j++)
            a[i][j] = 0;
    }
}Matrix;
Matrix multiply(Matrix x, Matrix y){
    Matrix res;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++){
        res.a[i][j] = 0;
        for(int k=0;k<N;k++){
            res.a[i][j] += (x.a[i][k]%p * y.a[k][j]%p) % p;
            res.a[i][j] %= p;
        }
    }
    return res;
}
long long fast_power(long long a, long long n){
    long long res = 1;
    a %= p;
    while(n){
        if(n&1LL) res = (res*a)%p;//if(n%2 != 0)
        a = (a*a)%p;
        n >>= 1; // n = (n>>1); // n /= 2;
    }
    return res;
}
Matrix power(Matrix x, long long n){
    Matrix res;
    for(int i=0;i<N;i++) res.a[i][i] = 1;
    while(n){
        if(n&1LL) res = multiply(res, x);
        x = multiply(x, x);
        n >>= 1;
    }
    return res;
}

int main(){
    return 0;
}