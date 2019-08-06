#include <stdio.h>
#include <string.h>
int main() {
    int N1, N2, i, j, t, t2, arr1[101], arr2[101], lcs[101], cases = 1;
    while(scanf(" %d %d", &N1, &N2) == 2) {
        if(N1 == 0 && N2 == 0) {
            break;
        }
        for(i = 0; i < N1; i++) {
            scanf(" %d", &arr1[i]);
        }
        for(i = 0; i < N2; i++) {
            scanf(" %d", &arr2[i]);
        }
        memset(lcs, 0, sizeof(lcs));
        for(i = 1; i <= N1; i++) {
            t = lcs[0];
            for(j = 1; j <= N2; j++) {
                t2 = lcs[j];
                if(arr1[i - 1] == arr2[j -1]) {
                    lcs[j] = t + 1;
                } else if(lcs[j - 1] > lcs[j]) {
                    lcs[j] = lcs[j -1];
                }
                t = t2;
            }
        }
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", cases++, lcs[N2]);
    }
    return 0;
}