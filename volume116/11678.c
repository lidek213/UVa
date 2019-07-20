#include <stdio.h>
#include <string.h>
int main() {
    int A, B, X[100001], Y[100001], c1, c2, min, i, t;
    while(scanf(" %d %d", &A, &B) == 2) {
        if(!A && !B) {
            break;
        }
        memset(X, 0, sizeof(int) * 100001);
        memset(Y, 0, sizeof(int) * 100001);
        for(i = 0; i < A; i++) {
            scanf(" %d", &t);
            X[t] = 1;
        }
        for(i = 0; i < B; i++) {
            scanf(" %d", &t);
            Y[t] = 1;
        }
        c1 = c2 = 0;
        for(i = 0; i < 100001; i++) {
            c1 += X[i] & !Y[i];
            c2 += !X[i] & Y[i];
        }
        min = c1;
        if(c1 > c2) {
            min = c2;
        }
        printf("%d\n", min);
    }
    return 0;
}