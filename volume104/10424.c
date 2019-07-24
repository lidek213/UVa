#include <stdio.h>
#include <string.h>
int solve(char *s) {
    int  t, i, len, sum, v;
    len = strlen(s);
    if(s[len - 1] == '\n') {
        s[len - 1] = '\0';
        len -= 1;
    }
    for(i = 0, t = 0; i < len; i++) {
        v = s[i] | 32;
        if(v >= 'a' && v <= 'z') {
            t += (s[i] | 32) - 'a' + 1;
        }
    }
    do {
        sum = 0;
        while(t) {
            sum += t % 10;
            t /= 10;
        }
        t = sum;
    } while(t > 9);
    return t;
}
int main() {
    int a, b, t;
    char s[32];
    while(fgets(s, 32, stdin) != NULL) {
        a = solve(s);
        fgets(s, 32, stdin);
        b = solve(s);
        if(a > b) {
            t = a;
            a = b;
            b = t;
        }
        printf("%.2lf %%\n", a * 100.0 / b);
    }
    return 0;
}