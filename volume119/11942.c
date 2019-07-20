#include <stdio.h>
int main() {
    int N, a[10], f1, f2, i;
    printf("Lumberjacks:\n");
    scanf(" %d", &N);
    while(N-- > 0) {
        scanf(" %d", &a[0]);
        f1 = f2 =  0;
        for(i = 1; i < 10; i++) {
            scanf(" %d", &a[i]);
            if(a[i] >= a[i - 1]) {
                f1++;
            }
            if(a[i] <= a[i - 1]) {
                f2++;
            }
        }
        if(f1 == 9 || f2 == 9) {
            printf("Ordered\n");
        } else {
            printf("Unordered\n");
        }
    }
    return 0;
}