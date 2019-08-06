#include <stdio.h>
long long int gcd(long long int a, long long int b) {
    if(b) {
        return gcd(b, a % b);
    }
    return a;
}
int main() {
    int S, N, i, cases;
    long long int t1, t2, r, a[10];
    scanf(" %d", &S);
    for(cases = 1; cases <= S; cases++) {
        scanf(" %d", &N);
        t1 = 1;
        for(i = 0; i < N; i++) {
            scanf(" %lld", &a[i]);
            t1 *= a[i];
        }
        t2 = 0;
        for(i = 0 ; i < N; i++) {
            t2 += t1 / a[i];
        }
        t1 *= N;
        r = gcd(t1, t2);
        printf("Case %d: %lld/%lld\n", cases, t1 / r, t2 / r);
    }
    return 0;
}