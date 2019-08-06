#include <stdio.h>
int ans[10001];
void make() {
    char silve[10000] = {0};
    int i, j, k, count = 1, prime[1229];    
    prime[0] = 2;
    for(i = 3; i < 10000; i += 2) {
        if(silve[i] == 0) {
            prime[count++] = i;
        }
        for(j = i * i; j < 10000; j += i) {
            silve[j] = 1;
        }
    }
    i = 3;
    j = 0;
    while(i <= 10000) {
        if(i % prime[j] == 0) {
            j++;
        }
        ans[i] = prime[j];
        i++;
    }
}
int main() {
    int M, N;
    make();
    scanf(" %d", &M);
    while(M-- > 0) {
        scanf(" %d", &N);
        printf("%d\n", ans[N]);
    }
    return 0;
}