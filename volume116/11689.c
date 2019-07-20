#include <stdio.h>
int main() {
    int N, e, f, c, t, k, ans;
    scanf(" %d", &N);
    while(N-- > 0) {
        scanf(" %d %d %d", &e, &f, &c);
        ans = 0;
        t = e + f;
        while(t >= c) {
            k = t / c;
            t = t % c + k;
            ans += k;
        }
        printf("%d\n", ans);
    }
    return 0;
}