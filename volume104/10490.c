#include <stdio.h>

int main() {
    int n, i, j, perfectK[] = {2, 3, 5, 7, 13, 17, 19, 31}, f;
    long long int perfect[] = {6, 28, 496, 8128, 33550336, 8589869056, 137438691328, 2305843008139952128};
    while(scanf(" %d", &n) != EOF) {
        if(!n) {
            break;
        }
        f = 1;
        for(j = 0; j < 8; j++) {
            if(n == perfectK[j]) {
                printf("Perfect: %lld!\n", perfect[j]);
                f = 0;
                break;
            }
        }
        if(f) {
            if(n == 11 || n == 23 || n == 29) {
                printf("Given number is prime. But, NO perfect number is available.\n");
            } else  {
                printf("Given number is NOT prime! NO perfect number is available.\n");
            }
        }
    }
    return 0;
}