#include <stdio.h>
#include <string.h>
int main() {
    char s[1000], c;
    int i, j, len, t;
    while(fgets(s, 1000, stdin) != NULL) {
        if(strcmp(s, "\n") == 0) {
            printf("\n");
            continue;
        }
        len = strlen(s);
        t = 0;
        for(i = 0; i < len; i++) {
            if(s[i] == '!' || s[i]=='\n') {
                printf("\n");
                continue;
            } else if(s[i] >= '0' && s[i] <= '9') {
                t += s[i] - '0';
            } else {
                c = s[i];
                if(s[i] == 'b') {
                    c = ' ';
                }
                for(j = 0; j < t; j++) {
                    putchar(c);
                }
                t = 0;
            }
        }
    }
    return 0;
}