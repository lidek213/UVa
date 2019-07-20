#include <stdio.h>
int prime[3401] = {2};

int makePrime() {
    int make[31622] = {0}, i, j, count = 1;
    for(i = 3; i < 31622; i += 2) {
        if(!make[i]) {
            prime[count++] = i;
        }
        for(j = i * i; j < 31622; j += i) {
            make[j] = 1;
        }
    }
}

long long int quickPowMod(long long int a, long long int p, long long int mod) {
    long long int result = 1, base = a;
    while(p) {
        if(p & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        p >>= 1;
    }
    return result;
}
int main() {
    long long int p, a;
    int flag, i;
    makePrime(); 
    while(scanf(" %lld %lld", &p, &a) == 2) {
        if(!p && !a) {
            break;
        }
        flag = 1;
        for(i = 0; i < 3401; i++) {
            if(p == prime[i]) {
                break;
            }
            if(p % prime[i] == 0) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            printf("no\n");
        } else {
            if(a == quickPowMod(a, p, p)) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }
    return 0;
}