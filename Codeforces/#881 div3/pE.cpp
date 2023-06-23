#include<bits/stdc++.h>
using namespace std;
vector<int> change(200005,0);
vector< vector<int> > prefix_loc(100005);
bool check(int l,int r,int c,int n){
    vector<int> prefix(n+5,0),cnt(n+5,0);
    for(auto x:prefix_loc[c]){
        prefix[x]=1;
    }
    for(int i=1;i<=n;i++){
        cnt[i]=prefix[i]+cnt[i-1];
    }
    int one_cnt=cnt[r]-cnt[l-1];
    int zero_cnt=r-l+1-one_cnt;
    if(one_cnt>zero_cnt)return 1;
    else return 0;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> segs(m);
    for(int i=0;i<m;i++){
        cin>>segs[i].first>>segs[i].second;
    }
    int q;cin>>q;
    for(int i=0;i<n;i++){
        cin>>change[i];
        if(i>0)prefix_loc[i]=prefix_loc[i-1];
        prefix_loc[i].push_back(change[i]);
    }
    int l=0,r=q-1;
    while(l<r){
        int mid= (l+r)/2;
        bool ok=0;
        for(int i=0;i<m;i++){
            if(check(segs[i].first,segs[i].second,mid,n)){
                ok=1;
            }
        }
        if(ok){
            r=mid;
        }
        else l=mid+1;
    }
    cout<<l+1<<'\n';
}
int main(){
    int t;cin>>t;
    while(t--)solve();
}