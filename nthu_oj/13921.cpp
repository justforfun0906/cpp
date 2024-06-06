#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>q;
    set<int> pts;
    while(q--){
        int instruct; cin>>instruct;
        if(instruct == 1){
            int x;
            cin>>x;
            if(pts.find(x)!=pts.end()) pts.erase(x);//if already in the set, erase it
            else pts.insert(x);//if not in the set, insert it
        }else if(instruct == 2){
            int x; cin>>x;
            auto right = pts.upper_bound(x), left = right;
            if(right != pts.begin())left--;//if has a left bound
            if(right == pts.end()||left == right){//no right bound or no left bound
                cout<<-1<<'\n';
            }else{
                cout<<*right - *left<<'\n';
            }
        }
    }
}