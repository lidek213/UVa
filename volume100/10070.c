#include <stdio.h>
#include <string.h>

int factorThree(char *s, int len) {
    int i, num = 0;
    for(i = 0; i < len; i++) {
        num += s[i] - '0';
    }
    return !(num % 3);
}

int factorFour(char *s, int len) {
    int num = (s[len - 2] - '0') * 10 + (s[len - 1] - '0');
    return !(num % 4);
}

int factorFive(char *s, int len) {
    int num = s[len - 1] - '0';
    return !(num % 5);
}

int factorEleven(char *s, int len) {
    int i, num = 0;
    for(i = 0; i < len; i += 2) {
        num += s[i] - '0';
    }
    for(i = 1; i < len; i += 2) {
        num -= s[i] - '0';
    }
    return !(num % 11);
}

int factorOneHundred(char *s, int len) {
    int num = (s[len - 3] - '0') * 100 + (s[len - 2] - '0') * 10 + (s[len - 1] - '0');
    return !(num % 100);
}

int factorFourHundred(char *s, int len) {
    int num = (s[len - 4] - '0') * 1000 + (s[len - 3] - '0') * 100 + (s[len - 2] - '0') * 10 + (s[len - 1] - '0');
    return !(num % 400);
}

int main() {
    char s[10000];
    int len, flag, newline = 0, f3, f4, f5, f11, f100, f400;
    while(fgets(s, 10000, stdin) != NULL) {
        if(newline) {
            printf("\n");
        }
        newline = 1;
        len = strlen(s);
        if(s[len - 1] == '\n') {
            s[len - 1] = '\0';
            len -= 1;
        }
        flag = 0;
        f3 = factorThree(s, len);
        f4 = factorFour(s, len);
        f5 = factorFive(s, len);
        f11 = factorEleven(s, len);
        f100 = factorOneHundred(s, len);
        f400 = factorFourHundred(s, len);
        if((f4 && !f100) || (f400)) {
            flag = 1;
            printf("This is leap year.\n");
        }
        if(f3 && f5) {
            flag = 1;
            printf("This is huluculu festival year.\n");
        }
        if((f5 && f11) && ((f4 && !f100) || (f400))) {
            flag = 1;
            printf("This is bulukulu festival year.\n");
        }
        if(!flag) {
            printf("This is an ordinary year.\n");
        }
    }
    return 0;
}