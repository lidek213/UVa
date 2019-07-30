#include <stdio.h>
int main() {
    char s[16], c;
    int i;
    while(fgets(s, 16, stdin) != NULL) {
        if(s[0] == '_') {
            continue;
        }
        c = 0;
        for(i = 0; i < 11; i++) {
            switch(s[i]) {
                case ' ':
                    c <<= 1;
                    break;
                case 'o':
                    c = (c << 1) | 1;
                    break;
            }
        }
        putchar(c);
    }
    return 0;
}