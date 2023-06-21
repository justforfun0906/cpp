#include<bits/stdc++.h>
using namespace std;

vector< vector<int>> g(200005);
vector<int> child_cnt(200005,0);

void dfs(int v, int p){//vertex, its parent
    if(g[v].size()==1&&g[v][0]==p){//leaf
        child_cnt[v]=1;
    }else{
        for(auto x:g[v]){
            if(x!=p){
                dfs(x,v);
                child_cnt[v]+=child_cnt[x];
            }
        }
    }
}

void solve(){
    int v;
    cin>>v;
    for(int i=0;i<200005;i++){
        g[i].clear();
        child_cnt[i]=0;
    }
    for(int i=0;i<v-1;i++){
        int a,b;
        cin>>a>>b;
        g[b].push_back(a);
        g[a].push_back(b);
    }
    dfs(1,0);
    int q;cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<(long long)child_cnt[a]*child_cnt[b]<<'\n';
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