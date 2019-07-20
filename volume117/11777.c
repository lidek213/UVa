#include <stdio.h>
int main() {
    int  T, i, t1, t2, f, a, ct1, ct2, ct3, score, max;
    scanf(" %d", &T);
    for(i = 1; i <= T; i++) {
        scanf(" %d %d %d %d %d %d %d", &t1, &t2, &f, &a, &ct1, &ct2, &ct3);
        max = ct1 + ct3;
        if(ct1 + ct2 > ct1 + ct3) {
            max = ct1 + ct2;
        }
        if(ct2 + ct3 > max) {
            max = ct2 + ct3;
        }
        score = t1 + t2 + f + a + max / 2;
        printf("Case %d: ", i);
        if(score >= 90) {
            printf("A\n");
        } else if(score >= 80) {
            printf("B\n");
        } else if(score >= 70) {
            printf("C\n");
        } else if(score >= 60) {
            printf("D\n");
        } else {
            printf("F\n");
        }
    }
    return 0;
}