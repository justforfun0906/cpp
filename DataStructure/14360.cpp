#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> preorder(n),inorder(n),postorder(n);
    for(int i=0;i<n;i++) cin>>preorder[i];
    for(int i=0;i<n;i++) cin>>inorder[i];
    //calculate postorder
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