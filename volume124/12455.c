#include <stdio.h>
#include <string.h>
int main() {
    int t, n, p, i, j, a[20], dp[1001];
    scanf(" %d", &t);
    while(t-- > 0) {
        scanf(" %d %d", &n, &p);
        for(i = 0; i < p; i++) {
            scanf(" %d", &a[i]);
        }
        memset(dp, 0, sizeof(int) * 1001);
        dp[0] = 1;
        for(i = 0; i < p; i++) {
            for(j = 1000; j >= a[i]; j--) {
                if(dp[j - a[i]]) {
                    dp[j] = 1;
                }
            }
        }
        if(dp[n]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}