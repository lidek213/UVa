#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int code, count;
} Data;
int cmp(const void *a, const void *b) {
    Data p = *(Data *)a, q = *(Data *)b;
    if(p.count == q.count) {
        return q.code - p.code;
    }
    return p.count - q.count;
}
int main() {
    char s[1004];
    int i, len, flag = 0;
    Data data[132];
    while(fgets(s, 1004, stdin) != 0) {
        if(flag) {
            printf("\n");
        }
        for(i = 0; i <= 128; i++) {
            data[i].code = i;
            data[i].count = 0;
        }
        len = strlen(s);
        if(s[len - 1] == '\n') {
            len -= 1;
        }
        for(i = 0; i < len; i++) {
            data[s[i]].count++;
        }
        qsort(data, 128, sizeof(Data), cmp);
        i = 0;
        while(data[i].count == 0) {
            i++;
        }
        for(;i < 128; i++) {
            printf("%d %d\n", data[i].code, data[i].count);
        }
        flag = 1;
    }
    return 0;
}