#include <stdio.h>
int main() {
    int T;
    long long int N;
    scanf(" %d", &T);
    while(T-- > 0) {
        scanf(" %lld", &N);
        printf("%lld\n", N / 2);
    }
    return 0;
}