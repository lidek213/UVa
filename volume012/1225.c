#include <stdio.h>
void sumCount(int n, int *out) {
    int i, j, p, q, r, s, t;
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
    int T, n, i, ans[10];
    scanf(" %d", &T);
    while(T-- > 0) {
        scanf(" %d", &n);
        for(i = 0; i < 10; i++) {
            ans[i] = 0;
        }
        sumCount(n, ans);
        printf("%d", ans[0]);
        for(i = 1; i < 10; i++) {
            printf(" %d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}