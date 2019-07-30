#include <stdio.h>
#include <string.h>
int main() {
    int i, len, map[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
    char s[32];
    while(fgets(s, 32, stdin) != NULL) {
        len = strlen(s);
        for(i = 0; i < len; i++) {
            if(s[i] == '\n') {
                break;
            } else if(s[i] >= 'A' && s[i] <= 'Z') {
                printf("%d", map[s[i] - 'A']);
            } else {
                printf("%c", s[i]);
            }
        }
        printf("\n");
    }
    return 0;
}