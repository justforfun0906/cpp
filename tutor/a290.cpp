#include<iostream>
#include<queue>
#include<vector> 
using namespace std;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    while(cin >> n){
        int m;
        cin>>m;
        vector<vector<int>> graph(n+5);
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
        }
        int a,b;
        cin >> a >> b;
        vector<bool> visited(n+5, false);
        queue<int> q;
        q.push(a);
        visited[a] = true;
        bool found = false;
        while(!q.empty()){
            int current = q.front();
            q.pop();
            if(current == b){
                cout << "Yes!!!" << endl;
                found = true;
                break;
            }
            for(int neighbor : graph[current]){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        if(!found)cout << "No!!!" << endl;
    }
}