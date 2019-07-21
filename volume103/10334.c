#include <stdio.h>
#include <string.h>
typedef struct {
    long long int number[15];
    int size;
} BigNumber;

BigNumber ans[1001];

void initBigNumber(BigNumber *a, long long int value) {
    memset(a, 0, sizeof(BigNumber));
    a->size = 1;
    a->number[0] = value;
}

void addBigNumber(BigNumber a, BigNumber b, BigNumber *c) {
    int i, size = a.size > b.size ? a.size : b.size;
    initBigNumber(c, 0);
    for(i = 0; i < size; i++) {
        c->number[i] += a.number[i] + b.number[i];
        c->number[i + 1] += c->number[i] / 1000000000000000;
        c->number[i] %= 1000000000000000;
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

void solve() {
    int i;
    initBigNumber(&ans[0], 1);
    initBigNumber(&ans[1], 2);
    for(i = 2; i < 1001; i++) {
        addBigNumber(ans[i - 2], ans[i - 1], &ans[i]);
    }
}
int main() {
    int n;
    solve();
    while(scanf(" %d", &n) != EOF) {
        printBigNumber(ans[n]);
    }
    return 0;
}