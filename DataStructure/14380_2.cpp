#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int bfs_min_cycle(int start, vector<vector<int>>& adj, int n) {
    vector<int> dist(n + 1, -1);
    queue<pair<int, int>> q;
    q.push({start, 0});
    dist[start] = 0;
    
    int min_cycle = INF;
    
    while (!q.empty()) {
        int node = q.front().first;
        int depth = q.front().second;
        q.pop();
        
        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {  // Not visited
                dist[neighbor] = depth + 1;
                q.push({neighbor, depth + 1});
            } else if (dist[neighbor] >= dist[node]) {  // Cycle detected
                min_cycle = min(min_cycle, dist[node] - dist[neighbor] + 1);
            }
        }
    }
    
    return min_cycle == INF ? -1 : min_cycle;
}

int find_smallest_cycle(int n, vector<vector<int>>& adj) {
    int min_cycle = INF;
    
    for (int i = 1; i <= n; ++i) {
        min_cycle = min(min_cycle, bfs_min_cycle(i, adj, n));
    }
    
    return min_cycle == INF ? -1 : min_cycle;
}

void solve() {
    int T;
    cin >> T;
    
    while (T--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> adj(n + 1);
        
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        int result = find_smallest_cycle(n, adj);
        cout << result << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
