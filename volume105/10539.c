#include <stdio.h>
#include <math.h>
int prime[78498] = {2};
double logMap[78498];
void make() {
    char silve[1000000] = {0};
    register int count = 1;
    register long long int i, j;
    logMap[0] = log10(2);
    for(i = 3; i < 1000000; i += 2) {
        if(silve[i] == 0) {
            logMap[count] = log10(i);
            prime[count++] = i;
        }
        for(j = i * i; j < 1000000; j += i) {
            silve[j] = 1;
        }
    }
}
int solve(long long int n) {
    int i, count = 0;
    double lgn = log10(n);
    for(i = 0; i < 78498 && prime[i] * prime[i] <= n; i++) {
        count += (int)floor(lgn / logMap[i] - 1);
    }
    return count;
}
int main() {
    make();
    int N;
    long long int low, high;
    scanf(" %d", &N);
    while(N-- > 0) {
        scanf(" %lld %lld", &low, &high);
        printf("%d\n", solve(high) - solve(low - 1));
    }
    return 0;
}