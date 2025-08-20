#include<iostream>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    vector<int> dp(n);
    dp[0] = 1;
    for(int i=1;i<n;i++){
        if(x[i] >= x[i-1]){
            dp[i] = dp[i-1] + 1;
        }else{
            dp[i] = dp[i-1];
        }
    }
    for(int i=0;i<n;i++){
        cout<<dp[i]<<' ';
    }
}