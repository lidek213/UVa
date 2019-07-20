#include <stdio.h>
#include <stdlib.h>
int main() {
    int M, a, b;
    scanf(" %d", &M);
    while(M-- > 0) {
        scanf(" %d %d", &a, &b);
        if(b == 0) {
            printf("1\n");
        } else if(a ==  0) {
            printf("2\n");
        } else if(abs(a) == abs(b)) {
            printf("4\n");
        } else {
            printf("TOO COMPLICATED\n");
        }
    }
    return 0;
}