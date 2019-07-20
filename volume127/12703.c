#include <stdio.h>
#include <string.h>

typedef struct {
    int count[168];
} PrimeCount;

int prime[168];

void makePrime() {
    int make[1000] = {0}, i, j, k;
    for(i = 3; i <= 31; i++) {
        if(!make[i]) {
            for(k = 999 / i, j = i * k; k >= i; k--,j -=i) {
                if(!make[k]) {
                    make[j] = 1;
                }
            }
        }
    }
    prime[0] = 2;
    for(i = 3, j = 1; i < 1000; i += 2){
        if(!make[i]){
            prime[j] = i;
            j++;
        }
    }
}
int main() {
    makePrime();
    PrimeCount primeCount[41];
    int T, n, a, b, i, j, t;
    scanf(" %d", &T);
    while(T-- > 0) {
        scanf(" %d %d %d", &n, &a, &b);
        memset(primeCount, 0, sizeof(PrimeCount) * 41);
        t = a;
        for(i = 0; i < 168 && t > 1; i++) {
            while(t % prime[i] == 0) {
                primeCount[0].count[i]++;
                t /= prime[i];
            }
        }
        t = b;
        for(i = 0; i < 168 && t > 1; i++) {
            while(t % prime[i] == 0) {
                primeCount[1].count[i]++;
                t /= prime[i];
            }
        }
        for(i = 2; i <= n; i++) {
            for(j = 0; j < 168; j++) {
                primeCount[i].count[j] = primeCount[i - 1].count[j] + primeCount[i - 2].count[j];
            }
        }
        for(i = 0; i < 168; i++) {
            if(primeCount[n].count[i]) {
                printf("%d %d\n", prime[i], primeCount[n].count[i]);
            }
        }
        printf("\n");
    }
    return 0;
}