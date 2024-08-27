#include<bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main(){
    int N;
    cin>>N;
    int height[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>height[i][j];
        }
    }
    vector<vector<pair<int, int> > > G(N, vector<pair<int, int> >(N, {1e9, 1e9}));//mininum max height diff, path length
    G[0][0] = {0, 0};
    queue<pair<int, int> > q;//cord
    q.push({0, 0});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<N){
                int diff = max(G[x][y].first, abs(height[x][y]-height[nx][ny]));
                if(diff < G[nx][ny].first){
                    G[nx][ny].first = diff;//update mininum max height diff
                    G[nx][ny].second = G[x][y].second+1;
                    q.push({nx, ny});
                }else if(diff == G[nx][ny].first && G[x][y].second+1 < G[nx][ny].second){
                    G[nx][ny].second = G[x][y].second+1;//choose shorter path
                    q.push({nx, ny});
                }
            }
        }
    }
    cout<<G[N-1][N-1].first<<'\n'<<G[N-1][N-1].second<<'\n';
}