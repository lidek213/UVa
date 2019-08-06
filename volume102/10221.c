#include <stdio.h>
#include <string.h>
#include <math.h>
int main() {
    int s, a;
    double r, pi = acos(-1.0), d;
    char str[4];
    while(scanf(" %d %d %s", &s, &a, &str) == 3) {
        r = 6440 + s;
        d = a;
        if(!strcmp(str, "min")) {
            d /= 60;
        }
        while(d > 360) {
            d -= 360;
        }
        if(d > 180) {
            d = 360 - d;
        }
        printf("%lf %lf\n", r * pi * d / 180, sqrt(r * r * 2 - 2 * r * r * cos(d * pi / 180)));
    }
    return 0;
}