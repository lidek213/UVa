#include <stdio.h>
#include <math.h>
int main() {
    int N, cases = 1;
    double l2 = log(2);
    while(scanf(" %d", &N) != EOF) {
        if(N <= 0) {
            break;
        }
        if(N == 1) {
            printf("Case %d: 0\n", cases);
        } else {
            printf("Case %d: %d\n", cases, (int)floor(log(N - 1) / l2 + 1e-8) + 1);
        }
        cases++;
    }
    return 0;
}