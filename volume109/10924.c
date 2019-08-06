#include <stdio.h>
#include <string.h>
char silve[5200] = {0};
void makePrime() {
    int i, j;
    silve[0] = 1;
    for(i = 2; i < 5200; i++) {
        for(j = i * i; j < 5200; j += i) {
            silve[j] = 1;
        }
    }
}


int main() {
    char s[100];
    int i, len, sum;
    makePrime();
    while(scanf(" %s", s) != EOF) {
        len = strlen(s);
        sum = 0;
        for(i = 0; i < len; i++) {
            if(s[i] >= 'a' && s[i] <= 'z') {
                sum += s[i] - 'a' + 1;
            } else if(s[i] >= 'A' && s[i] <= 'Z') {
                sum += s[i] - 'A' + 27;;
            }
        }
        if(silve[sum] == 0) {
            printf("It is a prime word.\n");
        } else {
            printf("It is not a prime word.\n");
        }
    }
    return 0;
}