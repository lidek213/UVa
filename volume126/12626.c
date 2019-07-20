#include <stdio.h>
#include <string.h>

int main() {
    int N, count[26] = {0}, len, i, min;
    char s[1000];
    scanf(" %d", &N);
    while(N-- > 0) {
        memset(count, 0, sizeof(int) * 26);
        scanf(" %s", &s);
        len = strlen(s);
        for(i = 0; i < len; i++) {
            count[s[i] - 'A']++;
        }
        min = count[0] / 3;
        if(count[6] < min) {
            min = count[6];
        }
        if(count[17] / 2 < min) {
            min = count[17] / 2;
        }
        if(count[12] < min) {
            min = count[12];
        }
        if(count[8] < min) {
            min = count[8];
        }
        if(count[19] < min) {
            min = count[19];
        }
        printf("%d\n", min);
    }
    return 0;
}