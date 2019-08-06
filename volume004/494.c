#include <stdio.h>
#include <string.h>
int main() {
    char s[10000];
    int len, count, i, t;
    while(fgets(s, 10000, stdin) != NULL) {
        len = strlen(s);
        count = t = 0;
        for(i = 0; i <= len; i++) {
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                t=1;
            } else if(t) {
                count++;
                t = 0;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}