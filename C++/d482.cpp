#include<bits/stdc++.h>
using namespace std;
long long dp[105][105]={0};
int a[105][105]={0};
int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<105;i++){
            for(int j=0;j<105;j++){
                dp[i][j]=0;
                a[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
          for(int j=1;j<=n;j++){
            cin>>a[i][j];
            }
        }
        dp[1][1]=a[1][1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=a[i][j]+max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout<<dp[n][n]<<'\n';
    }
    
}