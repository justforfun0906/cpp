#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int dfs(int start, int cur, vector<vector<int>> &adj, int len_cnt, vector<bool> &visited) {
    visited[cur] = true;
    int min_cycle = INF;
    
    for (auto& next : adj[cur]) {
        if (next == start) {
            min_cycle = min(min_cycle, len_cnt);  // Found a cycle
        } else if (!visited[next]) {
            int result = dfs(start, next, adj, len_cnt + 1, visited);
            if (result != INF) {
                min_cycle = min(min_cycle, result);
            }
        }
    }
    
    visited[cur] = false;  // Unmark the node for other paths
    return min_cycle;
}

int findShortestCycle(int n, vector<vector<int>>& adj) {
    int result = INF;
    for (int i = 1; i <= n; ++i) {
        vector<bool> visited(n + 1, false);
        result = min(result, dfs(i, i, adj, 1, visited));
    }
    return result == INF ? -1 : result;
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
        
        int result = findShortestCycle(n, adj);
        cout << result << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}