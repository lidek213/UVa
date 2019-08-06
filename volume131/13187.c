#include <stdio.h>
int main() {
    long long int t, S;
    scanf(" %lld", &t);
    while(t-- > 0) {
        scanf(" %lld", &S);
        printf("%lld\n", (S + 1) * (S + 1) - 1);
    }
    return 0;
}