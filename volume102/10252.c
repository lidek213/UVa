#include <stdio.h>
#include <string.h>
int main() {
    char s1[1008], s2[1008];
    int count1[26] = {0}, count2[26] = {0}, i, j, t, len;
    while(fgets(s1, 1008, stdin) != NULL) {
        fgets(s2, 1008, stdin);
        len = strlen(s1);
        for(i = 0; i < len; i++) {
            if(s1[i] >= 'a' && s1[i] <= 'z') {
                count1[s1[i] - 'a']++;
            }
        }
        len = strlen(s2);
        for(i = 0; i < len; i++) {
            if(s2[i] >= 'a' && s2[i] <= 'z') {
                count2[s2[i] - 'a']++;
            }
        }
        for(i = 0; i < 26; i++) {
            t = count1[i]>count2[i]?count2[i]:count1[i];
            for(j = 0; j < t; j++) {
                putchar('a' + i);
            }
            count1[i] = count2[i] = 0;
        }
        putchar('\n');
    }
    return 0;
}