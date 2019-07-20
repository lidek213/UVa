#include <stdio.h>
int main() {
    int N, P, i, t;
    while(scanf(" %d", &N) != EOF) {
        if(!N) {
            break;
        }
        t = 0;
        for(i = 0; i < N; i++) {
            scanf(" %d", &P);
            t ^= P;
        }
        if(t) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}