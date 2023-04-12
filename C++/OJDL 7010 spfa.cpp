//code for fun
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(false);cin.tie(0);
#define int long long
#define pii pair<int, int>
#define vi vector<int>
typedef long long ll;
using namespace std;
int INF=1e18;
signed main(){
    faster;
    int v,e;
    cin>>v>>e;
    vector< vector<pii> > G(v+1);
    vector<int> dis (v+5,INF);
    dis[1]=0;
    for(int i=0;i<e;i++){
        int a,b,w;
        cin>>a>>b>>w;
        G[a].push_back(make_pair(b,w));
        G[b].push_back(make_pair(a,w));
    }
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(auto i=G[top].begin();i<G[top].end();i++){
            int it=i-G[top].begin();
            if(dis[top]+G[top][it].second < dis[G[top][it].first]){
                dis[G[top][it].first]=dis[top]+G[top][it].second;
                q.push(G[top][it].first);
            }
        }
    }
    for(int i=1;i<=v;i++){
        cout<<dis[i]<<'\n';
    }
}
