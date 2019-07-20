#include <stdio.h>
int countBit(int n) {
    int c = 0;
    while(n) {
        c += n & 1;
        n >>= 1;
    }
    return c;
}
int main() {
    int N, M, H;
    char s[10];
    scanf(" %d\n", &N);
    while(N-- > 0) {
        fgets(s, 10, stdin);
        sscanf(s, " %d", &M);
        sscanf(s, " %X", &H);
        printf("%d %d\n", countBit(M), countBit(H));
    }
    return 0;
}