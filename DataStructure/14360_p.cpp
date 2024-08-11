#include<bits/stdc++.h>
using namespace std;
void build(int &index, int l, int r, vector<int> &pre, vector<int> &in_index, vector<int> &post, int &post_idx){
    if(l>r) return;
    int pos = in_index[pre[index]];
    int root = pre[index];
    index++;//go to next root in pre
    build(index, l, pos-1, pre, in_index, post, post_idx);
    build(index, pos+1, r, pre, in_index, post, post_idx);
    post[post_idx++] = root; 
}
int main(){
    int n;
    cin>>n;
    vector<int> pre(n+1);
    vector<int> in(n+1);
    vector<int> in_index(n+1);
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    for(int i=0;i<n;i++){
        cin>>in[i];
        in_index[in[i]] = i;
    }
    int index = 0;
    int post_idx = 0;
    vector<int> post(n);
    build(index, 0, n-1, pre, in_index, post, post_idx);
    for(auto x:post) cout<<x<<' ';
}