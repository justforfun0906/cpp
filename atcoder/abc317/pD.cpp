#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n; cin>>n;
    long long z_sum=0, a_vote=0, b_vote=0;
    vector<long long> cost;
    vector<long long> value;
    for(int i=0;i<n;i++){
        long long x, y, z;
        cin>>x>>y>>z;
        z_sum+=z;
        if(x<y){
            cost.push_back(((y-x)/2)+1);
            value.push_back(z);
            b_vote+=z;
        }
        else{
            a_vote+=z;
        }
    }
    long long target = (z_sum + 1) / 2 ;
    //target = overhalf
    long long ans = 1e18;
    if(a_vote>b_vote) ans = 0;
    else{
        vector<long long> dp(z_sum+5,1e18); 
        //dp[n] = the cost to get exactly n value. if can't, it will be INF.
        dp[0]=0;
        int N = cost.size();
        for(int i = 0;i < N;i++){
            for(int j = z_sum ; j >= value[i] ; j--){    
                dp[j] = min(dp[j] , dp[j - value[i]]+cost[i]);    
            }
        }
        for(int i = target - a_vote ; i <= z_sum ; i++){
            ans = min(ans, dp[i]);
        }
    }
    cout<<ans;
}