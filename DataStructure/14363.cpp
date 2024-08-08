#include<bits/stdc++.h>
using namespace std;
void dfs(vector<bool> &visited, vector<pair<int, int> > &child, vector< vector<int> > &adj, int x){
    visited[x] = 1;
    for(auto i:adj[x]){
        if(!visited[i]){
            visited[i] = 1;
            if(child[x].first == -1){
                child[x].first = i;
            }else{
                child[x].second = i;
            }
            dfs(visited, child, adj, i);
        }
    }
}
void build(map<int, vector<int> > &mp, vector<pair<int, int> > &child, vector<int> &weight, int x){
    if(child[x].first == -1){//leaf node
        mp[x].push_back(weight[x]);
    }else{
        build(mp, child, weight, child[x].first);
        if(child[x].second!=-1)build(mp, child, weight, child[x].second);
        mp[x].push_back(weight[x]);
        mp[x].insert(mp[x].end(), mp[child[x].first].begin(), mp[child[x].first].end());
        if(child[x].second!=-1) mp[x].insert(mp[x].end(), mp[child[x].second].begin(), mp[child[x].second].end());
        sort(mp[x].begin(), mp[x].end(), greater<int>());
    }
}
int main(){
    int n, q;
    cin>>n>>q;
    vector<int> weight(n+1);
    for(int i=1;i<=n;i++){
        cin>>weight[i];
    }
    vector< vector<int> > adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    map<int, vector<int> > mp;//node -> sorted weights of its subtree
    vector< pair<int, int> > child(n+1,{-1, -1}); //left child, right child
    vector<bool> visited(n+1, false);
    dfs(visited, child, adj, 1);
    build(mp, child, weight, 1);
    while(q--){
        int x, k;
        cin>>x>>k;
        if(mp[x].size()<k){
            cout<<-1<<endl;
        }else{
            cout<<mp[x][k-1]<<endl;
        }
    }
}