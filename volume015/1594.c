#include <stdio.h>
#include <stdlib.h>
int main() {
    int T, n, a[15],i,j,t;
    scanf(" %d",&T);
    while(T-->0) {
        scanf(" %d",&n);
        for(i=0;i<n;i++) {
            scanf(" %d",&a[i]);
        }
        for(j=0;j<1000;j++) {
            t=a[0];
            for(i=1;i<n;i++) {
                a[i-1]=abs(a[i]-a[i-1]);
            }
            a[n-1]=abs(a[n-1]-t);
        }
        for(i=0,t=0;i<n;i++) {
            if(a[i]!=0) {
                t=1;
                break;
            }
        }
        if(t) {
            printf("LOOP\n");
        } else {
            printf("ZERO\n");
        }
    }
    return 0;
}
