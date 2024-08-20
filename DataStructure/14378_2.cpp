#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> height(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> height[i][j];
        }
    }

    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {INT_MAX, INT_MAX}));
    dp[0][0] = {0, 0};
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;
    pq.push({0, 0, 0, 0}); // {max_diff, path_length, x, y}

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!pq.empty()) {
        auto [max_diff, path_length, x, y] = pq.top();
        pq.pop();

        if (x == n - 1 && y == n - 1) {
            cout << max_diff << "\n" << path_length << "\n";
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                int diff = abs(height[x][y] - height[nx][ny]);
                int new_max_diff = max(max_diff, diff);
                int new_path_length = path_length + 1;
                if (new_max_diff < dp[nx][ny].first || (new_max_diff == dp[nx][ny].first && new_path_length < dp[nx][ny].second)) {
                    dp[nx][ny] = {new_max_diff, new_path_length};
                    pq.push({new_max_diff, new_path_length, nx, ny});
                }
            }
        }
    }

    return 0;
}