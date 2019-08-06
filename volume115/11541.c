#include <stdio.h>
#include <string.h>
int main() {
    int T, cases = 1, len, count, i, j;
    char s[1000], c;
    scanf(" %d\n", &T);
    while(T-- > 0) {
        fgets(s, 1000, stdin);
        len = strlen(s);
        count = 0;
        c = 0;
        printf("Case %d: ", cases++);
        for(i = 0; i < len; i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                count = count * 10 + s[i] - '0';
            } else if(s[i] >= 'A' && s[i] <= 'Z') {
                for(j = 0; j < count; j++) {
                    putchar(c);
                }
                c = s[i];
                count = 0;
            }
        }
        for(j = 0; j < count; j++) {
            putchar(c);
        }
        printf("\n");
    }
    return 0;
}