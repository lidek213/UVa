#include <stdio.h>

int main() {
    int i, sum, max, N = 0, a[100001];
    char c;
    while(scanf("%d%c", &a[N], &c) != EOF) {
        N++;
        if(c == '\n') {
            sum = 0;
            max = 0;
            for(i = 0; i < N; i++) {
                sum += a[i];
                if(sum > max) {
                    max = sum;
                } else if(sum < 0){
                    sum = 0;
                }
            }
            printf("%d\n",max);
            N = 0;
        }
    }
    return 0;
}
