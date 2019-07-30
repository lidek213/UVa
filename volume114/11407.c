#include <stdio.h>
#define min(a, b) ((a)<(b)?(a):(b))
int main() {
    int dp[10001] = {0}, i, j, N;
    for(i = 1; i < 10001; i++) {
        dp[i] = 10000000;
    }
    for(i = 1; i < 10001; i++) {
        for(j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i - j * j] + 1, dp[i]);
        }
    }
    scanf(" %d", &N);
    while(N-- > 0) {
        scanf(" %d", &i);
        printf("%d\n", dp[i]);
    }
    return 0;
}