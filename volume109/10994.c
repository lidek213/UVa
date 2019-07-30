#include <stdio.h>
long long int dfs(long long int n) {
    if(n <= 0) {
        return 0;
    }
    long long int t = n / 10, u = n % 10;
    return t * 45 + ((1 + u) * u / 2) + dfs(t);
}
int main() {
    long long int p, q, t, sum;
    while(scanf(" %lld %lld", &p, &q) == 2) {
        if(p < 0 && q < 0) {
            break;
        }
        printf("%lld\n", dfs(q) - dfs(p - 1));
    }
    return 0;
}