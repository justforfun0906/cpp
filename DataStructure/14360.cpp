#include<bits/stdc++.h>
using namespace std;
void build(int l, int r, int root, vector<int> &preorder, vector<int> &inorder_pos, vector<int> &postorder, int &post_idx) {
    if (l > r) return;
    int pos = inorder_pos[preorder[root]];
    build(l, pos - 1, root + 1, preorder, inorder_pos, postorder, post_idx);
    build(pos + 1, r, root + pos - l + 1, preorder, inorder_pos, postorder, post_idx);
    postorder[post_idx++] = preorder[root];
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
    int post_idx = 0;
    build(0, n - 1, 0, preorder, inorder_pos, postorder, post_idx);
    for(int i=0;i<n;i++) cout<<postorder[i]<<" ";
}