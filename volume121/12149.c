#include <stdio.h>
int main() {
    int a[101] = {0}, i, N;
    for(i = 1; i < 101; i++) {
        a[i] = i * i + a[i - 1];
    }
    while(scanf(" %d", &N) != EOF) {
        if(N == 0) {
            break;
        }
        printf("%d\n", a[N]);
    }
    return 0;
}