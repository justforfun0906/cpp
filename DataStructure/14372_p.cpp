#include<bits/stdc++.h>
using namespace std;
int bfs(int n, vector<int> adj[], int start, set<int> cookie){
    queue<int> q;
    vector<bool> visited(n+1, false);
    vector<int> dist(n+1, 1e9);
    q.push(start);
    visited[start] = true;
    dist[start] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: adj[u]){
            if(!visited[v]){
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    int ans = 1e9;
    for(auto c: cookie){
        ans = min(ans, dist[c]);
    }
    if(ans == 1e9) return -1;
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, start;
        cin>>n>>m;
        vector<int> adj[n+1];
        for(int i=0; i<m; i++){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cin>>start;
        int cookie_num;
        cin>>cookie_num;
        set<int> cookie;
        for(int i=0; i<cookie_num; i++){
            int c;
            cin>>c;
            cookie.insert(c);
        }
        int res = bfs(n, adj, start, cookie);
        if(res == -1) cout<<"SAD\n";
        else cout<<res<<"\n";
    }
}