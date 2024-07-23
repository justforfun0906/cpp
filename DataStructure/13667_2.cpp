#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank, team;

    DSU(int n): parent(n+1), rank(n+1, 0), team(n+1, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (x != parent[x]) {
            int original_parent = find(parent[x]);
            team[x] ^= team[parent[x]]; // Inherit and possibly invert team assignment
            parent[x] = original_parent;
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return team[x] == team[y]; // Same team if team assignments are equal
        }
        if (rank[rootX] < rank[rootY]) {
            swap(rootX, rootY);
            swap(x, y);
        }
        parent[rootY] = rootX;
        team[rootY] = team[x] ^ team[y] ^ 1; // Ensure different teams after merge
        if (rank[rootX] == rank[rootY]) rank[rootX]++;
        return true;
    }
};

int main() {
    int participants, matches;
    cin >> participants >> matches;
    DSU dsu(participants);
    for (int i = 0; i < matches; i++) {
        int x, y;
        cin >> x >> y;
        if (dsu.unite(x, y)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}