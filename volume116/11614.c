#include <stdio.h>
#include <math.h>
int main() {
    int T;
    long long int n, m;
    scanf(" %d", &T);
    while(T-- > 0) {
        scanf(" %lld", &n);
        m = (long long int)floor((sqrt(8 * n + 1) - 1) / 2 + 1e-8);
        printf("%lld\n", m);
    }
    return 0;
}