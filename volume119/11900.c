#include <stdio.h>
int main() {
    int T, i, n, P, Q, total, count, k, cases = 1;
    scanf(" %d", &T);
    while(T-- > 0) {
        scanf(" %d %d %d", &n, &P, &Q);
        total = count = 0;
        for(i = 0; i < n; i++) {
            scanf(" %d", &k);
            if(count < P && total + k <= Q) {
                total += k;
                count++;
            }
        }
        printf("Case %d: %d\n", cases, count);
        cases++;
    }
    return 0;
}