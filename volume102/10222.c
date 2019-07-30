#include <stdio.h>
#include <string.h>
int main() {
    char map[128], t[] = "qwertyuiop[]asdfghjkl;'zxcvbnm,./";
    char s[10001];
    int i, j, len;
    for(i = 2; i < 33; i++) {
        map[t[i]] = t[i - 2];
    }
    while(fgets(s, 10001, stdin) != NULL) {
        len = strlen(s);
        for(i = 0; i < len; i++) {
            switch(s[i]) {
                case ' ':
                case '\n':
                    putchar(s[i]);
                    break;
                default:
                    putchar(map[s[i]]);
            }
        }
    }
    return 0;
}