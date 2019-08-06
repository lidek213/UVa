#include <stdio.h>
int ans[101][25] = {0};
void make() {
    char silve[100] = {0};
    register int i, j, c = 1, t;
    int prime[25] = {2};
    for(i = 3; i < 100; i += 2) {
        if(silve[i] == 0) {
            prime[c++] = i;
        }
        for(j = i * i; j < 100; j += i) {
            silve[j] = 1;
        }
    }
    for(i = 2; i < 101; i++) {
        t = i;
        for(j = 0; j < 25; j++) {
            ans[i][j] = ans[i - 1][j];
            while(t && t % prime[j] == 0) {
                ans[i][j]++;
                t /= prime[j];
            }
        }
    }
}
int main() {
    int N, i;
    make();
    while(scanf(" %d", &N) != EOF) {
        if(N == 0) {
            break;
        }
        printf("%3d! =", N);
        for(i = 0; i < 25 && ans[N][i]; i++) {
            if(i && i % 15 == 0) {
                printf("\n      ");
            }
            printf("%3d", ans[N][i]);
        }
        printf("\n");
    }
    return 0;
}