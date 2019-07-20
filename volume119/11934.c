#include <stdio.h>
int main() {
    int square[1001], i, a, b, c, d, L, ans;
    for(i = 0; i < 1001; i++) {
        square[i] = i * i;
    }
    while(scanf(" %d %d %d %d %d", &a, &b, &c, &d, &L) == 5) {
        if(!a && !b && !c && !d && !L) {
            break;
        }
        ans = 0;
        for(i = 0; i <= L; i++) {
            ans += !(((square[i] * a) + i * b + c) % d);
        }
        printf("%d\n", ans);
    }
    return 0;
}