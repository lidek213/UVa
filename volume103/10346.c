#include <stdio.h>
int main() {
    int n, k, ans, t, u;
    while(scanf(" %d %d", &n, &k) == 2) {
        u = n / k;
        ans = n + u;
        t = n % k;
        u = u + t;
        while(u >= k) {
            t = u % k;
            u = u / k;
            ans += u;
            u = u + t;
        }
        printf("%d\n", ans);
    }
    return 0;
}