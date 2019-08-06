#include <stdio.h>
int prime[168];
void makePrime() {
    char silve[1000] = {0};
    int i, j, count = 1;
    prime[0] = 2;
    for(i = 3; i < 1000; i += 2) {
        if(silve[i] == 0) {
            prime[count++] = i;
        }
        for(j = i * i; j < 1000; j += i) {
            silve[j] = 1;
        }
    }
}
int main() {
    int t, n, i, k, p, q, sum;
    makePrime();
    scanf(" %d", &t);
    while(t-- > 0) {
        scanf(" %d", &n);
        sum = 1;
        k = n;
        for(i = 0; i < 168 && prime[i] <= k; i++) {
            if(k % prime[i] == 0) {
                p = prime[i];
                q = prime[i];
                do {
                    p *= q;
                    k /= q;
                } while(k % q == 0); 
                sum *= (p - 1) / (q - 1);
            }
        }
        sum -= n;
        if(sum == n) {
            printf("perfect\n");
        } else if(sum < n) {
            printf("deficient\n");
        } else {
            printf("abundant\n");
        }
    }
    return 0;
}