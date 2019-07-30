#include <stdio.h>
#include <string.h>
int num[100000005] = {0};
int main() {
    int N, M, i, f = 0, a, b;
    scanf(" %d", &N);
    while(N-- > 0) {
        if(f) {
            printf("\n");
        }
        scanf(" %d", &M);
        memset(num, 0, sizeof(int) * 100000005);
        for(i = 0; i < M; i++) {
            scanf(" %d %d", &a, &b);
            num[i] = a + b;
        }
        for(i = M - 1; i > 0; i--) {
            num[i - 1] += num[i] / 10;
            num[i] %= 10;
        }
        for(i = 0; i < M; i++) {
            printf("%d", num[i]);
        }
        printf("\n");
        f = 1;
    }
    return 0;
}