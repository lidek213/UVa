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
    char s1[1001], s2[1001];
    int i, j, len1, len2, lcs[1005], t, t2;
    while((len1 = readLine(s1)) != 0) {
        len2 = readLine(s2);
        memset(lcs, 0, sizeof(lcs));
        for(i = 1; i <= len1; i++) {
            t = lcs[0];
            for(j = 1; j <= len2; j++) {
                t2 = lcs[j];
                if(s1[i - 1] == s2[j - 1]) {
                    lcs[j] = t + 1;
                } else if(lcs[j] < lcs[j - 1]) {
                    lcs[j] = lcs[j - 1];
                }
                t = t2;
            }
        }
        printf("%d\n", lcs[len2]);
    }
    return 0;
}