#include <stdio.h>

char isPrime[1000] = {0};
int prime[168] = {2}, primeCount = 1;
int N[64726] = {1}, NCount = 0;
void makePrime() {
    int i, j, k;
    for(i = 3; i < 1000;i += 2) {
        if(!isPrime[i]) {
            prime[primeCount] = i;
            primeCount++;
        }
        for(j = 1; (k = i * prime[j]) < 1000; j++) {
            isPrime[k] = 1;
            if(i % prime[j] == 0) {
                break;
            }
        }
    }
}

int NOD(int x) {
    int t = x, ans = 1, i, m;
    for(i = 0; i < primeCount && prime[i] <= t; i++) {
        if(t % prime[i] == 0) {
            m = 0;
            while(t % prime[i] == 0) {
                m++;
                t /= prime[i];
            }
            ans *= (m + 1);
        }
    }
    if(t != 1) {
        ans <<= 1;
    }
    return ans;
}

void makeN() {
     do {
        NCount++;
        N[NCount] = N[NCount - 1] + NOD(N[NCount - 1]);
    } while(N[NCount] < 1000000);
}



int binarySearch(int x) {
    int L = 0, R = NCount - 1, M;
    while(L <= R) {
        M = (L + R) >> 1;
        if(N[M] == x) {
            return M;
        } else if(N[M] > x) {
            R = M - 1;
        } else {
            L = M + 1;
        }
    }
    return M;
}

int main() {
    makePrime();
    makeN();
    int T, A, B, i, p, q;
    scanf(" %d", &T);
    for(i = 1; i <= T; i++) {
        scanf(" %d %d", &A, &B);
        p = binarySearch(A);
        q = binarySearch(B);
        while(N[p] < A) {
            p++;
        }
        while(N[q] > B) {
            q--;
        }
        printf("Case %d: %d\n", i, q - p + 1);
    }
    return 0;
}