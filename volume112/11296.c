#include <stdio.h>
int main() {
    int n;
    long long k;
    while(scanf(" %d", &n) != EOF) {
        k = n / 2 + 1;
        printf("%lld\n", (1 + k) * k / 2);
    }
    return 0;
}