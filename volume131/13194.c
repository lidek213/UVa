#include <stdio.h>
long long int prime[78498];
void makePrime() {
    char silve[1000000] = {0};
    register long long int i, j, count = 1;
    prime[0] = 2;
    for(i = 3; i < 1000000; i += 2) {
        if(silve[i] == 0) {
            prime[count++] = (int)i;
        }
        for(j = i * i; j < 1000000; j += i) {
            silve[j] = 1;
        }
    }
}
int main() {
    long long int t, n, i, k, p, q, sum;
    makePrime();
    scanf(" %lld", &t);
    while(t-- > 0) {
        scanf(" %lld", &n);
        sum = 1;
        k = n;
        for(i = 0; i < 78498 && prime[i] * prime[i] <= k; i++) {
            if(k % prime[i] == 0) {
                p = prime[i];
                q = p;
                do {
                    p *= q;
                    k /= q;
                } while(k % q == 0); 
                sum *= (p - 1) / (q - 1);
                if(sum > 2 * n) {
                    break;
                }
            }
        }
        if(k > 1) {
            sum *= (k + 1);
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