#include<stdio.h>
#include<string.h>
int dp[1005][1005]={-1};
char a[1005];
int f(int i, int j){
    if(i==j) return 1;
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==a[j]){
        dp[i][j]=f(i+1, j-1)+2;
    }else if(f(i+1,j)>f(i,j-1)){
        dp[i][j]=f(i+1,j);
    }else{
        dp[i][j]=f(i,j-1);
    }
    return dp[i][j];
}
int main(){
    int n,k;
    scanf("%d %d", &n, &k);
    scanf("%s", a);
    memset(dp,-1, sizeof(dp));
    f(0,n-1);
    if(n-dp[0][n-1]<=k)printf("Yes\n");
    else printf("No\n");
}