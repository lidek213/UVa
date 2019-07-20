#include <stdio.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
int main() {
    int N,M,i,k,x1,x2,y1,y2,sx,sy,ex,ey;
    scanf(" %d",&N);
    for(k=1;k<=N;k++) {
        scanf(" %d",&M);
        scanf(" %d %d %d %d",&sx,&sy,&ex,&ey);
        for(i=1;i<M;i++) {
            scanf(" %d %d %d %d",&x1,&y1,&x2,&y2);
            if(x1>sx) {
                sx=x1;
            }
            if(y1>sy) {
                sy=y1;
            }
            if(x2<ex) {
                ex=x2;
            }
            if(y2<ey) {
                ey=y2;
            }
        }
        printf("Case %d: ",k);
        if(ex>=sx && ey>=sy) {
            printf("%d\n", (ex-sx)*(ey-sy));
        } else {
            printf("0\n");
        }
    }
    return 0;
}
