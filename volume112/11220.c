#include <stdio.h>
#include <string.h>

int main() {
    int T, k, i, j, len, t, c;
    char s[1001];
    scanf(" %d ",&T);
    for(k=1;k<=T;k++) {
        printf("Case #%d:\n",k);
        while(fgets(s,1000,stdin)!=NULL) {
            if(strcmp(s, "\n")==0) {
                break;
            }
            len = strlen(s);
            t=1;
            c=1;
            for(i=0;i<len;i++) {
                if(s[i]==' '||s[i]=='\n') {
                    c=1;
                } else if(c==t) {
                    putchar(s[i]);
                    t++;
                    c=t+1;
                } else {
                    c++;
                }
            }
            printf("\n");
        }
        if(k<T) {
            printf("\n");
        }
    }
    return 0;
}
