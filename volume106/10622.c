#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prime[6542] = {2, 3};

int make() {
    int make[65536] = {0}, i, j, count = 2, gap = 2;
    for(i = 5; i < 65536; i += gap, gap = 6 - gap) {
        if(!make[i]) {
            prime[count] = i;
            count++;
        }
        for(j = i * 2; j < 65536; j += i) {
            make[j] = 1;
        }
    }
}

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    long long int x, t;
    int count[6542], i, j, ans, max;
    make();
    while(scanf(" %lld", &x) != EOF) {
        if(x == 0) {
            break;
        }
        memset(count, 0, sizeof(int) * 6542);
        t = labs(x);
        ans = 0;
        if(x == 1) {
            ans = 1;
        }
        for(i = 0; i < 6542; i++) {
            if(t % prime[i] == 0) {
                do {
                    t /= prime[i];
                    count[i]++;
                } while(t % prime[i] == 0);
                ans = gcd(count[i], ans);
            }
        }
        if(t > 1) {
            ans = 1;
        }
        if(x < 0) {
            while(ans % 2 == 0) {
                ans /= 2;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}