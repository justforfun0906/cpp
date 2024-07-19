#include<bits/stdc++.h>
using namespace std;

// DSU structure
struct DSU {
    vector<int> parent, rank;

    DSU(int n) : parent(n+1), rank(n+1, 0) {
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if(x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return false; // Already in the same team
        if(rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if(rank[px] == rank[py]) rank[px]++;
        return true;
    }
};

int main(){
    int participants, matches;
    cin >> participants >> matches;
    DSU dsu(participants);
    for(int i = 0; i < matches; i++){
        int u, v; cin >> u >> v;
        if(dsu.unite(u, v)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}