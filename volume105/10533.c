#include <stdio.h>
#define SIZE 1000000
int count[SIZE] = {0}, prime[SIZE] = {1, 1};
int main() {
    int i, j, N, t1, t2, sum;
    for(i = 2; i < SIZE; i++) {
        count[i] += count[i - 1];
        if(!prime[i]) {
            t1 = i;
            sum = 0;
            do {
                sum += t1 % 10;
                t1 /= 10;
            } while(t1);
            if(!prime[sum]) {
                count[i] += 1;
            }
        }
        for(j = i * 2; j < SIZE; j += i) {
            prime[j] = 1;
        }
    }
    scanf(" %d", &N);
    while(N-- > 0) {
        scanf(" %d %d", &t1, &t2);
        printf("%d\n", count[t2] - count[t1 - 1]);
    }
    return 0;
}