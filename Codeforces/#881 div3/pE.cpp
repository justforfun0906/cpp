#include<bits/stdc++.h>
using namespace std;
int n,m;
bool check(vector<pair<int,int>> segments, vector<int> change, int mid){
    vector<int> prefix(n+5,0), prefix_sum(n+5,0);
    for(int i=1;i<=mid;i++)prefix[change[i]]=1;
    for(int i=1;i<=n;i++)prefix_sum[i]=prefix_sum[i-1]+prefix[i];
    for(int i=0;i<m;i++){
        int one=prefix_sum[segments[i].second]-prefix_sum[segments[i].first-1];
        int zero=segments[i].second-segments[i].first+1-one;
        if(one>zero)return true;
    }
    return false;
}
void solve(){
    cin>>n>>m;
    vector< pair<int, int> > segments(m+5);
    for(int i=0;i<m;i++) cin>>segments[i].first>>segments[i].second;
    int q;cin>>q;
    vector<int> change(q+5);
    for(int i=1;i<=q;i++) cin>>change[i];
    int l=1, r=q;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(segments,change,mid))r=mid-1;
        else l=mid+1;
        
    }
    if(l>q)cout<<-1<<'\n';
    else cout<<l<<'\n';

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--)solve();
}