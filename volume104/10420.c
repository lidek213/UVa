#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char s[100];
    int count;
} Str;

Str str[2011];
int strCount = 0, hashIndex[2011];

int cmp(const void *a, const void *b) {
    return strcmp(((Str*)a)->s, ((Str*)b)->s);
}

unsigned int hashcode(char *s) {
    unsigned int hash = 1;
    while(*s) {
        hash = hash * 65599 + (*s++);
    }
    return hash & 0x7FFFFFFF;
}

void insert(char *s) {
    unsigned int i = hashcode(s) % 2011;
    while(hashIndex[i] != -1) {
        if(strcmp(str[hashIndex[i]].s, s) == 0) {
            str[hashIndex[i]].count++;
            return;
        }
        i = (i + 1) % 2011;
    }
    hashIndex[i] = strCount;
    strcpy(str[strCount].s, s);
    str[strCount].count = 1;
    strCount++;
}

int main() {
    int n, i;
    char buf[100], s[100];
    memset(hashIndex, -1, 2011 * sizeof(int));
    scanf(" %d\n", &n);
    while(n-- > 0) {
        fgets(buf, 100, stdin);
        sscanf(buf, " %s", s);
        insert(s);
    }
    qsort(str, strCount, sizeof(Str), cmp);
    for(i = 0; i < strCount; i++) {
        printf("%s %d\n", str[i].s, str[i].count);
    }
    return 0;
}