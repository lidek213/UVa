#include <stdio.h>
#include <math.h>
int main() {
    double pi = acos(-1.0), r, n;
    while(scanf(" %lf %lf", &r, &n) == 2) {
        printf("%.3lf\n", n * r * r * sin(360 * pi / n / 180) / 2);
    }
    return 0;
}