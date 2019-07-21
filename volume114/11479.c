#include <stdio.h>

void sort(long long int *a) {
    int i, j, t;
    for(i = 0; i < 2; i++) {
        for(j = i + 1; j < 3; j++) {
            if(a[i] > a[j]) {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

int main() {
    int T, x;
    long long int a[3];
    scanf(" %d", &T);
    for(x = 1; x <= T; x++) {
        scanf(" %lld %lld %lld", &a[0], &a[1], &a[2]);
        sort(a);
        printf("Case %d: ", x);
        if(a[0] > 0 && a[1] > 0 && a[2] > 0) {
            if(a[0] + a[1] > a[2]) {
                if(a[0] == a[1] && a[1] == a[2]) {
                    printf("Equilateral\n");
                } else if(a[0] == a[1] || a[1] == a[2]) {
                    printf("Isosceles\n");
                } else {
                    printf("Scalene\n");
                }
            } else {
                printf("Invalid\n");
            }
        } else {
            printf("Invalid\n");
        }
    }
    return 0;
}