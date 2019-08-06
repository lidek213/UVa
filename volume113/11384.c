#include <stdio.h>
int solve(int n) {
    int l = 0, r = 31, mid;
    while(l < r) {
        mid = (l + r) >> 1;
        if(n >> mid > 1) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return r + 1;
}
int main() {
    int N, ans[] = {1, 2, 4, };
    while(scanf(" %d", &N) != EOF) {
        printf("%d\n", solve(N));
    }
    return 0;
}