#include <stdio.h>
int ans[10005];
void solve() {
    char silve[10000] = {0};
    int prime[1229] = {2};
    int i, j, count = 1, n, f;
    for(i = 3; i < 10000; i += 2) {
        if(silve[i] == 0) {
            prime[count++] = i;
        }
        for(j = i * i; j < 10000; j += i) {
            silve[j] = 1;
        }
    }
    for(i = 0; i < 10001; i++) {
        n = i * i + i + 41;
        f = 1;
        for(j = 0; j < 1229 && prime[j] * prime[j] <= n; j++) {
            if(n % prime[j] == 0) {
                f = 0;
                break;
            }
        }
        ans[i + 1] = ans[i] + f;
    }
}
int main() {
    solve();
    int a, b;
    while(scanf(" %d %d", &a, &b) == 2) {
        printf("%.2f\n", ((ans[b + 1] - ans[a]) * 100.0) / (b - a + 1) + 1e-6);
    }
    return 0;
}