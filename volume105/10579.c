#include <stdio.h>
#include <string.h>

typedef struct {
    long long int number[67];
    int size;
} BigNumber;

void initBigNumber(BigNumber *a, long long int value) {
    memset(a, 0, sizeof(BigNumber));
    a->number[0] = value;
    a->size = 1;
}

void addBigNumber(BigNumber a, BigNumber b, BigNumber *c) {
    initBigNumber(c, 0);
    int i, size = a.size > b.size ? a.size : b.size;
    long long int t;
    for(i = 0; i < size; i++) {
        c->number[i] += a.number[i] + b.number[i];
        t = c->number[i] / 1000000000000000;
        c->number[i + 1] += t;
        c->number[i] -= t * 1000000000000000;
    }
    c->size = size;
    if(c->number[size] > 0) {
        c->size = size + 1;
    }
}

void printBigNumber(BigNumber a) {
    int i = a.size - 1;
    printf("%lld", a.number[i]);
    for(i = i - 1; i >= 0; i--) {
        printf("%015lld", a.number[i]);
    }
    printf("\n");
}

BigNumber f[5000];

int main() {
    int n, i;
    initBigNumber(&f[0], 0);
    initBigNumber(&f[1], 1);
    initBigNumber(&f[2], 1);
    for(i = 3; i < 5000; i++) {
        addBigNumber(f[i - 2], f[i - 1], &f[i]);
    }
    while(scanf(" %d", &n) != EOF) {
        printBigNumber(f[n]);
    }
    return 0;
}