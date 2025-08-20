#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
signed main(){
    int n;
    cin>>n;
    vector<pair<int,int>> points;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        points.push_back(make_pair(x,y));
    }
    sort(points.begin(), points.end());
    vector<int> dp;
    for(int i=0;i<n;i++){
        if(dp.empty()||points[i].second>=dp.back())dp.push_back(points[i].second);
        else{
            int it = lower_bound(dp.begin(),dp.end(),points[i].second) - dp.begin();
            dp[it] = points[i].second;
        }
        // for(auto x:dp) cout<<x<<' ';
        // cout<<endl;
    }
    cout<<dp.size();
}