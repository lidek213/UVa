#include <stdio.h>
#include <string.h>
char silve[2004];
void make() {
    int i, j;
    silve[0] = 1;
    silve[1] = 1;
    for(i = 2; i < 2004; i++) {
        for(j = i * i; j < 2004; j += i) {
            silve[j] = 1;
        }
    }
}
int main() {
    int T, i, len, cases = 1, empty, count[128];
    char s[2004];
    make();
    scanf(" %d\n", &T);
    while(T-- > 0) {
        fgets(s, 2004, stdin);
        memset(count, 0, sizeof(count));
        len = strlen(s);
        for(i = 0; i < len; i++) {
            count[s[i]]++;
        }
        printf("Case %d: ", cases++);
        empty = 1;
        for(i = 0; i < 128; i++) {
            if(silve[count[i]] == 0) {
                empty = 0;
                putchar(i);
            }
        }
        if(empty) {
            printf("empty");
        }
        printf("\n");
    }
    return 0;
}