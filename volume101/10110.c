#include <stdio.h>
#include <math.h>
int main() {
    long long int n, k;
    while(scanf(" %lld", &n) != EOF) {
        if(!n) {
            break;
        }
        k = (long long int)(sqrt(n) + 1e-8);
        if(k * k == n) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}