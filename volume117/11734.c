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
    s[len++] = '\0';
    return len;
}
int isOutputFormatError(char *s1, int len1, char *s2, int len2) {
    int i = 0, j = 0;
    while(i < len1 && j < len2) {
        while(s1[i] == ' ') {
            i++;
        }
        while(s2[j] == ' ') {
            j++;
        }
        if(s1[i] != s2[j]) {
            return 0;
        }
        i++;
        j++;
    }
    return 1;
}
int main() {
    int t, i, len1, len2;
    char s1[32], s2[32];
    scanf(" %d\n", &t);
    for(i = 1; i <= t; i++) {
        printf("Case %d: ", i);
        len1 = readLine(s1);
        len2 = readLine(s2);
        if(!strcmp(s1, s2)) {
            printf("Yes\n");
        } else if(isOutputFormatError(s1, len1, s2, len2)) {
            printf("Output Format Error\n");
        } else {
            printf("Wrong Answer\n");
        }
    }
    return 0;
}