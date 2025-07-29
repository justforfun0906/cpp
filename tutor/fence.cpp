#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int ma[n][m];
    vector<int> ans;
    bool visited[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j] = 0;
            cin>>ma[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ma[i][j] == 1 && visited[i][j] == 0){
                int temp = 0;
                queue<pair<int,int>> q;
                q.push(make_pair(i,j));
                while(!q.empty()){
                    int fx = q.front().first;
                    int fy = q.front().second;
                    q.pop();
                    visited[fx][fy] = 1;
                    if(ma[fx-1][fy] == 0){
                        temp++;
                    }
                    if(ma[fx+1][fy] == 0){
                        temp++;
                    }
                    if(ma[fx][fy-1] == 0){
                        temp++;
                    }
                    if(ma[fx][fy+1] == 0){
                        temp++;
                    }
                    int dx[4] = {1, 0, -1, 0};
                    int dy[4] = {0, -1, 0, 1};
                    for(int k=0;k<4;k++){
                        if(ma[fx+dx[k]][fy+dy[k]]==1 && visited[fx+dx[k]][fy+dy[k]]==0){
                            q.push(make_pair(fx+dx[k], fy+dy[k]));
                            visited[fx+dx[k]][fy+dy[k]] = 1;
                        }
                    }
                }
                ans.push_back(temp);
            }
        }
    }
    sort(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i!=ans.size()-1){
            cout<<' ';
        }
    }
}