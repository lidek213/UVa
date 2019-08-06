#include <stdio.h>
#include <math.h>
const double pi = acos(-1.0), e = exp(1);
double digitCount(int n) {
    return 0.5 * log10(2 * pi * n) + n * log10(n / e);
}
int main() {
    int n, k;
    while(scanf(" %d %d", &n, &k) == 2) {
        if(n == 1) {
            printf("1\n");
        } else {
            printf("%d\n", (int)ceil(digitCount(n) - digitCount(n - k) - digitCount(k)));
        }
    }
    return 0;
}