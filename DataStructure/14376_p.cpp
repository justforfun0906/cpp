#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    //undirected weighted graph
    //Floyd-Warshall algorithm
    long long A[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            A[i][j] = 1e18;
            if(i == j){
                A[i][j] = 0;
            }
        }
    }
    for(int i=0;i<m;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        A[a][b] = min(A[a][b], c);
        A[b][a] = min(A[b][a], c);
    }
    //Floyd-Warshall algorithm
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
            }
        }
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        if(A[a][b] >= 1e18){
            cout<<-1<<'\n';
        }else{
            cout<<A[a][b]<<'\n';
        }
    }
}