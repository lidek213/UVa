#include <stdio.h>
int main() {
    int n;
    long long int s, d, a, b;
    scanf(" %d", &n);
    while(n-- > 0) {
        scanf(" %lld %lld", &s, &d);
        a = (s + d) / 2;
        b = (s - d) / 2;
        if(a >= 0 && b >= 0 && a + b == s && a - b == d) {
            printf("%lld %lld\n", a, b);
        } else {
            printf("impossible\n");
        }
    }
    return 0;
}