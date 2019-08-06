#include <stdio.h>
#include <string.h>
int main() {
    int G, i, j, t, len;
    char s[101];
    while(scanf(" %d", &G) != EOF) {
        if(G == 0) {
            break;
        }
        scanf(" %s", &s);
        len = strlen(s);
        for(i = 0, t = len / G; i < len; i += t) {
            for(j = i + t - 1; j >= i; j--) {
                putchar(s[j]);
            }
        }
        putchar('\n');
    }
    return 0;
}