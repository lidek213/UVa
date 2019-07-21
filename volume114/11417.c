#include <stdio.h>
int gcd(int a, int b) {
    if(b) {
        return gcd(b, a % b);
    } else {
        return a;
    }
}
int main() {
    int N, ans[501] = {0}, t[501][501] = {0}, i, j;
    for(i = 1; i < 501; i++) {
        for(j = i + 1; j < 501; j++) {
            t[i][j] += t[i][j - 1] + gcd(i, j);
            ans[j] += t[i][j];
        }
    }
    while(scanf(" %d", &N) != EOF) {
        if(N < 1) {
            break;
        }
        printf("%d\n", ans[N]);
    }
    return 0;
}