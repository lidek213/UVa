#include <stdio.h>
#include <string.h>
#define N 1000000
#define maxSize (N >> 5) + 1
#define GET(x) (make[x >> 5] >> (x & 31) & 1)
#define SET(x) (make[x >> 5] |= 1 << (x & 31))
int make[maxSize];
void solve() {
    register int i, j, k;
    SET(1);
    for(i = 2; i <= N; i++) {
        if(!GET(i)) {
            for(k = N / i, j = i * k; k >= i; k--, j-= i) {
                SET(j);
            }
        }
    }
}
int isPalindromicPrime(int n) {
    if(n == 1) {
        return 1;
    }
    if(GET(n)) {
        return 0;
    }
    char s[20];
    sprintf(s, "%d", n);
    register int i, j, len = strlen(s);
    for(i = 0, j = len - 1; i < j; i++, j--) {
        if(s[i] != s[j]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    solve();
    int n;
    while(scanf(" %d", &n) != EOF) {
        printf("%d\n", n * 2);
        if(isPalindromicPrime(n)) {
            break;
        }
    }
    return 0;
}