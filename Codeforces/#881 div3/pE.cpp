#include<bits/stdc++.h>
using namespace std;
vector<int> change(200005,0);
vector< vector<int> > prefix_loc(100005);
bool check(int c){

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
        if(check(mid)){
            r=mid;
        }
        else l=mid+1;
    }
}
int main(){
    int t;cin>>t;
    while(t--)solve();
}