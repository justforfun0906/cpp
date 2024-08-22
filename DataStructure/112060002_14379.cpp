#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> in_deg(n+1, 0);
    vector<int> path_cnt(n+1, 0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        in_deg[v]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(in_deg[i] == 0){
            q.push(i);
        }
    }
    path_cnt[1] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto& next: adj[cur]){
            path_cnt[next] = (path_cnt[next] + path_cnt[cur]) % MOD;
            in_deg[next]--;
            if(in_deg[next] == 0){
                q.push(next);
            }
        }
    }
    cout<<path_cnt[n]<<'\n';
}