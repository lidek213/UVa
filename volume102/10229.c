#include <stdio.h>
#define LL long long int
typedef struct {
    LL m[2][2];
} Matrix;

void initMatrix(Matrix *matrix) {
    matrix->m[0][0] = 1;
    matrix->m[0][1] = 1;
    matrix->m[1][0] = 1;
    matrix->m[1][1] = 0;
}

void multpleMatrixMod(Matrix a, Matrix b, Matrix *c, LL mod) {
    LL i, j, k;
    c->m[0][0] = 0;
    c->m[0][1] = 0;
    c->m[1][0] = 0;
    c->m[1][1] = 0;
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            for(k = 0; k < 2; k++) {
                c->m[i][j] = (c->m[i][j] + (a.m[i][k] * b.m[k][j])) % mod;
            }
        }
    }
}

void quickMatrixPow(Matrix a, int n, LL mod, Matrix *result) {
    initMatrix(result);
    Matrix base = a;
    while(n) {
        if(n & 1) {
            multpleMatrixMod(*result, base, result, mod);
        }
        multpleMatrixMod(base, base, &base, mod);
        n >>= 1;
    }
}
int main() {
    Matrix matrix;
    int n, m;
    while(scanf(" %d %d", &n, &m) == 2) {
        initMatrix(&matrix);
        quickMatrixPow(matrix, n, 1 << m, &matrix);
        printf("%lld\n", matrix.m[1][1]);
    }
    return 0;
}