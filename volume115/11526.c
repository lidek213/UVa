#include <stdio.h>
long long int H(long long int n) {
    if(n < 0) {
        return 0;
    }
    long long int i, ti, t, result = n;
    for(i = 2; i <= n; i++) {
        t = n / i;
        ti = n / t;
        result += t * (ti - i + 1);
        i = ti;
    }
    return result;
}
int main() {
    int T;
    long long int n;
    scanf(" %d", &T);
    while(T-- > 0) {
        scanf(" %lld", &n);
        printf("%lld\n", H(n));
    }
    return 0;
}