#include <stdio.h>

typedef struct {
    char name[20];
    int f, t;
} Data;

int main() {
    int T, n, k, i, j, ansIndex;
    Data data[3001], o;
    scanf(" %d", &T);
    while(T-- > 0) {
        scanf(" %d %d", &n ,&k);
        for(i = 0; i < n; i++) {
            scanf(" %s %d", &data[i].name, &data[i].f);
            data[i].t = data[i].f;
        }
        for(i = 0; i < k; i++) {
            ansIndex = 0;
            for(j = 1; j < n; j++) {
                if(data[j].t < data[ansIndex].t) {
                    ansIndex = j;
                }
            }
            printf("%d %s\n", data[ansIndex].t, data[ansIndex].name);
            data[ansIndex].t += data[ansIndex].f;
        }
    }
    return 0;
}
