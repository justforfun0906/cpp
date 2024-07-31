#include<bits/stdc++.h>
using namespace std;
vector< pair<int, int> > build(vector<int> )
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> preorder(n),inorder(n),postorder(n), in_order_pos(n+1);
    for(int i=0;i<n;i++) cin>>preorder[i];
    for(int i=0;i<n;i++){
        cin>>inorder[i];
        in_order_pos[inorder[i]] = i;
    }
    //calculate postorder
    vector<pair<int, int>> tree(n, {-1,-1});//left, right, if -1, then it is leaf node
    function<void(int,int,int,int,int)> dfs = [&](int pre_start, int in_start, int in_end, int post_start, int post_end){
        if(in_start > in_end) return;
        int root = preorder[pre_start];
        postorder[post_end] = root;
        int root_index = in_start;
        while(inorder[root_index] != root) root_index++;
        int left_size = root_index - in_start;
        dfs(pre_start+1, in_start, root_index-1, post_start, post_start+left_size-1);
        dfs(pre_start+left_size+1, root_index+1, in_end, post_start+left_size, post_end-1);
    };
    dfs(0,0,n-1,0,n-1);
    for(int i=0;i<n;i++) cout<<postorder[i]<<" ";
}