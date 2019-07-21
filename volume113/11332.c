#include <stdio.h>
int main() {
    int n, t;
    while(scanf(" %d", &n) != EOF) {
        if(n < 3) {
            break;
        }
        while(n > 9) {
            t = 0;
            while(n) {
                t += n % 10;
                n /= 10;
            }
            n = t;
        }
        printf("%d\n", n);
    }
    return 0;
}