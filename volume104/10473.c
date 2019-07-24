#include <stdio.h>
#include <string.h>
int main() {
    char s[16];
    int len, value;
    while(fgets(s, 16, stdin) != NULL) {
        len = strlen(s);
        if(len >= 3 && s[0] == '0' && s[1] == 'x') {
            sscanf(s, " %X", &value);
            printf("%d\n", value);
        } else {
            sscanf(s, " %d", &value);
            if(value < 0) {
                break;
            }
            printf("0x%X\n", value);
        }
    }
    return 0;
}