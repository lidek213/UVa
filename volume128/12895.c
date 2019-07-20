#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    int p[10][10] = {0}, i, j, T, N, c, sum;
    for(i = 1; i < 10; i++) {
        p[0][i] = 1;
    }
    for(i = 1; i < 10; i++) {
        for(j = 1; j < 10; j++) {
            p[i][j] = p[i - 1][j] * j;
        }
    }
    scanf(" %d", &T);
    while(T-- > 0) {
        scanf(" %d", &N);
        c = (int)floor(log10(N)) + 1;
        sum = 0;
        j = N;
        for(i = 0; i < c; i++) {
            sum += p[c][j % 10];
            j /= 10;
        }
        if(N == sum) {
            printf("Armstrong\n");
        } else {
            printf("Not Armstrong\n");
        }
    }
    return 0;
}