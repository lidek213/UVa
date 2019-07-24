#include <stdio.h>
int main() {
    int T, cases = 1;
    long long int ans, n;
    scanf(" %d", &T);
    while(T-- > 0) {
        scanf(" %lld", &n);
        printf("Case %d: ", cases++);
        ans = n * (n - 1) / 2;
        if(ans & 1) {
            printf("%lld/2\n", ans);
        } else {
            printf("%lld\n", ans / 2);
        }
    }
    return 0;
}