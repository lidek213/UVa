#include <stdio.h>
int main() {
    int a, b, c, d, ans;
    while(scanf(" %d %d %d %d", &a, &b, &c, &d) == 4) {
        if(!a && !b && !c && !d) {
            break;
        }
        ans = 1080;
        ans += ((40 + a - b) % 40) * 9;
        ans += ((40 + c - b) % 40) * 9;
        ans += ((40 + c - d) % 40) * 9;
        printf("%d\n", ans);
    }
    return 0;
}