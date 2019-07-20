#include <stdio.h>

int main() {
    long long n, m, f, t;
    while(scanf(" %lld", &n) != EOF) {
        if(n == 0) {
            break;
        }
        m = 0;
        f = 1;
        while(n-- > 1) {
            t = m;
            m = f;
            f = t + m;
        }
        printf("%lld\n", m + f);
    }
    return 0;
}