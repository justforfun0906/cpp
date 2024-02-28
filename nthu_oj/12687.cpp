#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    int dp[k+5][n+5],weight[n+5],value[n+5];
    for(int i=1;i<=n;i++){
        cin>>value[i]>>weight[i];
    }
    for(int i=0;i<=k;i++){
        for(int j=0;j<=n;j++){//dp[i][j] = max value of first j items and i weight
            if(i==0||j==0){
                dp[i][j]=0;
            }else if(weight[j]>i){
                dp[i][j]=dp[i][j-1];
            }else{
                dp[i][j] = max(dp[i][j-1],dp[i-weight[j]][j-1]+value[j]);//don't pick or pick
            }
        }
    }
    cout<<dp[k][n]<<'\n';
}