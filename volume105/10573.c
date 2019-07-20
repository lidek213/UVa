#include <stdio.h>
#include <math.h>
int main() {
    int N, r1, r2;
    double area, pi = acos(-1.0), a, b, c;
    char s[20];
    scanf(" %d ", &N);
    while(N-- > 0) {
        fgets(s, 20, stdin);
        if(sscanf(s, " %d %d", &r1, &r2) == 1) {
            a = r1 / 2.0;
            b = c = r1 / 4.0;
        } else {
            a = r1 + r2;
            b = r1;
            c = r2;
        }
        area = (a * a - b * b - c * c) * pi;
        printf("%.4lf\n", area);
    }
    return 0;
}