#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
class TwoD_DSU{
    public:
        vector<vector<pii> > parent;
        vector<vector<pii> > size;
        vector<vector<int> > map;
        int n,m;
        int max_size = 0;
        int cnt = 0;
        TwoD_DSU(int n, int m){
            this->n = n;
            this->m = m;
            parent.resize(n, vector<pii>(m));
            size.resize(n, vector<pii>(m));
            map.resize(n, vector<int>(m));
        }
        void union(int x1, int y1, int x2, int y2){
            pii p1 = find(x1,y1);
            pii p2 = find(x2,y2);
            if(p1==p2) return;
            if(size[p1.first][p1.second]>size[p2.first][p2.second]){
                parent[p2.first][p2.second] = p1;
                size[p1.first][p1.second] += size[p2.first][p2.second];
                max_size = max(max_size, size[p1.first][p1.second]);
            } else{
                parent[p1.first][p1.second] = p2;
                size[p2.first][p2.second] += size[p1.first][p1.second];
                max_size = max(max_size, size[p2.first][p2.second]);
            }
            cnt--;
        }
        void insert(int x, int y){
            map[x][y] = 1;
            parent[x][y] = {x,y};
            //try union

        };
        pii find(int x, int y){
            if(parent[x][y]==make_pair(x,y)) return {x,y};
            return parent[x][y] = find(parent[x][y].first, parent[x][y].second);
        }
};
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int map[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }
    pair<int, int> dsu[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]==0){
                dsu[i][j] = {-1,-1};
            } else{
                dsu[i][j] = {i,j};
            }
        }
    }
}