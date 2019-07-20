#include <stdio.h>
int main() {
    int H1,M1,H2,M2,t;
    while(scanf(" %d %d %d %d",&H1,&M1,&H2,&M2)==4) {
        if(!H1&&!M1&&!H2&&!M2) {
            break;
        }
        t=H2*60+M2-H1*60-M1;
        if(t<0) {
            t+=1440;
        }
        printf("%d\n",t);
    }
    return 0;
}
