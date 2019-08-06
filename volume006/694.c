#include <stdio.h>
int solve(int A, int limit) {
    long long int t = A;
    int count = 1;
    while(t != 1) {
        if(t & 1) {
            t = 3 * t + 1;
            if(t > limit) {
                break;
            }
        } else {
            t /= 2;
        }
        count++;
    }
    return count;
}
int main() {
    int cases = 1, A, L;
    while(scanf(" %d %d", &A, &L) == 2) {
        if(A < 1 && L < 1) {
            break;
        }
        printf("Case %d: A = %d, limit = %d, number of terms = %d\n", cases, A, L, solve(A, L));
        cases++;
    }
    return 0;
}