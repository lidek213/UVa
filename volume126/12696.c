#include <stdio.h>

int main() {
    int length, width, depth, weight;
    int t, allowCount = 0, a, b;
    scanf(" %d", &t);
    while(t-- > 0) {
        scanf(" %d.%d", &a, &b);
        length = a * 100 + b;
        scanf(" %d.%d", &a, &b);
        width = a * 100 + b;
        scanf(" %d.%d", &a, &b);
        depth = a * 100 + b;
        scanf(" %d.%d", &a, &b);
        weight = a * 100 + b;
        if(((length <= 5600 && width <= 4500 && depth <= 2500) || (length + width + depth) <= 12500) && weight <= 700) {
            allowCount++;
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
    printf("%d\n", allowCount);
    return 0;
}