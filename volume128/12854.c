#include <stdio.h>

int main() {
    int x[5], y[5], f, i;
    while(scanf(" %d %d %d %d %d", &x[0], &x[1], &x[2], &x[3], &x[4]) == 5) {
        scanf(" %d %d %d %d %d", &y[0], &y[1], &y[2], &y[3], &y[4]);
        for(i = 0, f = 0; i < 5; i++) {
            f += x[i] ^ y[i];
        }
        printf("%c\n", f == 5 ? 'Y':'N');
    }
    return 0;
}