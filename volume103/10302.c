#include <stdio.h>
int main() {
    long long int x, t;
    while(scanf(" %lld", &x) != EOF) {
        t = x * (x + 1) / 2;
        printf("%lld\n", t * t);
    }
    return 0;
}