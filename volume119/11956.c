#include <stdio.h>
#include <string.h>
int main() {
    int T, len, i, k, index;
    char s[100005];
    unsigned char arr[100];
    scanf(" %d ", &T);
    for(k = 1; k <= T; k++) {
        fgets(s, 100001, stdin);
        memset(arr, 0, sizeof(unsigned char) * 100);
        len = strlen(s);
        index = 0;
        for(i = 0; i < len; i++) {
            switch(s[i]) {
                case '+':
                    arr[index]++;
                    break;
                case '-':
                    arr[index]--;
                    break;
                case '<':
                    index = (index + 99) % 100;
                    break;
                case '>':
                    index = (index + 1) % 100;
                    break;
            }
        }
        printf("Case %d:", k);
        for(i = 0; i < 100; i++) {
            printf(" %02X", arr[i]);
        }
        printf("\n");
    }
    return 0;
}