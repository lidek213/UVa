#include <stdio.h>
long long int quickPowMod(long long int a, long long int b, long long int mod) {
    long long int ans = 1, base = a;
    while(b) {
        if(b & 1) {
            ans = ans * base % mod;
        }
        base = base * base % mod;
        b >>= 1;
    }
    return ans;
}
int main() {
    int T, i;
    long long int N;
    scanf(" %d", &T);
    for(i = 1; i <= T; i++) {
        scanf(" %lld", &N);
        printf("Case #%d: %lld\n", i, ((N % 1000000007) * quickPowMod(2, N - 1, 1000000007)) % 1000000007);
    }
    return 0;
}