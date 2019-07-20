#include <stdio.h>
#include <string.h>
int main() {
    int R, N, i, a[10001], t;
    while(scanf(" %d %d", &N, &R) == 2) {
        memset(a, 0, sizeof(int) * 10001);
        for(i = 0; i < R; i++) {
            scanf(" %d", &t);
            a[t] = 1;
        }
        t = 1;
        for(i = 1; i <= N; i++) {
            if(!a[i]) {
                printf("%d ", i);
                t = 0;
            }
        }
        if(t) {
            printf("*\n");
        } else {
            printf("\n");
        }
    }
    return 0;
}
