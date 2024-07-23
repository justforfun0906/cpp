#include<bits/stdc++.h>
using namespace std;
int main (){
    int n,m;cin>>n>>m;//n = vertices, m = edges
    vector<vector<int> > adj(n+1,vector<int> (n+1,0));
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    vector< vector<int> > complement_adj(n+1, vector<int> (n+1, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j) complement_adj[i][j] = 0;
            else complement_adj[i][j] = 1 - adj[i][j];
        }
    }
    //output edges of complement graph
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(complement_adj[i][j] == 1){
                cout<<i<<" "<<j<<endl;
                complement_adj[i][j] = 0;
                complement_adj[j][i] = 0;
            }
        }
    }
}