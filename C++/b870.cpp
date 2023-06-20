/*
1 3 4 9 15 tree 
 2 1 5 6   dis 
  3   9 15 fire extin
2 0 1 0 0  tree fire dis
---*/
#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> tree, int target, int fire){
    int stand_cnt=0;
    int range=0;
    for(auto x:tree){
        if(range<x){
            range=x+(2*target);
            stand_cnt++;
        }
    }
    if (stand_cnt>fire)return false;
    else return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        if(n<m)cout<<0<<'\n';
        else{
            int l_bound=1e9, r_bound=0;
            vector<int> tree(n);
            for(int i=0;i<n;i++){
               cin>>tree[i];
               l_bound=min(l_bound,tree[i]);
              r_bound=max(r_bound,tree[i]);
            }
            sort(tree.begin(),tree.end());
            int r=r_bound-l_bound, l=0;// binary searching min max dis
            int mid=(l+r)/2;
            while(l<r){
                mid=(l+r)/2;
                if(check(tree, mid, m)){
                    r=mid;
                }
                else{
                    l=mid+1;
                }
            }
            if(check(tree,mid,m))cout<<mid<<'\n';
            else cout<<mid+1<<'\n';
        }
        
    }
}