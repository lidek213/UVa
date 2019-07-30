#include <stdio.h>
#include <math.h>
void solve(int n) {
    int i, x, u;
    for(i = (int)sqrt(n - 1); i > 0; i--) {
        x = n - i * i;
        u = x / i;
        if(u * i == x) {
            printf(" %d", x);
        }
    }
}
int main() {
    int T, N, cases;
    scanf(" %d", &T);
    for(cases = 1; cases <= T; cases++) {
        scanf(" %d", &N);
        printf("Case %d:", cases);
        solve(N);
        printf("\n");
    }
    return 0;
}