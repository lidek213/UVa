#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10007
typedef struct {
    char s[20];
    int count;
} Data;

Data data[SIZE];
int pos[SIZE], posCount = 0;
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
unsigned int hashcode(char *s) {
    unsigned int hash = 0;
    while(*s) {
        hash = hash * 65599 + (*s++);
    }
    return hash & 0x7FFFFFFF;
}
void insertData(char *s) {
    unsigned int i = hashcode(s) % SIZE;
    while(data[i].s[0]) {
        if(strcmp(data[i].s, s) == 0) {
            data[i].count++;
            return;
        }
        i = (i + 1) % SIZE;
    }
    strcpy(data[i].s, s);
    data[i].count = 1;
    pos[posCount++] = i;
}

int main() {
    int n, i, k, code[5], max = 0, ans, countTemp;
    char buf[20];
    while(scanf(" %d", &n) != EOF) {
        if(n == 0) {
            break;
        }
        posCount = 0;
        memset(data, 0, sizeof(Data) * SIZE);
        for(k = 0; k < n; k++) {
            for(i = 0; i < 5; i++) {
                scanf(" %d", &code[i]);
            }
            qsort(code, 5, sizeof(int), cmp);
            sprintf(buf,"%d %d %d %d %d", code[0], code[1], code[2], code[3], code[4]);
            insertData(buf);
        }
        max = 0;
        ans = 0;
        for(i = 0; i < posCount; i++) {
            countTemp = data[pos[i]].count;
            if(countTemp > max) {
                max = countTemp;
                ans = countTemp;
            } else if(countTemp == max) {
                ans += max;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}