#include <stdio.h>
int main() {
    int T, cases, ans;
    long long int N;
    scanf(" %d", &T);
    for(cases = 1; cases <= T; cases++) {
        scanf(" %lld", &N);
        ans = 0;
        while(N) {
            ans++;
            N >>= 1;
        }
        printf("Case %d: %d\n", cases, ans);
    }
    return 0;
}