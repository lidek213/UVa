#include <stdio.h>
#include <string.h>

int main() {
    char s[10];
    int cases = 1;
    while(scanf(" %s", &s) != EOF) {
        if(!strcmp(s, "*")) {
            break;
        } else if(!strcmp(s, "Hajj")) {
            printf("Case %d: Hajj-e-Akbar\n", cases);
        } else {
            printf("Case %d: Hajj-e-Asghar\n", cases);
        }
        cases++;
    }
    return 0;
}