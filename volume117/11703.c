#include <stdio.h>
#include <math.h>
int main() {
    double s;
    int i, x[1000000] = {1};
    for(i = 1; i < 1000000; i++) {
        s = sin(i);
        x[i] = (x[(int)floor(i - sqrt(i))] + x[(int)floor(log(i))] + x[(int)floor(i * s * s)]) % 1000000;
    }
    while(scanf(" %d", &i) != EOF) {
        if(i == -1) {
            break;
        }
        printf("%d\n", x[i]);
    }
    return 0;
}