#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int T, r, s[30001], i, mid, ans, k, v;
    scanf(" %d", &T);
    while(T-- > 0) {
        memset(s, 0, sizeof(int) * 30001);
        scanf(" %d", &r);
        for(i = 0; i < r; i++) {
            scanf(" %d", &v);
            s[v]++;
        }
        v = 0;
        k = r / 2;
        for(i = 1; i < 30001; i++) {
            v += s[i];
            if(v > k) {
                break;
            }
        }
        mid = i;
        ans = 0;
        for(i = 1; i < 30001; i++) {
            if(s[i]) {
                ans += abs(i - mid) * s[i];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}