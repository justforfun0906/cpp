#include<stdio.h>
long long a[1000005];
long long prefix[1000005];
int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        scanf("%lld", &a[i]);
    }
    for(int i=0;i<m;i++){
        int a,b,v;
        scanf("%d %d %d", &a, &b, &v);
        prefix[a-1]+=v;
        prefix[b]-=v;
    }
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i]+prefix[i-1];
    }
    printf("%lld", prefix[0]+a[0]);
    for(int i=1;i<n;i++){
        printf(" %lld", prefix[i]+a[i]);
    }
    printf("\n");
}