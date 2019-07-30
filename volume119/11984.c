#include <stdio.h>
int main() {
    int T, C, d, cases;
    double ans;
    scanf(" %d", &T);
    for(cases = 1; cases <= T; cases++) {
        scanf(" %d %d", &C, &d);
        ans = (((C * 9.0 / 5.0) + 32 + d) - 32) * 5.0 / 9.0;
        printf("Case %d: %.2lf\n", cases, ans);
    }

    return 0;
}