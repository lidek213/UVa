#include <stdio.h>
int main() {
    long long a, b, c;
    while(scanf(" %lld %lld", &a, &b) == 2) {
        c = b - a;
        if(c < 0) {
            c *= -1;
        }
        printf("%lld\n", c);
    }
    return 0;
}