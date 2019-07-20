#include <stdio.h>

int main() {
    int a, b, up, down;
    while(scanf(" %d %d", &a, &b) == 2) {
        if(a == -1 && b == -1) {
            break;
        }
        if(b < a) {
            a ^= b;
            b ^= a;
            a ^= b;
        }
        up = b - a;
        down = 100 - b + a;
        if(up < down) {
            printf("%d\n", up);
        } else {
            printf("%d\n", down);
        }
    }
    return 0;
}