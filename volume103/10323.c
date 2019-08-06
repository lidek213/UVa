#include <stdio.h>
int main() {
    int n, i;
    long long int ans[14] = {1};
    for(i = 1; i < 14; i++) {
        ans[i] = i * ans[i - 1];
    }
    while(scanf(" %d", &n) != EOF) {
        if(n < 0) {
            if(n & 1) {
                printf("Overflow!\n");
            } else {
                printf("Underflow!\n");
            }
        }
        else if(n < 8) {
            printf("Underflow!\n");
        } else if(n > 13) {
            printf("Overflow!\n");
        } else {
            printf("%lld\n", ans[n]);
        }
    }
    return 0;
}