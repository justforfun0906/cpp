#include<bits/stdc++.h>
using namespace std;
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
    while(q--){
        int k, v;
        //find the kth maximum weight of the subtree rooted at v
        cin>>k>>v;
        vector<int> subtree_weight;
        function<void(int, int)> dfs = [&](int u, int p){
            subtree_weight.push_back(weight[u]);
            for(int x: adj[u]){
                if(x == p) continue;
                dfs(x, u);
            }
        };
        dfs(v, 0);
        sort(subtree_weight.begin(), subtree_weight.end(), greater<int>());
        for(auto x: subtree_weight){
            cout<<x<<' ';
        }
        cout<<'\n';
    }
}