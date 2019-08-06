#include <stdio.h>
#include <string.h>
#include <math.h>
int prime[139];
double dis[1 << 20];
void makePrime() {
    char silve[800] = {0};
    int i, j, count = 1;
    prime[0] = 2;
    for(i = 3; i < 800; i += 2) {
        if(silve[i] == 0) {
            prime[count++] = i;
        }
        for(j = i * i; j < 800; j += i) {
            silve[j] = 1;
        }
    }
}
int main() {
    int N, B, i, j, t, c[10], fc[10][2], fs, min;
    makePrime();
    for(i = 2; i < (1 << 20); i++) {
        dis[i] = dis[i - 1] + log(i);
    }
    while(scanf(" %d %d", &N, &B) == 2) {
        memset(c, 0, sizeof(c));
        memset(fc, 0, sizeof(fc));
        t = B;
        for(i = 0, fs = 0; i < 139 && prime[i] <= t; i++) {
            if(t % prime[i] == 0) {
                fc[fs][0] = prime[i];
                do {
                    fc[fs][1]++;
                    t /= prime[i];
                } while(t % prime[i] == 0);
                fs++;
            }
        }
        for(i = 0, min = 2147483647; i < fs; i++) {
            for(j = fc[i][0]; j <= N; j *= fc[i][0]) {
                c[i] += N / j;
            }
            t = c[i] / fc[i][1];
            if(t < min) {
                min = t;
            }
        }
        printf("%d %d\n", min, (int)ceil(dis[N] / log(B) + 1e-10));
    }
    return 0;
}