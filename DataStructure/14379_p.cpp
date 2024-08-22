#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> in_degree(n+1, 0);
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        in_degree[v]++;
        //directed graph
    }
    vector<int> path_cnt(n+1, 0);
    path_cnt[1] = 1;
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: adj[u]){
            path_cnt[v] += path_cnt[u];
            path_cnt[v] %= MOD;
            in_degree[v]--;
            if(in_degree[v] == 0){
                q.push(v);
            }
        }
    }
    cout<<path_cnt[n]<<'\n';
}