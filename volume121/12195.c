#include <stdio.h>
#include <string.h>
int main() {
    char s[204];
    int i, len, ans, t;
    while(scanf(" %s", &s) != EOF) {
        if(!strcmp(s, "*")) {
            break;
        }
        len = strlen(s);
        t = 0;
        ans = 0;
        for(i = 1; i < len; i++) {
            switch(s[i]) {
                case 'W':
                    t += 64;
                    break;
                case 'H':
                    t += 32;
                    break;
                case 'Q':
                    t += 16;
                    break;
                case 'E':
                    t += 8;
                    break;
                case 'S':
                    t += 4;
                    break;
                case 'T':
                    t += 2;
                    break;
                case 'X':
                    t += 1;
                    break;
                case '/':
                    if(t == 64) {
                        ans++;
                    }
                    t = 0;
                    break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}