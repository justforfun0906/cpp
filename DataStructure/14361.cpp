#include<bits/stdc++.h>
using namespace std;
struct node{
    node *l = nullptr, *r = nullptr;
    int val;
    node(int x):val(x){};
};
void dfs(node* now_node, int k, vector<int> &inorder){
    if(now_node==nullptr) return;
    else{
        inorder[k] = now_node->val;
        dfs(now_node->l, k+1, inorder);
        dfs(now_node->r, k+1, inorder);
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
        tree[i].l = l == -1 ? nullptr : &tree[l];
        tree[i].r = r == -1 ? nullptr : &tree[r];
    }
    int root_node = 0;
    for(int i=1;i<=n;i++){
        if(parent[i] == 0){
            root_node = i;
            break;
        }
    }
    vector<int> inorder(n+1);
    dfs(&tree[root_node], 1, inorder);
    for(int i=1;i<=n;i++) cout<<inorder[i]<<" ";
}