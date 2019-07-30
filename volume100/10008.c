#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int count;
    char symbol;
} D;
int cmp(const void *a, const void *b) {
    return *(int*)b-*(int*)a;
}
int main() {
    D d[26];
    int i, n, len;
    char s[10000];
    for(i = 0; i < 26; i++) {
        d[i].count = 0;
        d[i].symbol = 'A' + i;
    }
    scanf(" %d\n", &n);
    while(n-- > 0){
        fgets(s, 10000, stdin);
        len = strlen(s);
        for(i = 0; i < len; i++) {
            if(s[i] >= 'A' && s[i] <= 'Z') {
                d[s[i] - 'A'].count++;
            } else if(s[i] >= 'a' && s[i] <= 'z') {
                d[s[i] - 'a'].count++;
            }
        }
    }
    qsort(d, 26, sizeof(D), cmp);
    for(i = 0; i < 26 && d[i].count > 0; i++) {
        printf("%c %d\n", d[i].symbol, d[i].count);
    }
    return 0;
}