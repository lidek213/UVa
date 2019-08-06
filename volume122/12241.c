#include <stdio.h>
void sumCount(long long int n, int *out) {
    long long int i, j, p, q, r, s, t;
    for(p  = n / 10, j = 1; j <= n; j *= 10, p /= 10) {
        q = n % (j * 10);
        r = q / j;
        s = (q % j) + 1;
        t = p * j;
        out[0] -= j;
        for(i = 0; i < 10; i++) {
            out[i] += t;
        }
        for(i = 0; i < r; i++) {
            out[i] += j;
        }
        out[r] += s;
    }
}
int main() {
    int A, B, i, out1[10], out2[10];
    while(scanf(" %d %d", &A, &B) == 2) {
        if(A == 0 && B == 0) {
            break;
        }
        for(i = 0; i < 10; i++) {
            out1[i] = 0;
            out2[i] = 0;
        }
        sumCount(A - 1, out1);
        sumCount(B, out2);
        printf("%d", out2[0] - out1[0]);
        for(i = 1; i < 10; i++) {
            printf(" %d", out2[i] - out1[i]);
        }
        printf("\n");
    }
    return 0;
}