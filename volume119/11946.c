#include <stdio.h>
#include <string.h>
int main() {
    int T, i, len;
    char s[100], mapStr[] = "OIZEASGTBP";
    scanf(" %d ", &T);
    while(T-- > 0) {
        while(fgets(s, 100, stdin) != NULL) {
            if(strcmp(s, "\n") == 0) {
                break;
            }
            len = strlen(s);
            if(s[len - 1] == '\n') {
                len -= 1;
            }
            for(i = 0; i < len; i++) {
                if(s[i] >= '0' && s[i] <= '9') {
                    putchar(mapStr[s[i] - '0']);
                } else {
                    putchar(s[i]);
                }
            }
            printf("\n");
        }
        if(T) {
            printf("\n");
        }
    }
    return 0;
}