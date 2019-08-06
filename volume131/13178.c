#include <stdio.h>
int main() {
    int T, n;
    scanf(" %d", &T);
    while(T-- > 0) {
        scanf(" %d", &n);
        if((n - 1) % 3 == 0) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}