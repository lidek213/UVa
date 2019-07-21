#include <stdio.h>
#include <string.h>
typedef struct {
    long long int number[70];
    int size;
} BigNumber;

BigNumber ans[2001];

void initBigNumber(BigNumber *a, long long int v) {
    memset(a, 0, sizeof(BigNumber));
    a->number[0] = v;
    a->size = 1;
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
    BigNumber t[2001];
    initBigNumber(&t[0], 1);
    initBigNumber(&ans[0], 0);
    for(i = 1; i < 2001; i++) {
        addBigNumber(t[i - 1], ans[i - 1], &t[i]);
        addBigNumber(t[i], ans[i - 1], &ans[i]);
    }
}

int main() {
    int N;
    solve();
    while(scanf(" %d", &N) != EOF) {
        if(N == 0) {
            break;
        }
        printBigNumber(ans[N]);
    }
    return 0;
}