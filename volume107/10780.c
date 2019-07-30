#include <stdio.h>
char sieve[5000];
int prime[669];
int factorCount[669][2];
void make() {
    register int i, j, count = 0;;
    for(i = 2; i < 5000; i++) {
        if(!sieve[i]) {
            prime[count] = i;
            count++;
        }
        for(j = 2 * i; j < 5000; j += i) {
            sieve[j] = 1;
        }
    }
}
int factorization(int n) {
    register int i, count = 0;
    for(i = 0; i < 669 && prime[i] <= n; i++) {
        if(n % prime[i] == 0) {
            factorCount[count][0] = prime[i];
            factorCount[count][1] = 0;
            do {
                factorCount[count][1]++;
                n /= prime[i];
            } while(n % prime[i] == 0);
            count++;
        }
    }
    return count;
}
int main() {
    int T, m, n, k, i, j, count, min, temp, tempCount;
    make();
    scanf(" %d", &T);
    for(k = 1; k <= T; k++) {
        scanf(" %d %d", &m, &n);
        printf("Case %d:\n", k);
        count = factorization(m);
        min = 100000;
        for(i = 0; i < count; i++) {
            tempCount = 0;
            for(j = factorCount[i][0]; j <= n; j *= factorCount[i][0]) {
                tempCount += n / j;
            }
            temp = tempCount / factorCount[i][1];
            if(temp < min) {
                min = temp;
            }
        }
        if(min == 0) {
            printf("Impossible to divide\n");
        } else {
            printf("%d\n", min);
        }
    }
    return 0;
}