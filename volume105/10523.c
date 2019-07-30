#include <stdio.h>
#include <string.h>
typedef struct {
    long long int num[30];
    int count;
} BigNumber;

void set(BigNumber *a, long long int v) {
    memset(a, 0, sizeof(BigNumber));
    a->num[0] = v;
    a->count = 1;
}

void carry(BigNumber *a) {
    long long int c;
    int i, t;
    for(i = 0; i < a->count; i++) {
        c = a->num[i] / 100000000;
        a->num[i] %= 100000000;
        a->num[i + 1] += c;
    }
    if(c) {
        a->count++;
    }
}

void add(BigNumber a, BigNumber b, BigNumber *c) {
    int i, max = a.count;
    if(a.count < b.count) {
        max = b.count;
    }
    for(i = 0; i < 29; i++) {
        c->num[i] = a.num[i] + b.num[i];
    }
    c->count = max;
    carry(c);
}

void mul(BigNumber a, BigNumber b, BigNumber *c) {
    int i, j;
    set(c, 0);
    for(i = 0; i < a.count; i++) {
        for(j = 0; j < b.count; j++) {
            c->num[i + j] += a.num[i] * b.num[j];
        }
    }
    c->count = a.count + b.count - 1;
    carry(c);
}

void print(BigNumber a) {
    int i = a.count - 1;
    printf("%lld", a.num[i]);
    for(i = i - 1; i >= 0; i--) {
        printf("%08lld", a.num[i]);
    }
    printf("\n");
}

int main() {
    BigNumber ans[16][151], t, t2, t3;
    int i, j, N, A;
    for(i = 1; i < 151; i++) {
        set(&ans[0][i], 0);
    }
    for(i = 1; i < 16; i++) {
        set(&t, 1);
        set(&t2, i);
        set(&ans[i][0], 0);
        for(j = 1; j < 151; j++) {
            set(&t3, j);
            mul(t, t2, &t);
            mul(t, t3, &t3);
            add(ans[i][j - 1], t3, &ans[i][j]);
        }
    }
    while(scanf(" %d %d", &N, &A) == 2) {
        print(ans[A][N]);
    }
    return 0;
}