#include <stdio.h>
int main() {
    int a, b, c, count;
    while(scanf(" %d %d", &a, &b) == 2) {
        if(!a && !b) {
            break;
        }
        count = 0;
        c = 0;
        while((a && b) || c) {
            c = (a % 10 + b % 10 + c) / 10;
            a /= 10;
            b /= 10;
            count += c;
        }
        if(count == 0) {
            printf("No carry operation.\n");
        } else if(count == 1) {
            printf("1 carry operation.\n");
        } else {
            printf("%d carry operations.\n", count);
        }
    }
    return 0;
}