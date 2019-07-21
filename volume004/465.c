#include <stdio.h>
#include <string.h>
typedef enum {none=0, rb=1, fb=2, sb=4} Message;
Message solve(char *s) {
    Message msg = none;
    int i, len = strlen(s), count1 = 0, count2 = 0, f1 = 1, f2 = 0;
    long long int v1 = 0, v2 = 0, v3;
    for(i = 0; i < len; i++) {
        if(s[i] >= '0' && s[i] <='9') {
            if(f1) {
                v1 = v1 * 10 + s[i] - '0';
                if(v1 > 0) {
                    count1++;
                }
            } else {
                v2 = v2 * 10 + s[i] - '0';
                if(v2 > 0) {
                    count2++;
                }
            }
        } else if(s[i] == '*') {
            f2 = 1;
        } else if(s[i] == '+') {
            f2 = 0;
        } else {
            f1 = 0;
        }
    }
    f1 = 1;
    if(count1 > 10 || v1 > 2147483647) {
        f1 = 0;
        msg |= fb;
        if(count2 > 1 || v2 > 0) {
            msg |= rb;
        }
    }
    if(count2 > 10 || v2 > 2147483647 ) {
        f1 = 0;
        msg |= sb;
        if(count1 > 1 || v1 > 0) {
            msg |= rb;
        }
    }
    if(f1) {
        if(f2) {
            v3 = v1 * v2;
        } else {
            v3 = v1 + v2;
        }
        if(v3 > 2147483647) {
            msg |= rb;
        }
    }
    return msg;
}

int main() {
    int len;
    char s[10000];
    Message msg;
    while(fgets(s, 10000, stdin) != NULL) {
        len = strlen(s);
        if(s[len - 1] == '\n') {
            s[len - 1] = '\0';
            len -= 1;
        }
        msg = solve(s);
        puts(s);
        if(msg & fb) {
            puts("first number too big");
        }
        if(msg & sb) {
            puts("second number too big");
        }
        if(msg & rb) {
            puts("result too big");
        }
    }
    return 0;
}