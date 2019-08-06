#include <stdio.h>
char selet[5];
int num[5];
int solve(int n, int t) {
    int i, j, v, f;
    if(t == 5) {
        if(n == 23) {
            return 1;
        }
        return 0;
    }
    for(i = 0; i < 5; i++) {
        if(selet[i] == 0) {
            selet[i] = 1;
            if(solve(n + num[i], t + 1)) {
                return 1;
            }
            if(t) {
                if(solve(n - num[i], t + 1)) {
                    return 1;
                }
                if(solve(n * num[i], t + 1)) {
                    return 1;
                }
            }
            selet[i] = 0;
        }
    }
    return 0;
}
int main() {
    int i;
    while(scanf(" %d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4]) == 5) {
        if(num[0] == 0 && num[1] == 0 && num[2] == 0 && num[3] == 0 && num[4] == 0) {
            break;
        }
        for(i = 0; i < 5; i++) {
            selet[i] = 0;
        }
        if(solve(0, 0)) {
            printf("Possible\n");
        } else {
            printf("Impossible\n");
        }
    }
    return 0;
}