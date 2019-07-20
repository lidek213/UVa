#include <stdio.h>
#include <math.h>
int main() {
    long long int n;
    while(scanf(" %lld", &n) != EOF) {
        printf("%lld\n", n - 1 + (long long int)(floor(log(n - 1) / log(2))));
    }
    return 0;
}