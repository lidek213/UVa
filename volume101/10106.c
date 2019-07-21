#include <stdio.h>
#include <string.h>
typedef struct {
    long long int number[100];
    int size;
} BigNumber;

void initBigNumber(BigNumber *a, char *s) {
    int len = strlen(s) - 1, t = 0, size = 0, k = 1;
    long long value = 0;
    memset(a, 0, sizeof(BigNumber));
    while(len >= 0) {
        t++;
        value = value + (s[len] - '0') * k;
        k *= 10;
        if(t == 9) {
            a->number[size++] = value;
            value = 0;
            t = 0;
            k = 1;
        }
        len--;
    }
    if(t > 0) {
        a->number[size++] = value;
    }
    a->size = size;
}

void multipleBigNumber(BigNumber a, BigNumber b, BigNumber *c) {
    int i, j;
    initBigNumber(c, "0");
    for(i = 0; i < a.size; i++) {
        for(j = 0; j < b.size; j++) {
            c->number[i + j] += a.number[i] * b.number[j];
            c->number[i + j + 1] += c->number[i + j] / 1000000000;
            c->number[i + j] %= 1000000000;
        }
    }
    c->size = a.size + b.size - 1;
    if(c->number[c->size] > 0){
        c->size += 1;
    }
}

void printBigNumber(BigNumber a) {
    int i = a.size - 1;
    while(a.number[i] == 0 && i > 0) {
        i--;
    }
    printf("%lld", a.number[i]);
    for(i = i - 1; i >= 0; i--) {
        printf("%09lld", a.number[i]);
    }
    printf("\n");
}

int main() {
    BigNumber a, b, c;
    char s1[250], s2[250];
    while(scanf(" %s %s", &s1, &s2) != EOF) {
        initBigNumber(&a, s1);
        initBigNumber(&b, s2);
        multipleBigNumber(a, b, &c);
        printBigNumber(c);
    }
    return 0;
}