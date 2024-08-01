#include<bits/stdc++.h>
using namespace std;
struct node{
    int l = -1, r = -1;
    int val;
    node(int x):val(x){};
};
void dfs(int now_node, vector<int> &preorder, vector<node> &tree){
    if(now_node == -1) return;
    else{
        preorder.push_back(now_node);
        dfs(tree[now_node].l, preorder, tree);
        dfs(tree[now_node].r, preorder, tree);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> parent(n+1);
    vector<node> tree(n+1, node(0));
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        if(l != -1) parent[l] = i;
        if(r != -1) parent[r] = i;
        tree[i].l = l == -1 ? -1 : l;
        tree[i].r = r == -1 ? -1 : r;
    }
    int root_node = 0;
    for(int i=1;i<=n;i++){
        if(parent[i] == 0){
            root_node = i;
            break;
        }
    }
    //cout<<"root node ="<<root_node<<'\n';
    vector<int> preorder;
    dfs(root_node, preorder, tree);
    cout<<preorder[n-1]<<'\n';
}