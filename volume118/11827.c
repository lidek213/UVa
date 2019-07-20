#include <stdio.h>
#include <string.h>
int M[1000], size = 0;

void read() {
    int v = 0;
    char c = getchar();
    size = 0;
    if(c == '\n') {
        c = getchar();
    }
    do {
        if(c >= '0' && c <= '9') {
            v = v * 10 + c - '0';
        } else {
            if(v) {
                M[size++] = v;
            }
            v = 0;
            if(c == '\n') {
                break;
            }
        }
    } while((c = getchar()) != EOF);
    if(v) {
        M[size++] = v;
    }
}

int gcd(int a, int b) {
    if(b) {
        return gcd(b, a % b);
    } else {
        return a;
    }
}

int main() {
    int N, i, j, max, t;
    scanf(" %d", &N);
    while(N-- > 0) {
        read();
        max = 0;
        for(i = 0; i < size; i++) {
            for(j = i + 1; j < size; j++) {
                t = gcd(M[i], M[j]);
                if(t > max) {
                    max = t;
                }
            }
        }
        printf("%d\n", max);
    }
    return 0;
}