#include<bits/stdc++.h>
using namespace std;
int dx[]= {0, 0, 1, -1};
int dy[]= {1, -1, 0, 0};
int main(){
    int n;
    cin>>n;
    int height[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>height[i][j];
        }
    }
    pair<int, int> dp[n][n];//max height difference, path length
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = {INT_MAX, INT_MAX};
        }
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    dp[0][0] = {0, 0};
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<n){
                int diff = max(dp[cur.first][cur.second].first, abs(height[cur.first][cur.second] - height[nx][ny]));
                int len = dp[cur.first][cur.second].second + 1;
                if(diff < dp[nx][ny].first){
                    dp[nx][ny].first = diff;
                    dp[nx][ny].second = len;
                    q.push({nx, ny});
                }
                else if(diff == dp[nx][ny].first && len < dp[nx][ny].second){
                    dp[nx][ny].second = len;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout<<dp[n-1][n-1].first<<"\n"<<dp[n-1][n-1].second<<'\n';
}