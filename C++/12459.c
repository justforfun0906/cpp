#include<stdio.h>
long long p[10];
long long solve(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return p[n-1]+solve(n-1);
}
int main(){
    p[0]=1;
    int n; scanf("%d", &n);
    for(int i=1;i<10;i++){
        p[i]=p[i-1]*8;
    }
    printf("%lld\n", solve(n));
}