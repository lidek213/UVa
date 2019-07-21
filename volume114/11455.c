#include <stdio.h>

void sort(int *a) {
    int i, j, t;
    for(i = 0; i < 3; i++) {
        for(j = i + 1; j < 4; j++) {
            if(a[i] > a[j]) {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

int main() {
    int T, a[4];
    scanf(" %d", &T);
    while(T-- > 0) {
        scanf(" %d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
        sort(a);
        if(a[0] == a[1] && a[2] == a[3]) {
            if(a[1] == a[2]) {
                printf("square\n");
            } else {
                printf("rectangle\n");
            }
        } else if(a[0] + a[1] + a[2] > a[3]) {
            printf("quadrangle\n");
        } else {
            printf("banana\n");
        }
    }
    return 0;
}