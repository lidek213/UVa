#include <stdio.h>
int ugly[1500];
int main() {
    int ugly[1500] = {1}, count = 0, min;
    int c2 = 0, c3 = 0, c5 = 0, t2 = 1, t3 = 1, t5 = 1;
    while(count < 1500) {
        while(t2 <= ugly[count]) {
            t2 = 2 * ugly[c2++];
        }
        while(t3 <= ugly[count]) {
            t3 = 3 * ugly[c3++];
        }
        while(t5 <= ugly[count]) {
            t5 = 5 * ugly[c5++];
        }
        min = t2;
        if(t3 < min) {
            min = t3;
        }
        if(t5 < min) {
            min = t5;
        }
        ugly[++count] = min;
    }
    printf("The 1500'th ugly number is %d.\n", ugly[1499]);
    return 0;
}