#include <stdio.h>
#include <string.h>

int isPalinarome(char *s, int len) {
    int i, j;
    for(i = 0, j = len - 1; i < j; i++, j--) {
        if(s[i] != s[j]) {
            return 0;
        }
    }
    return 1;
}

void reverseAdd(char *s, int len) {
    int i, j;
    long long int a, b;
    sscanf(s, " %lld", &a);
    for(i = 0, j = len - 1; i < j; i++, j--) {
        s[i] ^= s[j];
        s[j] ^= s[i];
        s[i] ^= s[j];
    }
    sscanf(s, " %lld", &b);
    sprintf(s, "%lld", a + b);
}

int main() {
    int N, f = 0, len;
    char s[1000];
    scanf(" %d\n", &N);
    while(N-- > 0) {
        fgets(s, 1000, stdin);
        len = strlen(s);
        if(s[len - 1] == '\n') {
            s[len - 1] = '\0';
            len -= 1;
        }
        f = 0;
        while(1) {
            reverseAdd(s, len);
            len = strlen(s);
            f++;
            if(isPalinarome(s, len)) {
                break;
            }
        }
        printf("%d %s\n", f, s);
    }
    return 0;
}