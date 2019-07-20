#include <stdio.h>
#include <string.h>
int timemap(char *time) {
    char mapTime[][5]={
        "UTC","GMT","BST","IST","WET","WEST","CET","CEST",
        "EET","EEST","MSK","MSD","AST","ADT","NST","NDT",
        "EST","EDT","CST","CDT","MST","MDT","PST","PDT",
        "HST","AKST","AKDT","AEST","AEDT","ACST","ACDT","AWST"
    };
    int mapValue[]={
        0,0,60,60,0,60,60,120,
        120,180,180,240,-240,-180,-210,-150,
        -300,-240,-360,-300,-420,-360,-480,-420,
        -600,-540,-480,600,660,570,630,480
    };
    int i;
    for(i=0;i<32;i++) {
        if(!strcmp(time,mapTime[i])) {
            return mapValue[i];
        }
    }
}
int main() {
    int N, h, m, t;
    char time[10], slot[5], zone1[5], zone2[5];
    scanf(" %d", &N);
    while(N-- > 0) {
        scanf(" %s", &time);
        if(!strcmp(time, "noon")) {
            h=12;
            m=0;
        } else if(!strcmp(time, "midnight")) {
            h=0;
            m=0;
        } else {
            scanf(" %s", &slot);
            sscanf(time, "%d:%d", &h, &m);
            if(!strcmp(slot, "a.m.")) {
                h = h % 12;
            } else if(h != 12) {
                h += 12;
            }
        }
        scanf(" %s %s", &zone1, &zone2);
        t = -timemap(zone1) + timemap(zone2);
        m = m + t % 60 + 60;
        h = (h + t / 60 - 1 + m / 60 + 24) % 24;
        m = m % 60;
        if(h == 0) {
            if(m == 0) {
                printf("midnight\n");
            } else {
                printf("12:%02d a.m.\n", m);
            }
        } else if(h == 12) {
            if(m == 0) {
                printf("noon\n");
            } else {
                printf("12:%02d p.m.\n", m);
            }
        } else {
            if(h < 12) {
                printf("%d:%02d a.m.\n", h, m);
            } else {
                printf("%d:%02d p.m.\n", h - 12, m);
            }
        }
    }
    return 0;
}
