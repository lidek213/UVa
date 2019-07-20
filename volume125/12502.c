#include <stdio.h>
#include <math.h>
int main() {
    int T, x, y, z;
    double a;
    scanf(" %d", &T);
    while(T-- > 0) {
        scanf(" %d %d %d", &x, &y, &z);
        a = (x + y) / 3.0;
        if(x > a) {
            printf("%d\n", (int)floor(z * (x - a) / (x + y - 2 * a) + 0.00005));
        } else {
            printf("0\n");
        }
    }
    return 0;
}