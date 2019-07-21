#include <stdio.h>
int main() {
    int c[201][201] = {0}, i, j, N, K;
    for(i = 0; i < 201; i++) {
        c[i][0] = 1;
    }
    for(i = 1; i < 201; i++) {
        for(j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % 1000000;
        }
    }
    while(scanf(" %d %d", &N, &K) == 2) {
        if(!N && !K) {
            break;
        }
        printf("%d\n", c[N + K - 1][N]);
    }
    return 0;
}