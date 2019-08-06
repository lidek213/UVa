#include <stdio.h>
#include <string.h>
int main() {
    char s[32];
    int i, len, t, t2, map[]={0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};
    while(fgets(s, 32, stdin) != NULL) {
        len = strlen(s);
        if(s[len - 1] == '\n') {
            s[len - 1] = '\0';
            len -= 1;
        }
        t = 0;
        for(i = 0; i < len; i++) {
            t2 = map[s[i] - 'A'];
            if(t != t2 && t2 != 0) {
                printf("%d", t2);
            }
            t = t2;
        }
        printf("\n");
    }
    return 0;
}