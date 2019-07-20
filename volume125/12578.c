#include <stdio.h>
#include <math.h>

int main() {
    int T, L;
    double pi = acos(-1), R, W, A;
    scanf(" %d", &T);
    while(T-- > 0) {
        scanf(" %d", &L);
        W = L * 0.6;
        R = L * 0.2;
        A = R * R * pi;
        printf("%.2lf %.2lf\n", A, L * W - A);
    }
    return 0;
}