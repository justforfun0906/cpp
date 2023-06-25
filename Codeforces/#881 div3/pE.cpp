#include<bits/stdc++.h>
using namespace std;
vector<int> change(100005);

bool check(vector<int> cnt,int l,int r){
    int one_cnt=cnt[r]-cnt[l-1];
    int zero_cnt=r-l+1-one_cnt;
    if(one_cnt>zero_cnt)return 1;
    else return 0;
}

void solve(){
    for(int i=0;i<100005;i++)change[i]=0;
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> segs(m);
    for(int i=0;i<m;i++){
        cin>>segs[i].first>>segs[i].second;
    }
    int q;cin>>q;
    for(int i=0;i<q;i++){
        cin>>change[i];
    }
    int l=0,r=q-1;
    bool stop=0;
    bool ok_temp=0;

    vector<int> prefix(n+5,0),cnt(n+5,0);
    for(int i=0;i<=q;i++){
        prefix[change[i]]=1;
    }
    for(int i=1;i<=n;i++){
        cnt[i]=prefix[i]+cnt[i-1];
    }
    for(int i=0;i<m;i++){
        if(check(cnt,segs[i].first,segs[i].second)){
           ok_temp=1; 
        }
    }
    if(ok_temp==0){
        stop=1;
        cout<<-1<<'\n';
    }

    if(stop==0){
        while(l<r){
            int mid= (l+r)/2;
            bool ok=0;
            for(int i=0;i<n+5;i++){
                prefix[i]=0;
                cnt[i]=0;
            }
            for(int i=0;i<=mid;i++){
                prefix[change[i]]=1;
            }
            for(int i=1;i<=n;i++){
                cnt[i]=prefix[i]+cnt[i-1];
            }
            for(int i=0;i<m;i++){
                if(check(cnt,segs[i].first,segs[i].second)){
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
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}