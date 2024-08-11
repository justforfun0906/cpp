#include<bits/stdc++.h>
using namespace std;
void get(vector<int> &pre, vector< pair<int, int> > &tree, int x){
    pre.push_back(x);
    if(tree[x].first!=-1){
        get(pre, tree, tree[x].first);
    }
    if(tree[x].second!=-1){
        get(pre, tree, tree[x].second);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> pa(n+1);
    vector< pair<int, int> > tree(n+1);
    for(int i=1;i<=n;i++){
        pa[i] = i;
    }
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        if(a!=-1) pa[a] = i;
        if(b!=-1) pa[b] = i;
        tree[i] = {a,b};
    }
    int root = 0;
    for(int i=1;i<=n;i++){
        if(pa[i] == i){
            root = i;
            break;
        }
    }
    vector<int> pre;
    get(pre, tree, root);
    cout<<pre[n-1]<<'\n';
}