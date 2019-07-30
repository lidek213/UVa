#include <stdio.h>
#include <math.h>
int sieve[65000];
void make() {
    register int i, j;
    for(i = 3; i < 255; i += 2) {
        for(j = i * i; j < 65000; j += i) {
            sieve[j] = 1;
        }
    }
}

long long int quickPowMod(long long int a, int b, long long int mod) {
    long long int result = 1, base = a;
    while(b) {
        if(b & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        b >>= 1;
    }
    return result;
}

int main() {
    int n, i, j, f, ans[65000] = {0};
    make();
    ans[1] = 1;
    for(i = 3; i < 65000; i++) {
        if(sieve[i]) {
            f = 1;
            for(j = 2; j < i; j++) {
                if(quickPowMod(j, i, i) != j) {
                    f = 0;
                    break;
                }
            }
            ans[i] = f;
        }
    }
    while(scanf(" %d", &n) != EOF) {
        if(n == 0) {
            break;
        }
        if(ans[n] == 0) {
            printf("%d is normal.\n", n);
        } else {
            printf("The number %d is a Carmichael number.\n", n);
        }
    }
    return 0;
}