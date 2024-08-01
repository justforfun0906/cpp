#include<bits/stdc++.h>
using namespace std;
struct node{
    node *l = nullptr, *r = nullptr;
    int val;
    node(int x):val(x){};
};
node* build(int l, int r, int root, vector<int> preorder, vector<int> inorder_pos){
    node* root_node = new node(preorder[root]);
    if(l == r){
        return root_node;
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> preorder(n),inorder(n),postorder(n), inorder_pos(n+1);
    for(int i=0;i<n;i++) cin>>preorder[i];
    for(int i=0;i<n;i++){
        cin>>inorder[i];
        inorder_pos[inorder[i]] = i;
    }
    //calculate postorder
    node *root = build(0,n-1,0,preorder,inorder_pos);
    for(int i=0;i<n;i++) cout<<postorder[i]<<" ";
}