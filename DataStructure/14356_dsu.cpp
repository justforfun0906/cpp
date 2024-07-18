#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
class DSU{
public:
    int n,m;
    int max_size;
    int cnt;
    vector< vector<int> > MAP;
    vector< vector<pii> > parent;
    vector< vector<int> > size;
    DSU(vector< vector<int> > MAP,int n, int m):MAP(MAP),n(n),m(m){
        parent.resize(n,vector<pii>(m));
        size.resize(n,vector<int>(m,0));
        max_size = 0;
        cnt = 0;
        this->init();
    }
    pii find(pii u){
        if(u == parent[u.first][u.second])return u;
        return parent[u.first][u.second] = find(parent[u.first][u.second]);
    }
    void merge(pii u, pii v){
        u = find(u);
        v = find(v);
        if(u == v)return;
        if(size[u.first][u.second] < size[v.first][v.second])swap(u,v);
        parent[v.first][v.second] = u;
        size[u.first][u.second] += size[v.first][v.second];
        max_size = max(max_size,size[u.first][u.second]);
        cnt--;
    }
    void init(){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(MAP[i][j]){
                    size[i][j] = 1;
                    parent[i][j] = {i,j};
                    cnt++;
                } else{
                    parent[i][j] = {-1,-1};
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(MAP[i][j]){
                    for(int k=0;k<4;k++){
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        if(nx<0||nx>=n||ny<0||ny>=m)continue;
                        if(MAP[nx][ny]){
                            merge({i,j},{nx,ny});
                        }
                    }
                }
            }
        }
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> MAP(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>MAP[i][j];
        }
    }
    stack<pii> st;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        x--; y--;
        st.push({x,y});
        MAP[x][y] = 0;
    }
    DSU dsu(MAP,n,m);
    stack<pii> ans;
    ans.push({dsu.max_size,dsu.cnt});
    while(!st.empty()){
        auto [x,y] = st.top();
        st.pop();
        dsu.MAP[x][y] = 1;
        dsu.parent[x][y] = {x,y};
        dsu.size[x][y] = 1;
        dsu.cnt++;
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m)continue;
            if(dsu.MAP[nx][ny]){
                dsu.merge({x,y},{nx,ny});
            }
        }
        ans.push({dsu.max_size,dsu.cnt});
    }
    while(!ans.empty()){
        auto [a,b] = ans.top();
        ans.pop();
        cout<<a<<' '<<b<<'\n';
    }
}