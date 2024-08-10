#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, vector<int> &b){
    //max size = 20
    vector<int> ans;
    int i=0, j=0;
    while(i<a.size() && j<b.size()&& ans.size()<20){
        if(a[i]>b[j]){
            ans.push_back(a[i]);
            i++;
        }else{
            ans.push_back(b[j]);
            j++;
        }
    }
    while(i<a.size()&&ans.size()<20){
        ans.push_back(a[i]);
        i++;
    }
    while(j<b.size()&&ans.size()<20){
        ans.push_back(b[j]);
        j++;
    }
    a.resize(ans.size());
    a.assign(ans.begin(), ans.end());
}

void dfs(vector<bool> &visited, vector<vector<int>> &mp, vector< vector<int> > &adj, int x, vector<int> &weight){
    visited[x] = 1;
    mp[x].push_back(weight[x]);
    for(auto i:adj[x]){
        if(!visited[i]){
            visited[i] = 1;
            dfs(visited, mp, adj, i, weight);
            merge(mp[x], mp[i]);
        }
    }
}

int main(){
    int n, q;
    cin>>n>>q;
    vector<int> weight(n+1);
    for(int i=1;i<=n;i++){
        cin>>weight[i];
    }
    vector< vector<int> > adj(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int> > mp(n+1);//node -> sorted weights of its subtree
    vector< pair<int, int> > child(n+1,{-1, -1}); //left child, right child
    vector<bool> visited(n+1, false);
    dfs(visited, mp, adj, 1, weight);
    while(q--){
        int x, k;
        cin>>x>>k;
        cout<<mp[x][k-1]<<'\n'; 
    }
}