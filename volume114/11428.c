#include <stdio.h>
int main() {
    int mt[60] = {0}, i, j, t, n, ans[10001][2] = {0};
    for(i = 1; i < 60; i++) {
        mt[i] = i * i * i;
    }
    for(i = 2; i < 60; i++) {
        for(j = 1 ; j < i; j++) {
            t = mt[i] - mt[j];
            if(t < 10001 && ans[t][0] == 0) {
                ans[t][0] = i;
                ans[t][1] = j;
            }
        }
    }
    while(scanf(" %d", &n) != EOF) {
        if(n == 0) {
            break;
        }
        if(ans[n][0] == 0) {
            printf("No solution\n");
        } else {
            printf("%d %d\n", ans[n][0], ans[n][1]);
        }
    }
    return 0;
}