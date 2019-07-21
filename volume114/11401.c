#include <stdio.h>
int main() {
    int i, n;
    long long int ans[1000001] = {0}, p[2] = {1, 2}, q[2] = {3, 4};
    for(i = 4; i < 1000001; i++) {
        n = i & 1;
        ans[i] += ans[i - 1] + p[n];
        p[n] += q[n];
        q[n] += 2;
    }
    while(scanf(" %d", &n) != EOF) {
        if(n < 3) {
            break;
        }
        printf("%lld\n", ans[n]);
    }
    return 0;
}