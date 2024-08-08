#include<bits/stdc++.h>
#define int long long
using namespace std;
bool flag = 1;
struct Node{
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};
Node* build(int l, int r, vector<int> &pre, vector<int> &in_index, int &index){
    if(l>r) return nullptr; //base case
    Node* x = new Node(pre[index]);
    // cout<<"now at: "<<x->data<<endl;
    index++;
    if(l==r) return x;
    else{
        int pos = in_index[x->data];
        x->left = build(l, pos-1, pre, in_index, index);
        x->right = build(pos+1, r, pre, in_index, index);
        // cout<<"node:" <<x->data;
        // if(x->left) cout<<" left:"<<x->left->data;
        // if(x->right) cout<<" right:"<<x->right->data;
        if(x->left){
            if(in_index[x->left->data] > pos){
                flag = 0;
            }
        }
        if(x->right){
            if(in_index[x->right->data] < pos){
                flag = 0;
            }
        }
    }
    return x;
}
void get_postorder(Node* x, vector<int> &ans){
    if(x==nullptr) return;
    else{
        get_postorder(x->left, ans);
        get_postorder(x->right, ans);
        ans.push_back(x->data);
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int> pre(n), in(n), post(n);
    vector<int> in_index(n+1);

    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    for(int i=0;i<n;i++){
        cin>>in[i];
        in_index[in[i]] = i;
    }
    for(int i=0;i<n;i++){
        cin>>post[i];
    }
    vector<int> ans;
    int root_idx = 0;
    flag = 1;
    Node* root = build(0, n-1, pre, in_index, root_idx);
    get_postorder(root,ans);
    if(ans == post && flag){
        cout<<"yes\n";
    }else{
        cout<<"no\n";
    }
}
signed main(){
    int q; cin>>q;
    while(q--){
        solve();
    }
}