#include <stdio.h>
#include <math.h>
int main() {
    long long int catalan[21] = {1}, n, i;
    for(i = 0; i < 20; i++) {
        catalan[i + 1] = (4 * i + 2) / (i + 2.0) * catalan[i];
    }
    while(scanf(" %lld", &n) != EOF) {
        for(i = 1; i < 21; i++) {
            if(catalan[i] == n) {
                printf("%lld\n", i);
                break;
            }
        }
    }
    return 0;
}