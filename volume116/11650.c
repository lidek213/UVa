#include <stdio.h>
int main() {
    int T, h, m, h2, m2;
    scanf(" %d", &T);
    while(T-- > 0) {
        scanf(" %d:%d", &h, &m);
        m2 = 60 - m;
        h2 = 11 - h + m2 / 60;
        m2 %= 60;
        if(h2 <= 0) {
            h2 += 12;
        }
        printf("%02d:%02d\n", h2, m2);
    }
    return 0;
}