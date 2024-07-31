#include<bits/stdc++.h>
using namespace std;
struct node{
    node *l = nullptr, *r = nullptr;
    int val;
    node(int x):val(x){};
};
vector< pair<int, int> > build(int l, int r, vector<pair<int, int>> tree, vector<int> preorder, vector<int> inorder_pos){

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
    vector<pair<int, int>> tree(n, {-1,-1});//left, right, if -1, then it is leaf node
    for(int i=0;i<n;i++) cout<<postorder[i]<<" ";
}