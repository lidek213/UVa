#include <stdio.h>
long long int solve(long long int n) {
    if(n == 0) {
        return 0;
    }
    return solve(n >> 1) + (n & 1);
}
int main() {
    int T;
    long long n;
    scanf(" %d", &T);
    while(T-- > 0) {
        scanf(" %lld", &n);
        printf("%lld\n", solve(n));
    }
    return 0;
}