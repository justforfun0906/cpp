#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    set<int> s;
    int q; cin>>q;
    while(q--){
        char ins;
        int x;
        cin>>ins>>x;
        switch(ins){
            case 'I':
                s.insert(x);
                cout<<s.size()<<'\n';
                break;
            case 'D':
                s.erase(x);
                cout<<s.size()<<'\n';
                break;
            case 'S':
                cout<<(s.count(x)>0?"YES\n":"NO\n");
                break;
            case 'L':
                //if can't find x, return -1
                //else return the smallest element greater than or equal to x
                if(s.lower_bound(x) == s.end()) cout<<"-1\n";
                else cout<<*s.lower_bound(x)<<'\n';
                break;
            case 'U':
                if(s.upper_bound(x) == s.end()) cout<<"-1\n";
                else cout<<*s.upper_bound(x)<<'\n';
                break;
        }
    }
}