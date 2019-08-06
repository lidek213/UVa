#include <stdio.h>
long long int solve(int x, int y) {
    long long int t = x + y;
    return (t + 1) * t / 2 + (t - y + 1);
}
int main() {
    int n, x1, y1, x2, y2, cases = 1;
    scanf(" %d", &n);
    while(n-- > 0) {
        scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
        printf("Case %d: %lld\n", cases++, solve(x2, y2) - solve(x1, y1));
    }
    return 0;
}