#include<bits/stdc++.h>
using namespace std;
int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<int>> adj(V+1);
    vector<int> in_degree(V+1,0);
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        in_degree[v]++;
    }
    queue<int> q;
    for(int i=1;i<=V;i++){
        if(in_degree[i]==0) q.push(i);
    }
    vector<int> topo;
    bool flag = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for(int v:adj[u]){
            in_degree[v]--;
            if(in_degree[v]==0) q.push(v);
        }
    }
    if(topo.size()!=V) flag = false;
    if(flag) for(int i=0;i<V;i++) cout<<topo[i]<<" ";
    else cout<<"IMPOSSIBLE"<<endl;
}