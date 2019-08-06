#include <stdio.h>
int main() {
    int N, M, D, days[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334}, t;
    char weeks[][10] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    scanf(" %d", &N);
    while(N-- > 0) {
        scanf(" %d %d", &M, &D);
        t = (days[M - 1] + D - 1) % 7;
        printf("%s\n", weeks[t]);
    }
    return 0;
}