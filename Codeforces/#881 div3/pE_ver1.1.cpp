#include<bits/stdc++.h>
using namespace std;
int n,m;
bool check(vector<int> prefix_sum,int l,int r){
    int one_cnt=prefix_sum[r]-prefix_sum[l-1];
    int zero_cnt=r-l+1-one_cnt;
    if(one_cnt>zero_cnt)return 1;
    else return 0;
}
void solve(){
    //input
    cin>>n>>m;
    vector< pair<int, int> > segments(m+5);
    for(int i=0;i<m;i++) cin>>segments[i].first>>segments[i].second;
    int q;cin>>q;
    vector<int> change(q+5);
    for(int i=1;i<=q;i++) cin>>change[i];
    int l=1, r=q;
    bool stop=1;
    //checking if there's ans
    vector<int> prefix(n+5,0),prefix_sum(n+5,0);
    for(int i=1;i<=q;i++)prefix[change[i]]=1;
    for(int i=1;i<=n;i++)prefix_sum[i]=prefix_sum[i-1]+prefix[i];
    for(int i=0;i<m;i++) if(check(prefix_sum,segments[i].first,segments[i].second))stop=0;
    if(stop){
        cout<<-1<<'\n';
    }
    else{//there's answer
        while(l!=r){
            stop=0;
            int mid=(l+r)/2;
            //making prefix sum array
            for(int i=0;i<n+5;i++){
                prefix[i]=0;
                prefix_sum[i]=0;
            }
            for(int i=1;i<=mid;i++) prefix[change[i]]=1;
            for(int i=1;i<=n;i++) prefix_sum[i]=prefix_sum[i-1]+prefix[i];
            //checking all segments;
            for(int i=0;i<m;i++){
                if(check(prefix_sum,segments[i].first,segments[i].second)){
                    stop=1;//one of the segments is beautiful
                    break;
                }
            }
            if(stop)r=mid;
            else l=mid+1;
        }
        cout<<l<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}