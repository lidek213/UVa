#include <stdio.h>
#include <string.h>

typedef struct {
    long long int number[8];
    int size;
} BigNumber;

BigNumber f[500];

void initBigNumber(BigNumber *a, char *s) {
    int i, j, len, size = 0;
    long long int value, k = 1;
    memset(a, 0, sizeof(BigNumber));
    len = strlen(s);
    value = 0;
    j = 0;
    for(i = len - 1; i >= 0; i--) {
        value = value + (s[i] - '0') * k;
        k *= 10;
        j++;
        if(j == 15) {
            a->number[size++] = value;
            value = 0;
            j = 0;
            k = 1;
        }
    }
    if(value > 0) {
        a->number[size++] = value;
    }
    a->size = size;
}

void addBigNumber(BigNumber a, BigNumber b, BigNumber *c) {
    initBigNumber(c, "0");
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

int comparisonBigNumber(BigNumber a, BigNumber b) {
    if(a.size == b.size) {
        int i;
        for(i = a.size - 1; i >= 0; i--) {
            if(a.number[i] != b.number[i]) {
                if(a.number[i] > b.number[i]) {
                    return 1;
                }
                return -1;
            }
        }
        return 0;
    } else if(a.size > b.size) {
        return 1;
    } else {
        return -1;
    }
}

int searchIndex(BigNumber a) {
    int l = 1, r = 499, mid, result;
    while(l < r) {
        mid = (l + r) / 2;
        result = comparisonBigNumber(a, f[mid]);
        if(result == 0) {
            return mid;
        } else if(result < 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r;
}


int main() {
    int n, i, m1, m2;
    char s1[101], s2[101];
    BigNumber A, B;
    initBigNumber(&f[0], "0");
    initBigNumber(&f[1], "1");
    initBigNumber(&f[2], "2");
    for(i = 3; i < 500; i++) {
        addBigNumber(f[i - 2], f[i - 1], &f[i]);
    }
    while(scanf(" %s %s", &s1, &s2) == 2) {
        if(!strcmp(s1, "0") && !strcmp(s2, "0")) {
            break;
        }
        initBigNumber(&A, s1);
        initBigNumber(&B, s2);
        m1 = searchIndex(A);
        m2 = searchIndex(B);
        if(comparisonBigNumber(B, f[m2]) == 0) {
            m2++;
        }
        printf("%d\n", m2 - m1);
    }
    return 0;
}