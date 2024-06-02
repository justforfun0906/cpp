#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q; cin>>n>>q;
    set<int> s;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        s.insert(x);
    }
    while(q--){
        int x; cin>>x;
        auto it = s.lower_bound(x);
        auto prev = it;
        if(it!=s.begin()){
            prev--;
        }
        if(it==s.end()){
            cout << *prev << '\n';
        }else{
            int dis1 = abs(*it-x);
            int dis2 = abs(*prev-x);
            if(dis1<dis2){
                cout << *it << '\n';
            }else{
                cout << *prev << '\n';
            }
        }
    }
}