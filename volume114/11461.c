#include <stdio.h>
#include <math.h>
int main() {
    int a, b, p, q;
    while(scanf(" %d %d", &a, &b) == 2) {
        if(!a && !b) {
            break;
        }
        p = (int) sqrt(a);
        q = (int) sqrt(b);
        printf("%d\n", q - p + 1 - (p * p != a));
    }
    return 0;
}