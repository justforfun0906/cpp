#include<stdio.h>
long long p[10];
int main(){
    p[0]=1;
    int n; scanf("%d", &n);
    long long ans=1;
    for(int i=1;i<n;i++){
        p[i]=p[i-1]*8;
        ans += p[i];
    }
    printf("%lld\n", ans);
}