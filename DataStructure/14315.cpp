#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    multiset<int> s;
    set<int> s2;
    int q; cin>>q;
    while(q--){
        char ins;
        int x;
        cin>>ins>>x;
        multiset<int>::iterator it;
        switch(ins){
            case 'I':
                s.insert(x);
                s2.insert(x);
                //print number of distinct elements
                cout<<s2.size()<<'\n';
                break;
            case 'D':
                //delete one of the x
                //if x doesn't exist, do nothing
                it = s.find(x);
                if(it != s.end()){
                    s.erase(it);
                    if(s.count(x) == 0) s2.erase(x);//no more x in multiset
                }
                cout<<s2.size()<<'\n';
                break;
            case 'C':
                cout<<s.count(x)<<'\n';
                break;
            case 'L':
                //if can't find x, return -1
                //else return the smallest element greater than or equal to x
                it = s.lower_bound(x);
                if(it == s.end()) cout<<"-1\n";
                else cout<<*it<<'\n';
                break;
            case 'U':
                it = s.upper_bound(x);
                if(it == s.end()) cout<<"-1\n";
                else cout<<*it<<'\n';
                break;
        }
    }
}