#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> s;
    int q; cin>>q;
    while(q--){
        char i; int x;
        cin>>i>>x;
        if(i == 'I'){
            s.insert(x);
            cout<<s.size()<<'\n';
        }else if(i == 'D'){
            s.erase(x);
            cout<<s.size()<<'\n';
        }else if( i == 'S'){
            cout<<(s.count(x)?"YES\n":"NO\n");
        }else if(i == 'L'){
            auto it = s.lower_bound(x);
            if(it == s.end())cout<<-1<<'\n';
            else cout<<*it<<'\n';
        }else{
            auto it = s.upper_bound(x);
            if(it == s.end())cout<<-1<<'\n';
            else cout<<*it<<'\n';
        }
    }
}