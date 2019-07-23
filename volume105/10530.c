#include <stdio.h>
#include <string.h>
int main() {
    int a = 0, b = 11, n;
    char s[10];
    while(scanf(" %d", &n) != EOF) {
        if(n == 0) {
            break;
        }
        getchar();
        fgets(s, 10, stdin);
        if(strcmp(s, "right on\n") == 0) {
            if(a < n && n < b) {
                printf("Stan may be honest\n");
            } else {
                printf("Stan is dishonest\n");
            }
            a = 0;
            b = 11;
        } else if(strcmp(s, "too high\n") == 0) {
            if(n < b) {
                b = n;
            }
        } else {
            if(n > a) {
                a = n;
            }
        }
    }
    return 0;
}