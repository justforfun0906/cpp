#include<bits/stdc++.h>
#define int long long
// remember to use long long
using namespace std;
struct edge{
    int from, to, weight;
};
void dfs(vector<vector<int> > &g, vector<bool> &visited, int now){
    visited[now] = true;
    for(int i=0;i<g[now].size();i++){
        if(!visited[g[now][i]]){
            dfs(g, visited, g[now][i]);
        }
    }
}
signed main(){
    int v,e;
    cin>>v>>e;
    struct edge edges[e];
    vector<vector<int> > g(v+1);
    vector<vector<int>> rev_g(v+1);
    for(int i=0;i<e;i++){
        cin>>edges[i].from>>edges[i].to>>edges[i].weight;
        g[edges[i].from].push_back(edges[i].to);
        rev_g[edges[i].to].push_back(edges[i].from);
        // change the weight to negative
        // longest path = shortest path with negative weight
        edges[i].weight = -edges[i].weight;
    }  
    vector<int> dist(v+1, 1e18);
    vector<bool> visited(v+1, false);
    vector<bool> rev_visited(v+1, false);
    //find what nodes are reachable from 1 and v
    //if a node is not reachable from 1 or v, the negative cycle will not affect it
    dfs(g, visited, 1);
    dfs(rev_g, rev_visited, v);
    dist[1] = 0;
    // Bellman-Ford algorithm
    bool neg_cycle = false;
    for(int i=0;i<=v-1;i++){
        for(int j=0;j<e;j++){
            if(!visited[edges[j].from] || !rev_visited[edges[j].to]) continue;
            if(dist[edges[j].to] > dist[edges[j].from] + edges[j].weight){
                dist[edges[j].to] = dist[edges[j].from] + edges[j].weight;
                if(i == v-1){
                    neg_cycle = true;
                    break;
                }
            }
        }
    }
    if(neg_cycle){
        cout<<-1<<'\n';
    }else{
        cout<<-dist[v]<<'\n';
    }
}