#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int dp[k+5][n+5], a[n+5];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        dp[0][i]+=dp[0][i-1];
    }
    int ans =0;
    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=max(dp[i-1][j-1],dp[i][j-1]+a[j]);
            ans = max(dp[i][j], ans);
        }
    }
    cout<<ans;
}