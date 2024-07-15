#include<bits/stdc++.h>
using namespace std;
int maxx = 0;
int uni_find(vector<int> &dsu, int v){
    if(dsu[v]==v) return v;
    else{
        dsu[v] = uni_find(dsu,dsu[v]);//path compression
        return dsu[v];
    }
}
void uni(vector<int> &dsu, vector<int> &size, int a, int b){
    int pa = uni_find(dsu,a);
    int pb = uni_find(dsu,b);
    if(pa==pb) return;
    else{
        if(size[pa]>size[pb]){
            dsu[pb] = pa;
            size[pa] += size[pb];
        }else{
            dsu[pa] = pb;
            size[pb] += size[pa];
        }
        maxx = max(maxx, max(size[pa],size[pb]));
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> dsu(n+5);
    vector<int> size(n+5,1);
    for(int i=0;i<=n;i++){
        dsu[i] = i;
        size[i] = 1;
    }
    int cnt = n;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if(uni_find(dsu,u)!=uni_find(dsu,v)){
            uni(dsu,size,u,v);
            cnt--;
        }
        cout<<cnt<<' '<<maxx<<'\n';
    }
}