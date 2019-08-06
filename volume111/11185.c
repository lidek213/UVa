#include <stdio.h>
void printBase3(long long int n) {
    char s[20] = {0};
    int i, len = 0;
    if(n == 0) {
        printf("0\n");
        return;
    }
    while(n) {
        s[len++] = (n % 3) + '0';
        n /= 3;
    }
    for(i = len - 1; i >= 0; i--) {
        putchar(s[i]);
    }
    putchar('\n');
}
int main() {
    long long int N;
    while(scanf(" %lld", &N) != EOF) {
        if(N < 0) {
            break;
        }
        printBase3(N);
    }
    return 0;
}