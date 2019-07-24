#include <stdio.h>
int prime[168] = {2}, M[1000001] = {0, 1};
void makePrime() {
    int make[1000] = {0}, i, j, count = 1;
    for(i = 3; i < 1000; i += 2) {
        if(!make[i]) {
            prime[count++] = i;
        }
        for(j = i * i; j < 1000; j += i) {
            make[j] = 1;
        }
    }
}

void solve() {
    int i, j, t, count = 0, totalCount, mu = 1;
    for(i = 2; i < 1000001; i++) {
        t = i;
        mu = -1;
        totalCount = 0;
        for(j = 0; j < 168 && prime[j] * prime[j] <= t; j++) {
            if(t % prime[j] == 0) {
                count = 0;
                do {
                    count++;
                    t /= prime[j];
                } while(t % prime[j] == 0);
                totalCount += count;
                if(count >= 2) {
                    mu = 0;
                    break;
                }
            }
        }
        if(mu != 0) {
            if(t > 1) {
                totalCount += 1;
            }
            if(totalCount & 1) {
                mu = -1;
            } else {
                mu = 1;
            }
        }
        M[i] = M[i - 1] + mu;
    }
}

int main() {
    int n;
    makePrime();
    solve();
    while(scanf(" %d", &n) != EOF) {
        if(n == 0) {
            break;
        }
        printf("%8d%8d%8d\n",n, M[n] - M[n - 1], M[n]);
    }
    return 0;
}