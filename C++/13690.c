#include<stdio.h>
long long f[100]={0};
long long g[100]={0};
int main(){
    int a,b,c,d,n;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &n);
    f[0]=a;
    f[1]=b;
    g[0]=c;
    g[1]=d;
    for(int i=2;i<=n;i++){
        if(i%5==0){
            g[i]=g[i-1]+f[g[(i/5)]%i];
        }else{
            g[i]=g[i-1]+f[i-2];
        }if(i%3==0){
            f[i]=f[i-1]+g[f[i/3]%i];
        }else{
            f[i]=f[i-1]+g[i-2];
        }
    }
    printf("%lld %lld\n",f[n],g[n]);
}