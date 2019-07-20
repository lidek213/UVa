#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, num, v;
    char code[4];
    scanf(" %d", &N);
    while(N-- > 0) {
        scanf(" %3s-%d", &code, &num);
        v = ((code[0] - 'A') * 26 + code[1] - 'A') * 26 + code[2] - 'A';
        if(abs(v - num) <= 100) {
            printf("nice\n");
        } else {
            printf("not nice\n");
        }
    }
    return 0;
}