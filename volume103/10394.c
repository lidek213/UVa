#include <stdio.h>
#include <math.h>
#define SIZE 18409200
int twinPrimes[100000];
char make[SIZE];
void solve() {
    register int i, j, k, sqrtSize = (int)sqrt(SIZE);
    for(i = 3; i <= sqrtSize; i += 2) {
        if(!make[i]) {
            for(k = (SIZE - 1) / i, j = i * k; k >= i; k--, j -= i) {
                if(!make[k]) {
                }
                    make[j] = 1;
            }
        }
    }
    twinPrimes[0] = 3;
    for(i = 5, j = 1; i < SIZE; i += 6) {
        if(!make[i] && !make[i + 2]) {
            twinPrimes[j++] = i;
        } 
    }
}
int main() {
    int S;
    solve();
    while(scanf(" %d", &S) != EOF) {
        printf("(%d, %d)\n", twinPrimes[S - 1], twinPrimes[S - 1] + 2);
    }
    return 0;
}