#include <stdio.h>
int count(int n) {
    int result = 0;
    while(n) {
        n &= n - 1;
        result++;
    }
    return result;
}

void printBinary(int n) {
    char *p = (char *)&n;
    int i, j, f = 0, t;
    for(i = 3; i >= 0; i--) {
        for(j = 7; j >= 0; j--) {
            t = (*(p + i) >> j) & 1;
            if(f || t) {
                f = 1;
                putchar(t + '0');
            }
        }
    }
}
int main() {
    int I;
    while(scanf(" %d", &I) != EOF) {
        if(I == 0) {
            break;
        }
        printf("The parity of ");
        printBinary(I);
        printf(" is %d (mod 2).\n", count(I));
    }
    return 0;
}