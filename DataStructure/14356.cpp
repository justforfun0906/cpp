#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int map[n][m];
    bool visited[n][m]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
            visited[i][j] = 0;
        }
    }
    int max_size = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j] && !visited[i][j]){
                cnt++;
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = 1;
                int size = 0;
                while(!q.empty()){
                    size++;
                    auto [x,y] = q.front();
                    q.pop();
                    if(x>0 && map[x-1][y] && !visited[x-1][y]){
                        q.push({x-1,y});
                        visited[x-1][y] = 1;
                    }
                    if(x<n-1 && map[x+1][y] && !visited[x+1][y]){
                        q.push({x+1,y});
                        visited[x+1][y] = 1;
                    }
                    if(y>0 && map[x][y-1] && !visited[x][y-1]){
                        q.push({x,y-1});
                        visited[x][y-1] = 1;
                    }
                    if(y<m-1 && map[x][y+1] && !visited[x][y+1]){
                        q.push({x,y+1});
                        visited[x][y+1] = 1;
                    }
                }
                max_size = max(max_size,size);
            }
        }
    }
    cout<<max_size<<' '<<cnt<<'\n';
    while(k--){
        max_size = 0;
        cnt = 0;
        int tx,ty;
        cin>>tx>>ty;
        tx--; ty--;
        map[tx][ty] = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                visited[i][j] = 0;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j] && !visited[i][j]){
                    cnt++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = 1;
                    int size = 0;
                    while(!q.empty()){
                        size++;
                        auto [x,y] = q.front();
                        q.pop();
                        if(x>0 && map[x-1][y] && !visited[x-1][y]){
                            q.push({x-1,y});
                            visited[x-1][y] = 1;
                        }
                        if(x<n-1 && map[x+1][y] && !visited[x+1][y]){
                            q.push({x+1,y});
                            visited[x+1][y] = 1;
                        }
                        if(y>0 && map[x][y-1] && !visited[x][y-1]){
                            q.push({x,y-1});
                            visited[x][y-1] = 1;
                        }
                        if(y<m-1 && map[x][y+1] && !visited[x][y+1]){
                            q.push({x,y+1});
                            visited[x][y+1] = 1;
                        }
                    }
                    max_size = max(max_size,size);
                }
            }
        }
        cout<<max_size<<' '<<cnt<<'\n';
    }
}#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int map[n][m];
    bool visited[n][m]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
            visited[i][j] = 0;
        }
    }
    int max_size = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j] && !visited[i][j]){
                cnt++;
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = 1;
                int size = 0;
                while(!q.empty()){
                    size++;
                    auto [x,y] = q.front();
                    q.pop();
                    if(x>0 && map[x-1][y] && !visited[x-1][y]){
                        q.push({x-1,y});
                        visited[x-1][y] = 1;
                    }
                    if(x<n-1 && map[x+1][y] && !visited[x+1][y]){
                        q.push({x+1,y});
                        visited[x+1][y] = 1;
                    }
                    if(y>0 && map[x][y-1] && !visited[x][y-1]){
                        q.push({x,y-1});
                        visited[x][y-1] = 1;
                    }
                    if(y<m-1 && map[x][y+1] && !visited[x][y+1]){
                        q.push({x,y+1});
                        visited[x][y+1] = 1;
                    }
                }
                max_size = max(max_size,size);
            }
        }
    }
    cout<<max_size<<' '<<cnt<<'\n';
    while(k--){
        max_size = 0;
        cnt = 0;
        int tx,ty;
        cin>>tx>>ty;
        tx--; ty--;
        map[tx][ty] = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                visited[i][j] = 0;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j] && !visited[i][j]){
                    cnt++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = 1;
                    int size = 0;
                    while(!q.empty()){
                        size++;
                        auto [x,y] = q.front();
                        q.pop();
                        if(x>0 && map[x-1][y] && !visited[x-1][y]){
                            q.push({x-1,y});
                            visited[x-1][y] = 1;
                        }
                        if(x<n-1 && map[x+1][y] && !visited[x+1][y]){
                            q.push({x+1,y});
                            visited[x+1][y] = 1;
                        }
                        if(y>0 && map[x][y-1] && !visited[x][y-1]){
                            q.push({x,y-1});
                            visited[x][y-1] = 1;
                        }
                        if(y<m-1 && map[x][y+1] && !visited[x][y+1]){
                            q.push({x,y+1});
                            visited[x][y+1] = 1;
                        }
                    }
                    max_size = max(max_size,size);
                }
            }
        }
        cout<<max_size<<' '<<cnt<<'\n';
    }
}