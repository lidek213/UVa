#include <stdio.h>
#include <string.h>
int leapYeayCount(int y) {
    return y / 4 - y / 100 + y / 400;
}
int main() {
    int T, d1, y1, d2, y2, i, j, p, q, cases = 1, ans;
    char monMap[][10] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August", "September",
        "October", "November", "December"
    }, m1[10], m2[10];
    scanf(" %d", &T);
    while(T-- > 0) {
        scanf(" %s %d, %d", &m1, &d1, &y1);
        scanf(" %s %d, %d", &m2, &d2, &y2);
        for(p = 0; p < 12; p++) {
            if(!strcmp(monMap[p], m1)) {
                break;
            }
        }
        for(q = 0; q < 12; q++) {
            if(!strcmp(monMap[q], m2)) {
                break;
            }
        }
        if(p <= 1) {
            y1 -= 1;
        }
        if(q <= 1) {
            y2 -= 1;
        }
        if(q == 1 && d2 == 29) {
            y2 += 1;
        }
        ans = leapYeayCount(y2) - leapYeayCount(y1);
        printf("Case %d: %d\n", cases++, ans);
    }
    
    return 0;
}