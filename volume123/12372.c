#include <stdio.h>
int main() {
    int T, L, W, H, cases = 1;
    scanf(" %d", &T);
    while(T-- > 0) {
        scanf(" %d %d %d", &L, &W, &H);
        if(L > 20 || W > 20 || H > 20) {
            printf("Case %d: bad\n", cases++);
        } else {
            printf("Case %d: good\n", cases++);
        }
    }
    return 0;
}