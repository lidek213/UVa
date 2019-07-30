#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int n, i, a, b, t;
    char check[3001];
    while(scanf(" %d", &n) != EOF) {
        memset(check, 0, sizeof(char) * 3001);
        scanf(" %d", &a);
        for(i = 1; i < n; i++) {
            scanf(" %d", &b);
            t = abs(b - a);
            if(t < 3001) {
                check[t] = 1;
            }
            a = b;
        }
        t = 1;
        for(i = 1; i < n; i++) {
            if(check[i] == 0) {
                t = 0;
                break;
            }
        }
        if(t) {
            printf("Jolly\n");
        } else {
            printf("Not jolly\n");
        }
    }
    return 0;
}