#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int main() {
    int n, x[1000000], mid, i, a, b, c;
    while(scanf(" %d", &n) != EOF) {
        for(i = 0; i < n; i++) {
            scanf(" %d", &x[i]);
        }
        qsort(x, n, sizeof(int), cmp);
        mid = (n - 1) / 2;
        a = x[mid];
        c = 0;
        if(n & 1) {
            b = 1;
            for(i = mid; i >= 0 && x[i] == x[mid]; i--) {
                c++;
            }
            for(i = mid + 1; i < n && x[i] == x[mid]; i++) {
                c++;
            }
        } else {
            b = x[mid + 1] - x[mid] + 1;
            for(i = mid; i >= 0 && x[i] == x[mid]; i--) {
                c++;
            }
            for(i = mid + 1; i < n && x[i] == x[mid + 1]; i++) {
                c++;
            }
        }
        printf("%d %d %d\n", a, c, b);
    }
    return 0;
}