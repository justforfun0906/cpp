#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
    int from, to, weight;
};
void dfs(int x, vector<vector<int>> &G, vector<bool> &visited){
    visited[x] = true;
    for(auto u: G[x]){
        if(!visited[u]){
            dfs(u, G, visited);
        }
    }
    return;
}
signed main(){
    int n, m;
    cin>>n>>m;
    struct edge edges[m];
    vector<vector<int>> G(n+1);
    vector<vector<int>> reverse_G(n+1);
    for(int i=0; i<m; i++){
        cin>>edges[i].from>>edges[i].to>>edges[i].weight;
        G[edges[i].from].push_back(edges[i].to);
        reverse_G[edges[i].to].push_back(edges[i].from);
        edges[i].weight = -edges[i].weight;
    }
    vector<int> dist(n+1, 1e18);
    vector<bool> visited(n+1, false);
    vector<bool> reverse_visited(n+1, false);
    dfs(1, G, visited);
    dfs(n, reverse_G, reverse_visited);
    dist[1] = 0;
    bool neg_cycle = false;
    // Bellman-Ford algorithm
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<m;j++){
            //if can't reach from 1 or can't reach to n, continue
            //doing this to avoid detecting the negative cycle that doesn't affect the shortest path
            if(!visited[edges[j].from] || !reverse_visited[edges[j].to]) continue;
            if(dist[edges[j].to] > dist[edges[j].from] + edges[j].weight){
                dist[edges[j].to] = dist[edges[j].from] + edges[j].weight;
                if(i == n-1){
                    neg_cycle = true;
                    break;
                }
            }
        }
    }
    if(neg_cycle){
        cout<<-1<<'\n';
    }else{
        cout<<-dist[n]<<'\n';
    }
}