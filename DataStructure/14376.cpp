#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    long long G[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            G[i][j] = 1e18;
            //initialize the diagonal to 0
            if(i == j){
                G[i][j] = 0;
            }
        }
    }
    for(int i=0;i<m;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        G[a][b] = min(G[a][b], c);
        G[b][a] = min(G[b][a], c);
    }
    // Floyd-Warshall algorithm

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        if(G[a][b] >= 1e18){
            cout<<-1<<'\n';
        }else{
            cout<<G[a][b]<<'\n';
        }
    }
}