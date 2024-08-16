#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int start;
    cin >> start;
    
    int cookie_num;
    cin >> cookie_num;
    vector<int> cookie(cookie_num);
    for(int i = 0; i < cookie_num; i++) {
        cin >> cookie[i];
    }
    
    vector<bool> visited(n+1, false);
    vector<int> dist(n+1, -1);
    queue<int> q;
    
    q.push(start);
    visited[start] = true;
    dist[start] = 0;
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    int min_dist = INT_MAX;
    for(int i = 0; i < cookie_num; i++) {
        if(dist[cookie[i]] != -1) {
            min_dist = min(min_dist, dist[cookie[i]]);
        }
    }
    
    if(min_dist == INT_MAX) {
        cout << "SAD" << endl;
    } else {
        cout << min_dist << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}