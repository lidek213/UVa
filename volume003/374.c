#include <stdio.h>
#define LL long long int
LL quickPowMod(LL a, LL n, LL mod) {
    LL result = 1, base = a;
    while(n) {
        if(n & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        n >>= 1;
    }
    return result;
}

int main() {
    LL B, P, M;
    while(scanf(" %lld %lld %lld", &B, &P, &M) == 3) {
        printf("%lld\n", quickPowMod(B % M, P, M));
    }
    return 0;
}