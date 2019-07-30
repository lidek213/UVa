#include <stdio.h>
#include <string.h>
int quickPowMod(int a, int n, int mod) {
    int result = 1, base = a;
    while(n) {
        if(n & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        n >>= 1;
    }
    return result;
}
int main() {
    int T, len, n, i, j;
    char num[1001];
    scanf(" %d", &T);
    while(T-- > 0) {
        scanf(" %s", &num);
        len = strlen(num);
        if(len >= 3) {
            j = 3;
        } else if(len >= 2) {
            j = 2;
        } else {
            j = 1;
        }
        for(i = j, n = 0; i > 0; i--) {
            n = n * 10 + (num[len - i] - '0');
        }
        if(len == 1 && n < 2) {
            if(n == 0) {
                printf("1\n");
            } else {
                printf("66\n");
            }
        } else {
            n += 20;
            printf("%d\n", quickPowMod(66, n, 100));
        }
    }
    return 0;
}