#include <stdio.h>
#include <string.h>
int readLine(char *s) {
    int len = 0;
    char c;
    while((c = getchar()) != EOF) {
        if(c == '\n') {
            break;
        }
        s[len++] = c;
    }
    s[len] = '\0';
    return len;
}
int main() {
    int cases = 1, i, j, t, t2, len1, len2, lcs[105];
    char s1[105], s2[105];
    while(1) {
        len1 = readLine(s1);
        if(strcmp(s1, "#") == 0) {
            break;
        }
        len2= readLine(s2);
        memset(lcs, 0, sizeof(lcs));
        for(i = 1; i <= len1; i++) {
            t = lcs[0];
            for(j = 1; j <= len2; j++) {
                t2 = lcs[j];
                if(s1[i - 1] == s2[j - 1]) {
                    lcs[j] = t + 1;
                } else if(lcs[j - 1] > lcs[j]) {
                    lcs[j] = lcs[j - 1];
                }
                t = t2;
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n", cases++, lcs[len2]);
    }
    return 0;
}