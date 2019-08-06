#include <stdio.h>
int ans[1001] = {1};
void solve() {
    long long int num[181] = {1}, t, i, carry;
    int sum, j;
    for(i = 1; i < 1001; i++) {
        for(j = 0; j < 180; j++) {
            num[j] *= i;
        }
        sum = 0;
        carry = 0;
        for(j = 0; j < 180; j++) {
            num[j + 1] += num[j] / 1000000000000000;
            num[j] %= 1000000000000000;
            t = num[j];
            while(t) {
                sum += t % 10;
                t /= 10;
            }
        }
        ans[i] = sum;
    }
}
int main() {
    int n;
    solve();
    while(scanf(" %d", &n) != EOF) {
        printf("%d\n", ans[n]);
    }
    return 0;
}