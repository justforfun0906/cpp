#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Edge {
    int src, dest, weight;
};
signed main(){
    int v,e;
    cin>>v>>e;
    vector<vector<pair<int,int>>> adj(v);
    for(int i=0;i<e;i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u-1].push_back(make_pair(v-1, w));
    }
    vector<int> dis(v, __LONG_LONG_MAX__);
    queue<int> q;
    vector<bool> inQueue(v, false);
    q.push(0); // Start from the first vertex
    inQueue[0] = true;
    dis[0] = 0; // Starting node distance is 0
    while(!q.empty()){
        int u = q.front();
        q.pop();
        inQueue[u] = false;
        for(auto v : adj[u]){
            int vIndex = v.first;
            int weight = v.second;
            if(dis[u] != __LONG_LONG_MAX__ && dis[u] + weight < dis[vIndex]){
                dis[vIndex] = dis[u] + weight;
                if(!inQueue[vIndex]){
                    q.push(vIndex);
                    inQueue[vIndex] = true;
                }
            }
        }
    }
    for(int i=0;i<v;i++){
        cout<<dis[i]<<" ";
    }
}