#include <stdio.h>
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int main() {
    int T, a, b, c, t, i;
    scanf(" %d", &T);
    for(i = 1; i <= T; i++) {
        scanf(" %d %d %d", &a, &b ,&c);
        if(a > c) {
            swap(&a, &c);
        }
        if(b > c) {
            swap(&b, &c);
        }
        if(a > b) {
            swap(&a, &b);
        }
        printf("Case %d: %d\n", i, b);
    }
    return 0;
}