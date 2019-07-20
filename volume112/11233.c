#include <stdio.h>
#include <string.h>

typedef struct {
    char s[32];
} Str;
Str key[31];
Str str[31];

unsigned int hashcode(char *p) {
    unsigned int hash = 0;
    while(*p) {
        hash = hash * 65599 + (*p++);
    }
    return hash & 0x7FFFFFFF;
}

void insert(char *p, char *q) {
    unsigned int i = hashcode(p) % 31;
    while(strcmp(key[i].s, "")) {
        i = (i + 1) % 31;
    }
    strcpy(key[i].s, p);
    strcpy(str[i].s, q);
}

int searchIndex(char *p) {
    unsigned int i = hashcode(p) % 31, ti;
    ti = i;
    while(strcmp(key[i].s, p)) {
        if(!strcmp(key[i].s, "")) {
            return -1;
        }
        i = (i + 1) % 31;
        if(ti == i) {
            return -1;
        }
    }
    return i;
}

int main() {
    int L, N, i, index, len;
    char s1[32], s2[32];
    memset(key, 0, sizeof(Str) * 31);
    memset(str, 0, sizeof(Str) * 31);
    scanf(" %d %d", &L, &N);
    for(i = 0; i < L; i++) {
        scanf(" %s %s", s1, s2);
        insert(s1, s2);
    }
    for(i = 0; i < N; i++) {
        scanf(" %s", s1);
        index = searchIndex(s1);
        if(index == -1) {
            len = strlen(s1);
            if(s1[len - 1] == 'y') {
                if(len >= 2) {
                    switch(s1[len - 2]) {
                        case 'a':
                        case 'e':
                        case 'i':
                        case 'o':
                        case 'u':
                            printf("%ss\n", s1);
                            break;
                        default:
                            s1[len - 1] = '\0';
                            printf("%sies\n", s1);
                    }
                } else {
                    s1[len - 1] = '\0';
                    printf("%sies\n", s1);
                }
            } else if(s1[len - 1] == 'o' || s1[len - 1] == 's' || s1[len - 1] == 'x' ||
                (len >=2 && (s1[len - 2] == 'c' || s1[len - 2] == 's') && s1[len - 1] == 'h')) {
                printf("%ses\n", s1);
            } else {
                printf("%ss\n", s1);
            }
        } else {
            printf("%s\n", str[index].s);
        }
    }
    return 0;
}