#include <stdio.h>
int main() {
    int cubr[22], i, j, t;
    long long int ans[10001] = {1};
    for(i = 1; i < 22; i++) {
        t = i * i * i;
        for(j = t; j < 10001; j++) {
            ans[j] += ans[j - t];
        }
    }
    while(scanf(" %d", &t) != EOF) {
        printf("%lld\n", ans[t]);
    }
    return 0;
}