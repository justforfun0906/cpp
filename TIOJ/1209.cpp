#include<iostream>
#include<vector>
using namespace std;
int root[50000];
int find(int i){
    if(root[i]==i) return i;
    root[i]=find(root[i]);
}
int main(){
    ios_base::sync_with_stdio;
    cin.tie(0);
    int v,e;
    while(cin>>v>>e&&v!=0&&e!=0){
        for(int i=0;i<50000;i++) root[i]=i;
        vector<vector<int> > g(v+10);
        for(int i=0;i<e;i++){
            int a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        bool isBipartite = true;
        for(int i=1;i<=v;i++){
            int first = g[i][0];
            for(auto x : g[i]){
                if(find(x)==find(i)){
                    isBipartite = false;
                    cout<<x<<"'s root ="<<find(x)<<'\n';
                    cout<<i<<"'s root ="<<find(i)<<'\n';
                }
                root[find(x)] = root[first];
            }
        }
        if(isBipartite)cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';
    }
}