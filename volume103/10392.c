#include <stdio.h>
#include <math.h>
int main() {
    int f = 0;
    long long int num, sqrt_num, i;
    while(scanf(" %lld", &num) != EOF) {
        if(num < 0) {
            break;
        }
        if(f) {
            printf("\n");
        }
        sqrt_num = (long long int)sqrt(num);
        for(i = 2; i < sqrt_num; i++) {
            while(num % i == 0) {
                printf("    %lld\n", i);
                num /= i;
            }
        }
        if(num > 1) {
            printf("    %lld\n", num);
        }
        f = 1;
    }
    return 0;
}