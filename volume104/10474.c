#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int searctIndex(int arr[], int size, int x) {
    int l = 0, r = size, mid;
    while(l < r) {
        mid = (l + r) / 2;
        if(arr[mid] == x) {
            return mid;
        }
        else if(arr[mid] < x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return -1;
}

int main() {
    int arr[10000], N, Q, i, x, index, cases =  1;
    while(scanf(" %d %d", &N, &Q) == 2) {
        if(N == 0 && Q == 0) {
            break;
        }
        printf("CASE# %d:\n", cases++);
        for(i = 0; i < N; i++) {
            scanf(" %d", &arr[i]);
        }
        qsort(arr, N, sizeof(int), cmp);
        for(i = 0; i < Q; i++) {
            scanf(" %d", &x);
            index = searctIndex(arr, N, x);
            if(index != -1) {
                printf("%d found at %d\n", x, index + 1);
            } else {
                printf("%d not found\n", x);
            }
        }
    }
    return 0;
}