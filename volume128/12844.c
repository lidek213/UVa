#include <stdio.h>

int main() {
    int T, W[10], i, w1, w2, w3, w4, w5, k, avg;
    scanf(" %d", &T);
    for(k = 1; k <= T; k++) {
        avg = 0;
        for(i = 0; i < 10; i++) {
            scanf(" %d", &W[i]);
            avg += W[i];
        }
        avg /= 4;
        w3 = avg - W[0] - W[9];
        w1 = W[1] - w3;
        w2 = W[0] - w1;
        w5 = W[8] - w3;
        w4 = W[9] - w5;
        printf("Case %d: %d %d %d %d %d\n", k, w1, w2, w3, w4, w5);
    }
    return 0;
}