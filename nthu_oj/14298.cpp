#include<bits/stdc++.h>
using namespace std;
void Max_val(multiset<int> &S){
    if(S.empty()){
        cout<<"No votes recorded\n";
        return;
    }
    cout<< *S.rbegin()<<'\n';
    return;
}
void Min_val(multiset<int> &S){
    if(S.empty()){
        cout<<"No votes recorded\n";
        return;
    }
    cout<< *S.begin()<<'\n';
    return;
}
void Remove(multiset<int> &S, int x){
    auto it = S.find(x);
    if(it!=S.end()){
        S.erase(it);
    }
}
void Output(multiset<int> &S){
    if(S.empty()){
        cout<<"No votes recorded\n";
        return;
    }
    for(auto it:S){
        cout<<it<<' ';
    }
    cout<<'\n';
}
int main(){
    multiset<int> S;
    int q; cin>>q;
    while(q--){
        string cmd; cin>>cmd;
        if(cmd == "Max"){
            Max_val(S);
        } else if(cmd == "Min"){
            Min_val(S);
        } else if(cmd == "Remove"){
            int target; cin>>target;
            Remove(S, target);
        } else if(cmd == "Add"){
            int target; cin>>target;
            S.insert(target);
        } else if(cmd == "Output"){
            Output(S);
        }
    }
}