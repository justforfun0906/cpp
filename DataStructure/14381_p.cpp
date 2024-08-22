#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
    int u, v, w;
};
int find(int x, int dsu[]){
    if(dsu[x] == x) return x;
    return dsu[x] = find(dsu[x], dsu);
}
bool cmp(edge a, edge b){
    return a.w < b.w;
}
int find_mst(int n, int m, vector<edge> edges, int excld_idx){
    int dsu[n+1];
    for(int i=1;i<=n;i++){
        dsu[i] = i;
    }
    int mst = 0;
    int cnt = 0;
    for(int i=0;i<m;i++){
        if(i == excld_idx) continue;
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        int fu = find(u, dsu);
        int fv = find(v, dsu);
        if(fu != fv){
            mst += w;
            dsu[fu] = fv;
            cnt++;
        }
        if(cnt == n-1) break;
    }
    if(cnt != n-1) return 1e18;
    return mst;
}
signed main(){
    int n,m;
    cin>>n>>m;
    vector<edge> edges(m);
    int dsu[n+1];
    for(int i=1;i<=n;i++){
        dsu[i] = i;
    }
    for(int i=0;i<m;i++){
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
    }
    sort(edges.begin(), edges.end(), cmp);
    vector<int> mst_edges_idx;
    for(int i=0;i<m;i++){
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        int fu = find(u, dsu);
        int fv = find(v, dsu);
        if(fu != fv){
            mst_edges_idx.push_back(i);
            dsu[fu] = fv;
        }
    }
    int secondbest= 1e18;
    for(auto i: mst_edges_idx){
        secondbest = min(secondbest, find_mst(n, m, edges, i));
    }
    cout<<secondbest<<'\n';
}