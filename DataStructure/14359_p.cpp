#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector< vector<int> > G(n+1);
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  vector< vector<bool> > CompG(n+1, vector<bool>(n+1, true));
  for(int i=1;i<=n;i++){
	CompG[i][i] = false;
    for(auto x:G[i]){
      CompG[i][x] = false;
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(CompG[i][j]){
        cout<<i<<' '<<j<<'\n';
        CompG[j][i] = false;
      }
    }
  }
}
