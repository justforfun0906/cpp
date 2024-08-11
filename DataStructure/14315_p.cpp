#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    multiset<int> ms;
    set<int> s;
    for(int i=0;i<n;i++){
        char c; int x;
        cin>>c>>x;
        if(c == 'I'){
            s.insert(x);
            ms.insert(x);
            cout<<s.size()<<'\n';
        }else if(c == 'D'){
            auto it = ms.find(x);
            if(it!=ms.end()){
                ms.erase(it);
                if(ms.count(x) == 0){
                    s.erase(x);
                }
            }
            cout<<s.size()<<'\n';
        }else if(c == 'C'){
            cout<<ms.count(x)<<'\n';
        }else if(c == 'L'){
            auto it = ms.lower_bound(x);
            if(it == ms.end()) cout<<-1<<'\n';
            else cout<<*it<<'\n';
        }else if(c == 'U'){
            auto it = ms.upper_bound(x);
            if(it == ms.end()) cout<<-1<<'\n';
            else cout<<*it<<'\n';
        }
    }
}