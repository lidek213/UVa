#include <stdio.h>
int main() {
    int ages[101] = {0}, age, n, i, j, f;
    while(scanf(" %d", &n) != EOF) {
        if(!n) {
            break;
        }
        for(i = 0; i < n; i++) {
            scanf(" %d", &age);
            ages[age]++;
        }
        f = 0;
        for(i = 1; i < 101; i++) {
            for(j = ages[i] - 1; j >= 0 ; j--) {
                if(f) {
                    printf(" %d", i);
                } else {
                    printf("%d", i);
                    f = 1;
                }
            }
            ages[i] = 0;
        }
        printf("\n");
    }
    return 0;
}