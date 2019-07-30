#include <stdio.h>
#include <math.h>
int main() {
    double a, b, c, r, R, area, s, pi = acos(-1);
    double ya, ba, ra;
    while(scanf(" %lf %lf %lf", &a, &b, &c) == 3) {
        s = (a + b + c) / 2;
        area = sqrt(s * (s - a) * (s - b) * (s - c));
        r = 2 * area / (a + b + c);
        R = a * b * c / (4 * area);
        ra = r * r * pi;
        ba = area - ra;
        ya = R * R * pi - area;
        printf("%.4lf %.4lf %.4lf\n", ya, ba, ra);
    }
    return 0;
}