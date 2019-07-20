#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10113

typedef struct {
    char s[32];
    int count;
} Tree;

int cmp(const void *a, const void *b) {
    return strcmp(((Tree*)a)->s , ((Tree*)b)->s);
}

unsigned int hashcode(char *s) {
    unsigned int hash = 0;
    while(*s) {
        hash = hash * 65599 + (*s++);
    }
    return hash & 0x7FFFFFFF;
}

int insert(Tree tree[], char *s) {
    unsigned int hash = hashcode(s) % SIZE;
    while(tree[hash].count != 0) {
        if(!strcmp(tree[hash].s, s)) {
            tree[hash].count++;
            return 0;
        }
        hash++;
    }
    strcpy(tree[hash].s, s);
    tree[hash].count = 1;
    return 1;
}

int main() {
    int T, totalCount, i, treeCount;
    char s[32];
    Tree tree[SIZE];
    scanf(" %d ", &T);
    while(T-- > 0) {
        totalCount = 0;
        treeCount = 0;
        memset(tree, 0, sizeof(Tree) * SIZE);
        while(fgets(s, 32, stdin) != NULL) {
            if(!strcmp(s, "\n")) {
                break;
            }
            if(s[strlen(s) - 1] == '\n') {
                s[strlen(s) - 1] = '\0';
            }
            treeCount += insert(tree, s);
            totalCount++;
        }
        qsort(tree, SIZE, sizeof(Tree), cmp);
        for(i = SIZE - treeCount; i < SIZE; i++) {
            printf("%s %.4f\n", tree[i].s, tree[i].count * 100.0 / totalCount);
        }
        if(T) {
            printf("\n");
        }
    }
    return 0;
}
