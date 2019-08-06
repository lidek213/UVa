#include <stdio.h>
int main() {
    int T, n, m, i, j, k;
    scanf(" %d", &T);
    while(T-- > 0) {
        scanf(" %d %d", &n, &m);
        for(i = m - 1; i >= 0; i--) {
            for(j = 1; j < n; j++) {
                for(k = 0; k < j; k++) {
                    printf("%d", j);
                }
                printf("\n");
            }
            for(j = n; j >= 0; j--) {
                for(k = 0; k < j; k++) {
                    printf("%d", j);
                }
                if(T || i || j) {
                    printf("\n");
                }
            }
        }
    }
    return 0;
}