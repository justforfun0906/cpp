#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> G(100005);
int N,M,K;
vector<int> dist(100005, 1e9);
int main(){
    cin>>N>>M>>K;//N: town, M: road, K: diamond
    for(int i=0;i<M;i++){
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=0;i<K;i++){
        int a;
        cin>>a;
        dist[a] = 0;
        queue<int> Q;
        Q.push(a);
        while(Q.empty()==false){
            int x = Q.front();
            Q.pop();
            for(auto it:G[x]){
                if(dist[it]>dist[x]+1){
                    dist[it] = dist[x]+1;
                    Q.push(it);
                }
            }
        }
    }
    for(int i=1;i<=N;i++){
        cout<<dist[i]<<'\n';
    }
}