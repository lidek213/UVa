#include <stdio.h>
int prime[3401], primeCount = 0, mapSum[3401];
char sieve[31623] = {0};
int digitsSum(int n) {
    int result = 0;
    while(n) {
        result += n % 10;
        n /= 10;
    }
    return result;
}
int make() {
    register int i, j;
    for(i = 2; i < 31623; i++) {
        if(sieve[i] == 0) {
            mapSum[primeCount] = digitsSum(i);
            prime[primeCount++] = i;
        }
        for(j = 2 * i; j < 31623; j += i) {
            sieve[j] = 1;
        }
    }
}
int main() {
    make();
    int T, n, i, j, k, f, temp1, sum1, sum2;
    scanf(" %d", &T);
    while(T-- > 0) {
        scanf(" %d", &n);
        for(i = n + 1; ; i++) {
            k = i;
            sum1 = 0;
            sum2 = 0;
            f = 0;
            if(i < 31623 && sieve[i] == 0) {
                continue;
            }
            for(j = 0; j < primeCount; j++) {
                while(k % prime[j] == 0) {
                    k /= prime[j];
                    sum2 += mapSum[j];
                }
            }
            if(i == k) {
                continue;
            }
            if(k > 1) {
                sum2 += digitsSum(k);
            }
            sum1 = digitsSum(i);
            if(sum1 == sum2) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}