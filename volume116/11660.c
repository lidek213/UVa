#include <stdio.h>
#include <string.h>
int main() {
    char x[10001], t[10001], s;
    int i,j,len,len2,count,x1,k,p,q;
    while(scanf(" %d %d %d",&x1,&i,&j)==3) {
        if(!x1&&!i&&!j) {
            break;
        }
        sprintf(x,"%d",x1);
        for(k=1;k<i;k++) {
            len=strlen(x);
            count=1;
            s=x[0];
            len2=0;
            memset(t,0,2001);
            for(p=1;p<=len;p++) {
                if(x[p]==s) {
                    count++;
                } else {
                    sprintf(&t[len2],"%d%c",count,s);
                    s=x[p];
                    count=1;
                    len2=strlen(t);
                    if(p>j) {
                        break;
                    }
                }
            }
            strcpy(x,t);
        }
        printf("%c\n",x[j-1]);
    }
    return 0;
}
