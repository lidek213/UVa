#include <stdio.h>

int gcd(int a, int b) {
    if(b) {
        return gcd(b, a % b);
    } else {
        return a;
    }
}

int main() {
    int T, G, L;
    scanf(" %d", &T);
    while(T-- > 0) {
        scanf(" %d %d", &G, &L);
        if(gcd(G, L) == G) {
            printf("%d %d\n", G, L);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}