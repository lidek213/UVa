#include <stdio.h>
#include <string.h>
char make[729];
void solve() {
    int count[729] = {0}, temp[300], size = 0, t, u, v, i, j;
    make[1] = 1;
    for(i = 2; i < 730; i++) {
        if(make[i] == 0) {
            t = i;
            size = 0;
            memset(count, 0, sizeof(int) * 729);
            do {
                count[t]++;
                temp[size++] = t;
                u = 0;
                while(t) {
                    v = t % 10;
                    u += v * v;
                    t /= 10;
                }
                t = u;
            } while(count[t] == 0 && make[t] == 0);
            if(t == 1 || make[t] == 1) {
                for(j = 0; j < size; j++) {
                    make[temp[j]] = 1;
                }
            } else {
                for(j = 0; j < size; j++) {
                    make[temp[j]] = -1;
                }
            }
        }
    }
}

int main() {
    int T, N, p, t, u, v;
    solve();
    scanf(" %d", &T);
    for(p = 1; p <= T; p++) {
        scanf(" %d", &N);
        t = N;
        u = 0;
        while(t) {
            v = t % 10;
            u += v * v;
            t /= 10;
        }
        if(make[u] == 1) {
            printf("Case #%d: %d is a Happy number.\n", p, N);
        } else {
            printf("Case #%d: %d is an Unhappy number.\n", p, N);
        }
    }
    return 0;
}