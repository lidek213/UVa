#include <stdio.h>

typedef struct {
    long long int num[5];
    int size;
} BigNumber;

void resetBigNumber(BigNumber *number, long long int value) {
    int i;
    for(i = 0; i < 5; i++) {
        number->num[i] = 0;
    }
    number->size = 0;
    number->num[0] = value;
}
void multiply(BigNumber a, BigNumber b, BigNumber *result) {
    int i = 0, j;
    resetBigNumber(result, 0);
    for(i = 0; i <= b.size; i++) {
        for(j = 0; j <= a.size; j++) {
            result->num[i + j] += a.num[j] * b.num[i];
        }
    }
    for(i = 0; i < 4; i++) {
        result->num[i + 1] += result->num[i] / 100000000;
        result->num[i] %= 100000000;
        if(result->num[i + 1] != 0) {
            result->size = i + 1;
        }
    }
}

void print(BigNumber number) {
    int i = number.size;
    printf("%lld", number.num[i]);
    for(i = i - 1; i >= 0; i--) {
        printf("%08lld", number.num[i]);
    }
    printf("\n");
}

void quickPow(long long int a, long long int p, BigNumber *result) {
    BigNumber base;
    resetBigNumber(result, 1);
    resetBigNumber(&base, a);
    while(p) {
        if(p & 1) {
            multiply(*result, base, result);
        }
        multiply(base, base, &base);
        p >>= 1;
    }
}

int main() {
    int i, j, N, D;
    BigNumber number[11][26];
    for(i = 0; i < 11; i++) {
        for(j = 0; j < 26; j++) {
            quickPow(i, j, &number[i][j]);
        }
    }
    while(scanf(" %d %d", &N, &D) == 2) {
        if(!N && !D) {
            break;
        }
        print(number[N][D]);
    }
    return 0;
}