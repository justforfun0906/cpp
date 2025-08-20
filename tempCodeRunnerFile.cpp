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
    for(int i=1;i<n;i++){
        if(points[i].second>dp.back() || dp.empty())dp.push_back(points[i].second);
        else{
            int it = lower_bound(dp.begin(),dp.end(),points[i].second) - dp.begin();
            dp[it] = points[i].second;
        }
    }
    cout<<dp.size();
}