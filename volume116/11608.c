#include <stdio.h>
int main() {
    int S, a[12], i, t, cases = 1;
    while(scanf(" %d", &S) != EOF) {
        if(S < 0) {
            break;
        }
        for(i = 0; i < 12; i++) {
            scanf(" %d", &a[i]);
        }
        printf("Case %d:\n",cases);
        for(i = 0; i < 12; i++) {
            scanf(" %d", &t);
            if(S >= t) {
                S -= t;
                printf("No problem! :D\n");
            } else {
                printf("No problem. :(\n");
            }
            S += a[i];
        }
        cases++;
    }
    return 0;
}