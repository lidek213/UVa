#include <stdio.h>
#include <string.h>
int main() {
    int T, K, total = 0;
    char s[10];
    scanf(" %d", &T);
    while(T-- > 0) {
        scanf(" %s", &s);
        if(strcmp(s, "donate") == 0) {
            scanf(" %d", &K);
            total += K;
        } else {
            printf("%d\n", total);
        }
    }
    return 0;
}