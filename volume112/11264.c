#include <stdio.h>
int main() {
    int T, n, i, arr[1001], temp, ans;
    scanf(" %d", &T);
    while(T-- > 0) {
        scanf(" %d", &n);
        for(i = 0; i < n; i++) {
            scanf(" %d", &arr[i]);
        }
        ans = 0;
        temp = 0;
        for(i = 1; i < n; i++) {
            if(temp + arr[i - 1] < arr[i]) {
                temp += arr[i - 1];
                ans++;
            }
        }
        if(temp < arr[n - 1]) {
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}