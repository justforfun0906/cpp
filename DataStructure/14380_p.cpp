#include<bits/stdc++.h>
using namespace std;
int dfs(bool &found, int start, int now, vector<bool> &visited, vector<int> adj[],int len_cnt){
    visited[now] = true;
    int ans = 1e9;
    for(auto next : adj[now]){
        if(next == start){
            found = true;
            ans = min(ans, len_cnt);
        }else if(!visited[next]){
            int res = dfs(found, start, next, visited, adj, len_cnt+1);
            ans = min(ans, res);
        }
    }
    return ans;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        //directed graph
    }
    int min_cycle_len = 1e9;
    bool flag = false;
    for(int i=1;i<=n;i++){
        vector<bool> visited(n+1, false);
        int res = dfs(flag, i, i, visited, adj, 1);
        min_cycle_len = min(min_cycle_len, res);
    }
    if(!flag){
        cout<<"-1\n";
    }else{
        cout<<min_cycle_len<<'\n';
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}