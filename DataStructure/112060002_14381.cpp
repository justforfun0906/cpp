#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
    int u, v , weight;
    int tag = 0;
};
bool cmp(edge a, edge b){
    return a.weight < b.weight;  // sort by weight from smallest to largest
}
int query(vector<int> &dsu, int now){
    // path compression
    if(dsu[now] == now) return now;
    return dsu[now] = query(dsu, dsu[now]);
}
int findMST(int V, vector<edge> &edges, int excludeIndex) {
    vector<int> dsu(V + 1);
    for(int i = 1; i <= V; i++) {
        dsu[i] = i;
    }
    int cnt = 0, sum = 0;
    for(int i = 0; i < edges.size(); i++) {
        if(i == excludeIndex) {
            continue;  // skip the excluded edge
        }
        int from = query(dsu, edges[i].u);
        int to = query(dsu, edges[i].v);
        if(from != to) {
            dsu[from] = to;
            cnt++;
            sum += edges[i].weight;
        }
        if(cnt == V - 1) break;  // If we already have V-1 edges in MST
    }

    if(cnt == V - 1) return sum;  // If a valid MST was formed
    return LLONG_MAX;  // If no valid MST was found
}

signed main(){
    int V, E;
    cin >> V >> E;
    vector<edge> edges(E);
    for(int i = 0; i < E; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].tag = i;
    }

    sort(edges.begin(), edges.end(), cmp);

    // Find the original MST
    vector<int> dsu(V + 1);
    for(int i = 1; i <= V; i++) {
        dsu[i] = i;
    }

    int cnt = 0, sum = 0;
    vector<int> mstEdges;
    for(int i = 0; i < E; i++){
        if(cnt == V - 1) break;
        int u = query(dsu, edges[i].u);
        int v = query(dsu, edges[i].v);
        if(u != v){
            dsu[u] = v;
            cnt++;
            sum += edges[i].weight;
            mstEdges.push_back(i);
        }
    }

    int secondBest = LLONG_MAX;
    for(int i : mstEdges) {
        int possibleMST = findMST(V, edges, i);
        secondBest = min(secondBest, possibleMST);
    }

    cout << secondBest << endl;
    return 0;
}
