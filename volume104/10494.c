#include <stdio.h>
#include <string.h>
int main() {
    char num[10001], c, divValue[10001];
    long long int value = 0, size, t;
    int i, len, n;
    while(scanf(" %s %c %d", &num, &c, &n) == 3) {
        memset(divValue, 0, sizeof(char) * 10001);
        divValue[0] = '0';
        len = strlen(num);
        value = 0;
        size = 0;
        for(i = 0; i < len; i++) {
            value = value * 10 + num[i] - '0';
            t = value / n;
            if(size || t) {
                divValue[size++] = t + '0';
                value -= t * n;
            }
        }
        if(c == '/') {
            printf("%s\n", divValue);
        } else {
            printf("%lld\n", value);
        }
    }
    return 0;
}