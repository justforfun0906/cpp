#include<stdio.h>
int main(){
    int n, target;
    scanf("%d %d", &n, &target);
    int cnt = 0, h[n+5], c[n+5];
    int ans[n+5];
    for(int i=1;i<=n;i++){
        scanf("%d", &h[i]);
        int j;
        for(j=i-1;j>=1;){
            if(h[j]<h[i]){
                j-=c[j]+1;
            }
            else break;
        }
        c[i]=i-j-1;
        if(c[i]==target) ans[cnt++]= i;
    }
    if(cnt>0){
        printf("%d",ans[0]);
        for(int i=1;i<cnt;i++){
            printf(" %d", ans[i]);
        }
    }else{
        printf("ouo");
    }
    printf("\n");
}