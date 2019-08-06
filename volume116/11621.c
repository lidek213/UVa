#include <stdio.h>
long long int next[328] = {1};
void make() {
    long long int count = 0, t2 = 1, t3 = 1, c2 = 0, c3 = 0;
    while(next[count] < 2147483648) {
        while(t2 <= next[count]) {
            t2 = next[c2++] * 2;
        }
        while(t3 <= next[count]) {
            t3 = next[c3++] * 3;
        }
        if(t2 < t3) {
            next[++count] = t2;
        } else {
            next[++count] = t3;
        }
    }
}
int binarySearchIndex(int m) {
    int l = 0, r = 328, mid;
    while(l < r) {
        mid = (l + r) / 2;
        if(next[mid] >= m) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r;
}
int main() {
    int m, t;
    make();
    while(scanf(" %d", &m) != EOF) {
        if(m == 0) {
            break;
        }
        t = binarySearchIndex(m);
        printf("%lld\n", next[t]);
    }
    return 0;
}