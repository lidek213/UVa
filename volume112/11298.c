#include <stdio.h>
int main() {
    int n;
    while(scanf(" %d", &n) != EOF) {
        printf("%d\n", n >= 3 && !(n % 3));
    }
    return 0;
}