#include <stdio.h>
int main() {
    int n, f, a, b, c, i, ans;
    scanf(" %d", &n);
    while(n-- > 0) {
        scanf(" %d", &f);
        ans = 0;
        for(i = 0; i < f; i++) {
            scanf(" %d %d %d", &a, &b, &c);
            ans += a * c;
        }
        printf("%d\n", ans);
    }
    return 0;
}