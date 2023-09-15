#include<stdio.h>
int main(){
    int p,a,b,c,d, ans =0;
    scanf("%d %d %d %d %d",&p, &a, &b, &c, &d);
    while(p>=50&&d){
        d--;
        ans++;
        p-=50;
    }
    while(p>=10&&c){
        c--;
        ans++;
        p-=10;
    }
    while(p>=5&&b){
        b--;
        ans++;
        p-=5;
    }
    while(p>=1&&a){
        a--;
        ans++;
        p-=1;
    }
    if(p!=0) printf("-1\n");
    else printf("%d\n", ans);
}