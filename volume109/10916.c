#include <stdio.h>
#include <math.h>
int ans[21];
void solve() {
    int i, k = 1;
    double t1 = log10(16), t2, t3 = 0;
    t2 = t1;
    for(i = 0; i < 21; i++) {
        while(t3 <= t1) {
            t3 += log10(++k);
        }
        t1 += t2;
        t2 *= 2;
        ans[i] = k - 1;
    }
}
int main() {
    int y;
    solve();
    while(scanf(" %d", &y) != EOF) {
        if(y == 0) {
            break;
        }
        printf("%d\n", ans[(y - 1960) / 10]);
    }
    return 0;
}