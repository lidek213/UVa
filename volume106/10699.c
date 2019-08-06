#include <stdio.h>
#include <string.h>
int prime[168] = {2};
void make() {
    char silve[1000] = {0};
    int count = 1;
    long long int i, j;
    for(i = 3; i < 1000; i += 2) {
        if(silve[i] == 0) {
            prime[count++] = i;
        }
        for(j = i * i; j < 1000; j += i) {
            silve[j] = 1;
        }
    }
}

int main() {
    int i, count, num, t;
    make();
    while(scanf(" %d", &num) != EOF) {
        if(num == 0) {
            break;
        }
        count = 0;
        t = num;
        for(i = 0; i < 168 && prime[i] * prime[i] <= t; i++) {
            if(t % prime[i] == 0) {
                count++;
                while(t % prime[i] == 0) {
                    t /= prime[i];
                }
            }
        }
        if(t > 1) {
            count++;
        }
        printf("%d : %d\n", num, count);
    }
    return 0;
}