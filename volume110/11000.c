#include <stdio.h>
int main() {
    long long N, i, m = 0, f = 0, t;
    while(scanf(" %lld", &N) != EOF) {
        if(N == -1) {
            break;
        }
        m = 0;
        f = 1;
        while(N-- > 0) {
            t = f;
            f = f + m + 1;
            m = t;
        }
        printf("%lld %lld\n", m, f);
    }
    return 0;
}
