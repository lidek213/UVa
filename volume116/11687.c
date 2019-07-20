#include <stdio.h>
#include <string.h>

int main() {
    char s[1000005];
    int len, i, t;
    while(fgets(s, 1000005, stdin) != NULL) {
        len = strlen(s);
        if(s[len - 1] == '\n') {
            s[len - 1] = '\0';
            len--;
        }
        if(!strcmp(s, "END")) {
            break;
        }
        i = 1;
        t = 0;
        if(strcmp(s, "1")) {
            do {
                t = len;
                sprintf(s, "%d", len);
                len = strlen(s);
                i++;
            } while(t != len);
        }
        printf("%d\n", i);
    }
    return 0;
}