#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char f0[100005], f1[100005];
long long len[100];
char f(int n, long long m){
    if(n==0)return f0[m];
    if(n==1)return f1[m];
    if(m>=len[n-2]) return f(n-1,m-len[n-2]);
    else return f(n-2,m);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s %s",f0,f1);
        long long n,m;
        scanf("%lld %lld",&n, &m);
        len[0] = strlen(f0);
        len[1] = strlen(f1);
        for(int i=2;i<=n;i++){
            len[i] = len[i-2]+ len[i-1];
        }
        char ans = f(n,m);
        printf("%c\n",ans);
    }
}