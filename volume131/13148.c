#include <stdio.h>
int map[22];
int binarySearchIndex(int n) {
    int l = 1, r = 22, mid;
    while(l < r) {
        mid = (l + r) / 2;
        if(map[mid] == n) {
            return mid;
        } else if(map[mid] > n){
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}
int main() {
    int n, i, t;
    for(i = 1; i < 22; i++) {
        t = i * i;
        map[i] = t * t * t;
    }
    while(scanf(" %d", &n) != EOF) {
        if(n == 0) {
            break;
        }
        t = binarySearchIndex(n);
        if(t == -1) {
            printf("Ordinary\n");
        } else {
            printf("Special\n");
        }
    }
    return 0;
}