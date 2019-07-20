#include <stdio.h>
int main() {
    int T, N, i, j, h, t, totalHighJump, totalLowJump;
    scanf(" %d", &T);
    for(i = 1; i <= T; i++) {
        scanf(" %d", &N);
        scanf(" %d", &h);
        totalHighJump = totalLowJump = 0;
        for(j = 1; j < N; j++) {
            scanf(" %d", &t);
            if(h > t) {
                totalLowJump++;
            } else if(h < t) {
                totalHighJump++;
            }
            h = t;
        }
        printf("Case %d: %d %d\n", i, totalHighJump, totalLowJump);
    }
    return 0;
}